#include "class.h"

//图形环境控制器类
Background::Background() : Background(1280, 960) {}
Background::Background(int width, int height) {
		this->width = width;
		this->height = height;
		initgraph(width, height);
		setbkcolor(WHITE);
		ege::line(160, 0, 160, height);
}
void Background::line(void){
		ege::line(160, 0, 160, height);
}

//点类
Point::Point() :Point(0, 160) {}
Point::Point(int x, int y) {
		this->x = x;
		this->y = y;
}
int Point::getX(void)const{
		return x;
}
int Point::getY(void)const {
		return y;
}
//void Point::setX(int x){
//		this->x = x;
//}
//void Point::setY(int y){
//		this->y = y;
//}

//颜色类
Color::Color() :Color(0, 0, 0) {}
Color::Color(int R, int G, int B) {
		this->R = R;
		this->B = B;
		this->G = G;
		color = EGERGB(R, G, B);
}
color_t Color::getColor(void)const {
		return color;
}
//void Color::setColor(int R, int G, int B){
//		this->color = Color(R, G, B).getColor();
//}

//圆类
Circle::Circle() :Circle(200, 200, 50, Color(255, 0, 0).getColor()) {}
Circle::Circle(int x, int y, int r, color_t color) {
		p = Point(x, y);
		this->r = r;
		this->color = color;
		setcolor(color);
		circle(p.getX(), p.getY(), r);
		setcolor(BLACK);
}
int Circle::getRadius(void)const{
		return r;
}
color_t Circle::getColor(void)const{
		return color;
}
Point Circle::getPoint(void)const{
		return p;
}
void Circle::setRadius(int r){
		this->r = r;
}
void Circle::setColor(int R, int G, int B){
		this->color = Color(R, G, B).getColor();
}
void Circle::setPoint(int x, int y){
		this->p = Point(x, y);
}

//矩形类
int example[4]{ 200, 200, 300, 300 };
Rectangle_::Rectangle_() :Rectangle_(example,	Color(255, 0, 0).getColor()) {}
Rectangle_::Rectangle_(int xy[4], color_t color) {
		for(int i = 0, j = 0; i < 4 && j < 2; i++, j++){
				p[j] = Point(xy[i++], xy[i]);
		}
		this->color = color;
		setcolor(color);
		rectangle(p[0].getX(), p[0].getY(), p[1].getX(), p[1].getY());
		setcolor(BLACK);
}
Point Rectangle_::getPoint(int index)const{
		return p[index];
}
void Rectangle_::setPoint(int x, int y, int index){
		p[index] = Point(x, y);
}
color_t Rectangle_::getColor(void)const {
		return color;
}
void Rectangle_::setColor(int R, int G, int B) {
		this->color = Color(R, G, B).getColor();
}

//三角形类
int exampleTri[6]{ 200, 200, 200, 300, 300, 300 };
Triangle::Triangle() :Triangle(exampleTri, Color(255, 0, 0).getColor(), Color(0, 0, 255).getColor()) {}
Triangle::Triangle(int xy[6], color_t colorBorder, color_t colorFill) {
		for (int i = 0, j = 0; i < 6; j++) {
				p[j] = Point(xy[i++], xy[i++]);
		}
		this->colorBorder = colorBorder;
		this->colorFill = colorFill;
		setcolor(this->colorBorder);
		setfillcolor(this->colorFill);
		int xy_[6];
		for(int i = 0, j = 0; i < 6; j++){
				xy_[i++] = p[j].getX();
				xy_[i++] = p[j].getY();
		}
		fillpoly(3, xy_);
		setcolor(BLACK);
}
Point Triangle::getPoint(int index)const {
		return p[index];
}
color_t Triangle::getColorBorder(void)const {
		return colorBorder;
}
color_t Triangle::getColorFill(void)const {
		return colorFill;
}
void Triangle::setPoint(int x, int y, int index) {
		p[index] = Point(x, y);
}
void Triangle::setColor(int R, int G, int B) {
		this->colorBorder = Color(R, G, B).getColor();
}