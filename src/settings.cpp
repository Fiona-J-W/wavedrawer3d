#ifndef __class_settings_cpp__
#define __class_settings_cpp__

#include "settings.hpp"
#include "stimulator.hpp"

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

	unsigned int n_stimulators = stimulators.size();
	while(n_stimulators == 0) {
		cout << "Please enter the number of stimulators (at least 1): ";
		cin >> n_stimulators;
	}

	double x, y, z, freq, amp, phase;
	for(unsigned int i = stimulators.size(); i < n_stimulators; i++) {
		cout << endl << "Please enter the x coordinate of stimulator #" << i << ": ";
		cin >> x;
		cout << "Please enter the y coordinate of stimulator #" << i << ": ";
		cin >> y;
		cout << "Please enter the z coordinate of stimulator #" << i << ": ";
		cin >> z;
		cout << "Please enter the frequency of stimulator #" << i << ": ";
		cin >> freq;
		cout << "Please enter the amplitude (max. 1) of stimulator #" << i << ": ";
		cin >> amp;
		cout << "Please enter the phase shift (in degrees) of stimulator #" << i << ": ";
		cin >> phase;
		stimulators.push_back(stimulator(x, y, z, freq, amp, phase));
	}
}

#endif
