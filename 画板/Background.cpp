#include "Background.h"
//ͼ�λ�����������
Background::Background() : Background(1280, 960) {}
Background::Background(int width, int height) {
		this->width = width;
		this->height = height;
		initgraph(width, height);
		setbkcolor(WHITE);
		ege::line(160, 0, 160, height);
}
void Background::line(void) {
		ege::line(160, 0, 160, 960);
}