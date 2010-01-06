#ifndef __FENG_HPP__
#define __FENG_HPP__
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
	R3 watch(R3 dot);
};

#endif
