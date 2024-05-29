#include"page.h"


void page::init() {
	AIplayer = false;
	MCTSboard.initMCTS();
	mb.showSteps();
	initgraph(width, height);

	// 创建页面1 开始目录页面
	IMAGE* page1 = new IMAGE(width, height);//可以直接用loadimage()函数加载图片
	setfillcolor(RGB(240, 240, 240)); // 设置页面1的背景颜色为浅灰色
	solidrectangle(0, 0, width, height); // 绘制页面1的背景矩形
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);

	settextstyle(40, 0, _T("微软雅黑"));
	std::wstring menuTitle = L"Dots And Boxes Game";
	outtextxy(250, 80, menuTitle.c_str());

	getimage(page1, 0, 0, width, height); // 将页面1的内容保存到图片中

	addPage(page1); // 添加页面1

	// 在页面1 目录页面创建按钮1 指向玩法指导文本
	mButton* button1_1 = new mButton(400, 200, 200, 50, L"玩法指导", [&]() {
		setCurrentIndex(1); // 点击按钮1时，切换到页面2
		});
	addButton(0, button1_1); // 将按钮1添加到页面1

	// 在页面1 目录页面创建按钮2 指向基本对战模式
	mButton* button1_2 = new mButton(400, 300, 200, 50, L"基本对战", [&]() {
		setCurrentIndex(2);// 点击按钮2时，执行相关的逻辑
		textBoxs[2][1]->setText(L"左右互搏");
		});
	addButton(0, button1_2); // 将按钮2添加到页面1



	// 在页面1 目录页面创建按钮3 指向人机对战模式
	mButton* button1_3 = new mButton(400, 400, 200, 50, L"人机对战", [&]() {

		setCurrentIndex(2); // 点击按钮3时，执行相关的逻辑
		textBoxs[2][1]->setText(L"人机对战");
		AIplayer = true;
		//MCTSboard.setMCTS(mb);//这行未解析 因为MCTS还没有初始化

		});
	addButton(0, button1_3); // 将按钮3添加到页面1







	// 创建页面2 introduction page
	IMAGE* page2 = new IMAGE(width, height);
	setfillcolor(RGB(240, 240, 240)); // 设置页面2的背景颜色
	solidrectangle(0, 0, width, height); // 绘制页面2的背景矩形
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("微软雅黑"));
	outtextxy(220, 80, menuTitle.c_str());


	settextstyle(30, 0, _T("微软雅黑"));
	std::wstring introText1 = L"先在纸上划上排列为方形的点群，通常采用11x11的方格";
	std::wstring introText2 = L"双方轮流以纵或横方向画一条直线连结两点，但不能画在已被占领区域内";
	std::wstring introText3 = L"当画线使该区域封闭时，在区域内画一个该玩家符号，表示占领";
	std::wstring introText4 = L"当无法再画线时，游戏结束。游戏结束时占领更多区域的玩家获胜。";
	//int introBeginP = 60;把每一行的开始位置设置在60会赏心悦目
	outtextxy(60, 150, introText1.c_str());
	outtextxy(60, 250, introText2.c_str());
	outtextxy(60, 350, introText3.c_str());
	outtextxy(60, 450, introText4.c_str());
	getimage(page2, 0, 0, width, height); // 将页面2的内容保存到图片中

	addPage(page2); // 添加页面2

	// 在页面2创建按钮1
	mButton* button2_1 = new mButton(400, 550, 100, 50, L"返回目录", [&]() {
		setCurrentIndex(0); // 点击按钮1时，切换回页面1
		AIplayer = false;
		});
	addButton(1, button2_1); // 将按钮1添加到页面2






	//创建页面3 下棋界面
	IMAGE* page3 = new IMAGE(width, height);
	setfillcolor(RGB(240, 240, 240)); // 设置页面2的背景颜色
	solidrectangle(0, 0, width, height); // 绘制页面2的背景矩形
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("微软雅黑"));
	outtextxy(0, 0, menuTitle.c_str());

	//画圆点

	setfillcolor(BLACK);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			fillcircle(30 + 100 * i, 40 + 100 * j, 10);//此处数据均为经验数值
		}
	}

	addPage(page3);
	getimage(page3, 0, 0, width, height); // 将页面1的内容保存到图片中


	textBox* textBox3_1 = new textBox(700, 100, 100, 50, L"游戏进行中");

	addTextBox(2, textBox3_1);
	textBoxs[2][0]->setText(L"游戏进行中");

	textBox* textBox3_2 = new textBox(700, 50, 100, 50, L"游戏模式");

	addTextBox(2, textBox3_2);
	//textBoxs[2][1]->setText(L"游戏进行中");

	mButton* button3_0 = new mButton(700, 500, 100, 50, L"返回目录", [&]() {
		setCurrentIndex(0); // 点击按钮1时，切换回页面1
		textBoxs[2][0]->setText(L"游戏进行中");//重置游戏状态文本textboxs[2][0]就是显示游戏状态的文本框
		mb.initBoard();//初始化棋盘

		});
	addButton(2, button3_0); // 将按钮1添加到页面3

	mButton* button3_1 = new mButton(700, 400, 100, 50, L"立刻投降", [&]() {

		std::wstring endWords = mb.showSteps() % 2 != 0 ?
			L"玩家1获胜" : L"玩家2获胜";
		textBoxs[2][0]->setText(endWords);

		});
	addButton(2, button3_1);

	mButton* button3_2 = new mButton(700, 300, 100, 50, L"悔棋", [&]() {

		if (mb.stepCount > 1) {

			if (type_ed) {
				//true==1==改Y
				mb.setBoard(2 * i_ed + 1, 2 * j_ed, 0);


			};
			if (!type_ed)
			{
				//false==0==改X
				mb.setBoard(2 * i_ed, 2 * j_ed + 1, 0);

			};


			mb.setLine(i_ed, j_ed, type_ed,false);
			mb.occupy();
			mb.stepCount--;
		}
		else {
			textBoxs[2][0]->setText(L"退无可退");
			std::cout << "悔棋操作不合法" << std::endl;
		}

		});
	addButton(2, button3_2);

	mButton* button3_3 = new mButton(700, 200, 100, 50, L"完成", [&]() {
		//插入一段
		if (AIplayer) {
			MCTSboard.setMCTS(mb);
			int i = MCTSboard.BestMove().first;
			int j = MCTSboard.BestMove().second;
			mb.boardMatrix[i][j] = 1;

			bool type = i % 2 == 1 ? true : false;
			mb.setLine(i, j, type, true);
			mb.occupy();

			for (int i = 0; i < 6; i++) {
				for (lineSpace::line* ptr : mb.lineX[i]) {
					ptr->print();
				}
			}
			for (int i = 0; i < 5; i++) {
				for (lineSpace::line* ptr : mb.lineY[i]) {
					ptr->print();
				}
			}

			for (int i = 0; i < 5; i++) {
				for (squareSpace::square* ptr : mb.squareB[i]) {
					ptr->print();
				}
			}


		}

		});
	addButton(2, button3_3); // 

	//把这里的NULL空指针改成指向改变board状态函数的指针
	std::vector<std::vector<lineSpace::line*>>
		lineX_(6, std::vector<lineSpace::line*>(5, NULL));
	std::vector<std::vector<lineSpace::line*>>
		lineY_(5, std::vector<lineSpace::line*>(6, NULL));


	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 5; ++j) {
			//第三个第四个参数调节line宽度和高度
			lineX_[i][j] = new lineSpace::line(80 + 100 * j, 40 + 100 * i, 80, 10, [&]() {
				//可以加入其他函数
				});
		}

	}
	mb.lineX = lineX_;


	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			//第三个第四个参数调节line宽度和高度
			lineY_[i][j] = new lineSpace::line(30 + 100 * j, 90 + 100 * i, 10, 80, [&] {

				});
		}
	}
	mb.lineY = lineY_;


	std::vector<std::vector<squareSpace::square*>>
		square_(5, std::vector<squareSpace::square*>(5, NULL));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			square_[i][j] = new squareSpace::square(80 + 100 * i, 90 + 100 * j, 0);
		}
	}
	mb.squareB = square_;






	// 设置初始显示页面为页面1-menu界面
	setCurrentIndex(0);
}







