#pragma once
#define SHOW_CONSOLE

#include "graphics.h"
#include "Color.h"
class Basic;
//»ùÀàshape
class Shape {
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
		void setBorder(color_t);
		color_t getFill(void)const;
		void setFill(void);
		void setFill(color_t);
		static int getCount(void);
		static void setCount(int);
};

