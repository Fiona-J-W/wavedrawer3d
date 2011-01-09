#ifndef __lib_picture_cpp__
#define __lib_picture_cpp__
#include "libpicture.hpp"

#include<fstream>
#include<cstdio>
#include<cmath>
#include <stdexcept>


picture::picture(int width,int height,color_rgb col){
/** constructor (defaults: width=0, height=0, col=col_white) **/
	//set the size:
	m_height=height;
	m_width=width;
	//create the container for the data and give it the fitting size:
	m_data.resize(m_width);
	for(int i=0;i<m_width;++i){
		m_data.at(i).resize(m_height);
		for(int j=0;j<m_height;++j){
			///set all pixels to the given color:
			m_data.at(i).at(j)=col;
		}
	}
}

color_rgb picture::set_pix(int x,int y,color_rgb color){
	/** set a Pixel with the Coordinates x|y to color **/
	if((x>=1)&&(x<=m_width)&&(y>=1)&&(y<=m_height)){
		///Are the coordinates valid?
		//try{
			m_data.at(x-1).at(y-1)=color;
			///set it
		//}
		//catch(out_of_range error){
		//	printf("out_of_range-exception: %s\n",error.what());
		//}
	}
	///return the colour to enable multible assignments:
	return color;
}

color_rgb picture::get_pix(int x,int y){
/** returns the colour of a Pixel **/
	if((x>=1)&&(x<=m_width)&&(y>=1)&&(y<=m_height)){
		return m_data.at(x-1).at(y-1);
	}
	return col_white;///return white if out of range;
}
color_rgb picture::get_pix_s(int x,int y){
/** returns the colour of a Pixel with exceptions **/
	///No testing if the field is valid, as this is for usage of exceptions:
	return m_data.at(x-1).at(y-1);
}

void picture::resize(int width,int height){
/** resizes the image; anything outstanding will be cut of and new space will be fild undefined **/
	if(width<=0||height<=0){///test if the new size is valid
		throw out_of_range("invalid new size");
	}
	m_height=height;
	m_width=width;
	m_data.resize(m_width);
	for(int i=0;i<m_width;++i){
		m_data.at(i).resize(m_height);
	}
}

void picture::line(point p1,point p2,color_rgb color){
/** draws a line from p1 to p2 in coloured in color **/
	if((((double)get_dif(p1.y,p2.y))/((double)get_dif(p1.x,p2.x)))<=1){
		double dif_per_pix=((double)get_dif(p1.y,p2.y))/get_dif(p1.x,p2.x);
		for(int i=smaller(p1.x,p2.x),j=0;i<=greater(p1.x,p2.x);++i){
			set_pix(i,smaller(p1.y,p2.y)+j*dif_per_pix,color);
			++j;
		}
	}
	else{
		double dif_per_pix=((double)get_dif(p1.x,p2.x))/get_dif(p1.y,p2.y);
		for(int i=smaller(p1.y,p2.y),j=0;i<=greater(p1.y,p2.y);++i){
			set_pix(smaller(p1.x,p2.x)+j*dif_per_pix,i,color);
			++j;
		}
	}
}


