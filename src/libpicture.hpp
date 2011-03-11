#ifndef __lib_picture_hpp__
#define __lib_picture_hpp__

#include "color.hpp"
#include "point.hpp"

#include <vector>
#include <string>

using namespace std;

class picture{
	public:
		picture(int width=0,int height=0,color_rgb col=col_white);
		color_rgb set_pix(int x,int y,color_rgb color);
		color_rgb get_pix(int x,int y);
		color_rgb get_pix_s(int x,int y);
		int draw_bmp(string file);
		int draw_bmp(const char *file);
	protected:
	//Values:
		int m_height;
		int m_width;
		vector<vector<color_rgb> > m_data;
	//Functions:
		unsigned char splitter(int number, int bytes);
};




#endif
