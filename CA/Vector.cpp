#include <iostream>
#include "Vector.h"

Vector::Vector() {

}

Vector::Vector(int n) {

	this->n = n;
	data = new double[n];
	for (int i = 0; i < n; ++i) {
		data[i] = 0.;
	}
}

Vector::~Vector() {

	delete[]data;
}

Vector Vector::operator+(const Vector& v) const {

	Vector c(n);
	for (int i = 0; i < n; ++i) {
		c.data[i] = v.data[i] + this->data[i];
	}
	return c;
}

Vector& Vector::operator+=(const Vector& v) {

	for (int i = 0; i < n; ++i) {
		this->data[i] = this->data[i] + v.data[i];
	}
	return *this;
}

Vector Vector::operator-(const Vector& v) const {

	Vector c(n);
	for (int i = 0; i < n; ++i) {
		c.data[i] = v.data[i] - this->data[i];
	}
	return c;
}

Vector& Vector::operator-=(const Vector& v) {

	for (int i = 0; i < n; ++i) {
		this->data[i] = this->data[i] - v.data[i];
	}
	return *this;
}

Vector Vector::operator*(double d) const {

	Vector c(n);
	for (int i = 0; i < n; ++i) {
		c.data[i] = d * this->data[i];
	}
	return c;
}

Vector& Vector::operator*=(double d) {

	Vector c(n);
	for (int i = 0; i < n; ++i) {
		this->data[i] = d * this->data[i];
	}
	return *this;
}

Vector& Vector::operator=(const Vector& v) {

	if (this->n != v.n) {
		this->resize(v.n);
	}
	for (int i = 0; i < n; ++i) {
		this->data[i] = v.data[i];
	}
	return *this;
}

double& Vector::operator[](int i) {

	return data[i];
}

double Vector::operator[](int i) const {

	return data[i];
}

void Vector::resize(int newSize) {

	delete[] data;
	data = new double[newSize];
	this->n = newSize;

	for (int i = 0; i < n; ++i) {
		data[i] = 0.;
	}
}

double Vector::dot(const Vector& v, const double inj) const {

	double mod, ans;
	for (int i = 0; i < n; ++i) {
		mod += (this->data[i] + v.data[i]);
	}
	ans = mod * inj;

	return ans;
}