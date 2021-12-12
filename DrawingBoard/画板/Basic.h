#pragma once
//基础功能类
#include <iostream>
#include <string>
#include "Rectangle_.h"
#include "Triangle.h"
#include "ColorError.h"
class Shape;
class Circle;
class Rectangle_;
class Triangle;
class Basic{
public:
		Basic() = default;
		static void font(void);//设置字体
		static void reDraw(Circle*, Rectangle_*, Triangle*, int*);//重画已有图形
		static color_t readColor(std::string);//读取图形颜色
		static std::string saveColor(color_t);//存储图形颜色
};

