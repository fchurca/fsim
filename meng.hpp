class R3{
private:
	long double _conts[3];
	long double fallback;
public:
	R3();
	R3(const long double a[3]);
	long double len();
	long double sqlen();
	R3 towards (R3 a);
	R3 operator = (R3 a);
	long double& operator [] (int i);
	R3 operator + (R3 a);
	R3 operator - (R3 a);
	long double operator * (R3 d);
	R3 operator ^ (R3 d);
	R3 operator * (long double a);
	R3 operator / (long double a);
	R3 operator += (R3 a);
	R3 operator -= (R3 a);
	R3 operator *= (long double a);
	R3 operator /= (long double a);
};

R3 operator * (long double a, R3 v);
