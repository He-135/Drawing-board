#include "Circle.h"
#include "Basic.h"
//圆类
Circle::Circle(int x, int y, int r) {
		Shape::setBool(0);
		p = Point(x, y);
		this->r = r;
}
Circle::Circle(const Circle& c) :Shape(c) {
		this->r = c.r;
		this->p = Point(c.p);
}
void Circle::draw(void) {
		Shape::draw();
		circle(p.getX(), p.getY(), r);
}

int Circle::getRadius(void)const {
		return r;
}
void Circle::setRadius(int r) {
		this->r = r;
}

Point Circle::getPoint(void)const {
		return p;
}
void Circle::setPoint(int x, int y) {
		this->p = Point(x, y);
}

int Circle::getCountCircle(void) {
		return countCircle;
}
void Circle::setCountCircle(int count) {
		countCircle = count;
}

void Circle::saveCircle(void)const {
		std::filesystem::path o("figure files.txt");
		std::fstream ofs{o, std::ios::app};
		ofs << this->getPoint().getX() << " "
				<< this->getPoint().getY() << " "
				<< this->getRadius() << std::endl
				<< Basic::saveColor(this->getBorder()) << " "
				<< this->getBool() << std::endl;
		ofs.close();
}

void Circle::readCircle(long int& loc){
		std::fstream ifs{ "figure files.txt", std::ios::in};
		ifs.seekg(loc, std::ios::beg);
		int x, y, r;
		bool b;
		color_t t;
		std::string str;
		ifs >> x >> y >> r;
		this->setPoint(x, y);
		this->setRadius(r);
		ifs >> str >> b;
		try
		{
				t = Basic::readColor(str);
				this->setBorder(t);
		}
		catch (const ColorError&)
		{
				this->setBorder(BLACK);
		}
		this->setBool(b);
		loc = ifs.tellg();
		ifs.close();
}
bool Circle::operator<(const Circle& c)const {
		if(this->r < c.r){
				return true;
		}
		else{
				return false;
	  }
}
bool Circle::operator>(const Circle& c)const {
		if (this->r > c.r) {
				return true;
		}
		else {
				return false;
		}
}
bool Circle::operator<=(const Circle& c)const {
		if (this->r <= c.r) {
				return true;
		}
		else {
				return false;
		}
}
bool Circle::operator>=(const Circle& c)const {
		if (this->r >= c.r) {
				return true;
		}
		else {
				return false;
		}
}
bool Circle::operator==(const Circle& c)const {
		if (this->p == c.p && this->r == c.r) {
				return true;
		}
		else {
				return false;
		}
}
bool Circle::operator!=(const Circle& c)const {
		if (this->p != c.p || this->r != c.r) {
				return true;
		}
		else {
				return false;
		}
}
Circle& Circle::operator=(const Circle& c){
		this->r = c.r;
		this->p = c.p;
		this->setBool(c.getBool());
		this->setBorder(c.getBorder());//这里进行了对指针的深拷贝
		return *this;
}
Point& Circle::operator[](const int& index){
		if(index == 0){
				return this->p;
		}
		else{
				throw std::out_of_range("The index is" + std::to_string(index));
		}
}