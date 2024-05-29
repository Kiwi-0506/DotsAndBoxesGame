#pragma once
#include <iostream>
#include <vector>
#include<easyx.h>
#include"mButton.h"
#include"line.h"
#include"square.h"
#include"player.h"
//#define DEBUG

/*��������������
* ���������̴�С����Ϊ11x11(֮����ܿ�����size������) ���̸��Ӵӣ�0,0��ԭ�㿪ʼ���
*
*����
* �����̾����� ���棬�棩Ϊ����� ��ż��ż��Ϊ�� ���棬ż����ż���棩Ϊ�ɻ��ߵ�
* ���������˽����
���̵Ĵ�С ���̾��� ��̬��Ա�Ʋ���
*
*/

class board {
	friend class player;//��취ֻ��drawline������Ϊ�Ѻ���
	friend class line;
	friend class page;
;
private:
	
	
	//������
	
	
	//������
	std::vector<std::vector<lineSpace::line*>> lineX;
	std::vector<std::vector<lineSpace::line*>> lineY;

	std::vector<std::vector<squareSpace::square*>> squareB;



	//������vector�ڴ��ָ����Ҫ���������ռ�

public:
	int boardSize;
	
	//��ʱ�Ȱ�������Ų������֮���ٵ�����װ
	std::vector<std::vector<int>> boardMatrix;
	
	int stepCount;

	board();
	void initBoard();//����״̬��ʼ������
	void drawBoard();//��������cmd�ϴ�ӡ����
	
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