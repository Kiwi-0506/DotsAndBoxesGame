#pragma once
#include<functional>
#include"easyx.h"

namespace lineSpace {
	class line {
	private:
		int xc, yc;
		bool click;

		int width, height;

		float scale;
		bool isMouseOver;
		std::function<void()> onClick;
	public:
		line(int xc, int yc, int width, int height, const std::function<void()>& onClick) :
			xc(xc), yc(yc), width(width), height(height), scale(1.0f), isMouseOver(false), onClick(onClick),
			click(false) {}

		void print();
		void checkMouseOver(int, int);
		bool checkClick(int, int);

		void setClick(bool);
		bool showClick() const ;
		void init();
	};
}