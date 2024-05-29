#pragma once
#include<easyx.h>
namespace squareSpace{

class square {
private:
	int xc, yc;
	int side=84;
	int owner;

public:

	square(int xc,int yc,int owner):xc(xc),yc(yc),owner(owner){}

	int showOwner() {
		return owner;
	}
	void setOwner(int);
	void initSquare();
	void print();

};

}