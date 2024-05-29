#pragma once
#include <iostream>
#include <vector>
#include<easyx.h>
#include"mButton.h"
#include"line.h"
#include"square.h"
#include"player.h"
//#define DEBUG

/*创建点格棋的棋盘
* 点格棋的棋盘大小锁定为11x11(之后可能可以用size来调节) 棋盘格子从（0,0）原点开始标号
*
*其中
* 在棋盘矩阵中 （奇，奇）为方块点 （偶，偶）为点 （奇，偶）（偶，奇）为可划线点
* 棋盘类包含私有类
棋盘的大小 棋盘矩阵 静态成员计步器
*
*/

class board {
	friend class player;//想办法只把drawline函数作为友函数
	friend class line;
	friend class page;
;
private:
	
	
	//里棋盘
	
	
	//表棋盘
	std::vector<std::vector<lineSpace::line*>> lineX;
	std::vector<std::vector<lineSpace::line*>> lineY;

	std::vector<std::vector<squareSpace::square*>> squareB;



	//好像在vector内存放指针需要交代命名空间

public:
	int boardSize;
	
	//暂时先把里棋盘挪出来，之后再调整封装
	std::vector<std::vector<int>> boardMatrix;
	
	int stepCount;

	board();
	void initBoard();//棋盘状态初始化函数
	void drawBoard();//调试用在cmd上打印棋盘
	
	void setBoard(int, int, int);
	void setLine(int, int, bool,bool);
	void occupy();
	
	int showSteps();


	//MCTS functions
	/*int GetBoardWinner();
	int GetFreeEdgeNum();
	int GetMCWinner(int);
	float GetMCEvalution(int, int, int);
	*/


	std::pair<int, int>RandomTurn();

	std::vector<std::pair<int, int>> empty_cells;

};