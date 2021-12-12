#include "Basic.h"
#include"Shape.h"
#include "Circle.h"
#include "Rectangle_.h"
#include "Triangle.h"

// 设置文字样式
void Basic::font(void) {
		setcolor(BLACK);
		setfont(18, 0, "楷体");
		setbkmode(TRANSPARENT);
}

//重画已做内容
void Basic::reDraw(Circle* c, Rectangle_* r, Triangle* t, int* shape) {
		int cir{ 0 }, rec{ 0 }, tri{ 0 };//用于计数
		int xy[6]{};
		for (int i = 0; i < Shape::getCount(); i++) {
				if (shape[i] == 1) {
						setcolor(c[cir].getBorder());
						circle(c[cir].getPoint().getX(),
								c[cir].getPoint().getY(),
								c[cir].getRadius());
						cir++;
				}
				else if (shape[i] == 2) {
						setcolor(r[rec].getBorder());
						rectangle(r[rec].getPoint(0).getX(),
								r[rec].getPoint(0).getY(),
								r[rec].getPoint(1).getX(),
								r[rec].getPoint(1).getY());
						rec++;
				}
				else if (shape[i] == 3) {
						setcolor(t[tri].getBorder());
						setfillcolor(t[tri].getFill());
						for (int k = 0, j = 0; j < 3; j++) {
								xy[k++] = t[tri].getPoint(j).getX();
								xy[k++] = t[tri].getPoint(j).getY();
						}
						fillpoly(3, xy);
						tri++;
				}
		}
}

//读取图形颜色
color_t Basic::readColor(std::string str){
		if (str == "purple_red") {
				return EGERGB(199, 21, 133);
		}
		else if (str == "purple") {
				return EGERGB(255, 0, 255);
		}
		else if (str == "blue") {
				return EGERGB(123, 104, 238);
		}
		else if (str == "green") {
				return EGERGB(60, 179, 113);
		}
		else if (str == "gold") {
				return EGERGB(255, 215, 0);
		}
		else if (str == "orange") {
				return EGERGB(255, 165, 0);
		}
		else if (str == "red") {
				return EGERGB(255, 0, 0);
		}
		else if (str == "black") {
				return EGERGB(0, 0, 0);
		}
		else{
				throw (ColorError());
		}
}

//存储图形颜色
std::string Basic::saveColor(color_t c){
		if(c == EGERGB(199, 21, 133)){
				return "purple_red";
		}
		else if(c == EGERGB(255, 0, 255)){
				return "purple";
		}
		else if (c == EGERGB(123, 104, 238)) {
				return "blue";
		}
		else if (c == EGERGB(60, 179, 113)) {
				return "green";
		}
		else if (c == EGERGB(255, 215, 0)) {
				return "gold";
		}
		else if (c == EGERGB(255, 165, 0)) {
				return "orange";
		}
		else if (c == EGERGB(255, 0, 0)) {
				return "red";
		}
		else if (c == EGERGB(0, 0, 0)) {
				return "black";
		}
}