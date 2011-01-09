#ifndef __lib_picture_hpp__
#define __lib_picture_hpp__
#include <vector>
#include <string>

#include "color.hpp"
#include "point.hpp"

using namespace std;

class picture{
	public:
		picture(int width=0,int height=0,color_rgb col=col_white);
		color_rgb set_pix(int x,int y,color_rgb color);
		color_rgb get_pix(int x,int y);
		color_rgb get_pix_s(int x,int y);
		void resize(int width,int height);
		int draw_bmp(string file);
		int draw_bmp(const char *file);
		void line(point p1,point p2,color_rgb color=col_black);
		
		void rect(point p1,point p2,color_rgb fill=col_black,int stroke=0,
			  color_rgb stroke_col=col_black);
		void circle(point m,int r,color_rgb fill=col_black,int stroke=0,
			  color_rgb stroke_col=col_black);
		void ellipse(point m,int rx,int ry,color_rgb fill=col_black,int stroke=0,
			  color_rgb stroke_col=col_black);
		picture sub_pic(point p1,point p2);
	protected:
	//Values:
		int m_height;
		int m_width;
		vector<vector<color_rgb> > m_data;
	//Functions:
		unsigned char splitter(int number, int bytes);
		int get_dif(int a,int b);
		int greater(int a,int b);
		int smaller(int a,int b);
		double get_dist(point p1,point p2);
};




#endif