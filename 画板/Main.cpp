#include "class.h"
#include <iostream>

void font(void);//设置字体
color_t setBorderColor(void);//设置颜色
color_t setFillColor(void);//设置填充颜色

int main(void){
		//Background();
		//a:font();
		//outtextrect(0, 0, 640, 480,
		//		"请选择作画内容：\n1.圆\n2.矩形\n3.三角形\n4.清空屏幕\n请输入您的选择：");
		while(1){
				int choose = getch();
				switch (choose) {
						//圆
						case '1': {
								char points[100];
								int coord[100];
								char cr[5];
								//输入圆心坐标
								inputbox_getline("请输入【圆心坐标】",
										"（以空格分隔）",
										points,
										sizeof(points) / sizeof(*points));
								char* tokenPtr = strtok(points, " ");
								for (int i = 0; tokenPtr != NULL; i++) {
										coord[i] = atoi(tokenPtr);
										tokenPtr = strtok(NULL, " ");
								}
								//输入圆半径
								inputbox_getline("请输入【半径】",
										"半径（r）：（按回车结束）",
										cr,
										sizeof(cr) / sizeof(*cr));
								int r = atoi(cr);
								Circle c{ coord[0], coord[1], r, setBorderColor() };
								break;
						}
								//矩形
						case '2': {
								char points[100];
								int coord[100];
								char cr[5];
								//输入左上和右下顶点坐标
								inputbox_getline("请输入【左上和右下顶点坐标】",
										"（以空格分隔）",
										points,
										sizeof(points) / sizeof(*points));
								char* tokenPtr = strtok(points, " ");
								for (int i = 0; tokenPtr != NULL; i++) {
										coord[i] = atoi(tokenPtr);
										tokenPtr = strtok(NULL, " ");
								}
								Rectangle_ r{ coord, setBorderColor() };
								break;
						}
										//三角形
						case '3': {
								char points[100];
								int coord[100];
								char cr[5];
								//输入左上和右下顶点坐标
								inputbox_getline("请输入【三个顶点坐标】",
										"（以空格分隔）",
										points,
										sizeof(points) / sizeof(*points));
								char* tokenPtr = strtok(points, " ");
								for (int i = 0; tokenPtr != NULL; i++) {
										coord[i] = atoi(tokenPtr);
										tokenPtr = strtok(NULL, " ");
								}
								Triangle t{ coord, setBorderColor(), setFillColor() };
								break;
						}
						case '4':
								cleardevice();
								goto a;
								break;
				}
		}
		getch();
		return 0;
}

//设置文字样式
void font(void) {
		setcolor(BLACK);
		setfont(18, 0, "楷体");
		setbkmode(TRANSPARENT);
		Background::line();
}

//设置颜色
color_t setBorderColor(void){
		char color[100];
		int RGB[100];
		//输入RGB值
		inputbox_getline("设置【边框】颜色",
				"请输入RGB的值（以空格分隔）",
				color,
				sizeof(color) / sizeof(*color));
		char* tokenPtr = strtok(color, " ");
		for (int i = 0; tokenPtr != NULL && i < 3; i++) {
				RGB[i] = atoi(tokenPtr);
				tokenPtr = strtok(NULL, " ");
		}
		return(Color(RGB[0], RGB[1], RGB[2]).getColor());
}

//设置填充颜色
color_t setFillColor(void) {
		char color[100];
		int RGB[100];
		//输入RGB值
		inputbox_getline("设置【填充】颜色",
				"请输入RGB的值（以空格分隔）",
				color,
				sizeof(color) / sizeof(*color));
		char* tokenPtr = strtok(color, " ");
		for (int i = 0; tokenPtr != NULL && i < 3; i++) {
				RGB[i] = atoi(tokenPtr);
				tokenPtr = strtok(NULL, " ");
		}
		return(Color(RGB[0], RGB[1], RGB[2]).getColor());
}