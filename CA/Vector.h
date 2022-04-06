#pragma once

class Vector {

private:

	double* data = 0;
	int n = 0;

public:

	Vector();
	Vector(int n);
	~Vector();

	void resize(int newSize);
	double dot(const Vector& v, const double inj) const;
	double& operator[](int i);
	double operator[](int i) const;

	Vector& operator=(const Vector& v);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector operator*(double d) const;
	Vector& operator*=(double d);

};