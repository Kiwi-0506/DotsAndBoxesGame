#include"line.h"
using namespace lineSpace;

void line::init() {
	click = false;
}

void line::checkMouseOver(int xMouse, int yMouse) {
	if (!click) {
		isMouseOver = abs(xMouse - xc) < width / 2 && abs(yMouse - yc) < height / 2;
		if (isMouseOver)scale = 0.9f;//�����ͣ���Ϸ�ʱ���Ű�ť
		else scale = 1.0f;
	}
}

void line::print() {
	int printWidth = scale * width;
	int printHeight = scale * height;

	if (!click) {
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

	}
	else {
		setlinecolor(BLACK);
		setfillcolor(BLACK);
	}
	fillrectangle(xc - printWidth / 2, yc - printHeight / 2,
		xc + printWidth / 2, yc + printHeight / 2);//���ư�ť
}

// ���������Ƿ��ڰ�ť�ڣ����Ҹ��߶�û�б�����������ڵ�����ִ�к���
bool line::checkClick(int mouseX, int mouseY)
{
	if (abs(mouseX - xc) < width/2 && abs(mouseY - yc) < height/2 && !click)
	{
		onClick(); // ִ�е��ʱ�ĺ���
		isMouseOver = false;
		scale = 1.0f;

		click = true;
		

		return true;
	}
	return false;
}

void line::setClick(bool click) {
	this->click = click;
}


bool line::showClick() const {

	return click;
}