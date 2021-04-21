#include "Triangle.h"
//Èý½ÇÐÎÀà
Triangle::Triangle(int xy[6]) {
		Shape::setBool(1);
		for (int i = 0, j = 0; i < 6; j++) {
				p[j] = Point(xy[i++], xy[i++]);
		}
		draw();
		setcolor(BLACK);
}
Triangle::Triangle(const Triangle& t) :Shape(t) {
		for (int i = 0; i < 3; i++) {
				this->p[i] = t.p[i];
		}
}
void Triangle::draw(void) {
		Shape::draw();
		int xy[6];
		for (int i = 0, j = 0; i < 6; j++) {
				xy[i++] = p[j].getX();
				xy[i++] = p[j].getY();
		}
		fillpoly(3, xy);
}

Point Triangle::getPoint(int index)const {
		return p[index];
}
void Triangle::setPoint(int x, int y, int index) {
		p[index] = Point(x, y);
}

int Triangle::getCountTriangle(void) {
		return countTriangle;
}
void Triangle::setCountTriangle(int count) {
		countTriangle = count;
}