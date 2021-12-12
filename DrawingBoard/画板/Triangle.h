#pragma once
#include <filesystem>
#include <fstream>
#include "Shape.h"
#include "Point.h"
class Basic;
//三角形类
class Triangle :public Shape {
private:
		Point p[3];
		static int countTriangle;
public:
		Triangle() = default;
		Triangle(int[6]);
		Triangle(const Triangle&);
		~Triangle() = default;
		void draw(void);
		Point getPoint(int)const;
		void setPoint(int, int, int);
		static int getCountTriangle(void);
		static void setCountTriangle(int);
		int getArea(void)const;
		void saveTriangle(void)const;
		void readTriangle(long int&);
		//比较面积大小
		bool operator<(const Triangle&)const;
		bool operator>(const Triangle&)const;
		bool operator<=(const Triangle&)const;
		bool operator>=(const Triangle&)const;
		bool operator==(const Triangle&)const;
		bool operator!=(const Triangle&)const;
		Triangle& operator=(const Triangle&);
		Point& operator[](const int&);
};

