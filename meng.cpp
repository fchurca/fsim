#include "meng.hpp"
#include "cmath"

////////////////////////////////////////
// Vector class

R3::R3(){
	for(int i = 0; i < 3; i++)
		_conts[i] = 0;
}
real R3::len(){
	return sqrtl(this->sqlen());
}
real R3::sqlen(){
	real ret = 0;
	for (int i = 0; i < 3; i++){
		ret += _conts[i] * _conts[i];
	}
	return ret;
}
real & R3::operator [] (int i){
	if (i < 0 || i >= 3)
		return fallback;
	else
		return _conts[i];
}
R33 R3::skewsym(){
	R33 ret;
	ret[0][1] = _conts[2];
	ret[0][2] = -_conts[1];
	ret[1][0] = -_conts[2];
	ret[1][2] = _conts[0];
	ret[2][0] = _conts[1];
	ret[2][1] = -_conts[0];
	return ret;
}

////////////////////////////////////////
// Matrix class

real R33::det(){
	return		_conts[0][0]*(_conts[1][1]*_conts[2][2]-_conts[1][2]*_conts[2][1])
		+	_conts[0][1]*(_conts[2][1]*_conts[0][2]-_conts[2][2]*_conts[0][1])
		+	_conts[0][2]*(_conts[0][1]*_conts[1][2]-_conts[0][2]*_conts[1][1])
	;
}
R3 & R33::operator [] (int i){
	if (i < 0 || i >= 3)
		return fallback;
	else
		return _conts[i];
}


////////////////////////////////////////
// Vector operations

R33 rotate(R3 v){
	real a = v.len();	// in radians
	v /= a;
	R33 u = v/v;
	return u + cos(a)*(I - u) + sin(a)*v.skewsym();
}
R3 operator >> (R3 a, R3 b){
	a -= b;
	return a / a.len();
}
R3 operator + (R3 a, R3 b){
	for(int i = 0; i < 3; i++)
		a[i] += b[i];
	return a;
}
R3 operator - (R3 a, R3 b){
	for(int i = 0; i < 3; i++)
		a[i] -= b[i];
	return a;
}
real operator * (R3 a, R3 b){
	real r = 0;
	for(int i = 0; i < 3; i++)
		r += a[i] * b[i];
	return r;
}
R3 operator ^ (R3 a, R3 b){
	R3 ret;
	ret[0] = a[1] * b[2] - a[2] * b[1];
	ret[1] = a[2] * b[0] - a[0] * b[2];
	ret[2] = a[0] * b[1] - a[1] * b[0];
	return ret;
}
R33 operator / (R3 a, R3 b){
	R33 ret;
	for (int i = 0; i < 3; i++)
		for (int j = 0; i < 3; j++)
			ret[i][j] = a[i] * b[j];
	return ret;
}
R3 operator * (R3 v, real a){
	for (int i = 0; i < 3; i++)
		v[i] *= a;
	return v;
}
R3 operator * (real a, R3 v){
	return v * a;
}
R3 operator / (R3 v, real a){
	R3 r;
	for (int i = 0; i < 3; i++)
		r[i] =v[i] / a;
	return r;
}
R3 operator += (R3 & a, R3 b){
	return a = a + b;;
}
R3 operator -= (R3 & a, R3 b){
	return a = a - b;;
}
R3 operator *= (R3 & v, real a){
	return v = v * a;
}
R3 operator /= (R3 & v, real a){
	return v = v / a;
}

////////////////////////////////////////
// Matrix operations
R33 identityR33(){
	R33 ret;
	for (int i = 0; i < 3; i++)
		ret[i][i] = 1;
	return ret;
}
R33 operator + (R33 a, R33 b){
	for (int i = 0; i < 3; i++)
		a[i] += b[i];
	return a;
}
R33 operator - (R33 a, R33 b){
	for (int i = 0; i < 3; i++)
		a[i] -= b[i];
	return a;
}

R33 operator * (R33 a, R33 b){
	R33 ret;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				ret[i][j] += a[i][k] * b[k][j];
	return ret;
}
R3 operator * (R33 m, R3 v){
	R3 ret;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ret[i] += m[i][j] * v[j];
	return ret;
}
R3 operator * (R3 v, R33 m){
	R3 ret;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ret[i] += v[i] * m[i][j];
	return ret;
}
R33 operator * (R33 m, real a){
	for (int i = 0; i < 3; i++)
		m[i] *= a;
	return m;
}
R33 operator * (real a, R33 m){
	return m * a;
}
R33 operator / (R33 m, real a){
	for (int i = 0; i < 3; i++)
		m[i] /= a;
	return m;
}
R33 operator += (R33 & a, R33 b){
	return a = a + b;
}
R33 operator -= (R33 & a, R33 b){
	return a = a - b;
}
R33 operator *= (R33 & m, real a){
	return m = m * a;
}
R33 operator /= (R33 & m, real a){
	return m = m / a;
}

