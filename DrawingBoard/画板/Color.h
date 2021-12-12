#pragma once
#define SHOW_CONSOLE

#include <stdexcept>
#include <string>
#include "graphics.h"
//��ɫ��
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
		bool operator==(const Color&);
		bool operator!=(const Color&);
		int& operator[](const int&);
		Color& operator++(void);//ǰ��++
		Color operator++(int dummy);//����++
		Color& operator--(void);//ǰ��--
		Color operator--(int dummy);//����++
		std::string tostring(void);//������
};