void picture::rect(point p1,point p2,
		   color_rgb fill,//=col_black,
		   int stroke,//=0,
		   color_rgb stroke_col//=col_black
	){
/** draws a rectangle between p1 and p2 **/
	///create a left_down_point and a top-right point from the given points
	point ld_point,rt_point;
	ld_point.set(smaller(p1.x,p2.x),smaller(p1.y,p2.y));
	rt_point.set(greater(p1.x,p2.x),greater(p1.y,p2.y));
	///and fill the area between
	for(int x=ld_point.x;x<=rt_point.x;++x){
		for(int y=ld_point.y;y<=rt_point.y;++y){
			set_pix(x,y,fill);
		}
	}
	if(stroke>0){
		///recursion is used, to draw the borders. NEVER use borders in the following rectangles as this would lead to endless 
		///recursion which would mean a segfault after some time
		
		///bottom:
		rect(point(ld_point.x-stroke/2,ld_point.y+stroke/2+stroke%2),point(rt_point.x+stroke/2,ld_point.y-stroke/2),stroke_col);
		///top:
		rect(point(ld_point.x-stroke/2,rt_point.y-stroke/2-stroke%2),point(rt_point.x+stroke/2,rt_point.y+stroke/2),stroke_col);
		///left:
		rect(point(ld_point.x-stroke/2,ld_point.y-stroke/2),point(ld_point.x+stroke/2+stroke%2,rt_point.y+stroke/2),stroke_col);
		///right:
		rect(point(rt_point.x-stroke/2-stroke%2,ld_point.y-stroke/2),point(rt_point.x+stroke/2,rt_point.y+stroke/2),stroke_col);
	}
}

void picture::circle(point m,int r,
		color_rgb fill,//=col_black,
		int stroke,//=0,
		color_rgb stroke_col//=col_black
	){
/** draws a circle around m with the radius r**/
	double dist,dist_to_border;
	for(int x=m.x-r;x<=m.x+r;++x){
		for(int y=m.y-r;y<=m.y+r;++y){
			dist=sqrt(((m.x-x)*(m.x-x))+((m.y-y)*(m.y-y)));
			dist_to_border=dist-r;
			dist_to_border=abs(dist_to_border);
			if(dist<=r){
				set_pix(x,y,get_pix(x,y).paint_over(fill,dist_to_border));
			}
		}
	}
	if(stroke){
		for(int y=m.y-r-stroke-(stroke%2);y<=m.y+r+stroke+(stroke%2);++y){
			for(int x=m.x-r-stroke-(stroke%2);x<=m.x+r+stroke+(stroke%2);++x){
				dist=sqrt(((m.x-x)*(m.x-x))+((m.y-y)*(m.y-y)));
				dist_to_border=dist-r;
				dist_to_border=abs(dist_to_border);
				if(dist_to_border<=(stroke/2.0)+1.0){
					color_rgb new_color=get_pix(x,y);
					new_color.paint_over(stroke_col,(1.0-(dist_to_border-(stroke/2.0))));
					set_pix(x,y,new_color);
				}
			}
		}
	}
}

void picture::ellipse(point m,int rx,int ry,
		   color_rgb fill,//=color_rgb(0,0,0),
		   int stroke,//=0,
		   color_rgb stroke_col//=color_rgb(0,0,0)
	){
/** draws an ellipse; be carfull with borders **/
	double dist=sqrt((greater(rx,ry)*greater(rx,ry))-(smaller(rx,ry)*smaller(rx,ry)))*2,linelength,rad_sum,dist_to_border;
	point m1,m2;
	color_rgb new_color;
	if(rx>=ry){
		m1.set(m.x-(dist/2),m.y);
		m2.set(m.x+(dist/2),m.y);
	}
	else{
		m1.set(m.x,m.y-(dist/2));
		m2.set(m.x,m.y+(dist/2));
	}
	linelength=2*greater(rx,ry);
	for(int x=m.x-rx;x<=m.x+rx;++x){
		for(int y=m.y-ry;y<=m.y+ry;++y){
			rad_sum=get_dist(m1,point(x,y))+get_dist(m2,point(x,y));
			if(rad_sum<=linelength){
				set_pix(x,y,fill);
			}
			else if(rad_sum<=linelength+1){
				dist_to_border=abs(linelength-rad_sum)-stroke;
				new_color=get_pix(x,y);
				new_color.paint_over(fill,1-dist_to_border);
				set_pix(x,y,new_color);
			}
		}
	}
	if(stroke){
		for(int x=m.x-rx-stroke-(stroke%2);x<=m.x+rx+stroke+(stroke%2);++x){
			for(int y=m.y-ry-stroke-(stroke%2);y<=m.y+ry+stroke+(stroke%2);++y){
				rad_sum=get_dist(m1,point(x,y))+get_dist(m2,point(x,y));
				if(rad_sum<=linelength+(stroke)+1&&rad_sum>=linelength-(stroke)-1){
					dist_to_border=abs(linelength-rad_sum)-stroke;
					new_color=get_pix(x,y);
					new_color.paint_over(stroke_col,1-dist_to_border);
					set_pix(x,y,new_color);
				}
			}
		}
	}
}


