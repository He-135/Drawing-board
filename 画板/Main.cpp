#include "class.h"
#include <iostream>

void font(void);//��������
color_t setBorderColor(void);//������ɫ
color_t setFillColor(void);//���������ɫ

int Shape::count;
int Circle::countCircle;
int Rectangle_::countRectangle;
int Triangle::countTriangle;

int main(void){
		Background();
		Circle c1{ 1, 1, 2 };
		Circle c2{ c1 };
		Circle circle[10];
		Rectangle_ rectangle_[10];
		Triangle triangle[10];
		a:font();
		outtextrect(0, 0, 640, 480,
				"��ѡ���������ݣ�\n1.Բ\n2.����\n3.������\n4.�����Ļ\n����������ѡ��");
		while(1){
				char points[100];
				int coord[100];
				char cr[5];
				char* tokenPtr = nullptr;
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
								Triangle::setCountTriangle(Triangle::getCountTriangle() + 1);
								break;

						case '4':
								cleardevice();
								Shape::setCount(0);
								Circle::setCount(0);
								Rectangle_::setCount(0);
								Triangle::setCount(0);
								goto a;
								break;
				}
		}
		getch();
		return 0;
}

//����������ʽ
void font(void) {
		setcolor(BLACK);
		setfont(18, 0, "����");
		setbkmode(TRANSPARENT);
		Background::line();
}