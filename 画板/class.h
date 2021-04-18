#pragma once
#include "graphics.h"
#include <iostream>
#include <array>

//ͼ�λ�����������
class Background{
private:
		int width, height;
public:
		Background();
		Background(int, int);
		static void line(void);
};

//����
class Point{
private:
		int x, y;
public:
		Point();
		Point(int, int);
		Point(const Point&);
		int getX(void)const;
		int getY(void)const;
		~Point() = default;
};

//��ɫ��
class Color{
private:
		int R, G, B;
		color_t color;
public:
		Color();
		Color(int, int, int);
		Color(const Color&);
		~Color() = default;
		color_t getColor(void)const;
};

//����shape
class Shape{
private:
		bool isFill;
		Color* borderColor = nullptr;
		Color borderColor_;
		Color* fillColor = nullptr;
		static int count;
public:
		Shape() = default;
		Shape(const Shape&);
		~Shape();
		virtual void draw(void);
		bool getBool(void)const;
		color_t getBorder(void)const;
		color_t getFill(void)const;
		static int getCount(void);
		void setBool(int);
		void setBorder(void);
		void setFill(void);
		static void setCount(int);
};

//Բ����
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
		int getRadius(void)const;
		Point getPoint(void)const;
		static int getCountCircle(void);
		static void setCountCircle(int);
		void setRadius(int);
		void setPoint(int, int);
		virtual void draw(void);
};

//������
class Rectangle_ :public Shape {
private:
		Point p[2];
		bool fill = false;
		static int countRectangle;
public:
		Rectangle_() = default;
		Rectangle_(int[4]);
		Rectangle_(const Rectangle_&);
		~Rectangle_();
		Point getPoint(int)const;
		void setPoint(int, int, int);
		void draw(void);
		static int getCountRectangle(void);
		static void setCountRectangle(int);
};

//��������
class Triangle :public Shape {
private:
		Point p[3];
		static int countTriangle;
public:
		Triangle() = default;
		Triangle(int[6]);
		Triangle(const Triangle&);
		~Triangle();
		Point getPoint(int)const;
		void setPoint(int, int, int);
		void draw(void);
		static int getCountTriangle(void);
		static void setCountTriangle(int);
};