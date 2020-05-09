//#include<iostream>
//#include<vector>
//#include<math.h>
//#include <GL/glut.h>
//#define PI 3.14159265359
//#define DEG2RAD PI/180.0
//using namespace std;
//
//
//void myDisplay() {
//	float R = 1.0;
//
//	float x, y;
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glLineWidth(2);
//	glColor3f(1.0, 0.0, 0.0);
//	glPointSize(2);
//	int k = 0;
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(0.0, 0.0);
//	for (int i = 0; i < 360; i += 10)
//	{
//		x = R * cos(DEG2RAD*(180.0 / 2 + i));
//		y = R * sin(DEG2RAD*(180.0 / 2 + i));
//		cout << "(" << x << "," << y << ")" << endl;
//		glVertex2f(x, y);
//		k++;
//	}
//	x = R * cos(DEG2RAD*(180.0 / 2 + 0));
//	y = R * sin(DEG2RAD*(180.0 / 2 + 0));
//	glVertex2f(x, y);
//	glEnd();
//
//	glFlush();
//}
//void init() {
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
//
//}
//int main() {
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Lab1");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutMainLoop();
//
//}