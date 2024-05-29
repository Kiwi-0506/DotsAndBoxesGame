#include"page.h"


void page::init() {
	AIplayer = false;
	MCTSboard.initMCTS();
	mb.showSteps();
	initgraph(width, height);

	// ����ҳ��1 ��ʼĿ¼ҳ��
	IMAGE* page1 = new IMAGE(width, height);//����ֱ����loadimage()��������ͼƬ
	setfillcolor(RGB(240, 240, 240)); // ����ҳ��1�ı�����ɫΪǳ��ɫ
	solidrectangle(0, 0, width, height); // ����ҳ��1�ı�������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);

	settextstyle(40, 0, _T("΢���ź�"));
	std::wstring menuTitle = L"Dots And Boxes Game";
	outtextxy(250, 80, menuTitle.c_str());

	getimage(page1, 0, 0, width, height); // ��ҳ��1�����ݱ��浽ͼƬ��

	addPage(page1); // ���ҳ��1

	// ��ҳ��1 Ŀ¼ҳ�洴����ť1 ָ���淨ָ���ı�
	mButton* button1_1 = new mButton(400, 200, 200, 50, L"�淨ָ��", [&]() {
		setCurrentIndex(1); // �����ť1ʱ���л���ҳ��2
		});
	addButton(0, button1_1); // ����ť1��ӵ�ҳ��1

	// ��ҳ��1 Ŀ¼ҳ�洴����ť2 ָ�������սģʽ
	mButton* button1_2 = new mButton(400, 300, 200, 50, L"������ս", [&]() {
		setCurrentIndex(2);// �����ť2ʱ��ִ����ص��߼�
		textBoxs[2][1]->setText(L"���һ���");
		});
	addButton(0, button1_2); // ����ť2��ӵ�ҳ��1



	// ��ҳ��1 Ŀ¼ҳ�洴����ť3 ָ���˻���սģʽ
	mButton* button1_3 = new mButton(400, 400, 200, 50, L"�˻���ս", [&]() {

		setCurrentIndex(2); // �����ť3ʱ��ִ����ص��߼�
		textBoxs[2][1]->setText(L"�˻���ս");
		AIplayer = true;
		//MCTSboard.setMCTS(mb);//����δ���� ��ΪMCTS��û�г�ʼ��

		});
	addButton(0, button1_3); // ����ť3��ӵ�ҳ��1







	// ����ҳ��2 introduction page
	IMAGE* page2 = new IMAGE(width, height);
	setfillcolor(RGB(240, 240, 240)); // ����ҳ��2�ı�����ɫ
	solidrectangle(0, 0, width, height); // ����ҳ��2�ı�������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("΢���ź�"));
	outtextxy(220, 80, menuTitle.c_str());


	settextstyle(30, 0, _T("΢���ź�"));
	std::wstring introText1 = L"����ֽ�ϻ�������Ϊ���εĵ�Ⱥ��ͨ������11x11�ķ���";
	std::wstring introText2 = L"˫���������ݻ�᷽��һ��ֱ���������㣬�����ܻ����ѱ�ռ��������";
	std::wstring introText3 = L"������ʹ��������ʱ���������ڻ�һ������ҷ��ţ���ʾռ��";
	std::wstring introText4 = L"���޷��ٻ���ʱ����Ϸ��������Ϸ����ʱռ������������һ�ʤ��";
	//int introBeginP = 60;��ÿһ�еĿ�ʼλ��������60��������Ŀ
	outtextxy(60, 150, introText1.c_str());
	outtextxy(60, 250, introText2.c_str());
	outtextxy(60, 350, introText3.c_str());
	outtextxy(60, 450, introText4.c_str());
	getimage(page2, 0, 0, width, height); // ��ҳ��2�����ݱ��浽ͼƬ��

	addPage(page2); // ���ҳ��2

	// ��ҳ��2������ť1
	mButton* button2_1 = new mButton(400, 550, 100, 50, L"����Ŀ¼", [&]() {
		setCurrentIndex(0); // �����ť1ʱ���л���ҳ��1
		AIplayer = false;
		});
	addButton(1, button2_1); // ����ť1��ӵ�ҳ��2






	//����ҳ��3 �������
	IMAGE* page3 = new IMAGE(width, height);
	setfillcolor(RGB(240, 240, 240)); // ����ҳ��2�ı�����ɫ
	solidrectangle(0, 0, width, height); // ����ҳ��2�ı�������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, _T("΢���ź�"));
	outtextxy(0, 0, menuTitle.c_str());

	//��Բ��

	setfillcolor(BLACK);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			fillcircle(30 + 100 * i, 40 + 100 * j, 10);//�˴����ݾ�Ϊ������ֵ
		}
	}

	addPage(page3);
	getimage(page3, 0, 0, width, height); // ��ҳ��1�����ݱ��浽ͼƬ��


	textBox* textBox3_1 = new textBox(700, 100, 100, 50, L"��Ϸ������");

	addTextBox(2, textBox3_1);
	textBoxs[2][0]->setText(L"��Ϸ������");

	textBox* textBox3_2 = new textBox(700, 50, 100, 50, L"��Ϸģʽ");

	addTextBox(2, textBox3_2);
	//textBoxs[2][1]->setText(L"��Ϸ������");

	mButton* button3_0 = new mButton(700, 500, 100, 50, L"����Ŀ¼", [&]() {
		setCurrentIndex(0); // �����ť1ʱ���л���ҳ��1
		textBoxs[2][0]->setText(L"��Ϸ������");//������Ϸ״̬�ı�textboxs[2][0]������ʾ��Ϸ״̬���ı���
		mb.initBoard();//��ʼ������

		});
	addButton(2, button3_0); // ����ť1��ӵ�ҳ��3

	mButton* button3_1 = new mButton(700, 400, 100, 50, L"����Ͷ��", [&]() {

		std::wstring endWords = mb.showSteps() % 2 != 0 ?
			L"���1��ʤ" : L"���2��ʤ";
		textBoxs[2][0]->setText(endWords);

		});
	addButton(2, button3_1);

	mButton* button3_2 = new mButton(700, 300, 100, 50, L"����", [&]() {

		if (mb.stepCount > 1) {

			if (type_ed) {
				//true==1==��Y
				mb.setBoard(2 * i_ed + 1, 2 * j_ed, 0);


			};
			if (!type_ed)
			{
				//false==0==��X
				mb.setBoard(2 * i_ed, 2 * j_ed + 1, 0);

			};


			mb.setLine(i_ed, j_ed, type_ed,false);
			mb.occupy();
			mb.stepCount--;
		}
		else {
			textBoxs[2][0]->setText(L"���޿���");
			std::cout << "����������Ϸ�" << std::endl;
		}

		});
	addButton(2, button3_2);

	mButton* button3_3 = new mButton(700, 200, 100, 50, L"���", [&]() {
		//����һ��
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

	//�������NULL��ָ��ĳ�ָ��ı�board״̬������ָ��
	std::vector<std::vector<lineSpace::line*>>
		lineX_(6, std::vector<lineSpace::line*>(5, NULL));
	std::vector<std::vector<lineSpace::line*>>
		lineY_(5, std::vector<lineSpace::line*>(6, NULL));


	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 5; ++j) {
			//���������ĸ���������line��Ⱥ͸߶�
			lineX_[i][j] = new lineSpace::line(80 + 100 * j, 40 + 100 * i, 80, 10, [&]() {
				//���Լ�����������
				});
		}

	}
	mb.lineX = lineX_;


	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			//���������ĸ���������line��Ⱥ͸߶�
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






	// ���ó�ʼ��ʾҳ��Ϊҳ��1-menu����
	setCurrentIndex(0);
}







void page::draw() {

	if (currentIndex >= 0 && currentIndex < pages.size())
	{
		putimage(0, 0, pages[currentIndex]); // �ڴ����л��Ƶ�ǰҳ���ͼƬ

		if (currentIndex >= 0 && currentIndex < buttons.size())
		{
			for (mButton* buttonPtr : buttons[currentIndex])
			{
				buttonPtr->print(); // ���Ƶ�ǰҳ���ϵ����а�ť
			}
		}

		if (currentIndex >= 0 && currentIndex < pages.size()) {

			for (textBox* textPtr : textBoxs[currentIndex]) {

				textPtr->tprint();//���Ƶ�ǰҳ���ϵ������ı���
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
				//i<6 j<5 ָ��û����
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
				//i<5 j<6 ָ��û���ⲻ�����
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

	//UI��ʾ����
	std::wstring endWords;
	settextcolor(BLACK);
	settextstyle(30, 0, _T("΢���ź�"));

	//������
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
	endWords = square_1 > square_2 ? L"���1���ʤ��" : L"���2���ʤ��";

	textBoxs[2][0]->setText(endWords);


	std::cout << "a textbox is added" << std::endl;

}