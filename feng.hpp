#include "meng.hpp"

class particle{
public:
	real mass;
	R3
		position,
		velocity;
	particle();
};

class camera{
public:
	R3 position;
	R3 orientation;
	R3 scale;
	R3 resolution;
	R3 watch(R3 dot){
		R3 ret;
		dot -= position;
		ret = dot;
//		ret[0] = dot[0] * (-4) + dot[1] * 4;
//		ret[1] = dot[0] * 3 + dot[1] * 3 + dot[2] * (-5);
		ret += resolution / 2;
		ret *= 1;
	}
};

particle::particle(){
	mass = 0;
}
