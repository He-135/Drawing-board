#include "Basic.h"
#include"Shape.h"
// ����������ʽ
void Basic::font(void) {
		setcolor(BLACK);
		setfont(18, 0, "����");
		setbkmode(TRANSPARENT);
}

//�ػ���������
void Basic::reDraw(Circle* c, Rectangle_* r, Triangle* t, int* shape) {
		int cir{ 0 }, rec{ 0 }, tri{ 0 };//���ڼ���
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

//��ȡͼ����ɫ
color_t Basic::readColor(std::string str){
		if (str == "��������") {
				return EGERGB(199, 21, 133);
		}
		else if (str == "����") {
				return EGERGB(255, 0, 255);
		}
		else if (str == "������") {
				return EGERGB(123, 104, 238);
		}
		else if (str == "������") {
				return EGERGB(60, 179, 113);
		}
		else if (str == "��ɫ") {
				return EGERGB(255, 215, 0);
		}
		else if (str == "��ɫ") {
				return EGERGB(255, 165, 0);
		}
		else if (str == "��ɫ") {
				return EGERGB(255, 0, 0);
		}
		else if (str == "��ɫ") {
				return EGERGB(0, 0, 0);
		}
		else{
				throw (ColorError());
		}
}

//�洢ͼ����ɫ
std::string Basic::saveColor(color_t c){
		if(c == EGERGB(199, 21, 133)){
				return "��������";
		}
		else if(c == EGERGB(255, 0, 255)){
				return "����";
		}
		else if (c == EGERGB(123, 104, 238)) {
				return "������";
		}
		else if (c == EGERGB(60, 179, 113)) {
				return "������";
		}
		else if (c == EGERGB(255, 215, 0)) {
				return "��ɫ";
		}
		else if (c == EGERGB(255, 165, 0)) {
				return "��ɫ";
		}
		else if (c == EGERGB(255, 0, 0)) {
				return "��ɫ";
		}
		else if (c == EGERGB(0, 0, 0)) {
				return "��ɫ";
		}
}