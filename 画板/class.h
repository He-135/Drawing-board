#pragma once
#include "graphics.h"
#include <iostream>
#include <array>

//图形环境控制器类
class Background{
private:
		int width, height;
public:
		Background();
		Background(int, int);
		static void line(void);
};

//点类
class Point{
private:
		int x, y;
public:
		Point();
		Point(int, int);
		int getX(void)const;
		int getY(void)const;
		/*void setX(int);
		void setY(int);*/
};

//颜色类
class Color{
private:
		int R, G, B;
		color_t color;
public:
		Color();
		Color(int, int, int);
		color_t getColor(void)const;
		//void setColor(int, int, int);
};

//基类shape
//class Shape{
//private:
//		bool isFill;
//		color_t borderColor;
//		color_t fillColor;
//public:
//		Shape()
//};

//圆形类
class Circle:public Shape{
private:
		int r;
		color_t color;
		Point p;
		bool fill = false;
public:
		Circle();
		Circle(int, int, int, color_t);
		int getRadius(void)const;
		color_t getColor(void)const;
		Point getPoint(void)const;
		void setRadius(int);
		void setColor(int, int, int);
		void setPoint(int, int);
};

//矩形类
class Rectangle_ :public Shape {
private:
		Point p[2];
		color_t color;
		bool fill = false;
public:
		Rectangle_();
		Rectangle_(int[4], color_t);
		Point getPoint(int)const;
		color_t getColor(void)const;
		void setPoint(int, int, int);
		void setColor(int, int, int);
};

//三角形类
class Triangle :public Shape {
private:
		Point p[3];
		color_t colorBorder;
		color_t colorFill;
		bool fill = true;
public:
		Triangle();
		Triangle(int[6], color_t, color_t);
		Point getPoint(int)const;
		color_t getColorBorder(void)const;
		color_t getColorFill(void)const;
		void setPoint(int, int, int);
		void setColor(int, int, int);
};