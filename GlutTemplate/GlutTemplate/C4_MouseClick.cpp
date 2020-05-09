//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 500
//#define screen_Height 500
//#define PI 3.14159265359
//using namespace std;
//
//float l = -2, r = 4, b = -4, t = 2;
//int len = 10;
//
//bool left = false;
//bool right = false;
//
//struct point2d {
//	float x;
//	float y;
//};
//
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	glFlush();
//}
//static void init() {
//	glClearColor(0.0, 0.0, 0.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	glOrtho(0, screen_Width,  screen_Height, 0, -1.0, 1.0);
//	//glOrtho(0, screen_Width, 0, screen_Height, -1.0, 1.0);
//	//glOrtho(l, r, b, t, -1.0, 1.0);
//
//}
//void drawCircle(int o,int a) {
//	//float o1 = ((r - l) / screen_Width)*o + l;
//	//float len1 = (float(r - l) / screen_Width) * len;
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glColor3f((char)rand() % 256, (char)rand() % 256, (char)rand() % 256);
//	float o1 = o;
//	float len1 = len;
//	float x, y;
//	glBegin(GL_POINTS);
//	for (int i = 0; i <= 360; i++)
//	{
//		x = len1 * cos(PI / 2 * 2 * i*PI / 360.0);
//		y = len1 * sin(PI / 2 * 2 * i*PI / 360.0);
//		glVertex2f(o1+x, a+y);
//	}
//	glEnd();
//	glFlush();
//}
//void drawSquare(int x, int y) {
//	
//	//glColor3f((char)rand() %256, (char)rand() % 256, (char)rand() % 256);
//	//glBegin(GL_POLYGON);
//	//	glVertex2f(x + len, y + len);
//	//	glVertex2f(x - len, y + len);
//	//	glVertex2f(x - len, y - len);
//	//	glVertex2f(x + len, y - len);		
//	//	
//	//glEnd();
//
//
//	float x1 = ((r - l) / screen_Width)*x + l;
//	float y1 = ((b - t) / screen_Height)*y + t;
//	float len1 = (float(r - l) / screen_Width) * len;
//
//
//	glColor3f((char)rand() % 256, (char)rand() % 256, (char)rand() % 256);
//	glBegin(GL_POLYGON);
//	glVertex2f(x1 + len1, y1 + len1);
//	glVertex2f(x1 - len1, y1 + len1);
//	glVertex2f(x1 - len1, y1 - len1);
//	glVertex2f(x1 + len1, y1 - len1);
//
//	glEnd();
//	glFlush();
//}
//void myMouse(const int key, int state, int x, int y) {
//	//y = screen_Height - y;
//	
//	if (key == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		cout << x << " " << y << endl;
//		//drawSquare(x, y);
//	}
//	
//	
//}
//void myKeyboard(unsigned char  key, int x, int y) {
//	
//	cout << key << " pressed" << endl;
//}
//void mySpecial(int key, int x, int y)
//
//{
//	cout << key << " Pressed" << endl;
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutInitDisplayMode(GLUT_RGB  | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutMouseFunc(myMouse);
//	glutKeyboardFunc(myKeyboard);
//
//	glutPassiveMotionFunc(drawCircle);
//	glutSpecialFunc(mySpecial);
//	//glutMotionFunc(drawCircle);
//	glutMainLoop();
//}