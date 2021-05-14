#include <iostream>
#include <filesystem>
#include <fstream>
#include "Background.h"
#include "Point.h"
#include "Color.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"

void font(void);//��������
color_t setBorderColor(void);//������ɫ
color_t setFillColor(void);//���������ɫ

//��ʼ��ȫ�ֱ���
int Shape::count;
int Circle::countCircle;
int Rectangle_::countRectangle;
int Triangle::countTriangle;

namespace fs = std::filesystem;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::endl;

int main(void){
		Background();
		Circle* circle = new Circle[10];
		Rectangle_* rectangle_ = new Rectangle_[10];
		Triangle* triangle = new Triangle[10];
		int shape[100];//���ڼ�¼ͼ������
		a:font();//�����Ļ��Ӵ˴���ʼִ�г���
		for(int i = 0; i < 100; i++){ //��ʼ��/�������������
				shape[i] = -1;
		}
		outtextrect(0, 0, 640, 480,
				"��ѡ���������ݣ�\n1.Բ\n2.����\n3.������\n4.�����Ļ\n5.���沢�رջ���\n����������ѡ��");
		while(1){
				char points[100];
				int coord[100];
				char cr[5];
				char* tokenPtr = nullptr;
				Shape* sp = nullptr;//����ָ��
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
								circle[Circle::getCountCircle()].setCountCircle(Circle::getCountCircle() + 1);//countCircle+1
								shape[Shape::getCount()] = 1;//��¼ͼ������
								Shape::setCount(Shape::getCount() + 1);//Count+1
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
								Rectangle_::setCountRectangle(Rectangle_::getCountRectangle() + 1);//countRectangle+1
								shape[Shape::getCount()] = 2;//��¼ͼ������
								Shape::setCount(Shape::getCount() + 1);//Count+1
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
								Triangle::setCountTriangle(Triangle::getCountTriangle() + 1);//countTriangle+1
								shape[Shape::getCount()] = 3;//��¼ͼ������
								Shape::setCount(Shape::getCount() + 1);//Count+1
								break;
						//�����Ļ
						case '4':
								cleardevice();
								Shape::setCount(0);
								Circle::setCountCircle(0);
								Rectangle_::setCountRectangle(0);
								Triangle::setCountTriangle(0);
								goto a;
								break;
						//���沢�˳�����
						case '5':
								goto b;
								break;
				}
		}
		b://�洢����
		fs::path o{"figure files.txt"};
		ofstream ofs{o};
		int cir{0}, rec{0}, tri{0};//���ڼ���
		for(int i = 0; shape[i] != -1; i++){
				ofs << shape[i] << endl;
				if(shape[i] == 1){  //�洢Բ������
						ofs << circle[cir].getPoint().getX() << " ";
						ofs << circle[cir].getPoint().getY() << " ";
						ofs << circle[cir].getRadius() << endl;
						ofs << circle[cir].getBorder() << " "
								<< circle[cir].getBool() << endl;
						cir++;
				}
				else if(shape[i] == 2){
						ofs << rectangle_[rec].getPoint(0).getX() << " ";
						ofs << rectangle_[rec].getPoint(0).getY() << " ";
						ofs << rectangle_[rec].getPoint(1).getX() << " ";
						ofs << rectangle_[rec].getPoint(1).getY() << endl;
						ofs << rectangle_[rec].getBorder() << " "
								<< rectangle_[rec].getBool() << endl;
						rec++;
				}
				else if(shape[i] == 3){
						ofs << triangle[tri].getPoint(0).getX() << " ";
						ofs << triangle[tri].getPoint(0).getY() << " ";
						ofs << triangle[tri].getPoint(1).getX() << " ";
						ofs << triangle[tri].getPoint(1).getY() << " ";
						ofs << triangle[tri].getPoint(2).getX() << " ";
						ofs << triangle[tri].getPoint(2).getY() << endl;
						ofs << triangle[tri].getBorder() << " "
								<< triangle[tri].getBool() << " "
								<< triangle[tri].getFill() << endl;
						tri++;
				}
		}
		setcolor(BLACK);
		xyprintf(0, 190, "����ɹ�");
		Sleep(1000);
		closegraph();
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