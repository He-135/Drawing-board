#include "class.h"
#include <iostream>

void font(void);//��������
color_t setBorderColor(void);//������ɫ
color_t setFillColor(void);//���������ɫ

int main(void){
		//Background();
		//a:font();
		//outtextrect(0, 0, 640, 480,
		//		"��ѡ���������ݣ�\n1.Բ\n2.����\n3.������\n4.�����Ļ\n����������ѡ��");
		while(1){
				int choose = getch();
				switch (choose) {
						//Բ
						case '1': {
								char points[100];
								int coord[100];
								char cr[5];
								//����Բ������
								inputbox_getline("�����롾Բ�����꡿",
										"���Կո�ָ���",
										points,
										sizeof(points) / sizeof(*points));
								char* tokenPtr = strtok(points, " ");
								for (int i = 0; tokenPtr != NULL; i++) {
										coord[i] = atoi(tokenPtr);
										tokenPtr = strtok(NULL, " ");
								}
								//����Բ�뾶
								inputbox_getline("�����롾�뾶��",
										"�뾶��r���������س�������",
										cr,
										sizeof(cr) / sizeof(*cr));
								int r = atoi(cr);
								Circle c{ coord[0], coord[1], r, setBorderColor() };
								break;
						}
								//����
						case '2': {
								char points[100];
								int coord[100];
								char cr[5];
								//�������Ϻ����¶�������
								inputbox_getline("�����롾���Ϻ����¶������꡿",
										"���Կո�ָ���",
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
										//������
						case '3': {
								char points[100];
								int coord[100];
								char cr[5];
								//�������Ϻ����¶�������
								inputbox_getline("�����롾�����������꡿",
										"���Կո�ָ���",
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

//����������ʽ
void font(void) {
		setcolor(BLACK);
		setfont(18, 0, "����");
		setbkmode(TRANSPARENT);
		Background::line();
}

//������ɫ
color_t setBorderColor(void){
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
		return(Color(RGB[0], RGB[1], RGB[2]).getColor());
}

//���������ɫ
color_t setFillColor(void) {
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
		return(Color(RGB[0], RGB[1], RGB[2]).getColor());
}