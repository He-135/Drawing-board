#pragma once
#include "graphics.h"
#include "Color.h"
//µ„¿‡
class Point {
private:
		int x, y;
public:
		Point() = default;
		Point(int, int);
		Point(const Point&);
		~Point() = default;
		int getX(void)const;
		int getY(void)const;
};
