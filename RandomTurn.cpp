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
	// �ҵ����пյĿ��仮λ��
	for (int i = 0; i < boardSize; ++i) {
		for (int j = 0; j < boardSize; ++j) {
			if ((i % 2 == 0 && j % 2 != 0 && boardMatrix[i][j] == 0) ||   //ż���п�������
				(i % 2 != 0 && j % 2 == 0 && boardMatrix[i][j] == 0)) {   //�����п�ż����
				empty_cells.emplace_back(i, j);//����ʲôû������
			}
		}
	}
	//��һ������ķ�����������ѡ���һ����
	// std::random_shuffle(empty_cells.begin(), empty_cells.end());

	int randomIndex = rand() % empty_cells.size();// ʹ�� rand() ������ empty_cells �����ѡ��һ��Ԫ��
	if (empty_cells.empty()) {
		return std::make_pair(-1, -1);  // ���û���ҵ��յ�Ԫ�񣬷���һ������ֵ
	}
	else {
		return empty_cells[randomIndex];
		//return a.empty_cells[randomIndex];
	}
}
