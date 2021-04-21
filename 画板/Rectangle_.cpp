#include "Rectangle_.h"
//æÿ–Œ¿‡
Rectangle_::Rectangle_(int xy[4]) {
		Shape::setBool(0);
		for (int i = 0, j = 0; i < 4 && j < 2; i++, j++) {
				p[j] = Point(xy[i++], xy[i]);
		}
}
Rectangle_::Rectangle_(const Rectangle_& r) :Shape(r) {
		for (int i = 0; i < 2; i++) {
				this->p[i] = r.p[i];
		}
}
void Rectangle_::draw(void) {
		Shape::draw();
		rectangle(p[0].getX(), p[0].getY(), p[1].getX(), p[1].getY());
}

Point Rectangle_::getPoint(int index)const {
		return p[index];
}
void Rectangle_::setPoint(int x, int y, int index) {
		p[index] = Point(x, y);
}

int Rectangle_::getCountRectangle(void) {
		return countRectangle;
}
void Rectangle_::setCountRectangle(int count) {
		countRectangle = count;
}