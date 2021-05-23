#include "Triangle.h"
#include "Basic.h"
//Èý½ÇÐÎÀà
Triangle::Triangle(int xy[6]) {
		Shape::setBool(1);
		for (int i = 0, j = 0; i < 6; j++, i += 2) {
				p[j] = Point(xy[i], xy[i + 1]);
		}
}
Triangle::Triangle(const Triangle& t) :Shape(t) {
		for (int i = 0; i < 3; i++) {
				this->p[i] = t.p[i];
		}
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

Point Triangle::getPoint(int index)const {
		return p[index];
}
void Triangle::setPoint(int x, int y, int index) {
		p[index] = Point(x, y);
}

int Triangle::getCountTriangle(void) {
		return countTriangle;
}
void Triangle::setCountTriangle(int count) {
		countTriangle = count;
}

void Triangle::saveTriangle (void){
		std::filesystem::path o{"figure files.txt"};
		std::fstream ofs{o, std::ios::app};
		ofs << this->getPoint(0).getX() << " "
				<< this->getPoint(0).getY() << " "
				<< this->getPoint(1).getX() << " "
				<< this->getPoint(1).getY() << " "
				<< this->getPoint(2).getX() << " "
				<< this->getPoint(2).getY() << std::endl
				<< Basic::saveColor(this->getBorder()) << " "
				<< this->getBool() << " "
				<< Basic::saveColor(this->getFill()) << std::endl;
		ofs.close();
}

void Triangle::readTriangle(long int& loc){
		std::fstream ifs{ "figure files.txt", std::ios::in };
		ifs.seekg(loc, std::ios::beg);
		int xy[6];
		std::string str;
		bool b;
		color_t t;
		for (int j = 0; j < 6; j++) {
				ifs >> xy[j];
		}
		this->setPoint(xy[0], xy[1], 0);
		this->setPoint(xy[2], xy[3], 1);
		this->setPoint(xy[4], xy[5], 2);
		ifs >> str >> b;
		try
		{
				t = Basic::readColor(str);
				this->setBorder(t);
		}
		catch (const ColorError& mc)
		{
				this->setBorder(BLACK);
		}
		this->setBool(b);
		ifs >> str;
		try
		{
				t = Basic::readColor(str);
				this->setFill(t);
		}
		catch (const ColorError& mc)
		{
				this->setFill(BLACK);
		}
		loc = ifs.tellg();
		ifs.close();
}