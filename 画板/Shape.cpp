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
		char color[100];
		int RGB[100];
		//����RGBֵ
		inputbox_getline("���á��߿���ɫ",
				"������RGB��ֵ���Կո�ָ���",
				color,
				sizeof(color) / sizeof(*color));
		char* tokenPtr = strtok(color, " ");
		for (int i = 0; tokenPtr != NULL && i < 3; i++) {
				RGB[i] = atoi(tokenPtr);
				tokenPtr = strtok(NULL, " ");
		}
		this->borderColor = new Color(RGB[0], RGB[1], RGB[2]);
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