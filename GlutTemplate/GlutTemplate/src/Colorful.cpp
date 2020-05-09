//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 600
//#define screen_Height 600
//#define PI 3.14159265359
//using namespace std;
//float R = 4;
//struct point2d {
//	float x;
//	float y;
//};
//
//const int ARCDIV = 19;
//const int lineDIV = 16;
//point2d circle[ARCDIV * 5];
//point2d arcArr[5][ARCDIV];
//point2d lineArr[5][lineDIV + 1];
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
//
//void calculateData()
//{
//	for (int i = 0; i < ARCDIV * 5; i++)
//	{
//		circle[i].x = R * cos(PI / 2.0 + i * 2.0 * PI / (ARCDIV * 5.0));
//		circle[i].y = R * sin(PI / 2.0 + i * 2.0 * PI / (ARCDIV * 5.0));
//	}
//	for (int i = 0; i < 5; i++)
//		for (int j = 0; j < ARCDIV; j++)
//		{
//			arcArr[i][j].x = circle[i*ARCDIV + j].x;
//			arcArr[i][j].y = circle[i*ARCDIV + j].y;
//		}
//	cout << "Check: " << arcArr[0][0].y << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		lineArr[i][0].x = 0.0;
//		lineArr[i][0].y = 0.0;
//		//cout << arcArr[i][0].x<<" "<< arcArr[i][0].y << endl;
//		lineArr[i][lineDIV].x = arcArr[i][0].x;
//		lineArr[i][lineDIV].y = arcArr[i][0].y;
//		cout << lineArr[i][lineDIV].y << " " << arcArr[i][0].y << endl;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		float delx = (lineArr[i][lineDIV].x - lineArr[i][0].x) / (lineDIV );
//		float dely = (lineArr[i][lineDIV].y - lineArr[i][0].y) / (lineDIV );
//		for (int j = 1; j < lineDIV; j++)
//		{
//			lineArr[i][j].x = delx * j;
//			lineArr[i][j].y = dely * j;
//		}
//	}
//}
//void drawFigure(int idx1, int idx2, int r, int g, int b)
//{
//	glLineWidth(2);
//	glColor3f(r / 255.0, g / 255.0, b / 255.0);
//	for (int i = 0; i < 9; i++)
//		drawLine(lineArr[idx1][9 - i], lineArr[idx2][i]);
//	for (int i = 0; i < 10; i++)
//		drawLine(lineArr[idx1][7+  i], lineArr[idx2][lineDIV-i]);
//	for (int i = 0; i < ARCDIV; i++)
//		drawLine(arcArr[idx1][i], arcArr[idx2][i]);
//}
//void drawcircle(float x0, float y0, float R, int n = 60)
//{
//	float x, y;
//	float angleinc = 2 * PI / n;
//	float angle = 0;
//	glBegin(GL_LINE_LOOP);
//	angle = 0;
//	x = R * cos(angle);
//	y = R * sin(angle);
//	glVertex2f(x, y);
//	for (int i = 0; i < n; i++)
//	{
//		angle += angleinc;
//		x = R * cos(angle);
//		y = R * sin(angle);
//		glVertex2f(x, y);
//	}
//	glEnd();
//}
//static void myDisplay() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 0.0, 0.0);
//	calculateData();
//	drawcircle(0, 0, 4);
//
//	for (int i = 0; i < 5; i++)
//		for (int j = 0; j < ARCDIV; j++)
//		{
//
//			drawPoint(arcArr[i][j]);
//		}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << lineArr[i][lineDIV].y << endl;
//		drawLine(lineArr[i][0], lineArr[i][lineDIV]);
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < lineDIV + 1; j++)
//		{
//			drawPoint(lineArr[i][j]);
//		}
//	}
//	drawFigure(0, 1, 255, 128, 64);
//	drawFigure(1, 2, 0, 255, 0);
//	drawFigure(2, 3, 0, 0, 255);
//	drawFigure(3, 4, 255, 0, 255);
//	drawFigure(4, 0, 255, 0, 0);
//	glFlush();
//}
//static void init() {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-4.5, 4.5, -4.5, 4.5, -1.0, 1.0);
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
