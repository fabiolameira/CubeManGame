#include <gl/glut.h>

class Pacman {
public:
	
	int speed;
	double angle; //Anglo de rotacao necess�ria em x e em y em graus multiplos de 90
	bool animate;

	Pacman(int, int);

	void draw();

	void move(); //move the pacman

	void reinit();  //reinitialize everything

};