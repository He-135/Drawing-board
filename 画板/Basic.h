#pragma once
//基础功能类
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"

class Basic{
public:
		Basic() = default;
		static void font(void);//设置字体
		static void reDraw(Circle*, Rectangle_*, Triangle*, int*);//重画已有图形
};

