#include"board.h"
#include"RandomTurn.h"
#include"vector"
#include <iostream>
#include <cstdlib>
#include <ctime>

#pragma once


//#include <algorithm>
/*
int board::getsize() {
	return size;
}bool board::is_empty(int row, int col) {
	return boardMatrix[row][col] == 0;

}
*/

std::pair<int, int> board::RandomTurn() {
	// 找到所有空的可落划位置
	for (int i = 0; i < boardSize; ++i) {
		for (int j = 0; j < boardSize; ++j) {
			if ((i % 2 == 0 && j % 2 != 0 && boardMatrix[i][j] == 0) ||   //偶数行看奇数列
				(i % 2 != 0 && j % 2 == 0 && boardMatrix[i][j] == 0)) {   //奇数行看偶数列
				empty_cells.emplace_back(i, j);//这是什么没看懂？
			}
		}
	}
	//另一种随机的方法，打乱再选择第一个数
	// std::random_shuffle(empty_cells.begin(), empty_cells.end());

	int randomIndex = rand() % empty_cells.size();// 使用 rand() 函数从 empty_cells 中随机选择一个元素
	if (empty_cells.empty()) {
		return std::make_pair(-1, -1);  // 如果没有找到空单元格，返回一个错误值
	}
	else {
		return empty_cells[randomIndex];
		//return a.empty_cells[randomIndex];
	}
}
