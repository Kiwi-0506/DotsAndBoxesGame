#include"player.h"

void player::initianName() {
	std::cout << "hi, what's your name?" << std::endl;
	std::string name;
	std::cin >> name;
	playerName = name;
	std::cout << "welcome player" << playerName << std::endl;
}


//����������֮�����
void player::drawLine(board &mb) {
	//Ŀǰֻ�������Ǹ��ߵ�ȫ�����겻�Ǻܷ���
	int x = 0, y = 0;
	std::cin >> x >> y;
	mb.boardMatrix[x][y] = 1;
	board::stepCount++;
	mb.showSteps();
	std::cout << " A line is drawn by player" <<playerName<< std::endl;
	mb.drawBoard();
}

