#include "Basic.h"
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
				}
		}
}