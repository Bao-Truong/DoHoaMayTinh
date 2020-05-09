//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 640
//#define screen_Height 480
//#define PI 3.14159265359
//using namespace std;
//struct point2d {
//	float x;
//	float y;
//};
//void triangle(float *a, float*b, float*c)
//{
//	glVertex2fv(a);
//	glVertex2fv(b);
//	glVertex2fv(c);
//}
//void divide_triangle(float *a, float *b, float*c, int n = 4) {
//	float v0[2], v1[2], v2[2];
//	if (n> 0)
//	{
//		for (int i = 0; i < 2; i++) v0[i] = (a[i] + b[i]) / 2;
//		for (int i = 0; i < 2; i++) v1[i] = (a[i] + c[i]) / 2;
//		for (int i = 0; i < 2; i++) v2[i] = (c[i] + b[i]) / 2;
//		divide_triangle(a, v0, v1, n - 1);
//		divide_triangle(b, v0, v2, n - 1);
//		divide_triangle(c, v2, v1, n - 1);
//	}
//	else {
//		triangle(a, b, c);
//	}
//}
//void drawLine(point2d a, point2d  b) {
//	glBegin(GL_LINES);
//	glVertex2f(a.x, a.y);
//	glVertex2f(b.x, b.y);
//	glEnd();
//}
//static  void drawPoint(point2d p) {
//	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
//	glPointSize(5);
//	glBegin(GL_POINTS);
//	glVertex2f(p.x, p.y);
//	glEnd();
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 0.0, 0.0);
//	float v[3][2] = {
//		{-1.0,-0.58},
//	{1.0,-0.58},
//	{0.0,1.15}
//	};
//	glBegin(GL_TRIANGLES);
//	divide_triangle(v[0],v[1],v[2],4);
//	glEnd();
//	glFlush();
//}
//static void init() {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-2,2,-2,2, 0.0, 1.0);
//	glClearColor(1.0, 1.0, 1.0, 1);
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//
//	glutMainLoop();
//}