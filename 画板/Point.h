#pragma once
#define SHOW_CONSOLE
#include <stdexcept>
#include <string>
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
		Point operator+(const Point&);
		bool operator==(const Point)const;
		bool operator!=(const Point)const;
		int& operator[](const int&);
		std::string tostring(void);//≤‚ ‘”√
};
