#include "libpicture.hpp"
#include <string>
using namespace std;

#include<cstdio>
#include<cstdlib>
#include<stdexcept>
#include<iostream>

//this is just for testing purposes 

int main(){
	picture testpic(1680,1050);
	testpic.ellipse(point(841,525),837,250,col_green,5,col_red);
	testpic.draw_bmp("/home/florian/test.bmp");
	return 0;
}