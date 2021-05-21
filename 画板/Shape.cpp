#include "Shape.h"
#include"Basic.h"
//»ùÀàshape
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
		if (isFill) {
				setFill();
		}
		setBorder();
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
				"ÇëÑ¡Ôñ±ß¿òÑÕÉ«£º\n1.×ÏÂÞÀ¼ºì\n2.Ñó×Ï\n3.°åÑÒÀ¶\n4.º£ÑóÂÌ\n5.½ðÉ«\n6.³ÈÉ«\n7.ºìÉ«\n8.ºÚÉ«\nÇëÊäÈëÄúµÄÑ¡Ôñ£º");
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
		Basic::font();
		outtextrect(0, 220, 640, 960,
				"ÇëÑ¡ÔñÌî³äÑÕÉ«£º\n1.×ÏÂÞÀ¼ºì\n2.Ñó×Ï\n3.°åÑÒÀ¶\n4.º£ÑóÂÌ\n5.½ðÉ«\n6.³ÈÉ«\n7.ºìÉ«\n8.ºÚÉ«\nÇëÊäÈëÄúµÄÑ¡Ôñ£º");
		int choose = getch();
		switch (choose) {
		case '1':
				this->fillColor = new Color(199, 21, 133);
				break;
		case '2':
				this->fillColor = new Color(255, 0, 255);
				break;
		case '3':
				this->fillColor = new Color(123, 104, 238);
				break;
		case '4':
				this->fillColor = new Color(60, 179, 113);
				break;
		case '5':
				this->fillColor = new Color(255, 215, 0);
				break;
		case '6':
				this->fillColor = new Color(255, 165, 0);
				break;
		case '7':
				this->fillColor = new Color(255, 0, 0);
				break;
		case '8':
				this->fillColor = new Color(0, 0, 0);
				break;
		}
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