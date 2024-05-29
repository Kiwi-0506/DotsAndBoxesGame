#include"line.h"
using namespace lineSpace;

void line::init() {
	click = false;
}

void line::checkMouseOver(int xMouse, int yMouse) {
	if (!click) {
		isMouseOver = abs(xMouse - xc) < width / 2 && abs(yMouse - yc) < height / 2;
		if (isMouseOver)scale = 0.9f;//鼠标悬停在上方时缩放按钮
		else scale = 1.0f;
	}
}

void line::print() {
	int printWidth = scale * width;
	int printHeight = scale * height;

	if (!click) {
		if (isMouseOver)
		{
			setlinecolor(RGB(0, 120, 215)); // 鼠标悬停时按钮边框颜色
			setfillcolor(RGB(229, 241, 251)); // 鼠标悬停时按钮填充颜色

		}
		else
		{
			setlinecolor(RGB(173, 173, 173)); // 按钮边框颜色
			setfillcolor(RGB(225, 225, 225)); // 按钮填充颜色
		}

	}
	else {
		setlinecolor(BLACK);
		setfillcolor(BLACK);
	}
	fillrectangle(xc - printWidth / 2, yc - printHeight / 2,
		xc + printWidth / 2, yc + printHeight / 2);//绘制按钮
}

// 检查鼠标点击是否在按钮内，并且该线段没有被点击过，并在单击后执行函数
bool line::checkClick(int mouseX, int mouseY)
{
	if (abs(mouseX - xc) < width/2 && abs(mouseY - yc) < height/2 && !click)
	{
		onClick(); // 执行点击时的函数
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