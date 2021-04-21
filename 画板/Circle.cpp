#include "Circle.h"
//Բ��
Circle::Circle(int x, int y, int r) {
		Shape::setBool(0);
		p = Point(x, y);
		this->r = r;
}
Circle::Circle(const Circle& c) :Shape(c) {
		this->r = c.r;
		this->p = Point(c.p);
}
void Circle::draw(void) {
		Shape::draw();
		circle(p.getX(), p.getY(), r);
}

int Circle::getRadius(void)const {
		return r;
}
void Circle::setRadius(int r) {
		this->r = r;
}

Point Circle::getPoint(void)const {
		return p;
}
void Circle::setPoint(int x, int y) {
		this->p = Point(x, y);
}

int Circle::getCountCircle(void) {
		return countCircle;
}
void Circle::setCountCircle(int count) {
		countCircle = count;
}