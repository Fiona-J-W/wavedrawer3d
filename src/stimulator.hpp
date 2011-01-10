#ifndef __class_stimulator_hpp__
#define __class_stimulator_hpp__
#include <string>
#include "point3d.hpp"
#include "settings.hpp"

class stimulator : public point3d{
	public:
		stimulator(double x=0,double y=0,double z=0,double frequency=1,double amplitude=1,double start_phase=0);
		double get_elongation(point3d point, double time, settings S);

		double frequency;
		double amplitude;
		double start_phase; // Phase of the stimulator at time 0 in degrees
};


#endif
