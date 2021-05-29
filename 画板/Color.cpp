#include "Color.h"
//颜色类
Color::Color(int R, int G, int B) {
		this->R = R;
		this->B = B;
		this->G = G;
		color = EGERGB(R, G, B);
}
Color::Color(color_t t) :color(t) {
		this->R = EGEGET_R(t);
		this->G = EGEGET_G(t);
		this->B = EGEGET_B(t);
}
Color::Color(const Color& c) {
		this->R = c.R;
		this->G = c.G;
		this->B = c.B;
		this->color = c.color;
}
color_t Color::getColor(void)const {
		return color;
}
bool Color::operator==(const Color& c){
		if(this->color == c.color){
				return true;
		}
		else{
				return false;
		}
}
bool Color::operator!=(const Color& c) {
		if (this->color != c.color) {
				return true;
		}
		else {
				return false;
		}
}
int& Color::operator[](const int& index){
		if (index == 0) {
				return this->R;
		}
		else if (index == 1) {
				return this->G;
		}
		else if(index == 2){
				return this->B;
		}
		else {
				throw std::out_of_range("The index is" + std::to_string(index));
		}
}
Color& Color::operator++(void){ //前置++
		if (this->R < 255){
				this->R++;
		}
		if (this->G < 255) {
				this->G++;
		}
		if (this->B < 255) {
				this->B++;
		}
		return *this;
}
Color Color::operator++(int dummy){ //后置++
		int r = this->R;
		int g = this->G;
		int b = this->B;
		if (this->R < 255) {
				this->R++;
		}
		if (this->G < 255) {
				this->G++;
		}
		if (this->B < 255) {
				this->B++;
		}
		return Color(r, g, b);
}
Color& Color::operator--(void) { //前置--
		if (this->R > 0) {
				this->R--;
		}
		if (this->G > 0) {
				this->G--;
		}
		if (this->B > 0) {
				this->B--;
		}
		return *this;
}
Color Color::operator--(int dummy) { //后置--
		int r = this->R;
		int g = this->G;
		int b = this->B;
		if (this->R > 0) {
				this->R--;
		}
		if (this->G > 0) {
				this->G--;
		}
		if (this->B > 0) {
				this->B--;
		}
		return Color(r, g, b);
}
std::string Color::tostring(void){
		return ("R = " + std::to_string(R)
				+ " G = " + std::to_string(G)
				+ " B = " + std::to_string(B));
}