#pragma once
//����������
#include <iostream>
#include <string>
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"
#include "ColorError.h"
class Shape;
class Basic{
public:
		Basic() = default;
		static void font(void);//��������
		static void reDraw(Circle*, Rectangle_*, Triangle*, int*);//�ػ�����ͼ��
		static color_t readColor(std::string);//��ȡͼ����ɫ
		static std::string saveColor(color_t);//�洢ͼ����ɫ
};

