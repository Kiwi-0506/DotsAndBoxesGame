#pragma once
#include<string>
#include<functional>
#include <easyx.h>

class mButton {
protected:
	int xc;
	int yc;//按钮矩形中心坐标
	int width;
	int height;
	//float scale;
	//bool isMouseOver;
	std::wstring text;

private:
	std::function<void()> onClick;
	float scale;
	bool isMouseOver;
public:
	mButton(int xc, int yc, int width, int height, std::wstring text, const std::function<void()>& onClick) :
		xc(xc), yc(yc), width(width), height(height), scale(1.0f), isMouseOver(false), text(text), onClick(onClick) {}

	mButton(int xc, int yc, int width, int height, std::wstring text) :
		xc(xc), yc(yc), width(width), height(height) {}

	void setText(std::wstring text) {
		this->text = text;
	}
	void checkMouseOver(int, int);
	void print();

	bool checkClick(int, int);
	void locked() {
		isMouseOver = false;
	};
};