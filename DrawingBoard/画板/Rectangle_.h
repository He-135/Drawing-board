#pragma once
#include <filesystem>
#include <fstream>
#include "Shape.h"
#include "Point.h"
#include <cmath>
class Basic;
//矩形类
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
		int getArea(void)const;
		void saveRectangle(void)const;
		void readRectangle(long int&);
		//比较面积大小
		bool operator<(const Rectangle_&)const;
		bool operator>(const Rectangle_&)const;
		bool operator<=(const Rectangle_&)const;
		bool operator>=(const Rectangle_&)const;
		//比较坐标是否相同
		bool operator==(const Rectangle_&)const;
		bool operator!=(const Rectangle_&)const;
		Rectangle_& operator=(const Rectangle_&);
		Point& operator[](const int&);
};

