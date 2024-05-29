#include"square.h"

using namespace squareSpace;


void square::initSquare() {

	owner = 0;

}

void square::setOwner(int owner) {
	this->owner = owner;
}

void square::print() {

	switch (owner) {
	case(0): {
		setfillcolor(RGB(240, 240, 240));
		setlinecolor(BLACK);

		fillrectangle(xc - side / 2, yc - side / 2,
			xc + side / 2, yc + side / 2);
		break;
	}
	case(1): {

		setfillcolor(RGB(102,8,116));
		setlinecolor(RGB(102,8,116));

		fillrectangle(xc - side / 2, yc - side / 2,
			xc + side / 2, yc + side / 2);
		break;
	}
	case(2): {

		setfillcolor(RGB(139, 0, 18));
		setlinecolor(RGB(139, 0, 18));

		fillrectangle(xc - side / 2, yc - side / 2,
			xc + side / 2, yc + side / 2);
		break;
	}

	}



}