#pragma once
#include<iostream>
#include<string>
#include "board.h"

class board;//д��ĺ����ǵ�дǰ������
class player {
private:
	std::string playerName;
public:
	void initianName();
	void drawLine(board &mb);
	void surrender();
};