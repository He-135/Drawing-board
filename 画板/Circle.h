#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include "Shape.h"
#include "Point.h"
class Basic;
//圆形类
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
		void saveCircle(void)const;
		void readCircle(long int&);
		//比较半径
		bool operator<(const Circle&)const;
		bool operator>(const Circle&)const;
		bool operator<=(const Circle&)const;
		bool operator>=(const Circle&)const;
		bool operator==(const Circle&)const;
		bool operator!=(const Circle&)const;
		Circle& operator=(const Circle&);
		Point& operator[](const int&);
};

