#include "feng.hpp"

R3 camera::watch(R3 dot){
	R3 ret;
	dot -= position;
	ret = dot;
	ret[0] = dot[0] * (-4) + dot[1] * 4;
	ret[1] = dot[0] * 3 + dot[1] * 3 + dot[2] * (-5);
	ret *= 10;
	ret += resolution / 2;
	return ret;
}
	
particle::particle(){
	mass = 0;
}
