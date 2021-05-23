#include "Rectangle_.h"
#include "Basic.h"
//æÿ–Œ¿‡
Rectangle_::Rectangle_(int xy[4]) {
		Shape::setBool(0);
		for (int i = 0, j = 0; i < 4 && j < 2; i += 2, j++) {
				p[j] = Point(xy[i], xy[i + 1]);
		}
}
Rectangle_::Rectangle_(const Rectangle_& r) :Shape(r) {
		for (int i = 0; i < 2; i++) {
				this->p[i] = r.p[i];
		}
}
void Rectangle_::draw(void) {
		Shape::draw();
		rectangle(p[0].getX(), p[0].getY(), p[1].getX(), p[1].getY());
}

Point Rectangle_::getPoint(int index)const {
		return p[index];
}
void Rectangle_::setPoint(int x, int y, int index) {
		p[index] = Point(x, y);
}

int Rectangle_::getCountRectangle(void) {
		return countRectangle;
}
void Rectangle_::setCountRectangle(int count) {
		countRectangle = count;
}

void Rectangle_::saveRectangle(void){
		std::filesystem::path o{"figure files.txt"};
	  std::fstream ofs{o, std::ios::app};
		ofs << this->getPoint(0).getX() << " "
				<< this->getPoint(0).getY() << " "
				<< this->getPoint(1).getX() << " "
				<< this->getPoint(1).getY() << std::endl
				<< Basic::saveColor(this->getBorder()) << " "
				<< this->getBool() << std::endl;
		ofs.close();
}

void Rectangle_::readRectangle(long int& loc){
		std::fstream ifs{ "figure files.txt", std::ios::in};
		ifs.seekg(loc, std::ios::beg);
		int xy[4];
		std::string str;
		bool b;
		color_t t;
		for (int k = 0; k < 4; k++) {
				ifs >> xy[k];
		}
		this->setPoint(xy[0], xy[1], 0);
		this->setPoint(xy[2], xy[3], 1);
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