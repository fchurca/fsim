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
	R3 operator = (R3 a);
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
