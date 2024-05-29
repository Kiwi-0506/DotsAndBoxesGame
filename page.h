#pragma once
#include<easyx.h>
#include<vector>
#include<string>
//#include<Windows.h>
#include"line.h"
#include"square.h"
#include"board.h"
#include"mButton.h"
#include"textBox.h"
#include"MCTS.h"
#include"RandomTurn.h"


class page {
private:
	int width;
	int height;
	int currentIndex;

	bool AIplayer;
	//悔棋存储区
	bool type_ed = 0;//0代表上一步是点了x方向的线，1代表上一步点了y方向的线
	int i_ed, j_ed;//开两个int记录一下上一步下了那个位置，然后做一个伪悔棋

	//页面存储区
	std::vector <IMAGE*> pages; // 存储所有页面的图片指针
	std::vector<std::vector<mButton*>> buttons; // 存储每个页面上的按钮指针
	std::vector<std::vector<textBox*>> textBoxs;// 存储每个页面上动态变化文本框指针

	//两个棋盘 board类用于实现交互 MCTS类用于实现棋盘
	board mb;
	MCTS MCTSboard;
	
public:
	//添加一个页面
	void addPage(IMAGE* page)
	{
		pages.push_back(page);
		buttons.push_back({});
		textBoxs.push_back({});
	}

	// 在指定页面上添加一个按钮
	void addButton(int index, mButton* button)
	{
		if (index >= 0 && index < buttons.size())
		{
			buttons[index].push_back(button);
		}
	}

	//在指定页面上添加一个动态文本框
	void addTextBox(int index, textBox* textBox) {

		if (index >= 0 && index < textBoxs.size()) {

			textBoxs[index].push_back(textBox);
		}
	}


	// 设置当前显示的页面索引
	void setCurrentIndex(int index)
	{
		if (index >= 0 && index < pages.size())
		{
			currentIndex = index;
		}
	}

	// 处理鼠标点击事件
	void mouseClick(int mouseX, int mouseY);


	// 处理鼠标移动事件
	void mouseMove(int mouseX, int mouseY);



	// 绘制当前页面的内容
	void draw();


	page(int width, int height)
		:width(width), height(height), currentIndex(-1)
	{}
	~page() {}

	// 初始化控件，创建图形环境，设置页面和按钮
	void init();

	//调用目前已走的步数
	int showSteps() {
		return mb.stepCount;
	}

	// 运行，进入消息循环
	void run()
	{
		ExMessage msg;

		

		BeginBatchDraw(); // 开始批量绘制

		while (true)
		{

			

			if (peekmessage(&msg)) // 检查是否有消息
			{
				int mouseX = msg.x; // 获取鼠标x坐标
				int mouseY = msg.y; // 获取鼠标y坐标

				switch (msg.message)
				{
				case WM_LBUTTONDOWN: // 鼠标左键按下事件

					

					mouseClick(mouseX, mouseY); // 处理鼠标点击事件

					

					break;
				case WM_MOUSEMOVE: // 鼠标移动事件
					mouseMove(mouseX, mouseY); // 处理鼠标移动事件


					break;
				}
			}



			draw(); // 绘制当前页面内容
			FlushBatchDraw(); // 将缓冲区内容显示在屏幕上
			Sleep(10);

			if (mb.stepCount == 60) {
				gameEnding();
				mb.stepCount++;
				//init();
				//break;
			}


		}

		EndBatchDraw(); // 结束批量绘制

	}


	void close() {
		closegraph();
	}

	void gameEnding();
};
