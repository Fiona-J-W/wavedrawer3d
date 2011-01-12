#ifndef __class_stimulator_cpp__
#define __class_stimulator_cpp__

#include "stimulator.hpp"
#include "point3d.hpp"
#include "settings.hpp"
#include <cstdlib>
#include <cmath>

///Constructors:

stimulator::stimulator(double x, double y, double z, double frequency, double amplitude, double start_phase){
/** default constructor **/
	point3d::point3d(x, y, z);
	this->frequency=frequency;
	this->amplitude=amplitude;
	this->start_phase=start_phase;
}

///Member functions:
double stimulator::get_elongation(point3d point, double time, settings S){
	double wavelength = S.propagation_speed / frequency;
	return sin(time*frequency*2*M_PI - 2*M_PI*get_dist_3d(*this, point)/wavelength + start_phase*M_PI/180);
}

///Setters:
//there are no setters for single values needed, as all of them are public;
//same reason for the missing of getters

#endif
