#pragma once
#include "graphics.h"
//ÑÕÉ«Àà
class Color {
private:
		int R, G, B;
		color_t color;
public:
		Color() = default;
		Color(int, int, int);
		Color(color_t);
		Color(const Color&);
		~Color() = default;
		color_t getColor(void)const;
		//void setColor(color_t);
};


