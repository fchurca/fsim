#ifndef __MENG_HPP__
#define __MENG_HPP__
typedef long double real;

#define I (identityR33())

class R3;
class R33;

R33 identityR33();

////////////////////////////////////////
// Vector class

class R3{
private:
	real _conts[3];
	real fallback;
public:
	R3();
	real & operator [] (int i);
	real len();
	real sqlen();
	R33 skewsym();
};

////////////////////////////////////////
// Matrix class

class R33{
private:
	R3 _conts[3];
	R3 fallback;
public:
	real det();
	R3 & operator [] (int i);
};


////////////////////////////////////////
// Vector operations

R33 rotate(R3 v);
R3 operator >> (R3 a, R3 b);	// towards
R3 operator + (R3 a, R3 b);	// add
R3 operator - (R3 a, R3 b);	// substract
real operator * (R3 a, R3 b);	// dot product
R3 operator ^ (R3 a, R3 b);	// cross product
R33 operator / (R3 a, R3 b);	// outer product
R3 operator * (R3 v, real a);	// multipy by scalar
R3 operator * (real a, R3 v);
R3 operator / (R3 v, real a);	// divide by scalar
R3 operator += (R3 & a, R3 b);
R3 operator -= (R3 & a, R3 b);
R3 operator *= (R3 & v, real a);
R3 operator /= (R3 & v, real a);

////////////////////////////////////////
// Matrix operations

R33 operator + (R33 a, R33 b);	// add
R33 operator - (R33 a, R33 b);	// substract
R33 operator * (R33 a, R33 b);	// product
R3 operator * (R33 m, R3 v);	// matrix product by vector
R3 operator * (R3 v, R33 m);	// vector product by matrix
R33 operator * (R33 m, real a);	// matrix product by scalar
R33 operator * (real a, R33 m);	// scalar product by matrix
R33 operator / (R33 m, real a);	// divide by scalar
R33 operator += (R33 & a, R33 b);
R33 operator -= (R33 & a, R33 b);
R33 operator *= (R33 & m, real a);
R33 operator /= (R33 & m, real a);

#endif
