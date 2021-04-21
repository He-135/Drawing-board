#include "Point.h"
//µãÀà
Point::Point(int x, int y) {
		this->x = x;
		this->y = y;
}
Point::Point(const Point& p) {
		this->x = p.x;
		this->y = p.y;
}
int Point::getX(void)const {
		return x;
}
int Point::getY(void)const {
		return y;
}
