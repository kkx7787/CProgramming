#include <iostream>
#include <gl/glut.h>

void displayFunc() {

	double rad1 = 0.2;
	double rad2 = 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);

	glVertex3f(-0.2f, 0.7f, 0.0f);
	glVertex3f(0.2f, 0.7f, 0.0f);
	glVertex3f(0.2f, 0.6f, 0.0f);
	glVertex3f(-0.2f, 0.6f, 0.0f);

	glVertex3f(-0.4f, 0.5f, 0.0f);
	glVertex3f(0.4f, 0.5f, 0.0f);
	glVertex3f(0.4f, 0.4f, 0.0f);
	glVertex3f(-0.4f, 0.4f, 0.0f);

	glVertex3f(0.6f, 0.6f, 0.0f);
	glVertex3f(0.7f, 0.6f, 0.0f);
	glVertex3f(0.7f, -0.4f, 0.0f);
	glVertex3f(0.6f, -0.4f, 0.0f);

	glVertex3f(0.7f, 0.0f, 0.0f);
	glVertex3f(0.8f, 0.0f, 0.0f);
	glVertex3f(0.8f, 0.1f, 0.0f);
	glVertex3f(0.7f, 0.1f, 0.0f);

	glVertex3f(-0.1f, -0.3f, 0.0f);
	glVertex3f(0.1f, -0.3f, 0.0f);
	glVertex3f(0.1f, -0.5f, 0.0f);
	glVertex3f(-0.0f, -0.5f, 0.0f);



	glEnd();

	glBegin(GL_LINES);
	for (int i = 0; i < 360; i++)
	{
		double angle = i * 3.141592 / 180;
		double x = rad2 * cos(angle);
		double y = rad2 * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		double angle = i * 3.141592 / 180;
		double x = rad1 * cos(angle);
		double y = rad1 * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutCreateWindow("draw example");
	glutDisplayFunc(displayFunc);
	glutMainLoop();

	return 0;
}