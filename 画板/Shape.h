#pragma once
#include "graphics.h"
#include "Color.h"

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
		color_t getFill(void)const;
		void setFill(void);
		static int getCount(void);
		static void setCount(int);
};

