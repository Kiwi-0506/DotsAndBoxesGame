#pragma once
#include <memory>
#include <cstdlib>
#include <ctime>
#include"board.h"
#include"player.h"
#include"RandomTurn.h"
#include"board.h"
//int GetBoardWinner();

//int GetMCWinner(board& CB, int NextPlayer);

//float GetMCEvalution(board& CB, int NextPlayer, int Winner, int TIMES);




//MCTNode�������ؿ������е�һ���ڵ�
class MCTSNode :public board{
public:
	MCTSNode(std::vector<std::vector<int>>& boardMatrix);     //��ʼ���ֽڵ�

	void AddChild(std::unique_ptr<MCTSNode> child);    // ����ӽڵ�

	int visits; // ���ʴ���
	int score; // �ۼƷ���

	std::vector<std::vector<int>> CBboardMatrix; // ��ǰ����״̬����
	std::vector<std::unique_ptr<MCTSNode>> children; // ָ���ӽڵ������ָ�룬�͸��ӽڵ㹲����
};


class MCTS :public board{
public:
	void setMCTS(board&); //���ؿ���������������ú���
	void initMCTS();

	void DoIteration();  //MCT����������ִ��һ�ΰ���ѡ��ģ�⡢���������׶�

	//int BestMove();  // ѡ���������λ��
	std::pair<int,int> BestMove();  // ѡ���������λ��

private:
	std::unique_ptr<MCTSNode> root;    //ָ����ڵ������ָ��

	// ѡ����
	//MCTSNode* Selection(const std::vector<std::vector<int>>& boardMatrix);
	MCTSNode* Selection();

	// ģ�⺯�����򻯰棩
	//int Simulation(const std::vector<std::vector<int>>& boardMatrix);
	int Simulation();

	// ���ݺ��� �ص���������ķֲ�ڵ�
	void Backpropagation(MCTSNode* node, int score);

	// ��ȡ����ӽڵ�
	MCTSNode* bestChild(MCTSNode* node, double C);

	// �ж��Ƿ�Ϊ��ֹ�ڵ�
	bool IsTerminalNode(MCTSNode* node);

	// MCTS��������
	//int GetMCEvaluation(const std::vector<std::vector<int>>& boardMatrix);
	//int GetMCEvaluation();
	
	int GetBoardWinner();
	int GetFreeEdgeNum();
	int GetMCWinner(int);
	float GetMCEvalution(int, int, int);
	// ����C���ڵ���
	const double C = 1.0;
};



/*ʹ��ʾ��
int main() {
	std::vector<std::vector<int>> boardMatrix = {
		...
	};

	MCTS mcts(boardMatrix);

	// ����N�ε���
	int iterations = 1000;
	for (int i = 0; i < iterations; ++i) {
		mcts.DoIteration();
	}

	// ѡ����Ѷ���
	int bestMove = mcts.BestMove();
	std::cout << "Best move: " << bestMove << std::endl;

	return 0;
}
*/