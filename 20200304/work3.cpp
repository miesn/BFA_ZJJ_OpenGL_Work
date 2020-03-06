#include <iostream>
#include <GL/glut.h>
#include <ctime>
using namespace std;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-.8f, -.2f);
	glVertex2f(-.4f, -.2f);
	glVertex2f(-.6f, .2f);
	glColor3f(0, 1, 0);
	glVertex2f(-.3f, -.2f);
	glVertex2f(.1f, -.2f);
	glVertex2f(-.1f, .2f);
	glColor3f(0, 0, 1);
	glVertex2f(.2f, -.2f);
	glVertex2f(.6f, -.2f);
	glVertex2f(.4f, .2f);
	glEnd();
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GL 3 Triangles");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
