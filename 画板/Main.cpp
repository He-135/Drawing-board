#include <iostream>
#include <filesystem>
#include <fstream>
#include <exception>
#include <string>
#include "Background.h"
#include "Point.h"
#include "Color.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"
#include "Basic.h"
#include "ColorError.h"

//��ʼ��ȫ�ֱ���
int Shape::count;
int Circle::countCircle;
int Rectangle_::countRectangle;
int Triangle::countTriangle;

namespace fs = std::filesystem;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::endl;
int main(void){
		/*{//����operator
				//Point
				cout << "Test Point operator" << endl;
				Point a(1, 4);
				Point b(2, 3);
				Point c = a + b;
				Point d(1,4);
				cout << "c = " << c.tostring() << endl;
				if(a != b){
						cout << "a != b" << endl;
				}
				if (a == d) {
						cout << "a == d" << endl;
				}
				cout << "a[0] = " << a[0] << endl;
				a[0] = 2;
				cout << "a[0] = " << a[0] << endl;
				//cout << "a[3] = " << a[3] << endl; //�ᱨ��out_of_range
		}

		{
				//Color
				cout << "Test Color operator" << endl;
				Color a(255, 100, 0);
				Color b(15, 15, 15);
				Color c(255, 100, 0);
				if(a != b){
						cout << "a != b" << endl;
				}
				if (a == c) {
						cout << "a == c" << endl;
				}
				cout << "b[0] = " << b[0] << endl;
				b[0] = 2;
				cout << "b[0] = " << b[0] << endl;
				//cout << "a[3] = " << a[3] << endl; //�ᱨ��out_of_range
				cout << "����ǰ��/���� ++/--" << endl;
				Color d = a++;
				cout << "a: " << a.tostring() << endl;
				cout << "d: " << d.tostring() << endl;
				Color e = ++a;
				cout << "a: " << a.tostring() << endl;
				cout << "e: " << e.tostring() << endl;
				Color f = a--;
				cout << "a: " << a.tostring() << endl;
				cout << "f: " << f.tostring() << endl;
				Color g = --a;
				cout << "a: " << a.tostring() << endl;
				cout << "g: " << g.tostring() << endl;
		}
		{
				//Circle
				cout << "Test Circle operator" << endl;
				Circle c1(100, 100, 50);
				c1.setBorder(BLACK);
				Circle c2(100, 100, 60);
				c2.setBorder(BLACK);
				Circle c3(100, 100, 50);
				c3.setBorder(BLACK);
				if(c1 < c2){
						cout << "c1 < c2" << endl;
				}
				if (c1 <= c2) {
						cout << "c1 <= c2" << endl;
				}
				if (c2 > c1) {
						cout << "c2 > c1" << endl;
				}
				if (c2 >= c1) {
						cout << "c2 >= c1" << endl;
				}
				if (c1 == c3) {
						cout << "c1 == c3" << endl;
				}
				if (c1 != c2) {
						cout << "c1 != c2" << endl;
				}
				c1 = c2;
				cout << "c1.r = " << c1.getRadius() << endl;
				cout << "c1[0] = " << c1[0].tostring() << endl;
				c1[0] = Point(200, 200);
				cout << "c1[0] = " << c1[0].tostring() << endl;
				//cout << "c1[1] = " << c1[1].tostring() << endl;//�ᱨ��out_of_range
		}
		{
				//Rectangle
				cout << "Test Rectangle operator" << endl;
				int xy1[4]{ 100, 100, 200, 200 };
				Rectangle_ r1 (xy1);
				r1.setBorder(BLACK);
				int xy2[4]{300, 300, 500, 500};
				Rectangle_ r2 (xy2);
				r2.setBorder(BLACK);
				int xy3[4]{ 100, 100, 200, 200 };
				Rectangle_ r3 (xy3);
				r3.setBorder(BLACK);
				if (r1 < r2) {
						cout << "r1 < r2" << endl;
				}
				if (r1 <= r2) {
						cout << "r1 <= r2" << endl;
				}
				if (r2 > r1) {
						cout << "r2 > r1" << endl;
				}
				if (r2 >= r1) {
						cout << "r2 >= r1" << endl;
				}
				if (r1 == r3) {
						cout << "r1 == r3" << endl;
				}
				if (r1 != r2) {
						cout << "r1 != r2" << endl;
				}
				cout << "r1[0] = " << r1[0].tostring() << endl;
				r1 = r2;
				cout << "r1[0] = " << r1[0].tostring() << endl;
				r1[0] = Point(222, 333);
				cout << "r1[0] = " << r1[0].tostring() << endl;
				//cout << "r1[2] = " << r1[2].tostring() << endl;//�ᱨ��out_of_range
		}
		{
				//Triangle
				cout << "Test Trangle operator" << endl;
				int xy1[6]{ 150, 150, 200, 200, 300, 400 };
				Triangle t1(xy1);
				t1.setBorder(BLACK);
				t1.setFill(BLACK);
				int xy2[6]{ 100, 100, 100, 500, 800, 100 };
				Triangle t2(xy2);
				t2.setBorder(BLACK);
				t2.setFill(BLACK);
				int xy3[6]{ 100, 100, 200, 200, 300, 300 };
				Triangle t3(xy3);
				t3.setBorder(BLACK);
				t3.setFill(BLACK);
				if (t1 < t2) {
						cout << "t1 < t2" << endl;
				}
				if (t1 <= t2) {
						cout << "t1 <= t2" << endl;
				}
				if (t2 > t1) {
						cout << "t2 > t1" << endl;
				}
				if (t2 >= t1) {
						cout << "t2 >= t1" << endl;
				}
				if (t1 == t3) {
						cout << "t1 == t3" << endl;
				}
				if (t1 != t2) {
						cout << "t1 != t2" << endl;
				}
				cout << "t1[0] = " << t1[0].tostring() << endl;
				t1 = t2;
				cout << "t1[0] = " << t1[0].tostring() << endl;
				t1[0] = Point(222, 333);
				cout << "t1[0] = " << t1[0].tostring() << endl;
				//cout << "t1[3] = " << t1[3].tostring() << endl;//�ᱨ��out_of_range

		}*/
		Background();
		Circle* circle_ = new Circle[10];
		Rectangle_* rectangle_ = new Rectangle_[10];
		Triangle* triangle = new Triangle[10];
		int shape[100];//���ڼ�¼ͼ������
		Basic::font();
		for(int i = 0; i < 100; i++){ //��ʼ������������
				shape[i] = -1;
		}
	  //���ļ��ж�ȡ����
		fs::path i{"figure files.txt"};
		fstream ifs{i, std::ios::in};
		if(ifs.fail()){
				xyprintf(0, 190, "�ļ���ʧ��");
				ifs.close();
				Sleep(1000);
				cleardevice();
		}
		else{
				int count{ 0 }, cir{ 0 }, rec{ 0 }, tri{ 0 };//���ڼ���
				long int loc{0};
				ifs.seekg(loc, std::ios::beg);
				ifs >> count;
				loc = ifs.tellg();
				ifs.close();
				for (int i = 0; i < count; i++) {
						fstream ifs{ "figure files.txt", std::ios::in};
						ifs.seekg(loc, std::ios::beg);
						ifs >> shape[i];
						loc = ifs.tellg();
						ifs.close();
						if (shape[i] == 1) { //Circle
								circle_[cir].readCircle(loc);
								cir++;
						}
						else if (shape[i] == 2) {  //Rectangle
								rectangle_[rec].readRectangle(loc);
								rec++;
						}
						else if (shape[i] == 3) {  //Triangle
								triangle[tri].readTriangle(loc);
								tri++;
						}
				}
				Shape::setCount(count);
				Circle::setCountCircle(cir);
				Rectangle_::setCountRectangle(rec);
				Triangle::setCountTriangle(tri);
		}
		while(1){
				cleardevice();
				Basic::reDraw(circle_, rectangle_, triangle, shape);
				Basic::font();
				xyprintf(0,0,"��ѡ���������ݣ�");
				xyprintf(0, 20, "1.Բ");
				xyprintf(0, 40, "2.����");
				xyprintf(0, 60, "3.������");
				xyprintf(0, 80, "4.�����Ļ");
				xyprintf(0, 100, "5.���沢�رջ���");
				xyprintf(0, 120, "����������ѡ��");

				char points[100];
				int coord[100];
				char cr[5];
				char* tokenPtr = nullptr;
				Shape* sp = nullptr;//����ָ��
				int r;
				int choose = getch();

				Circle _c;//��ʱ����
				Rectangle_ _r;
				Triangle _t;

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
								_c.setBool(0);
								_c.setPoint(coord[0], coord[1]);
								_c.setRadius(r);
								sp = &_c;
								cleardevice();
								Basic::reDraw(circle_, rectangle_, triangle, shape);
								sp->draw();
								circle_[Circle::getCountCircle()] = _c;
								circle_[Circle::getCountCircle()].setCountCircle(Circle::getCountCircle() + 1);//countCircle+1
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
								_r.setBool(0);
								_r.setPoint(coord[0], coord[1], 0);
								_r.setPoint(coord[2], coord[3], 1);
								sp = &_r;
								cleardevice();
								Basic::reDraw(circle_, rectangle_, triangle, shape);
								sp->draw();
								rectangle_[Rectangle_::getCountRectangle()] = _r;
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
								_t.setBool(1);
								_t.setPoint(coord[0], coord[1], 0);
								_t.setPoint(coord[2], coord[3], 1);
								_t.setPoint(coord[4], coord[5], 2);

								sp = &_t;
								cleardevice();
								Basic::reDraw(circle_, rectangle_, triangle, shape);
								sp->draw();
								triangle[Triangle::getCountTriangle()] = _t;
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
								for (int i = 0; i < 100; i++) { //�������������
										shape[i] = -1;
								}
								break;
						//���沢�˳�����
						case '5':
								goto b;
								break;
				}
		}
		b://�洢����
		int cir{ 0 }, rec{ 0 }, tri{ 0 };//���ڼ���
		fs::path o{"figure files.txt"};
		fstream ofs{o, std::ios::out};
		ofs << Shape::getCount() << endl;
		ofs.close();
		for(int i = 0; shape[i] != -1; i++){
				fstream ofs{ o, std::ios::app };
				ofs << shape[i] << endl;
				ofs.close();
				if(shape[i] == 1){  //�洢Բ������
						circle_[cir].saveCircle();
						cir++;
				}
				else if(shape[i] == 2){
						rectangle_[rec].saveRectangle();
						rec++;
				}
				else if(shape[i] == 3){
						triangle[tri].saveTriangle();
						tri++;
				}
		}
		setcolor(BLACK);
		xyprintf(0, 190, "����ɹ�");
		Sleep(1000);
		closegraph();
		delete[]circle_;
		delete[]rectangle_;
		delete[]triangle;

		return 0;
}

