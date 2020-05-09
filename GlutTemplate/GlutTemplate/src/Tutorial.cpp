//#include <iostream>
//#include <GL/glew.h>
//#include <GL/glut.h>
//#include "Renderer.h"
//using namespace std;
//#define Width 640
//#define Height 480
//
//struct mouse_state {
//	bool Left;
//	bool Middle;
//	bool Right;
//	mouse_state() {
//		Left = 0;
//		Middle = 0;
//		Right = 0;
//	}
//	void reset() {
//		Left = 0;
//		Middle = 0;
//		Right = 0;
//	}
//};
//mouse_state mouse;
//void drawRec_Tri() {
//	glBegin(GL_POLYGON);
//	glVertex2f(-2.0, 0.0);
//	glVertex2f(-2.0, 2.0);
//	glVertex2f(0.0, 2.0);
//	glVertex2f(0.0, 0.0);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glVertex2f(0.0, -4.0);
//	glVertex2f(2.0, 0.0);
//	glVertex2f(4.0, -4.0);
//	glEnd();
//}
//void myDisplay() {
//
//	GLCall(glClear(GL_COLOR_BUFFER_BIT));
//
//	glViewport(0, 0, Width / 2, Height / 2);
//	GLCall(glColor3f(88.0 / 255.0, 54.0 / 255.0, 222.0 / 255.0));
//	drawRec_Tri();
//
//	glViewport(Width / 2, 0, Width / 2, Height / 2);
//	GLCall(glColor3f(88.0 / 255.0, 54.0 / 255.0, 222.0 / 255.0));
//	drawRec_Tri();
//
//	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
//	GLCall(glColor3f(88.0 / 255.0, 54.0 / 255.0, 222.0 / 255.0));
//	drawRec_Tri();
//
//	glViewport(0, Height / 2, Width / 2, Height / 2);
//	GLCall(glColor3f(88.0 / 255.0, 54.0 / 255.0, 222.0 / 255.0));
//	drawRec_Tri();
//	GLCall(glFlush());
//
//}
//void init() {
//	GLCall(glMatrixMode(GL_PROJECTION));
//	GLCall(glLoadIdentity());
//	GLCall(glOrtho(-2.0, 4.0, -4.0, 2.0, 0, 1));
//
//	GLCall(glClearColor(1.0, 1.0, 1.0, 1));
//
//}
//void myMouse(int button, int state, int x, int y)
//{
//	mouse.reset();
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		mouse.Left = 1;
//	}
//	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
//	{
//		mouse.Middle = 1;
//	}
//	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//	{
//		mouse.Right = 1;
//	}
//}
//void myPassMotion(int x, int y) {
//	//cout << "Callnack";
//	if (mouse.Right == 1)
//		exit(0);
//}
//int main(int argc, char **argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutInitWindowSize(Width, Height);
//	glutInitWindowPosition(0, 0); //Goc trai tren	
//	glutCreateWindow("Hello world");
//	init();
//	if (glewInit() != GLEW_OK) {
//		cout << "Error";
//		exit(0);
//	}
//	else {
//		cout << glGetString(GL_VERSION) << endl;
//	}
//	GLCall(glutDisplayFunc(myDisplay));
//	GLCall(glutMouseFunc(myMouse));
//	GLCall(glutMotionFunc(myPassMotion));
//
//	GLCall(glutMainLoop());
//
//}
