#pragma once
#define SHOW_CONSOLE

#include <stdexcept>
#include <string>
#include "graphics.h"
//颜色类
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
		Color& operator++(void);//前置++
		Color operator++(int dummy);//后置++
		Color& operator--(void);//前置--
		Color operator--(int dummy);//后置++
		std::string tostring(void);//测试用
};


