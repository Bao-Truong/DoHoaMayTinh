//#include <iostream>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 640
//#define screen_Height 480
//using namespace std;
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
//static void drawRecangle(int x, int y);
//float r, g, b;
//
//static void myPassmotion(int x, int y)
//{
//	y = screen_Height - y;
//	if (mouse.Left == 1)
//	{
//		cout << "MOSE:";
//		drawRecangle(x, y);
//	}
//}
//static void myMotion(int x, int y)
//{
//	
//	y = screen_Height - y;
//	if (mouse.Left == 1)
//	{
//		cout << "DRAW";
//		drawRecangle(x, y);
//	}
//}
//static  void myMouse(int button, int state, int x, int y)//gọi khii chuột được ấn hoặc thả
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
//
//}
//static void drawRecangle(int x, int y) {
//	//int randNum = rand() % (max - min + 1) + min;
//	cout << "x: " << x << endl; cout << "x: " << x << endl;
//	glColor3f(r, 0.0,1.0);
//	r += 0.01;
//	g += 0.01;
//	b += 0.01;
//	if (r >= 0.8)
//	{
//		r = g = b = 0.0;
//	}
//	glBegin(GL_TRIANGLE_STRIP);
//	glVertex2f(x, y + 20);
//	glVertex2f(x - 20, y - 20);
//	glVertex2f(x + 20, y - 20);
//	glEnd();
//	glFlush();
//	glutPostRedisplay();
//}
//static void myDisplay() {
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_TRIANGLE_STRIP);
//	glVertex2f(50, 50 + 20);
//	glVertex2f(50 - 20, 50 - 20);
//	glVertex2f(50 + 20, 50 - 20);
//	glEnd();
//	glFlush();
//}
//static void init() {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0, screen_Width, 0, screen_Height , 0.0, 1.0);
//
//	glClearColor(1.0, 1.0, 1.0, 1);
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutMouseFunc(myMouse);
//	glutMotionFunc(myMotion);
//	glutPassiveMotionFunc(myPassmotion);
//	
//	glutMainLoop();
//}