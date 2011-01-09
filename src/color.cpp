#ifndef __color_cpp__
#define __color_cpp__
#include "color.hpp"


color_rgb::color_rgb(){
	m_r=m_g=m_b=0;
}
color_rgb::color_rgb(unsigned char r,unsigned char g,unsigned char b){
	m_r=r;
	m_g=g;
	m_b=b;
}
color_rgb::color_rgb(unsigned char r,unsigned char g,unsigned char b,unsigned char alpha){
	m_r=r;
	m_g=g;
	m_b=b;
	m_alpha=alpha;
}
color_rgb::color_rgb(unsigned char grey){
	m_r=m_g=m_b=grey;
}

void color_rgb::set(unsigned char r,unsigned char g,unsigned char b){
	m_r=r;
	m_g=g;
	m_b=b;
}
void color_rgb::set(unsigned char grey){
	m_r=m_g=m_b=grey;
}

color_rgb color_rgb::operator *(double factor){
	unsigned int r,g,b;
	r=m_r*factor+0.5;//printf("%.2f|%d ",m_r*factor+0.5,r);
	g=m_g*factor+0.5;//printf("%.2f|%d ",m_g*factor+0.5,g);
	b=m_b*factor+0.5;//printf("%.2f|%d ",m_b*factor+0.5,b);
	if(r>255)r=255;
	if(g>255)g=255;
	if(b>255)b=255;
	return color_rgb(r,g,b);
}
color_rgb operator *(double factor,color_rgb color){
	unsigned int r,g,b;
	r=color.get_r()*factor+0.5;
	g=color.get_r()*factor+0.5;
	b=color.get_b()*factor+0.5;
	if(r>255)r=255;
	if(g>255)g=255;
	if(b>255)b=255;
	return color_rgb(r,g,b);
}
color_rgb color_rgb::operator *=(double factor){
	unsigned int r,g,b;
	r=m_r*factor+0.5;//printf("%.2f|%d ",m_r*factor+0.5,r);
	g=m_g*factor+0.5;//printf("%.2f|%d ",m_g*factor+0.5,g);
	b=m_b*factor+0.5;//printf("%.2f|%d ",m_b*factor+0.5,b);
	if(r>255)r=255;
	if(g>255)g=255;
	if(b>255)b=255;
	m_r=r;
	m_g=g;
	m_b=b;
	return *this;
}

color_rgb color_rgb::operator +(color_rgb col_2){
	return color_rgb(
		m_r+col_2.m_r,
		m_g+col_2.m_g,
		m_b+col_2.m_b
	);
}

color_rgb color_rgb::operator +=(color_rgb col_2){
	m_r+=col_2.m_r;
	m_g+=col_2.m_g;
	m_b+=col_2.m_b;
	return *this;
}

color_rgb color_rgb::paint_over(color_rgb col2,double rel){
	if(rel>=1){
		*this=col2;
		return *this;
	}
	else if(rel<=0){
		return *this;
	}
	double r,g,b;
	r=col2.m_r*rel+m_r*(1.0-rel)+0.5;m_r=r;
	g=col2.m_g*rel+m_g*(1.0-rel)+0.5;m_g=g;
	b=col2.m_b*rel+m_b*(1.0-rel)+0.5;m_b=b;
	return *this;
}

void color_rgb::set_r(unsigned char r){m_r=r;}
void color_rgb::set_g(unsigned char g){m_g=g;}
void color_rgb::set_b(unsigned char b){m_b=b;}

unsigned char color_rgb::get_r(){return m_r;}
unsigned char color_rgb::get_g(){return m_g;}
unsigned char color_rgb::get_b(){return m_b;}
#endif