void page::draw() {

	if (currentIndex >= 0 && currentIndex < pages.size())
	{
		putimage(0, 0, pages[currentIndex]); // 在窗口中绘制当前页面的图片

		if (currentIndex >= 0 && currentIndex < buttons.size())
		{
			for (mButton* buttonPtr : buttons[currentIndex])
			{
				buttonPtr->print(); // 绘制当前页面上的所有按钮
			}
		}

		if (currentIndex >= 0 && currentIndex < pages.size()) {

			for (textBox* textPtr : textBoxs[currentIndex]) {

				textPtr->tprint();//绘制当前页面上的所有文本框
			}
		}

		if (currentIndex == 2) {
			for (int i = 0; i < 6; i++) {
				for (lineSpace::line* ptr : mb.lineX[i]) {
					ptr->print();
				}
			}
			for (int i = 0; i < 5; i++) {
				for (lineSpace::line* ptr : mb.lineY[i]) {
					ptr->print();
				}
			}

			for (int i = 0; i < 5; i++) {
				for (squareSpace::square* ptr : mb.squareB[i]) {
					ptr->print();
				}
			}
		}
	}

}

void page::mouseMove(int mouseX, int mouseY) {

	if (currentIndex >= 0 && currentIndex < buttons.size())
	{
		for (mButton* button : buttons[currentIndex])
		{
			button->checkMouseOver(mouseX, mouseY);
		}

	}

	if (currentIndex == 2) {
		for (int i = 0; i < 6; i++) {
			for (lineSpace::line* ptr : mb.lineX[i]) {
				ptr->checkMouseOver(mouseX, mouseY);
			}
		}
		for (int i = 0; i < 5; i++) {
			for (lineSpace::line* ptr : mb.lineY[i]) {
				ptr->checkMouseOver(mouseX, mouseY);
			}
		}

	}

}

