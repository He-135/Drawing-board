#pragma once
//����������
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"

class Basic{
public:
		Basic() = default;
		static void font(void);//��������
		static void reDraw(Circle*, Rectangle_*, Triangle*, int*);//�ػ�����ͼ��
};