picture picture::sub_pic(point p1,point p2){
/** returns a subpicture between the given points **/
	point ld_point,rt_point;
	ld_point.set(smaller(p1.x,p2.x),smaller(p1.y,p2.y));
	rt_point.set(greater(p1.x,p2.x),greater(p1.y,p2.y));
	picture return_pic(rt_point.x-ld_point.x,rt_point.y-ld_point.y);
	for(int x=0;x<=rt_point.x-ld_point.x;++x){
		for(int y=0;y<=rt_point.y-ld_point.y;++y){
			return_pic.set_pix(x,y,get_pix(ld_point.x+x,ld_point.y+y));
		}
	}
	return return_pic;
}

int picture::draw_bmp(string file){
/** convert the given destination from std::string to const char* **/
	return draw_bmp(file.c_str());
}
int picture::draw_bmp(const char *file){
/** draw the pic as bmp to file **/
	const unsigned char zero=0;
	int size=(m_width+2*(m_width%2))*(m_height+2*(m_height%2))*3+54;//size in bytes
	ofstream output;
	output.open(file);
	///BITMAPFILEHEADER
	output.write("BM",2);
	output.put(splitter(size,1));output.put(splitter(size,2));output.put(splitter(size,3));output.put(splitter(size,4));///size
	output.put(zero);output.put(zero);output.put(zero);output.put(zero);///zeros
	output.put(54);output.put(zero);output.put(zero);output.put(zero);///offset
	///BITMAPFILEHEADER-end
	///BITMAPINFOHEADER
	output.put(40);output.put(zero);output.put(zero);output.put(zero);///infoheader-size
	output.put(splitter(m_width,1));output.put(splitter(m_width,2));output.put(splitter(m_width,3));output.put(splitter(m_width,4));///width
	output.put(splitter(m_height,1));output.put(splitter(m_height,2));output.put(splitter(m_height,3));output.put(splitter(m_height,4));///height
	output.put(1);output.put(zero);
	output.put(24);output.put(zero);///True color
	output.write("\0\0\0\0",4);///not compressed
	output.write("\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",20);
	///BITMAPINFOHEADER-end
	//////////////////////////////////////////////////////////////////////
	for(long y(0);y<m_height;++y){
		for(long x(0);x<m_width;++x){
			output.put(m_data.at(x).at(y).get_b());
			output.put(m_data.at(x).at(y).get_g());
			output.put(m_data.at(x).at(y).get_r());
		}
		for(int i(0);i<((m_width*3)%4);++i){
			output.put(0);
		}
	}
	output.close();
	return 0;
}
///private helper functions:
///returns one byte from a long number
inline unsigned char picture::splitter(int number, int bytes){
	for(int i(1);i<bytes;++i){
		number-=number/256;
		number/=256;
	}
	return number;
}
int picture::get_dif(int a,int b){
	/** returns the difference between to integers **/
	if(a>=b)
		return a-b;
	else return b-a;
}
int picture::greater(int a,int b){
	/** returns the larger of two values **/
	if(a>b)
		return a;
	else return b;
}
int picture::smaller(int a,int b){
	/** returns the smaller of two values **/
	if(a<b)
		return a;
	else return b;
}

double picture::get_dist(point p1,point p2){
/** calculates the distance between to points **/
	return sqrt(get_dif(p1.x,p2.x)*get_dif(p1.x,p2.x)+get_dif(p1.y,p2.y)*get_dif(p1.y,p2.y));
}
#endif