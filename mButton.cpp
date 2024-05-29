#include"mButton.h"
#include<cmath>

void mButton::checkMouseOver(int xMouse, int yMouse) {
	isMouseOver = abs(xMouse - xc) < width / 2 && abs(yMouse - yc) < height / 2;
	if (isMouseOver)scale = 0.9f;//�����ͣ���Ϸ�ʱ���Ű�ť
	else scale = 1.0f;
}

void mButton::print() {
	int printWidth = scale * width;
	int printHeight = scale * height;

	if (isMouseOver)
	{
		setlinecolor(RGB(0, 120, 215)); // �����ͣʱ��ť�߿���ɫ
		setfillcolor(RGB(229, 241, 251)); // �����ͣʱ��ť�����ɫ

	}
	else
	{
		setlinecolor(RGB(173, 173, 173)); // ��ť�߿���ɫ
		setfillcolor(RGB(225, 225, 225)); // ��ť�����ɫ
	}

	fillrectangle(xc - printWidth / 2, yc - printHeight / 2, xc + printWidth / 2, yc + printHeight / 2);//���ư�ť

	settextcolor(BLACK); // �����ı���ɫΪ��ɫ
	setbkmode(TRANSPARENT); // �����ı�����͸��
	settextstyle(20 * scale, 0, _T("΢���ź�")); // �����ı���С������

	//������ʾ��ť�ı�
	int textX = xc - textwidth(text.c_str()) / 2; // �����ı��ڰ�ť�����x����
	int textY = yc - textheight(_T("΢���ź�")) / 2; // �����ı��ڰ�ť�����y����
	outtextxy(textX, textY, text.c_str()); // �ڰ�ť�ϻ����ı�
}


// ���������Ƿ��ڰ�ť�ڣ����ڵ�����ִ�к���
bool mButton::checkClick(int mouseX, int mouseY)
{
	if (abs(mouseX - xc) < width/2 && abs(mouseY - yc) < height/2)
	{
		onClick(); // ִ�а�ť���ʱ�ĺ���
		isMouseOver = false;
		scale = 1.0f;
		return true;
	}
	return false;
}