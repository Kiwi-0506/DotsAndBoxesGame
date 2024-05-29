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




//MCTNode代表蒙特卡洛树中的一个节点
class MCTSNode :public board{
public:
	MCTSNode(std::vector<std::vector<int>>& boardMatrix);     //初始化字节点

	void AddChild(std::unique_ptr<MCTSNode> child);    // 添加子节点

	int visits; // 访问次数
	int score; // 累计分数

	std::vector<std::vector<int>> CBboardMatrix; // 当前棋盘状态矩阵
	std::vector<std::unique_ptr<MCTSNode>> children; // 指向子节点的智能指针，和该子节点共存亡
};


class MCTS :public board{
public:
	void setMCTS(board&); //蒙特卡洛树搜索类的设置函数
	void initMCTS();

	void DoIteration();  //MCT迭代函数，执行一次包括选择、模拟、回溯三个阶段

	//int BestMove();  // 选择最佳下棋位置
	std::pair<int,int> BestMove();  // 选择最佳下棋位置

private:
	std::unique_ptr<MCTSNode> root;    //指向根节点的智能指针

	// 选择函数
	//MCTSNode* Selection(const std::vector<std::vector<int>>& boardMatrix);
	MCTSNode* Selection();

	// 模拟函数（简化版）
	//int Simulation(const std::vector<std::vector<int>>& boardMatrix);
	int Simulation();

	// 回溯函数 回到最后遇到的分叉节点
	void Backpropagation(MCTSNode* node, int score);

	// 获取最佳子节点
	MCTSNode* bestChild(MCTSNode* node, double C);

	// 判断是否为终止节点
	bool IsTerminalNode(MCTSNode* node);

	// MCTS评估函数
	//int GetMCEvaluation(const std::vector<std::vector<int>>& boardMatrix);
	//int GetMCEvaluation();
	
	int GetBoardWinner();
	int GetFreeEdgeNum();
	int GetMCWinner(int);
	float GetMCEvalution(int, int, int);
	// 常数C用于调试
	const double C = 1.0;
};



/*使用示例
int main() {
	std::vector<std::vector<int>> boardMatrix = {
		...
	};

	MCTS mcts(boardMatrix);

	// 进行N次迭代
	int iterations = 1000;
	for (int i = 0; i < iterations; ++i) {
		mcts.DoIteration();
	}

	// 选择最佳动作
	int bestMove = mcts.BestMove();
	std::cout << "Best move: " << bestMove << std::endl;

	return 0;
}
*/