#include <iostream>
#include "Background.h"
#include "Point.h"
#include "Color.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"

void font(void);//设置字体
color_t setBorderColor(void);//设置颜色
color_t setFillColor(void);//设置填充颜色

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
				"请选择作画内容：\n1.圆\n2.矩形\n3.三角形\n4.清空屏幕\n5.关闭画板\n请输入您的选择：");
		while(1){
				char points[100];
				int coord[100];
				char cr[5];
				char* tokenPtr = nullptr;
				Shape* sp = nullptr;
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
								circle[Circle::getCountCircle()].setCountCircle(Circle::getCountCircle() + 1);
								Shape::setCount(Shape::getCount() + 1);
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
								Rectangle_::setCountRectangle(Rectangle_::getCountRectangle() + 1);
								Shape::setCount(Shape::getCount() + 1);
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

//设置文字样式
void font(void) {
		setcolor(BLACK);
		setfont(18, 0, "楷体");
		setbkmode(TRANSPARENT);
		Background::line();
}