#ifndef __class_point_hpp__
#define __class_point_hpp__

#include <string>

class point{
	public:
		point(unsigned int x=0,unsigned int y=0);
		point(std::string str);
		void set(unsigned int x,unsigned int y);
		int x;
		int y;
};


double get_dist(point p1,point p2); /** calculates the distance between to points **/


#endif
