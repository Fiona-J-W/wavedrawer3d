#ifndef __lib_picture_cpp__
#define __lib_picture_cpp__

#include "libpicture.hpp"

#include<fstream>
#include<cstdio>
#include<cmath>
#include<stdexcept>

#include <iostream>
using namespace std;


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
	for(int y(0);y<m_height;++y){
		//cout<<y<<": ";
		for(int x(0);x<m_width;++x){
			output.put(m_data.at(x).at(y).get_b());
			output.put(m_data.at(x).at(y).get_g());
			output.put(m_data.at(x).at(y).get_r());
			//cout<<x<<", ";
		}
		//cout<<endl;
		//cout<<m_width<<"("<<m_width*3<<"; "<<(4-((m_width*3)%4))%4<<"):\t";
		for(int i(0);i<(4-((m_width*3)%4))%4;++i){
			output.put(0);
			//cout<<i<<", ";
		}
		//cout<<endl;
	}
	output.close();
	return 0;
}
///private helper functions:
///returns one byte from a long number
inline unsigned char picture::splitter(int number, int bytes){
	unsigned char *ptr;
	unsigned int num=number;
	ptr=(unsigned char*)&num;
	return ptr[bytes-1];
}



#endif
