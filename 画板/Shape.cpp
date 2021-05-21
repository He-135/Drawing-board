#include "Shape.h"
//����shape
Shape::Shape(const Shape& s) {
		this->isFill = s.isFill;
		if (s.borderColor != nullptr) {
				this->borderColor = new Color(*s.borderColor);
		}
		if (s.fillColor != nullptr) {
				this->fillColor = new Color(*s.fillColor);
		}
}
Shape::~Shape() {
		if (borderColor != nullptr) {
				delete borderColor;
				borderColor = nullptr;
		}
		if (fillColor != nullptr) {
				delete fillColor;
				fillColor = nullptr;
		}
}
void Shape::draw(void) {
		setBorder();
		if (isFill) {
				setFill();
		}
}

bool Shape::getBool(void)const {
		return isFill;
}
void Shape::setBool(int isFill) {
		this->isFill = isFill;
}

color_t Shape::getBorder(void)const {
		return borderColor->getColor();
}
void Shape::setBorder(void) {
		Basic::font();
		outtextrect(0, 0, 640, 480,
				"��ѡ��߿���ɫ��\n1.��������\n2.����\n3.������\n4.������\n5.��ɫ\n6.��ɫ\n7.��ɫ\n8.��ɫ\n����������ѡ��");
		int choose = getch();
		switch(choose){
				case '1':
						this->borderColor = new Color(199, 21, 133);
						break;
				case '2':
						this->borderColor = new Color(255, 0, 255);
						break;
				case '3':
						this->borderColor = new Color(123, 104, 238);
						break;
				case '4':
						this->borderColor = new Color(60, 179, 113);
						break;
				case '5':
						this->borderColor = new Color(255, 215, 0);
						break;
				case '6':
						this->borderColor = new Color(255, 165, 0);
						break;
				case '7':
						this->borderColor = new Color(255, 0, 0);
						break;
				case '8':
						this->borderColor = new Color(0, 0, 0);
						break;
		}
		setcolor(borderColor->getColor());
}
void Shape::setBorder(color_t t){
		this->borderColor = new Color(t);
}

color_t Shape::getFill(void)const {
		return fillColor->getColor();
}
void Shape::setFill(void) {
		char color[100];
		int RGB[100];
		//����RGBֵ
		inputbox_getline("���á���䡿��ɫ",
				"������RGB��ֵ���Կո�ָ���",
				color,
				sizeof(color) / sizeof(*color));
		char* tokenPtr = strtok(color, " ");
		for (int i = 0; tokenPtr != NULL && i < 3; i++) {
				RGB[i] = atoi(tokenPtr);
				tokenPtr = strtok(NULL, " ");
		}
		fillColor = new Color(RGB[0], RGB[1], RGB[2]);
		setfillcolor(fillColor->getColor());
}
void Shape::setFill(color_t t){
		this->fillColor = new Color(t);
}

int Shape::getCount(void) {
		return count;
}
void Shape::setCount(int count_) {
		count = count_;
}