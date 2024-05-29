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
	//����洢��
	bool type_ed = 0;//0������һ���ǵ���x������ߣ�1������һ������y�������
	int i_ed, j_ed;//������int��¼һ����һ�������Ǹ�λ�ã�Ȼ����һ��α����

	//ҳ��洢��
	std::vector <IMAGE*> pages; // �洢����ҳ���ͼƬָ��
	std::vector<std::vector<mButton*>> buttons; // �洢ÿ��ҳ���ϵİ�ťָ��
	std::vector<std::vector<textBox*>> textBoxs;// �洢ÿ��ҳ���϶�̬�仯�ı���ָ��

	//�������� board������ʵ�ֽ��� MCTS������ʵ������
	board mb;
	MCTS MCTSboard;
	
public:
	//���һ��ҳ��
	void addPage(IMAGE* page)
	{
		pages.push_back(page);
		buttons.push_back({});
		textBoxs.push_back({});
	}

	// ��ָ��ҳ�������һ����ť
	void addButton(int index, mButton* button)
	{
		if (index >= 0 && index < buttons.size())
		{
			buttons[index].push_back(button);
		}
	}

	//��ָ��ҳ�������һ����̬�ı���
	void addTextBox(int index, textBox* textBox) {

		if (index >= 0 && index < textBoxs.size()) {

			textBoxs[index].push_back(textBox);
		}
	}


	// ���õ�ǰ��ʾ��ҳ������
	void setCurrentIndex(int index)
	{
		if (index >= 0 && index < pages.size())
		{
			currentIndex = index;
		}
	}

	// ����������¼�
	void mouseClick(int mouseX, int mouseY);


	// ��������ƶ��¼�
	void mouseMove(int mouseX, int mouseY);



	// ���Ƶ�ǰҳ�������
	void draw();


	page(int width, int height)
		:width(width), height(height), currentIndex(-1)
	{}
	~page() {}

	// ��ʼ���ؼ�������ͼ�λ���������ҳ��Ͱ�ť
	void init();

	//����Ŀǰ���ߵĲ���
	int showSteps() {
		return mb.stepCount;
	}

	// ���У�������Ϣѭ��
	void run()
	{
		ExMessage msg;

		

		BeginBatchDraw(); // ��ʼ��������

		while (true)
		{

			

			if (peekmessage(&msg)) // ����Ƿ�����Ϣ
			{
				int mouseX = msg.x; // ��ȡ���x����
				int mouseY = msg.y; // ��ȡ���y����

				switch (msg.message)
				{
				case WM_LBUTTONDOWN: // �����������¼�

					

					mouseClick(mouseX, mouseY); // ����������¼�

					

					break;
				case WM_MOUSEMOVE: // ����ƶ��¼�
					mouseMove(mouseX, mouseY); // ��������ƶ��¼�


					break;
				}
			}



			draw(); // ���Ƶ�ǰҳ������
			FlushBatchDraw(); // ��������������ʾ����Ļ��
			Sleep(10);

			if (mb.stepCount == 60) {
				gameEnding();
				mb.stepCount++;
				//init();
				//break;
			}


		}

		EndBatchDraw(); // ������������

	}


	void close() {
		closegraph();
	}

	void gameEnding();
};
