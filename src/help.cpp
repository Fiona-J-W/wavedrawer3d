#include <iostream>

using namespace std;

void print_help(){
	cout
	<<"Usage: wavedrawer3d [Parameters]\n"
	<<"All parameters are optional; those parameters are available:\n"
	<<"\t-h expects an integer and sets the height of the pictures\n"
	<<"\t-w expects an integer and sets the width of the pictures\n"
	<<"\t-n expects an integer and sets the number of singlepictures to be created\n"
	<<"\t-v expects a number and sets the propagation speed\n"
	<<"\t-f expects a string and sets the path to the outputfile\n"
	<<"\t-S expects a string and adds a stimulator; the string must look like this: \n"
	<<"\t\tx:y:z:amplitude:frequency:startphase\n"
	<<"\t\tall values may be floating point numbers; if you give less then six\n"
	<<"\t\tvalues, the not given ones are set to zero, except for amplitude and\n"
	<<"\t\tfrequency: Those are set to one"
	<<endl;
}


void print_about(){
	cout <<"wavedrawer3d Alpha" << endl << endl;
	
	
	
}