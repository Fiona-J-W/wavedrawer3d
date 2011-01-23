#include <iostream>

using namespace std;

void print_help(){
	cout
	<<"Usage: wavedrawer3d [Parameters]\n\n"
	<<"All parameters are optional; those parameters are available:\n"
	<<"\t-h expects an integer and sets the height of the pictures\n"
	<<"\t-w expects an integer and sets the width of the pictures\n"
	<<"\t-v expects a number and sets the propagation speed\n"
	<<"\t-f expects a string and sets the path to the outputfile\n"
	<<"\t-S expects a string and adds a stimulator; the string must look like \n"
	<<"\t\tthis:     x:y:z:amplitude:frequency:startphase\n"
	<<"\t\tAll values may be floating point numbers. If you give less then\n"
	<<"\t\tsix values, the not given ones are set to zero, except for\n"
	<<"\t\tamplitude and frequency: those are set to one. The startphase\n"
	<<"\t\tmust be given in degrees\n"
	<<"\t-n expects an integer and sets the number of single pictures to be\n"
	<<"\t\tcreated, the default is one\n\n"
	<<"If important parameters are missing, the program will ask for them.\n"
	<<flush;
}


void print_about(){
	cout 
	<<"wavedrawer3d Alpha\n\n"
	<<"A fast and small simulator for waves in 3D space\n\n"
	<<"This program is free software. It is released under the GPL V3\n"
	<<"(c) Philip Schwartz and Florian Weber\n\n"
	<<"WARNING: This is an Alpha-Version\n"
	<< flush;
}
