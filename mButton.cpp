#include"mButton.h"
#include<cmath>

void mButton::checkMouseOver(int xMouse, int yMouse) {
	isMouseOver = abs(xMouse - xc) < width / 2 && abs(yMouse - yc) < height / 2;
	if (isMouseOver)scale = 0.9f;//鼠标悬停在上方时缩放按钮
	else scale = 1.0f;
}

void mButton::print() {
	int printWidth = scale * width;
	int printHeight = scale * height;

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

	fillrectangle(xc - printWidth / 2, yc - printHeight / 2, xc + printWidth / 2, yc + printHeight / 2);//绘制按钮

	settextcolor(BLACK); // 设置文本颜色为黑色
	setbkmode(TRANSPARENT); // 设置文本背景透明
	settextstyle(20 * scale, 0, _T("微软雅黑")); // 设置文本大小和字体

	//居中显示按钮文本
	int textX = xc - textwidth(text.c_str()) / 2; // 计算文本在按钮中央的x坐标
	int textY = yc - textheight(_T("微软雅黑")) / 2; // 计算文本在按钮中央的y坐标
	outtextxy(textX, textY, text.c_str()); // 在按钮上绘制文本
}


// 检查鼠标点击是否在按钮内，并在单击后执行函数
bool mButton::checkClick(int mouseX, int mouseY)
{
	if (abs(mouseX - xc) < width/2 && abs(mouseY - yc) < height/2)
	{
		onClick(); // 执行按钮点击时的函数
		isMouseOver = false;
		scale = 1.0f;
		return true;
	}
	return false;
}