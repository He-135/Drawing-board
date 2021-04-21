#pragma once
#include "Shape.h"
#include "Point.h"

//æÿ–Œ¿‡
class Rectangle_ :public Shape {
private:
		Point p[2];
		static int countRectangle;
public:
		Rectangle_() = default;
		Rectangle_(int[4]);
		Rectangle_(const Rectangle_&);
		~Rectangle_() = default;
		void draw(void);
		Point getPoint(int)const;
		void setPoint(int, int, int);
		static int getCountRectangle(void);
		static void setCountRectangle(int);
};

