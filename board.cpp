#include "board.h"



//board构造函数
board::board() {
	stepCount = 0;
	boardSize = 11;//
	std::vector<std::vector<int>> matrix(boardSize, std::vector<int>(boardSize, 0));
	boardMatrix = matrix;//生成一个所有位置都是0的矩阵

#ifdef DEBUG
	boardMatrix[0][0] = 1;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			std::cout << boardMatrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "board is created" << std::endl;

#endif // DEBUG

}

//board初始化函数
void board::initBoard() {
	boardSize = 11;//
	stepCount = 0;
	std::vector<std::vector<int>> matrix(boardSize, std::vector<int>(boardSize, 0));
	boardMatrix = matrix;//生成一个所有位置都是0的矩阵

	//在cmd上测试的debug代码
#ifdef DEBUG
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			std::cout << boardMatrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "board is initialized" << std::endl;

#endif // DEBUG

	//初始化里棋盘
	for (int i = 0; i < 6; i++) {
		for (lineSpace::line* ptr : lineX[i]) {
			ptr->init();
		}
	}
	for (int i = 0; i < 5; i++) {
		for (lineSpace::line* ptr : lineY[i]) {
			ptr->init();
		}
	}
	for (int i = 0; i < 5; i++) {
		for (squareSpace::square* ptr : squareB[i]) {
			ptr->initSquare();
		}
	}

}

//打印现在棋盘状态
void board::drawBoard() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			std::cout << boardMatrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "Board is updated" << std::endl;
	showSteps();
}


//方格占据判断----思路：暴力检查所有格子
void board::occupy() {
	for (int i = 1; i <= boardSize / 2; i++) {
		for (int j = 1; j <= boardSize / 2; j++) {
			

			bool upChecking = boardMatrix[2 * i - 1][2 * j - 2] == 1;
			bool downChecking = boardMatrix[2 * i - 1][2 * j] == 1;
			bool leftChecking = boardMatrix[2 * i - 2][2 * j - 1] == 1;
			bool rightChecking = boardMatrix[2 * i][2 * j - 1] == 1;


			if (boardMatrix[2 * i - 1][2 * j - 1] == 0 && upChecking && downChecking && rightChecking && leftChecking)
			{
				boardMatrix[2 * i - 1][2 * j - 1] = stepCount % 2 + 1;
				std::cout << "a square is occupied" << std::endl;
			}

			if (boardMatrix[2 * i - 1][2 * j - 1] != 0&&(!upChecking || !downChecking || !leftChecking || !rightChecking)) {
				boardMatrix[2 * i - 1][2 * j - 1] = 0;
				std::cout << "a wrong square is cleaned" << std::endl;
			}

		}
	}
}

//更改矩阵某个位置的状态
void board::setBoard(int i, int j, int val) {

	boardMatrix[i][j] = val;
}

//更改某一条线的状态 true改Y false改X
void board::setLine(int i, int j, bool type_xy,bool mood=false) {
	if (type_xy) {
		lineY[i][j]->setClick(mood);
	};
	if (!type_xy) {
		lineX[i][j]->setClick(mood);
	}
}

//打印目前已经行棋的步数
int board::showSteps() {


	std::cout << "Step: " << stepCount << std::endl;
	return stepCount;
}

