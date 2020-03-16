#include <iostream>
#include<gl/glut.h>
using namespace std;

int snakeLenth = 2;
int snakeHead = 5;
int gridDensity = 10;
int speed = 1;
bool ifPause = false;

void drawGrid(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	for (int i = 1; i < 500 / gridDensity; i++) {
		glBegin(GL_LINES);
		GLfloat x = i * gridDensity;
		GLfloat pointA[2] = { x,0 };
		GLfloat pointB[2] = { x,100 };
		glVertex2fv(pointA);
		glVertex2fv(pointB);
		glEnd();
	}
	for (int i = 1; i < 100 / gridDensity; i++) {
		glBegin(GL_LINES);
		GLfloat x = i * gridDensity;
		GLfloat pointA[2] = { 0,x };
		GLfloat pointB[2] = { 500,x };
		glVertex2fv(pointA);
		glVertex2fv(pointB);
		glEnd();
	}
}

void drawSnake(int xx, int yy) {
	for (int i = 0; i < snakeLenth; i++) {
		GLfloat x = (xx + i) * gridDensity;
		GLfloat y = yy * gridDensity;
		while (x >= 500) {
			x = x - 500;
			snakeHead = snakeHead - 500 / gridDensity;
		}
		glBegin(GL_QUADS);
		GLfloat pointA[2] = { x,y };
		GLfloat pointB[2] = { x + gridDensity,y };
		GLfloat pointC[2] = { x + gridDensity,y + gridDensity };
		GLfloat pointD[2] = { x,y + gridDensity };
		glVertex2fv(pointA);
		glVertex2fv(pointB);
		glVertex2fv(pointC);
		glVertex2fv(pointD);
		glEnd();
	}
}


void renderWindow(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake(snakeHead, 5);
	glFlush();
}

void refreshWindow(int id) {
	if (ifPause == true) {
		
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT);
		snakeHead = snakeHead + speed;
		cout << "Head:" << snakeHead << ",Speed:" << speed << endl;
		drawGrid();
		drawSnake(snakeHead, 5);
		glFlush();
	}
	glutTimerFunc(100, refreshWindow, 1);
}

void keyEvent(unsigned char key, int x, int y) {
	if (key == 32) {
		ifPause = !ifPause;
	}
	if (key == 82 || key == 114) {
		snakeHead = 5;
	}
}

void specKeyEvent(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) {
		if (speed >= 1) {
			speed--;
		}
	}
	if (key == GLUT_KEY_RIGHT) {
		if (speed <= 10) {
			speed++;
		}
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(1, 1);
	glutInitWindowSize(500, 100);
	glutCreateWindow("Hello Snake!");
	gluOrtho2D(0, 500, 0, 100);
	glutDisplayFunc(&renderWindow);
	glutTimerFunc(100, refreshWindow, 1);
	glutKeyboardFunc(keyEvent);
	glutSpecialFunc(specKeyEvent);
	glutMainLoop();
	return 0;
}