#ifndef __class_point3d_cpp__
#define __class_point3d_cpp__

#include "point3d.hpp"
#include <cstdlib>
#include <cmath>

///Constructors:

point3d::point3d(double x,double y,double z){
/** default constructor **/
	set(x, y, z);
}

point3d::point3d(std::string str){
	set(str);
}

///Setters:
//there are no setters for single values needed, as x, y and z are public;
//same reason for the missing of getters

void point3d::set(double x,double y,double z){
/** Set both coordinates **/
	this->x=x;
	this->y=y;
	this->z=z;
}

void point3d::set(std::string str){
/** creates the Point from an inputstring with the form "x:y:z" **/
	x = 0;
	y = 0;
	z = 0;
	unsigned int divider1 = str.find(":");
	x = atof(str.substr(0, divider1).c_str());
	if(divider1 != std::string::npos) {
		unsigned int divider2 = str.find(":", divider1 + 1);
		y = atof(str.substr(divider1+1,divider2-divider1-1).c_str());
		if(divider2 != std::string::npos) { z=atof(str.substr(divider2+1).c_str()); }
	}
}


///Non-member-functions:

double get_dist_3d(point3d p1,point3d p2){
/** calculates the distance between to points **/
	double d_x,d_y,d_z;
	///d_x=distance in the x-dimension
	d_x=p1.x-p2.x;
	
	///d_y=distance in the y-dimension
	d_y=p1.y-p2.y;

	///d_y=distance in the y-dimension
	d_z=p1.z-p2.z;
	
	///pythagoras:
	return sqrt((d_x*d_x)+(d_y*d_y)+(d_z*d_z));
}

#endif
