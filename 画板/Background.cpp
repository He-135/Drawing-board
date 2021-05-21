#include "Background.h"
//图形环境控制器类
Background::Background() : Background(1280, 960) {}
Background::Background(int width, int height) {
		this->width = width;
		this->height = height;
		initgraph(width, height);
		setbkcolor(EGERGB(245, 245, 220));
}
