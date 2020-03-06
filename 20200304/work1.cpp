#include <iostream>
#include <GL/glut.h>
#include <ctime>
using namespace std;
const GLfloat PI = 3.14159265357f;

void display() {
	GLfloat a = 1 / (2 - 2 * cos(72 * PI / 180));
	GLfloat bx = a * cos(18 * PI / 180);
	GLfloat by = a * sin(18 * PI / 180);
	GLfloat cy = -a * cos(18 * PI / 180);
	GLfloat pointB[2] = { bx, by },
		pointC[2] = { 0.5, cy },
		pointD[2] = { -0.5, cy },
		pointE[2] = { -bx, by },
		pointA[2] = { 0,a };
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2fv(pointA);
	glVertex2fv(pointC);
	glVertex2fv(pointE);
	glVertex2fv(pointB);
	glVertex2fv(pointD);
	glVertex2fv(pointA);
	glEnd();
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GL Star");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
