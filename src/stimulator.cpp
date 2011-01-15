#ifndef __class_stimulator_cpp__
#define __class_stimulator_cpp__

#include "stimulator.hpp"
#include "divide_string.hpp"

#include <cstdlib>
#include <cmath>
#include <vector>

///Constructors:

stimulator::stimulator(double x, double y, double z, double frequency, double amplitude, double start_phase) {
/** default constructor **/
	set(x, y, z);
	this->frequency=frequency;
	this->amplitude=amplitude;
	this->start_phase=start_phase;
}

stimulator::stimulator(std::string str) {
	vector<double> values = divide_string(str, 6);
	x = values[0];
	y = values[1];
	z = values[2];
	frequency = values[3];
	amplitude = values[4];
	start_phase = values[5];
}

///Member functions:	
double stimulator::get_elongation(point3d point, double time, double propagation_speed) {
	double wavelength = propagation_speed / frequency;
	return sin(time*frequency*2*M_PI - 2*M_PI*get_dist_3d(*this, point)/wavelength + start_phase*M_PI/180);
}

///Setters:
//there are no setters for single values needed, as all of them are public;
//same reason for the missing of getters

#endif
