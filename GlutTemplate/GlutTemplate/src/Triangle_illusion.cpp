//#include <iostream>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 600
//#define screen_Height 400
//
//using namespace std;
//void drawLinef(float x1, float y1, float x2, float y2) {
//	glBegin(GL_LINES);
//	glVertex2f(x1, y1);
//	glVertex2f(x2, y2);
//	glEnd();
//}
//void drawRedTriangle(float x, float y) {
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_TRIANGLES);
//	glVertex2f(x, y);
//	glVertex2f(x + 8, y);
//	glVertex2f(x + 8, y + 3);
//	glEnd();
//}
//void drawDeepBTriangle(float x, float y) {
//	glColor3f(0.0, 0.0, 1.0);
//	glBegin(GL_TRIANGLES);
//	glVertex2f(x, y);
//	glVertex2f(x + 5, y);
//	glVertex2f(x + 5, y + 2);
//	glEnd();
//}
//
//void drawBluePolygon(float x, float y) {
//	glColor3f(12 / 255.0, 244 / 255.0, 252 / 255.0);
//	glBegin(GL_POLYGON);
//	glVertex2f(x, y);
//	glVertex2f(x, y + 1);
//	glVertex2f(x + 5, y + 1);
//	glVertex2f(x + 5, y);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glVertex2f(x + 2, y + 1);
//	glVertex2f(x + 2, y + 2);
//	glVertex2f(x + 5, y + 2);
//	glVertex2f(x + 5, y + 1);
//	glEnd();
//}
//void drawGreenPolygon(float x, float y)
//{
//	glColor3f(0.5, 1.0, 0.0);
//	glBegin(GL_QUADS);
//	glVertex2f(x, y);
//	glVertex2f(x + 2, y);
//	glVertex2f(x + 2, y + 1);
//	glVertex2f(x, y + 1);
//
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glVertex2f(x + 5, y + 1);
//	glVertex2f(x + 5, y + 2);
//	glVertex2f(x, y + 2);
//	glVertex2f(x, y + 1);
//	glEnd();
//}
//void drawGrid(int OrthoX, int OrthoY)
//{
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glLineWidth(2);
//	glColor3f(164 / 255.0, 164 / 255.0, 164 / 255.0);
//	for (int i = 0; i < OrthoX; i++)
//	{
//		drawLinef(i, 0, i, OrthoY);
//	}
//	for (int i = 0; i < OrthoY; i++)
//	{
//		//drawLinef(0, i, i, OrthoX);
//		drawLinef(0, i, OrthoX, i);
//	}
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 0.0, 0.0);
//
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	drawRedTriangle(1, 9);
//	drawRedTriangle(6, 3);
//
//	drawDeepBTriangle(1, 1);
//	drawDeepBTriangle(9, 12);
//
//	drawBluePolygon(9, 9);
//	drawBluePolygon(9, 1);
//
//	drawGreenPolygon(6, 1);
//	drawGreenPolygon(9, 10);
//
//	glColor3f(1.0, 0.0, 1.0);
//	glLineWidth(1);
//	drawLinef(1, 9, 14, 14);
//	drawLinef(1, 1, 14, 6);
//
//
//	//drawGrid(15, 15);
//	glFlush();
//}
//static void init() {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0, 15, 0, 15, 0.0, 1.0);
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