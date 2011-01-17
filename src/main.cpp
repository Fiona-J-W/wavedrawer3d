#include "draw.hpp"
#include "settings.hpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv){
	cout << endl << "wavedrawer3d Alpha" << endl << endl;

	settings S(argc,argv);

	draw(S);

	return 0;
}
