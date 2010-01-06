#include "meng.hpp"
#include "cmath"

R3::R3()
{
	for(int i = 0; i < 3; i++)
		_conts[i] = 0;
}
R3::R3(const real a[3])
{
	for(int i = 0; i < 3; i++)
		_conts[i] = a[i];
}
real R3::len()
{
	real ret;
	int i = 0;
	for(i = 0; i < 3; i++)
		ret += _conts[i] * _conts[i];
	return sqrtl(ret);
}
real R3::sqlen()
{
	int i = 0;
	real ret = 0;
	for (i = 0; i < 3; i++){
		ret += _conts[i] * _conts[i];
	}
	return ret;
}
R3 R3::towards (R3 a)
{
	return (a - (*this)) / (a - (*this)).len();
}
/*R3 R3::operator = (R3 a)
{
	int i = 0;
	for(i = 0; i < 3; i++)
		_conts[i] = a[i];
	return *this;
}*/	
real& R3::operator [] (int i)
{
	if (i < 0 || i >= 3)
		return fallback;
	else
		return _conts[i];
}
R3 R3::operator + (R3 a)
{
	R3 r;
	int i = 0;
	for(i = 0; i < 3; i++)
		r[i] = a[i] + _conts[i];
	return r;
}
R3 R3::operator - (R3 a)
{
	R3 r;
	int i = 0;
	for(i = 0; i < 3; i++)
		r[i] = a[i] - _conts[i];
	return r;
}
real R3::operator * (R3 d)
{
	real r = 0;
	int i = 0;
	for(i = 0; i < 3; i++)
		r += d[i] * _conts[i];
	return r;
}
R3 R3::operator ^ (R3 d)
{
	R3 ret;
	ret[0] = _conts[1] * d[2] - _conts[2] * d[1];
	ret[1] = _conts[2] * d[0] - _conts[0] * d[2];
	ret[2] = _conts[0] * d[1] - _conts[1] * d[0];
	return ret;
}
R3 R3::operator * (real a)
{
	R3 r;
	int i = 0;
	for(i = 0; i < 3; i++)
		r[i] = a * _conts[i];
	return r;
}
R3 R3::operator / (real a)
{
	R3 r;
	int i = 0;
	for(i = 0; i < 3; i++)
		r[i] = _conts[i] / a;
	return r;
}
R3 R3::operator += (R3 a)
{
	int i = 0;
	for(i = 0; i < 3; i++)
		_conts[i] += a[i];
	return *this;
}
R3 R3::operator -= (R3 a)
{
	int i = 0;
	for(i = 0; i < 3; i++)
		_conts[i] -= a[i];
	return *this;
}
R3 R3::operator *= (real a)
{
	int i = 0;
	for(i = 0; i < 3; i++)
		_conts[i] *= a;
	return *this;	
}
R3 R3::operator /= (real a)
{
	int i = 0;
	for(i = 0; i < 3; i++)
		_conts[i] /= a;
	return *this;		
}

R3 operator * (real a, R3 v){
	return v * a;
}
