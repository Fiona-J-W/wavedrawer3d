#ifndef __class_point3d_hpp__
#define __class_point3d_hpp__
#include <string>

class point3d{
	public:
		point3d(double x=0,double y=0,double z=0);
		point3d(std::string str);
		void set(double x,double y,double z);
		void set(std::string str);
		double x;
		double y;
		double z;
};


double get_dist_3d(point3d p1,point3d p2); /** calculates the distance between to points **/


#endif
