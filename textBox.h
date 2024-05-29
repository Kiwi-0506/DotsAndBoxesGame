#pragma once
#include"mButton.h"
#include<string>
#include<easyx.h>

//textBox��һ�ֶ�̬�ı��򣬿��Ը��ݲ�ͬ��״̬��̬�������е�����
//ͨ���̳�mbutton����������xc��yc�Ϳ��width�͸߶�height�����й��죬�Ӷ����ٴ�����

class textBox :private mButton {

public:
	textBox(int xc, int yc, int width, int height, std::wstring text) :
		mButton(xc, yc, width, height, text) {
		//
	}

	void tprint() {
		setlinecolor(RGB(225, 225, 225)); // �ı��������ɫ
		setfillcolor(RGB(225, 225, 225)); // �ı��������ɫ

		fillrectangle(xc -width / 2, yc -height / 2, xc +width / 2, yc + height / 2);//�����ı���

		settextcolor(BLACK); // �����ı���ɫΪ��ɫ
		setbkmode(TRANSPARENT); // �����ı�����͸��
		settextstyle(20 , 0, _T("΢���ź�")); // �����ı���С������

		//������ʾ�ı������ı�
		int textX = xc - textwidth(text.c_str()) / 2; // �����ı����ı��������x����
		int textY = yc - textheight(_T("΢���ź�")) / 2; // �����ı����ı��������y����
		outtextxy(textX, textY, text.c_str()); // ���ı����ϻ����ı�
	}

	void setText(std::wstring text_) {
		text = text_;
	}
};