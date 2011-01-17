#include "draw.hpp"
#include "settings.hpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv){
	cout << endl << "wavedrawer3d Alpha" << endl << endl;
	//get the parameters meansing
	settings S(argc,argv);
	//draw the files
	draw(S);

	return 0;
}
