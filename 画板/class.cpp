#include "class.h"

//ͼ�λ�����������
Background::Background() : Background(1280, 960) {}
Background::Background(int width, int height) {
		this->width = width;
		this->height = height;
		initgraph(width, height);
		setbkcolor(WHITE);
		ege::line(160, 0, 160, height);
}
void Background::line(void){
		ege::line(160, 0, 160, 960);
}

//����
Point::Point() :Point(0, 160) {}
Point::Point(int x, int y) {
		this->x = x;
		this->y = y;
}
Point::Point(const Point& p){
		this->x = p.x;
		this->y = p.y;
}
int Point::getX(void)const{
		return x;
}
int Point::getY(void)const {
		return y;
}

//��ɫ��
Color::Color() :Color(0, 0, 0) {}
Color::Color(int R, int G, int B) {
		this->R = R;
		this->B = B;
		this->G = G;
		color = EGERGB(R, G, B);
}
Color::Color(const Color& c){
		this->R = c.R;
		this->G = c.G;
		this->B = c.B;
		this->color = c.color;
}
color_t Color::getColor(void)const {
		return color;
}

//����shape
Shape::Shape(const Shape& s) {
		this->isFill = s.isFill;
		this->borderColor = new Color(*s.borderColor);
		this->fillColor = s.fillColor;
}
Shape::~Shape(){
		if(borderColor != nullptr){
				delete borderColor;
				borderColor = nullptr;
		}
		if(fillColor != nullptr){
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
color_t Shape::getBorder(void)const {
		return borderColor->getColor();
}
color_t Shape::getFill(void)const {
		return fillColor->getColor();
}
int Shape::getCount(void){
		return count;
}
void Shape::setBool(int isFill) {
		this->isFill = isFill;
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
void Shape::setCount(int count_){
		count = count_;
}

//Բ��
Circle::Circle(int x, int y, int r) {
		Shape::setBool(0);
		p = Point(x, y);
		this->r = r;
		draw();
		setcolor(BLACK);
}
Circle::Circle(const Circle& c){
		this->r = c.r;
		this->p = Point(c.p);
		
}
int Circle::getRadius(void)const{
		return r;
}
Point Circle::getPoint(void)const{
		return p;
}
int Circle::getCountCircle(void){
		return countCircle;
}
void Circle::setCountCircle(int count){
	  countCircle = count;
}
void Circle::setRadius(int r){
		this->r = r;
}
void Circle::setPoint(int x, int y){
		this->p = Point(x, y);
}
void Circle::draw(void){
		Shape::draw();
		circle(p.getX(), p.getY(), r);
}

//������
Rectangle_::Rectangle_(int xy[4]) {
		Shape::setBool(0);
		for(int i = 0, j = 0; i < 4 && j < 2; i++, j++){
				p[j] = Point(xy[i++], xy[i]);
		}
		draw();
		setcolor(BLACK);
}
Point Rectangle_::getPoint(int index)const{
		return p[index];
}
void Rectangle_::setPoint(int x, int y, int index){
		p[index] = Point(x, y);
}
void Rectangle_::draw(void) {
		Shape::draw();
		rectangle(p[0].getX(), p[0].getY(), p[1].getX(), p[1].getY());
}
Rectangle_::~Rectangle_() {
		setCount(getCount() - 1);
}
int Rectangle_::getCountRectangle(void){
		return countRectangle;
}
void Rectangle_::setCountRectangle(int count){
		countRectangle = count;
}

//��������
Triangle::Triangle(int xy[6]) {
		Shape::setBool(1);
		for (int i = 0, j = 0; i < 6; j++) {
				p[j] = Point(xy[i++], xy[i++]);
		}
		draw();
		setcolor(BLACK);
}
Point Triangle::getPoint(int index)const {
		return p[index];
}
void Triangle::setPoint(int x, int y, int index) {
		p[index] = Point(x, y);
}
void Triangle::draw(void) {
		Shape::draw();
		int xy[6];
		for (int i = 0, j = 0; i < 6; j++) {
				xy[i++] = p[j].getX();
				xy[i++] = p[j].getY();
		}
		fillpoly(3, xy);
}
Triangle::~Triangle() {
		setCount(getCount() - 1);
}
int Triangle::getCountTriangle(void){
		return countTriangle;
}
void Triangle::setCountTriangle(int count){
		countTriangle = count;
}