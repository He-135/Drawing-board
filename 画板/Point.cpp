#include "Point.h"
//µãÀà
Point::Point(int x, int y) {
		this->x = x;
		this->y = y;
}
Point::Point(const Point& p) {
		this->x = p.x;
		this->y = p.y;
}
int Point::getX(void)const {
		return x;
}
int Point::getY(void)const {
		return y;
}
Point Point::operator+(const Point& p){
		int x_ = this->x + p.x;
		int y_ = this->y + p.y;
		return Point(x_ / 2, y_ / 2);
}
bool Point::operator==(const Point p)const {
		if(this->x == p.x && this->y == p.y){
				return true;
		}
		else{
				return false;
		}
}
bool Point::operator!=(const Point p)const {
		if (this->x != p.x || this->y != p.y) {
				return true;
		}
		else {
				return false;
		}
}
int& Point::operator[](const int& index) {
		if(index == 0){
				return this->x;
		}
		else if(index == 1){
				return this->y;
		}
		else{
				throw std::out_of_range("The index is" + std::to_string(index));
		}
}
std::string Point::tostring(void){
		return ("(" + std::to_string(x) + ", " + std::to_string(y) + ")");
}