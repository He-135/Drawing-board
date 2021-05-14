#include <iostream>
#include <filesystem>
#include <fstream>
#include "Background.h"
#include "Point.h"
#include "Color.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"

void font(void);//设置字体
color_t setBorderColor(void);//设置颜色
color_t setFillColor(void);//设置填充颜色

//初始化全局变量
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
		int shape[100];//用于记录图形种类
		a:font();//清空屏幕后从此处开始执行程序
		for(int i = 0; i < 100; i++){ //初始化/清空数组内数据
				shape[i] = -1;
		}
		outtextrect(0, 0, 640, 480,
				"请选择作画内容：\n1.圆\n2.矩形\n3.三角形\n4.清空屏幕\n5.保存并关闭画板\n请输入您的选择：");
		while(1){
				char points[100];
				int coord[100];
				char cr[5];
				char* tokenPtr = nullptr;
				Shape* sp = nullptr;//基类指针
				int r;
				int choose = getch();
				switch (choose) {
						//圆
						case '1':
								//输入圆心坐标
								inputbox_getline("请输入【圆心坐标】",
										"（以空格分隔）",
										points,
										sizeof(points) / sizeof(*points));
								tokenPtr = strtok(points, " ");
								for (int i = 0; tokenPtr != NULL; i++) {
										coord[i] = atoi(tokenPtr);
										tokenPtr = strtok(NULL, " ");
								}
								//输入圆半径
								inputbox_getline("请输入【半径】",
										"半径（r）：（按回车结束）",
										cr,
										sizeof(cr) / sizeof(*cr));
								r = atoi(cr);
								circle[Circle::getCountCircle()] = Circle{ coord[0], coord[1], r };
								sp = &circle[Circle::getCountCircle()];
								sp->draw();
								circle[Circle::getCountCircle()].setCountCircle(Circle::getCountCircle() + 1);//countCircle+1
								shape[Shape::getCount()] = 1;//记录图形种类
								Shape::setCount(Shape::getCount() + 1);//Count+1
								break;

						//矩形
						case '2':
								//输入左上和右下顶点坐标
								inputbox_getline("请输入【左上和右下顶点坐标】",
										"（以空格分隔）",
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
								shape[Shape::getCount()] = 2;//记录图形种类
								Shape::setCount(Shape::getCount() + 1);//Count+1
								break;

						//三角形
						case '3':
								//输入左上和右下顶点坐标
								inputbox_getline("请输入【三个顶点坐标】",
										"（以空格分隔）",
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
								shape[Shape::getCount()] = 3;//记录图形种类
								Shape::setCount(Shape::getCount() + 1);//Count+1
								break;
						//清空屏幕
						case '4':
								cleardevice();
								Shape::setCount(0);
								Circle::setCountCircle(0);
								Rectangle_::setCountRectangle(0);
								Triangle::setCountTriangle(0);
								goto a;
								break;
						//保存并退出程序
						case '5':
								goto b;
								break;
				}
		}
		b://存储数据
		fs::path o{"figure files.txt"};
		ofstream ofs{o};
		int cir{0}, rec{0}, tri{0};//用于计数
		for(int i = 0; shape[i] != -1; i++){
				ofs << shape[i] << endl;
				if(shape[i] == 1){  //存储圆的数据
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
		xyprintf(0, 190, "保存成功");
		Sleep(1000);
		closegraph();
		delete[]circle;
		delete[]rectangle_;
		delete[]triangle;

		return 0;
}

//设置文字样式
void font(void) {
		setcolor(BLACK);
		setfont(18, 0, "楷体");
		setbkmode(TRANSPARENT);
		Background::line();
}