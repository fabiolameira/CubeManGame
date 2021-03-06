#include <gl/glut.h>
#include "Pacman.h"
#include <math.h>
extern const int TAB_SIZE;
extern const int CELL_SIZE;
Pacman::Pacman() {
	this->cube = Cube(1, 1, 0);
	this->x = 0;
	this->y = 0;
	this->scale = 0.8;
	this->index = 0;
	this->direction = 0;
}

void Pacman::translatePosition() {
	glTranslatef(-(TAB_SIZE * CELL_SIZE) / 2, -(TAB_SIZE * CELL_SIZE) / 2, CELL_SIZE / 2);
	glTranslatef(this->x * CELL_SIZE + CELL_SIZE / 2, this->y * CELL_SIZE + CELL_SIZE / 2, 0);
}

void Pacman::draw() {
	glPushMatrix();
	translatePosition();
	glScalef(this->scale, this->scale, 1);
	this->cube.draw();
	glPopMatrix();
}

void Pacman::randomPosition(Board board) {
	bool exist = false;
	while (!exist) {
		this->x = rand() % TAB_SIZE;
		this->y = rand() % TAB_SIZE;
		exist = board.haveCube(this->x, this->y);
	}
}
void Pacman::move(Board board) {
	switch (this->direction) {
	case GLUT_KEY_UP:
		if (this->y != TAB_SIZE - 1 && board.haveCube(floor(this->x), floor(this->y + 1))) {
			this->y+=0.1;
		}
		break;
	case GLUT_KEY_DOWN:
		if (this->y > 0 && board.haveCube(floor(this->x), ceil(this->y) - 1)) {
			this->y-=0.1;
		}
		break;
	case GLUT_KEY_RIGHT:
		if (this->x != TAB_SIZE - 1 && board.haveCube(floor(this->x) + 1, floor(this->y))) {
			this->x+=0.1;
		}
		break;
	case GLUT_KEY_LEFT:
		if (this->x > 0 && board.haveCube(ceil(this->x) - 1, floor(this->y))){
			this->x-=0.1;
		}
		break;
	}
}
bool Pacman::loseValidator(int xGhosts, int yGhosts) {
	if (this->x == xGhosts && this->y == yGhosts) {
		return true;
	}
	else if (this->x == xGhosts + 1 && this->y == yGhosts) {
		return true;
	}
	else if (this->x == xGhosts - 1 && this->y == yGhosts) {
		return true;
	}
	else if (this->x == xGhosts && this->y == yGhosts - 1) {
		return true;
	}
	else if (this->x == xGhosts && this->y == yGhosts - 1) {
		return true;
	}
	else {
		return false;
	}

}