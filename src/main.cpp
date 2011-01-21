#include "draw.hpp"
#include "settings.hpp"
#include "help.hpp"

#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
	if(argc==2){
		if(!strcmp(argv[1],"--help")){
		print_help();
		return 0;
		}
		else if(!strcmp(argv[1],"--info")){
			print_about();
			return 0;
		}
	}
	
	
	cout << endl << "wavedrawer3d Alpha" << endl << endl;

	//get the parameters meansing
	settings S(argc,argv);

	//draw the files
	draw(S);

	return 0;
}
