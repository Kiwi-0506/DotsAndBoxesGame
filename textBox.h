#pragma once
#include"mButton.h"
#include<string>
#include<easyx.h>

//textBox是一种动态文本框，可以根据不同的状态动态调整期中的文字
//通过继承mbutton的中心坐标xc，yc和宽度width和高度height来进行构造，从而减少代码量

class textBox :private mButton {

public:
	textBox(int xc, int yc, int width, int height, std::wstring text) :
		mButton(xc, yc, width, height, text) {
		//
	}

	void tprint() {
		setlinecolor(RGB(225, 225, 225)); // 文本框填充颜色
		setfillcolor(RGB(225, 225, 225)); // 文本框填充颜色

		fillrectangle(xc -width / 2, yc -height / 2, xc +width / 2, yc + height / 2);//绘制文本框

		settextcolor(BLACK); // 设置文本颜色为黑色
		setbkmode(TRANSPARENT); // 设置文本背景透明
		settextstyle(20 , 0, _T("微软雅黑")); // 设置文本大小和字体

		//居中显示文本框内文本
		int textX = xc - textwidth(text.c_str()) / 2; // 计算文本在文本框中央的x坐标
		int textY = yc - textheight(_T("微软雅黑")) / 2; // 计算文本在文本框中央的y坐标
		outtextxy(textX, textY, text.c_str()); // 在文本框上绘制文本
	}

	void setText(std::wstring text_) {
		text = text_;
	}
};