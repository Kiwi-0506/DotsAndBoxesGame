#include"player.h"

void player::initianName() {
	std::cout << "hi, what's your name?" << std::endl;
	std::string name;
	std::cin >> name;
	playerName = name;
	std::cout << "welcome player" << playerName << std::endl;
}


//连接两个点之间的线
void player::drawLine(board &mb) {
	//目前只能输入那个线的全局坐标不是很方便
	int x = 0, y = 0;
	std::cin >> x >> y;
	mb.boardMatrix[x][y] = 1;
	board::stepCount++;
	mb.showSteps();
	std::cout << " A line is drawn by player" <<playerName<< std::endl;
	mb.drawBoard();
}

