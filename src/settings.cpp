#ifndef __class_settings_cpp__
#define __class_settings_cpp__

#include "settings.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <getopt.h>

using namespace std;

settings::settings(){
	width=0;
	height=0;
	propagation_speed=0;
	number_of_pics=1;
	
}

settings::settings(int argc, char **argv){
	//init variables:
	string tempstr;
	//set some defaults:
	width=0;
	height=0;
	propagation_speed=0;
	number_of_pics=1;
	runtime=0;
	file = "";
	
	static const struct option long_options[] ={
		{"width", required_argument, 0, 'w'},
		{"height", required_argument, 0, 'h'},
		{"number-of-pics", required_argument, 0, 'n'},
		{"propagation-speed", required_argument, 0, 'v'},
		{"runtime", required_argument, 0, 't'},
		{"file", required_argument, 0, 'f'},
		{"stimulator", required_argument, 0, 'S'},
	};
	
	while(optind < argc){
		int index=0;//dummy
		int result = getopt_long(argc, argv,"w:h:n:v:t:f:S:",long_options, &index);
		if (result == -1) break;
		switch(result){
			case 'w': width=atoi(optarg); break;
			case 'h': height=atoi(optarg); break;
			case 'n': number_of_pics=atoi(optarg); break;
			case 'v': propagation_speed=atof(optarg); break;
			case 't': runtime=atof(optarg); break;
			case 'f': file=optarg; break;
			case 'S': stimulators.push_back(stimulator(optarg));  break;
			default: throw logic_error("invalid argument");
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

	while(file.empty()) {
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
