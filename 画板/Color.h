#pragma once
#include "graphics.h"
//��ɫ��
class Color {
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


