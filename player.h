#pragma once
#include<iostream>
#include<string>
#include "board.h"

class board;//写类的函数记得写前向声明
class player {
private:
	std::string playerName;
public:
	void initianName();
	void drawLine(board &mb);
	void surrender();
};