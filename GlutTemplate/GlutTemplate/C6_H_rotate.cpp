//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 12*50
//#define screen_Height 16*50
//#define PI 3.14159265359
//#define DEC2RAG PI/180.0
//using namespace std;
//float factor = 8;
//float m[16];
//float v0[12][2] = {
//	{0,0},{0,2},{0.6,2},
//	{0.6,1.2},{1.4,1.2},{1.4,2},
//	{2,2},{2,0},{1.4,0},
//	{1.4,0.8},{0.6,0.8},{0.6,0},
//};
//void printmat(float m[16])
//{
//	for (int i = 0; i < 4; i++)
//		cout << m[i] << " " << m[i + 4] << " " << m[i + 8] << " " << m[i + 12] << endl;
//};
//void drawGrid() {
//	glColor3f(0.5, 0.5, 0.5);
//	glLineWidth(1);
//	glBegin(GL_LINES);
//	for (int x = -8; x <= 8; x++)
//	{
//		glVertex2f(x, -1);
//		glVertex2f(x, 11);
//	}
//	for (int y = -1; y <= 11; y++)
//	{
//		glVertex2f(-8, y);
//		glVertex2f(8, y);
//	}
//
//	glEnd();
//}
//void myReshape(int w, int h) {
//
//	glViewport(0, 0, w, h); //Kéo dãn theo màn hình thay đổi, có thể sẽ mất hình dạng ban đầu( hình cầu kéo ngang qua thì bị dãn)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-8, 8, -1 * h / w, 11 * h / w, -10.0, 10.0);
//	else
//		glOrtho(-8 * w / h, 8 * w / h, -1, 11, -10.0, 10.0);
//}
//void drawFigure0()
//{
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < 12; i++)
//	{
//		glVertex2fv(v0[i]);
//	}
//	glEnd();
//}
//void drawFigure1() {
//	float v1[12][2];
//	for (int i = 0; i < 12; i++)
//	{
//		v1[i][0] = v0[i][0] * cos(PI / 3) - v0[i][1] * sin(PI / 3) + 4;
//		v1[i][1] = v0[i][0] * sin(PI / 3) + v0[i][1] * cos(PI / 3) + 5;
//	}
//	glColor3f(0, 0, 1);
//
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < 12; i++)
//	{
//		glVertex2fv(v1[i]);
//	}
//	glEnd();
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	drawGrid();
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glColor3f(1.00, 0.0, 0.0);
//	drawFigure0();
//
//
//	glPushMatrix();
//	{
//		glColor3f(0, 0, 1);
//		glTranslatef(4.0, 5.0, 0);
//		glRotatef(60.0, 0, 0, 1.0);		
//		
//		glGetFloatv(GL_MODELVIEW_MATRIX, m);
//		printmat(m);
//		drawFigure0();
//	}
//	glPopMatrix();
//
//	//glPushMatrix();
//	//{
//	//	glColor3f(1, 0, 1);
//	//	glRotatef(60, 0, 0, 1);
//	//	glTranslatef(3, 4, 0);
//	//	glScalef(2, 2, 0); //Nhìn từ dưới lên
//	//	drawFigure0();
//	//}
//	glPopMatrix();
//
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-8, 8, -1, 11, -1.0, 1.0);
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutReshapeFunc(myReshape);
//	glutMainLoop();
//}