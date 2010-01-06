#ifndef __MENG_HPP__
#define __MENG_HPP__
typedef long double real;

typedef real R2[2];

class R3{
private:
	real _conts[3];
	real fallback;
public:
	R3();
	R3(const real a[3]);
	real len();
	real sqlen();
	R3 towards (R3 a);
//	R3 operator = (R3 a);
	real& operator [] (int i);
	R3 operator + (R3 a);
	R3 operator - (R3 a);
	real operator * (R3 d);
	R3 operator ^ (R3 d);
	R3 operator * (real a);
	R3 operator / (real a);
	R3 operator += (R3 a);
	R3 operator -= (R3 a);
	R3 operator *= (real a);
	R3 operator /= (real a);
};

R3 operator * (real a, R3 v);

class R33{
private:
	R3 _conts[3];
	real fallback;
public:
	R33();
	R33(const real a[3][3]);
	real det();
//	R33 operator = (R33 a);
	R3& operator [] (int i);
	R33 operator + (R33 a);
	R33 operator - (R33 a);
	R33 operator * (R33 d);
	R3 operator * (R3 d);
	R33 operator * (real a);
	R33 operator / (real a);
	R33 operator += (R33 a);
	R33 operator -= (R33 a);
	R33 operator *= (real a);
	R33 operator /= (real a);
};

R3 operator * (R3 v, R33 m);
R33 operator * (real a, R33 m);

#endif
