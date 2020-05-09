//#include <iostream>
//#include <GL/glew.h>
//#include <GL/glut.h>
//#include<math.h>
//#define screen_Width 600
//#define screen_Height 600
//#define PI 3.1415926
//float RSaokim= 2.5;
//float RTraiDat= RSaokim *149600/108200;
//using namespace std;
//
//void drawCircle(float r){
//	float x, y;
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_POINTS);
//	//glPointSize(2);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glLineWidth(2);
//	glBegin(GL_LINE_STRIP);
//	for (int i = 0; i < 360; i++) {
//		x = r * cos(PI / 2 * i*2 * PI / 360);
//		y = r * sin(PI / 2 * i*2 * PI / 360);
//		glVertex2f(x, y);
//	}
//	glEnd();
//}
//
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(253/255.0, 138/255.0, 236/255.0);
//	float r=1.0,g=0.0, b=0.0;
//	drawCircle(RSaokim);
//	drawCircle(RTraiDat);
//
//	float angleTraidatInc = 4;
//	float factor = 365.0 / 224.0;
//	float angleSaoKimInc = factor * angleTraidatInc;
//	float xTraiDat, yTraiDat;
//	float xSaoKim, ySaoKim;
//	float angleTraidat=90, angleSaokim=90;
//	float sovongquay =8;
//	glBegin(GL_LINES);
//	for (int i = 0; i <= (360.0 / angleTraidatInc) * sovongquay; i++)
//	{
//		angleTraidat -= angleTraidatInc;
//		angleSaokim -= angleSaoKimInc;
//		xTraiDat = RTraiDat * cos(angleTraidat*PI / 180);
//		yTraiDat = RTraiDat * sin(angleTraidat*PI / 180);
//
//		xSaoKim = RSaokim * cos(angleSaokim*PI / 180);
//		ySaoKim = RSaokim * sin(angleSaokim*PI / 180);
//				
//		glVertex2f(xTraiDat, yTraiDat);
//		glVertex2f(xSaoKim, ySaoKim);
//	}
//	glEnd();
//	glFlush();
//}
//static void init() {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-4.5, 4.5, -4.5, 4.5, 0.0, 1.0);
//	glClearColor(1.0,1.0,1.0,1.0);
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