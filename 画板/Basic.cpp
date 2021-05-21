#include "Basic.h"
#include"Shape.h"
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
						circle(c[cir].getPoint().getX(), c[cir].getPoint().getY(), c[cir].getRadius());
						cir++;
				}
				else if (shape[i] == 2) {
						setcolor(r[rec].getBorder());
						rectangle(r[rec].getPoint(0).getX(), r[rec].getPoint(0).getY(),
								r[rec].getPoint(1).getX(), r[rec].getPoint(1).getY());
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
		if (str == "紫罗兰红") {
				return EGERGB(199, 21, 133);
		}
		else if (str == "洋紫") {
				return EGERGB(255, 0, 255);
		}
		else if (str == "板岩蓝") {
				return EGERGB(123, 104, 238);
		}
		else if (str == "海洋绿") {
				return EGERGB(60, 179, 113);
		}
		else if (str == "金色") {
				return EGERGB(255, 215, 0);
		}
		else if (str == "橙色") {
				return EGERGB(255, 165, 0);
		}
		else if (str == "红色") {
				return EGERGB(255, 0, 0);
		}
		else if (str == "黑色") {
				return EGERGB(0, 0, 0);
		}
		else{
				throw (ColorError());
		}
}

//存储图形颜色
std::string Basic::saveColor(color_t c){
		if(c == EGERGB(199, 21, 133)){
				return "紫罗兰红";
		}
		else if(c == EGERGB(255, 0, 255)){
				return "洋紫";
		}
		else if (c == EGERGB(123, 104, 238)) {
				return "板岩蓝";
		}
		else if (c == EGERGB(60, 179, 113)) {
				return "海洋绿";
		}
		else if (c == EGERGB(255, 215, 0)) {
				return "金色";
		}
		else if (c == EGERGB(255, 165, 0)) {
				return "橙色";
		}
		else if (c == EGERGB(255, 0, 0)) {
				return "红色";
		}
		else if (c == EGERGB(0, 0, 0)) {
				return "黑色";
		}
}