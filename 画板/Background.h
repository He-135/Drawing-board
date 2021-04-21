#pragma once
#include "graphics.h"
//图形环境控制器类
class Background {
private:
		int width, height;
public:
		Background();
		Background(int, int);
		static void line(void);
};

