#ifndef __class_stimulator_hpp__
#define __class_stimulator_hpp__

#include <string>

#include "point3d.hpp"

class stimulator : public point3d{
	public:
		stimulator(double x=0, double y=0, double z=0, double frequency=0, double amplitude=0, double start_phase=0);
		stimulator(std::string str);
		double get_elongation(point3d point, double time, double propagation_speed);

		double frequency;
		double amplitude;
		double start_phase; // Phase of the stimulator at time 0 in degrees
};


#endif
