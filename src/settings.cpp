#ifndef __class_settings_cpp__
#define __class_settings_cpp__

#include "settings.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

settings::settings(){
	width=0;
	height=0;
	propagation_speed=0;
	number_of_pics=1;
	
}

settings::settings(int argc, char **argv){
	///init variables:
	string tempstr;
	///set some defaults:
	width=0;
	height=0;
	propagation_speed=0;
	number_of_pics=1;
	file = "";
	///analyse the programs parameters:
	for(int i=1;i<argc;++i){
		tempstr=argv[i];
		if(tempstr.substr(0,2)=="-w"){
			width=atoi(tempstr.substr(2).c_str());
		}
		else if(tempstr.substr(0,2)=="-h"){
			height=atoi(tempstr.substr(2).c_str());
		}
		else if(tempstr.substr(0,2)=="-n"){
			number_of_pics=atoi(tempstr.substr(2).c_str());
		}
		else if(tempstr.substr(0,2)=="-v"){
			propagation_speed=atof(tempstr.substr(2).c_str());
		}
		else if(tempstr.substr(0,2)=="-f"){
			file=tempstr.substr(2);
		}
		else if(tempstr.substr(0,2)=="-S"){
			stimulators.push_back(stimulator(tempstr.substr(2)));
		}
	}

	string input;

	while(width == 0) {
		cout << "Please enter the width of the picture(s) to create: ";
		getline(cin, input);
		width = atoi(input.c_str());
	}

	while(height == 0) {
		cout << "Please enter the height of the picture(s) to create: ";
		getline(cin, input);
		height = atoi(input.c_str());
	}

	while(file == "") {
		cout << "Please enter the filename of the picture(s) to create: ";
		getline(cin, file);
	}

	while(propagation_speed == 0) {
		cout << "Please enter the propagation speed of the waves: ";
		getline(cin, input);
		propagation_speed = atof(input.c_str());
	}

	unsigned int n_stimulators = stimulators.size();
	while(n_stimulators == 0) {
		cout << "Please enter the number of stimulators (at least 1): ";
		getline(cin, input);
		n_stimulators = atoi(input.c_str());
	}

	double x, y, z, freq, amp, phase;
	for(unsigned int i = stimulators.size(); i < n_stimulators; i++) {
		cout << endl << "Please enter the x coordinate of stimulator #" << i << ": ";
		getline(cin, input);
		x = atof(input.c_str());

		cout << "Please enter the y coordinate of stimulator #" << i << ": ";
		getline(cin, input);
		y = atof(input.c_str());

		cout << "Please enter the z coordinate of stimulator #" << i << ": ";
		getline(cin, input);
		z = atof(input.c_str());

		cout << "Please enter the amplitude (max. 1) of stimulator #" << i << ": ";
		getline(cin, input);
		amp = atof(input.c_str());

		cout << "Please enter the frequency of stimulator #" << i << ": ";
		getline(cin, input);
		freq = atof(input.c_str());

		cout << "Please enter the phase shift (in degrees) of stimulator #" << i << ": ";
		getline(cin, input);
		phase = atof(input.c_str());

		stimulators.push_back(stimulator(x, y, z, amp, freq, phase));
	}
	
	total_amplitude=0;
	for(unsigned int i=0;i<stimulators.size();++i){
		total_amplitude+=stimulators.at(i).amplitude;
	}
}

#endif
