#ifndef __class_point_cpp__
#define __class_point_cpp__

#include "point.hpp"

#include <cstdlib>
#include <cmath>

///Constructors:

point::point(unsigned int x, unsigned int y){
/** default constructor **/
	this->x=x;
	this->y=y;
}

point::point(std::string str){
/** creates the Point from an inputstring with the form "x|y" **/
	unsigned int divider;
	divider=str.find(":");
	x=atoi(str.substr(0,divider).c_str());
	y=atoi(str.substr(divider+1).c_str());
}

///Setters:
//there are no setters for single values needed, as x and y are public;
//same reason for the missing of getters

void point::set(unsigned int x, unsigned int y){
/** Set both coordinates **/
	this->x=x;
	this->y=y;
}

///Non-member-functions:

double get_dist(point p1,point p2){
/** calculates the distance between to points **/
	unsigned int d_x,d_y;
	///d_x=distance in the x-dimension
	if(p1.x>p2.x){
		d_x=p1.x-p2.x;
	}
	else{
		d_x=p2.x-p1.x;
	}
	
	///d_y=distance in the y-dimension
	if(p1.y>p2.y){
		d_y=p1.y-p2.y;
	}
	else{
		d_y=p2.y-p1.y;
	}
	
	///pythagoras:
	return sqrt((d_x*d_x)+(d_y*d_y));
}

#endif
