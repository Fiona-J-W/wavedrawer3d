#ifndef __color_hpp__
#define __color_hpp__

class color_rgb{
	public:
		color_rgb();
		color_rgb(unsigned char grey);
		color_rgb(unsigned char r,unsigned char g,unsigned char b);
		color_rgb(unsigned char r,unsigned char g,unsigned char b,unsigned char alpha);
		///operations:
		color_rgb operator *(double factor);
		color_rgb operator *=(double factor);
		color_rgb operator +(color_rgb col_2);
		color_rgb operator +=(color_rgb col_2);
		color_rgb paint_over(color_rgb col2,double rel);
		///set:
		void set(unsigned char r,unsigned char g,unsigned char b);
		void set(unsigned char grey);
		void set_r(unsigned char r);
		void set_g(unsigned char g);
		void set_b(unsigned char b);
		///get:
		unsigned char get_r();
		unsigned char get_g();
		unsigned char get_b();
		
	private:
		unsigned char m_r;
		unsigned char m_g;
		unsigned char m_b;
		unsigned char m_alpha;
};

const color_rgb col_white=color_rgb(255,255,255);
const color_rgb col_black=color_rgb(0,0,0);
const color_rgb col_red=color_rgb(255,0,0);
const color_rgb col_green=color_rgb(0,255,0);
const color_rgb col_blue=color_rgb(0,0,255);
const color_rgb col_yellow=color_rgb(255,255,0);
const color_rgb col_turquoise=color_rgb(0,255,255);
const color_rgb col_pink=color_rgb(255,0,255);
#endif
