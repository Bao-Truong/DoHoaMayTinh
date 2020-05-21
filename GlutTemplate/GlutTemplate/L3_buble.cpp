//
//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 500
//#define screen_Height 500
//#define PI 3.14159265359
//#define DEC2RAG PI/180.0
//using namespace std;
//
//void drawArcs() {
//	glColor3f(0, 0, 0);
//	glLineWidth(1);
//	float R = 0.5;
//	glBegin(GL_LINE_STRIP);
//	for (int i = 0; i <= 90; i++) {
//		float x = R * cos(i*PI / 180.0);
//		float y = R * sin(i*PI / 180.0);
//		glVertex2f(x, y);
//	}
//	glEnd();
//	glBegin(GL_LINE_STRIP);
//	for (int i = 180; i <= 270; i++) {
//		float x = R * cos(i*PI / 180.0) + 1;
//		float y = R * sin(i*PI / 180.0) + 1;
//		glVertex2f(x, y);
//	}
//	glEnd();
//}
//void setCameraVolume(float l, float r, float b, float t) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
//}
//void setViewport(int l, int r, int b, int t) {
//	glViewport(l, b, r - l, t - b);
//}
//void drawBackGround() {
//	float vw = screen_Width / 15;
//	float vh = screen_Height / 15;
//	for (int i = 0; i < 15; i++)
//	{
//		for (int j = 0; j < 15; j++)
//		{
//			setViewport(vw*i, vw*(i + 1), vh*j, vh*(j + 1));
//
//			int x = rand() % 2;
//			cout << x << endl;
//			switch (x) {
//			case 0: setCameraVolume(0, 1, 0, 1);
//				drawArcs();
//				break;
//			case 1:
//				setCameraVolume(1, 0, 0, 1);
//				drawArcs();
//				break;
//			}
//		}
//	}
//}
//void MakeGon(int fRadius, int n, float startangle) {
//	float x, y;
//
//	float angleinc = 2 * PI / n;
//	float angle;
//	glBegin(GL_POLYGON);
//	for (int i = 0; i < n; i++)
//	{
//		angle = i * angleinc + startangle;
//		x = fRadius * cos(angle);
//		y = fRadius * sin(angle);
//		glVertex2f(x, y);
//	}
//	glEnd();
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//
//	//setCameraVolume(1,0,0,1);
//	////1 0  0 1
//	////0 1 1 0
//	//// 1 0 1 0
//
//	//drawArcs();
//	drawBackGround();
//	//int factor=3;
//	//setCameraVolume(-factor, factor, -factor, factor);
//	//MakeGon(2, 10, PI/2);
//
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	
//
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	//glutReshapeFunc(myReshape);
//	glutMainLoop();
//}