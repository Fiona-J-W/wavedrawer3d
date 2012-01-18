#ifndef __class_stimulator_hpp__
#define __class_stimulator_hpp__

#include <string>
#include <vector>
#include <utility>

using namespace std;

#include "point3d.hpp"

///stimulators are creating the waves and giving them their properties
class stimulator : public point3d{
	public:
		stimulator(double x = 0, double y = 0, double z = 0, double amplitude = 1, double frequency = 1, double start_phase = 0);
		stimulator(string str);
		double get_elongation(point3d point, double time, double propagation_speed);

		double frequency;
		double amplitude;
		double start_phase; // Phase of the stimulator at time 0 in degrees
		vector<pair<double,double> > active_times; //if this doesn't contain values, it won't habe efects
};


#endif
