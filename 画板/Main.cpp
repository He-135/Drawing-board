#include <iostream>
#include <filesystem>
#include <fstream>
#include <exception>
#include "Background.h"
#include "Point.h"
#include "Color.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"
#include "Basic.h"

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

class MyColorError:public std::exception{
public:
		MyColorError() = default;
		const char* what()const noexcept(true) override{
				return "color error";
		}
};

int main(void){
		Background();
		Circle* circle_ = new Circle[10];
		Rectangle_* rectangle_ = new Rectangle_[10];
		Triangle* triangle = new Triangle[10];
		int shape[100];//用于记录图形种类
		Basic::font();
		for(int i = 0; i < 100; i++){ //初始化数组内数据
				shape[i] = -1;
		}
	  //从文件中读取数据
		fs::path i{"figure files.txt"};
		ifstream ifs{i};
		if(ifs.fail()){
				xyprintf(0, 190, "文件打开失败");
				Sleep(1000);
				cleardevice();
		}
		else{
				int count{ 0 }, cir{ 0 }, rec{ 0 }, tri{ 0 };//用于计数
				ifs >> count;
				for (int i = 0; i < count; i++) {
						ifs >> shape[i];
						if (shape[i] == 1) { //Circle
								int x, y, r;
								ifs >> x >> y >> r;
								circle_[cir] = Circle(x, y, r);
								color_t t;
								bool b;
								ifs >> t >> b;
								circle_[cir].setBool(b);
								try
								{
										if (t < 0) {
												throw(MyColorError());
										}
										circle_[cir].setBorder(t);
								}
								catch (const MyColorError& mc)
								{
										circle_[cir].setBorder(BLACK);
								}
								cir++;
						}
						else if (shape[i] == 2) {  //Rectangle
								int xy[4];
								for (int k = 0; k < 4; k++) {
										ifs >> xy[k];
								}
								rectangle_[rec] = Rectangle_(xy);
								color_t t;
								bool b;
								ifs >> t >> b;
								try
								{
										if (t < 0) {
												throw(MyColorError());
										}
										rectangle_[rec].setBorder(t);
								}
								catch (const MyColorError& mc)
								{
										rectangle_[rec].setBorder(BLACK);
								}

								rectangle_[rec].setBool(b);
								rec++;
						}
						else if (shape[i] == 3) {  //Triangle
								int xy[6];
								for (int j = 0; j < 6; j++) {
										ifs >> xy[j];
								}
								triangle[tri] = Triangle(xy);
								color_t t1, t2;
								bool b;
								ifs >> t1 >> b >> t2;
								try
								{
										if (t1 < 0) {
												throw(MyColorError());
										}
										triangle[tri].setBorder(t1);
								}
								catch (const MyColorError& mc)
								{
										triangle[tri].setBorder(BLACK);
								}

								triangle[tri].setBool(b);

								try
								{
										if (t2 < 0) {
												throw(MyColorError());
										}
										triangle[tri].setFill(t2);
								}
								catch (const MyColorError& mc)
								{
										triangle[tri].setFill(BLACK);
								}
								tri++;
						}
				}
				Shape::setCount(count);
				Circle::setCountCircle(cir);
				Rectangle_::setCountRectangle(rec);
				Triangle::setCountTriangle(tri);
				//绘制图形
				cir = 0;
				rec = 0;
				tri = 0;
				//用于计数
				for (int i = 0; i < count; i++) {
						if (shape[i] == 1) { //circle
								setcolor(circle_[cir].getBorder());
								circle(circle_[cir].getPoint().getX(),
										circle_[cir].getPoint().getY(),
										circle_[cir].getRadius());
								cir++;
						}
						else if (shape[i] == 2) { //rectangle
								setcolor(rectangle_[rec].getBorder());
								rectangle(rectangle_[rec].getPoint(0).getX(),
										rectangle_[rec].getPoint(0).getY(),
										rectangle_[rec].getPoint(1).getX(),
										rectangle_[rec].getPoint(1).getY());
								rec++;
						}
						else if(shape[i] == 3){ //triangle
								setcolor(triangle[tri].getBorder());
								setfillcolor(triangle[tri].getFill());
								int xy[6];
								for (int i = 0, j = 0; j < 3; j++) {
										xy[i++] = triangle[tri].getPoint(j).getX();
										xy[i++] = triangle[tri].getPoint(j).getY();
								}
								fillpoly(3, xy);
								tri++;
						}
				}
		}
		while(1){
				cleardevice();
				Basic::reDraw(circle_, rectangle_, triangle, shape);
				Basic::font();
				xyprintf(0,0,"请选择作画内容：");
				xyprintf(0, 20, "1.圆");
				xyprintf(0, 40, "2.矩形");
				xyprintf(0, 60, "3.三角形");
				xyprintf(0, 80, "4.清空屏幕");
				xyprintf(0, 100, "5.保存并关闭画板");
				xyprintf(0, 120, "请输入您的选择：");

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
								circle_[Circle::getCountCircle()] = Circle{ coord[0], coord[1], r };
								sp = &circle_[Circle::getCountCircle()];
								cleardevice();
								Basic::reDraw(circle_, rectangle_, triangle, shape);
								sp->draw();
								circle_[Circle::getCountCircle()].setCountCircle(Circle::getCountCircle() + 1);//countCircle+1
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
								cleardevice();
								Basic::reDraw(circle_, rectangle_, triangle, shape);
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
								cleardevice();
								Basic::reDraw(circle_, rectangle_, triangle, shape);
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
								for (int i = 0; i < 100; i++) { //清空数组内数据
										shape[i] = -1;
								}
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
		ofs << Shape::getCount() << endl;
		for(int i = 0; shape[i] != -1; i++){
				ofs << shape[i] << endl;
				if(shape[i] == 1){  //存储圆的数据
						ofs << circle_[cir].getPoint().getX() << " ";
						ofs << circle_[cir].getPoint().getY() << " ";
						ofs << circle_[cir].getRadius() << endl;
						ofs << circle_[cir].getBorder() << " "
								<< circle_[cir].getBool() << endl;
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
		delete[]circle_;
		delete[]rectangle_;
		delete[]triangle;

		return 0;
}

