#include "task1.h"
#include "Circle.h"

double calcDelta() {
	Circle earth(6378100);
	double radiusInitial = earth.getRadius();
	earth.setFerence(earth.getFerence() + 1);
	return earth.getRadius() - radiusInitial;
}

double calcCost() {
	Circle pool(3), poolAndPaving(4);
	return 1000 * (poolAndPaving.getArea() - pool.getArea()) + 2000 * poolAndPaving.getFerence();
}