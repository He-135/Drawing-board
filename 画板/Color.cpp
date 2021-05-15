#include "Color.h"
//ÑÕÉ«Àà
Color::Color(int R, int G, int B) {
		this->R = R;
		this->B = B;
		this->G = G;
		color = EGERGB(R, G, B);
}
Color::Color(color_t t) :color(t) {}
Color::Color(const Color& c) {
		this->R = c.R;
		this->G = c.G;
		this->B = c.B;
		this->color = c.color;
}
color_t Color::getColor(void)const {
		return color;
}
//void Color::setColor(color_t t){
//		this->color = t;
//}
