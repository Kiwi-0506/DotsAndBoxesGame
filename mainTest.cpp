#include"board.h"
//#include"player.h"
#include"page.h"
#include"mButton.h"
#include"line.h"
#include"MCTS.h"
#include<iostream>

//#define DEBUG_BOARD


//在run之前先关闭cmd窗口 否则无法写入 每一次测试完后都要关闭cmd窗口方便之后使用
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
	//初始化MCTS里面的伪随机数计时器

	page mpage(800, 600);
	mpage.init();
	mpage.run();
	//一直执行run函数不再向下执行直到关闭
	

	mpage.close();
	return 0;

}