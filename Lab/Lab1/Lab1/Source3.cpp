#include<iostream>
#include<vector>
#include<math.h>
#include <GL/glut.h>
#define PI 3.14159265359
#define DEG2RAD PI/180.0
using namespace std;
float angle=1;

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	float R = 1.0;

	float x, y;
	
	float angle2, angle3;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2);
	
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2);
	int k = 0;

	

	//Use For if you want, i'm too lazy for that ~.~, doing the tutorial way
	glBegin(GL_TRIANGLES);
	x = R * cos(DEG2RAD*angle);
	y = R * sin(DEG2RAD*angle);
	glVertex2f(0.0, 0.0);
	glVertex2f(x, y);
	x = R * cos(DEG2RAD*(angle + 20));
	y = R * sin(DEG2RAD*(angle + 20));
	glVertex2f(x, y);
	glEnd();

	angle2 = angle + 120;
	x = R * cos(DEG2RAD*(angle2));
	y = R * sin(DEG2RAD*(angle2));
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.0);
	glVertex2f(x, y);
	x = R * cos(DEG2RAD*(angle2 + 20));
	y = R * sin(DEG2RAD*(angle2 + 20));
	glVertex2f(x, y);
	glEnd();

	angle3 = angle + 240;
	x = R * cos(DEG2RAD*(angle3));
	y = R * sin(DEG2RAD*(angle3));
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.0);
	glVertex2f(x, y);
	x = R * cos(DEG2RAD*(angle3 + 20));
	y = R * sin(DEG2RAD*(angle3 + 20));
	glVertex2f(x, y);
	glEnd();
	
	
	glFlush();
	glutSwapBuffers(); //Combo with the glClearColor(GL_COLOR_BUFFER_BIT);
}
void init() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.5, 1.5, -1.5, 1.5);

}
void processTimer(int value)
{
	angle += (float)value;
	if (angle > 360) angle -= 360;

	glutTimerFunc(100, processTimer, 10);
	glutPostRedisplay();
}
int main() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Lab1");
	init();
	glutDisplayFunc(myDisplay);
	glutTimerFunc(100, processTimer, 10);
	glutMainLoop();

}