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
		Point() = default;
		Point(int, int);
		Point(const Point&);
		~Point() = default;
		int getX(void)const;
		int getY(void)const;
};

//颜色类
class Color{
private:
		int R, G, B;
		color_t color;
public:
		Color() = default;
		Color(int, int, int);
		Color(const Color&);
		~Color() = default;
		color_t getColor(void)const;
};

//基类shape
class Shape{
private:
		bool isFill;
		Color* borderColor = nullptr;
		Color* fillColor = nullptr;
		static int count;
public:
		Shape() = default;
		Shape(const Shape&);
		~Shape();
		virtual void draw(void) = 0;
		bool getBool(void)const;
		void setBool(int);
		color_t getBorder(void)const;
		void setBorder(void);
		color_t getFill(void)const;
		void setFill(void);
		static int getCount(void);
		static void setCount(int);
};

//圆形类
class Circle:public Shape{
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
};

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
};