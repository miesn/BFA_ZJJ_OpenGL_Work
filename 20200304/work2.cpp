#include <iostream>
#include <GL/glut.h>
#include <ctime>
using namespace std;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glBegin(GL_POINTS);
	srand((int)time(0));
	for (int i = 0; i < 100; i++) {
		float random1 = (rand() % 10000) / (float)10000;
		float random2 = (rand() % 10000) / (float)10000;
		float random3 = (rand() % 10000) / (float)10000;
		float random4 = (rand() % 20000) / (float)10000 - 1;
		float random5 = (rand() % 20000) / (float)10000 - 1;
		cout << random1 << "," << random2 << "," << random3 << "," << random4 << "," << random5 <<endl;
		glColor3f(random1, random2, random3);
		glVertex2f(random4, random5);
	}
	glEnd();
	glFlush();
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GL Random 100 Point");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
