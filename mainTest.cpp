#include"board.h"
//#include"player.h"
#include"page.h"
#include"mButton.h"
#include"line.h"
#include"MCTS.h"
#include<iostream>

//#define DEBUG_BOARD


//��run֮ǰ�ȹر�cmd���� �����޷�д�� ÿһ�β������Ҫ�ر�cmd���ڷ���֮��ʹ��
int main() {
#ifdef DEBUG_BOARD
	board mb;
	player p1;
	p1.initianName();
	player p2;
	p2.initianName();

	std::cout << "\n" << "\n" << "Game is on" << std::endl;
	for (int i = 1; i < 5; i++) {
		mb.drawBoard();
		p1.drawLine(mb);
		mb.occupy();
		
		p2.drawLine(mb);
		mb.occupy();

	}
#endif
	//��ʼ��MCTS�����α�������ʱ��

	page mpage(800, 600);
	mpage.init();
	mpage.run();
	//һֱִ��run������������ִ��ֱ���ر�
	

	mpage.close();
	return 0;

}