#include <iostream>
#include "Background.h"
#include "Point.h"
#include "Color.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"

void font(void);//��������
color_t setBorderColor(void);//������ɫ
color_t setFillColor(void);//���������ɫ

int Shape::count;
int Circle::countCircle;
int Rectangle_::countRectangle;
int Triangle::countTriangle;

int main(void){
		Background();
		Circle* circle = new Circle[10];
		Rectangle_* rectangle_ = new Rectangle_[10];
		Triangle* triangle = new Triangle[10];
		a:font();
		outtextrect(0, 0, 640, 480,
				"��ѡ���������ݣ�\n1.Բ\n2.����\n3.������\n4.�����Ļ\n5.�رջ���\n����������ѡ��");
		while(1){
				char points[100];
				int coord[100];
				char cr[5];
				char* tokenPtr = nullptr;
				Shape* sp = nullptr;
				int r;
				int choose = getch();
				switch (choose) {
						//Բ
						case '1':
								//����Բ������
								inputbox_getline("�����롾Բ�����꡿",
										"���Կո�ָ���",
										points,
										sizeof(points) / sizeof(*points));
								tokenPtr = strtok(points, " ");
								for (int i = 0; tokenPtr != NULL; i++) {
										coord[i] = atoi(tokenPtr);
										tokenPtr = strtok(NULL, " ");
								}
								//����Բ�뾶
								inputbox_getline("�����롾�뾶��",
										"�뾶��r���������س�������",
										cr,
										sizeof(cr) / sizeof(*cr));
								r = atoi(cr);
								circle[Circle::getCountCircle()] = Circle{ coord[0], coord[1], r };
								sp = &circle[Circle::getCountCircle()];
								sp->draw();
								circle[Circle::getCountCircle()].setCountCircle(Circle::getCountCircle() + 1);
								Shape::setCount(Shape::getCount() + 1);
								break;

						//����
						case '2':
								//�������Ϻ����¶�������
								inputbox_getline("�����롾���Ϻ����¶������꡿",
										"���Կո�ָ���",
										points,
										sizeof(points) / sizeof(*points));
								tokenPtr = strtok(points, " ");
								for (int i = 0; tokenPtr != NULL; i++) {
										coord[i] = atoi(tokenPtr);
										tokenPtr = strtok(NULL, " ");
								}
								rectangle_[Rectangle_::getCountRectangle()] = Rectangle_ { coord };
								sp = &rectangle_[Rectangle_::getCountRectangle()];
								sp->draw();
								Rectangle_::setCountRectangle(Rectangle_::getCountRectangle() + 1);
								Shape::setCount(Shape::getCount() + 1);
								break;

						//������
						case '3':
								//�������Ϻ����¶�������
								inputbox_getline("�����롾�����������꡿",
										"���Կո�ָ���",
										points,
										sizeof(points) / sizeof(*points));
								tokenPtr = strtok(points, " ");
								for (int i = 0; tokenPtr != NULL; i++) {
										coord[i] = atoi(tokenPtr);
										tokenPtr = strtok(NULL, " ");
								}
								triangle[Triangle::getCountTriangle()] = Triangle { coord };
								sp = &triangle[Triangle::getCountTriangle()];
								sp->draw();
								Triangle::setCountTriangle(Triangle::getCountTriangle() + 1);
								Shape::setCount(Shape::getCount() + 1);
								break;

						case '4':
								cleardevice();
								Shape::setCount(0);
								Circle::setCountCircle(0);
								Rectangle_::setCountRectangle(0);
								Triangle::setCountTriangle(0);
								goto a;
								break;
						case '5':
								goto b;
								break;
				}
		}
    b:closegraph();
		delete[]circle;
		delete[]rectangle_;
		delete[]triangle;

		return 0;
}

//����������ʽ
void font(void) {
		setcolor(BLACK);
		setfont(18, 0, "����");
		setbkmode(TRANSPARENT);
		Background::line();
}