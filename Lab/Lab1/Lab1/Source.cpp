//#include<iostream>
//#include<math.h>
//#include <GL/glut.h>
//#define PI 3.14159265359
//#define DEG2RAD PI/180.0
//using namespace std;
//void myDisplay() {
//	float R = 1;
//
//	float x, y;
//	glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
//	glPointSize(2);
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_POINTS);
//	for (int i = 0; i <= 360; i += 10)
//	{
//		x = R * cos(PI / 2 + i * 2 * PI / 36);
//		y = R * sin(PI / 2 + i * 2 * PI / 36);
//		glVertex2f(x, y);
//		
//	}
//	glEnd();
//	glFlush();
//}
//void init() {
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-1, 1, -1, 1);
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