#define _USE_MATH_DEFINES

#include "Circle.h"
#include <cmath>

Circle::Circle(double r) {
	if (r <= 0) {
		r = 1;
	}
	area = M_PI * pow(r, 2.);
	ference = 2. * M_PI * r;
	radius = r;
}

Circle::Circle() {
	area = M_PI;
	ference = 2. * M_PI;
	radius = 1;
}

void Circle::setArea(double value) {
	if (value > 0) {
		area = value;
		ference = 2 * sqrt(M_PI) * sqrt(value);
		radius = sqrt(value / M_PI);
	}
}

void Circle::setFerence(double value) {
	if (value > 0) {
		area = pow(value, 2) / (4 * M_PI);
		ference = value;
		radius = value / (2. * M_PI);
	}
}

void Circle::setRadius(double value) {
	if (value > 0) {
		area = M_PI * pow(value, 2.);
		ference = 2. * M_PI * value;
		radius = value;
	}
}

double Circle::getArea() {
	return area;
}

double Circle::getFerence() {
	return ference;
}

double Circle::getRadius() {
	return radius;
}