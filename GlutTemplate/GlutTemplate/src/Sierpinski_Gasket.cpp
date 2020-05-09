//#include <iostream>
//#include <GL/glew.h>
//#include <GL/glut.h>
//#include <time.h>
//#include <random>
//#define screen_Width 400
//#define screen_Height 400
//using namespace std;
//float vertices[3][2] = {
//	{0.0,0.0},
//	{200.0,400.0},
//	{400.0,0.0}
//};
//
//static  void drawPointf(float x, float y) {
//	glBegin(GL_POINTS);
//	glVertex2f(x, y);
//	glEnd();
//}
//static void myDisplay() {
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	int j;
//	srand(time(NULL));
//	float p0[] = { 7.5,5.0 };
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_POINTS);
//	for (int i = 0; i < 500000; i++)
//	{
//		j = rand() % 3;
//		p0[0] = (p0[0] + vertices[j][0]) / (2.0f);
//		p0[1] = (p0[1] + vertices[j][1]) / (2.0f);
//		glVertex2fv(p0);
//	}
//
//	glEnd();
//	glFlush();
//}
//static void init() {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0, screen_Width, 0, screen_Height, 0.0, 1.0);
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
//
