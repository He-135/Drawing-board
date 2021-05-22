#pragma once
#include <filesystem>
#include <fstream>
#include "Shape.h"
#include "Point.h"
class Basic;
//Èý½ÇÐÎÀà
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
		void saveTriangle(void);
};

