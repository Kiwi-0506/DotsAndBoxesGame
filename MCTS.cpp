#include "MCTS.h"
//board CB;

void MCTS::setMCTS(board& mb) {
	boardMatrix = mb.boardMatrix;
	std::cout << "���ؿ������������Ѿ���ͬ��"<<std::endl;
}

void MCTS::initMCTS() {
	std::vector<std::vector<int>> matrix(boardSize, std::vector<int>(boardSize, 0));
	boardMatrix = matrix;//����һ������λ�ö���0�ľ���
	
}

int MCTS::GetBoardWinner() {
	int square_1 = 0;
	int square_2 = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (boardMatrix[2 * i + 1][2 * j + 1] == 1) {
				square_1++;
			};
			if (boardMatrix[2 * i + 1][2 * j + 1] == 2) {
				square_2++;
			}
		}
	}
	int winner = square_1 > square_2 ? 1 : -1;	//���2����ֵ��ʾΪ-1�����㽻����Ȩ
	return winner;
}

int MCTS::GetFreeEdgeNum()
{
	int freelines = 0;
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if ((i % 2 == 0 && j % 2 != 0 && boardMatrix[i][j] == 0) ||   //�ж�������RandomTurn����ͬ
				(i % 2 != 0 && j % 2 == 0 && boardMatrix[i][j] == 0)) {	 //�������ż�к�ż������		
				freelines++;
			}
		}
		return freelines;
	}
}

int MCTS::GetMCWinner(int NextPlayer)
{
	int player = NextPlayer;
	while (GetFreeEdgeNum() != 0) // �����������ɱߵ�ʱ��
	{
		RandomTurn();
		player = -player;    // ������Ȩ
	}
	int W = GetBoardWinner();
	return W;
}

float MCTS::GetMCEvalution(int NextPlayer=1, int Winner=1, int TIMES=1000) {	//TIMESΪģ�����
	//board MCB = CB;
	int MCE = 0;
	for (int i = 0; i < TIMES; i++) {
		if (GetMCWinner(NextPlayer) == 1) {
			MCE++;
		}
	}
	float MCsocore = ((float)MCE) / ((float)TIMES);//�õ����ؿ����ֵ
	return MCsocore;
}

//MCTS��ĳ�ʼ��
MCTSNode::MCTSNode(std::vector<std::vector<int>>& boardMatrix_) : visits(0), score(0) {
	boardMatrix = boardMatrix_;
};

void MCTSNode::AddChild(std::unique_ptr<MCTSNode> child) {
	children.push_back(std::move(child));
}
void MCTS::DoIteration() {
	MCTSNode* current = Selection();
	//int score = Simulation(current->boardMatrix);
	int score = Simulation();
	Backpropagation(current, score);
}
std::pair<int,int> MCTS::BestMove() {
	/*
	int bestScore = -1e9;
	int bestMove = -1;
	for (size_t i = 0; i < root->children.size(); ++i) {
		if (root->children[i]->score / root->children[i]->visits > bestScore) {
			bestScore = root->children[i]->score / root->children[i]->visits;
			bestMove = i;
		}
	}
	return empty_cells[bestMove];
	*/

	return std::pair<int,int>(0, 1);
}

MCTSNode*  MCTS:: Selection() {
	MCTSNode* current = root.get();//��һ��ʲô�﷨
	while (!IsTerminalNode(current) && !current->children.empty()) //ȷ�����ӽڵ�
	{
		current = bestChild(current, C);//�ݹ�Ѱ��
	}
	return current;
}

//?
int MCTS::Simulation() {
	return GetMCEvalution();//����ǿ��ת�� ������һ��float���� �����һ��int����
}

void MCTS::Backpropagation(MCTSNode* node, int score) {
	while (node != nullptr) {
		node->visits += 1;
		node->score += score;
		//node = node->parent.get();
		//node = node->root;
		//��ע�͵���������

	}
}

MCTSNode* MCTS::bestChild(MCTSNode* node, double C) {
	double bestScore = -1e9;//
	MCTSNode* bestChild = nullptr;
	for (const auto& child : node->children) {
		double exploitation = child->score / child->visits;
		double exploration = C * sqrt(log(node->visits) / child->visits);
		double score = exploitation + exploration;
		if (score > bestScore) {
			bestScore = score;
			bestChild = child.get();
		}
	}
	return bestChild;
};

// �ж��Ƿ�Ϊ��ֹ�ڵ�
bool MCTS::IsTerminalNode(MCTSNode* node) {
	// ������Ҫ���ݾ�����Ϸ����ʵ��
	return false;
}
