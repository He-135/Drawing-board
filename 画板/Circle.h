#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include "Shape.h"
#include "Point.h"
class Basic;
//‘≤–Œ¿‡
class Circle :public Shape {
private:
		int r;
		Point p;
		static int countCircle;
public:
		Circle() = default;
		Circle(int, int, int);
		Circle(const Circle&);
		~Circle() = default;
		void draw(void);
		int getRadius(void)const;
		void setRadius(int);
		Point getPoint(void)const;
		void setPoint(int, int);
		static int getCountCircle(void);
		static void setCountCircle(int);
		void saveCircle(void);
		void readCircle(long int&);
};

