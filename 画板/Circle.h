#pragma once
#include "Shape.h"
#include "Point.h"
//Բ����
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
};