void page::mouseClick(int mouseX, int mouseY) {

	if (currentIndex >= 0 && currentIndex < buttons.size())
	{
		for (mButton* button : buttons[currentIndex])
		{
			if (button->checkClick(mouseX, mouseY))
			{
				break;
			}
		}
	}

	if (currentIndex == 2) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++) {
				//i<6 j<5 指针没问题
				lineSpace::line* ptr = mb.lineX[i][j];

				if (ptr->checkClick(mouseX, mouseY)) {
					mb.boardMatrix[2 * i][2 * j + 1] = 1;
					i_ed = i;
					j_ed = j;
					type_ed = 0;
					mb.stepCount++;
					mb.occupy();
				}

			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 6; j++) {
				//i<5 j<6 指针没问题不会溢出
				lineSpace::line* ptr = mb.lineY[i][j];

				if (ptr->checkClick(mouseX, mouseY)) {
					mb.boardMatrix[2 * i + 1][2 * j] = 1;
					i_ed = i;
					j_ed = j;
					type_ed = 1;
					mb.stepCount++;
					mb.occupy();
				}

			}
		}


		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				mb.squareB[i][j]->setOwner(mb.boardMatrix[2 * j + 1][2 * i + 1]);
			}
		}
	}

	mb.drawBoard();

}

void page::gameEnding() {

	std::cout << "ending" << std::endl;

	//page N 's index is N-1

	//UI显示部分
	std::wstring endWords;
	settextcolor(BLACK);
	settextstyle(30, 0, _T("微软雅黑"));

	//数格子
	int square_1 = 0;
	int square_2 = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (mb.boardMatrix[2 * i + 1][2 * j + 1] == 1) {
				square_1++;
			};
			if (mb.boardMatrix[2 * i + 1][2 * j + 1] == 2) {
				square_2++;
			}
		}
	}
	endWords = square_1 > square_2 ? L"玩家1获得胜利" : L"玩家2获得胜利";

	textBoxs[2][0]->setText(endWords);


	std::cout << "a textbox is added" << std::endl;

}