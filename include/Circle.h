#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double radius, ference, area;
public:
	Circle(double r);
	Circle();
	void setArea(double value);
	void setFerence(double value);
	void setRadius(double value);
	double getArea();
	double getFerence();
	double getRadius();
};

#endif // !CIRCLE_H
