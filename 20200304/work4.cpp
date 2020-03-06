#include <iostream>
#include <GL/glut.h>
#include <ctime>
using namespace std;
const GLfloat factor = 0.1f;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloat x;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (x = -1.0f / factor; x < 1.0f / factor; x += 0.01f) {
		glVertex2f(x * factor, sin(x) * factor);
	}
	glEnd();
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GL Test");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
