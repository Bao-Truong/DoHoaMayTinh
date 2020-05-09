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
//float angle = 0;
//void drawText(float x, float y, float z, const char str[])
//{
//	glRasterPos3f(x, y, z);
//	void *font = GLUT_BITMAP_9_BY_15;
//	for (int i = 0; i < strlen(str); i++)
//	{
//		glutBitmapCharacter(font, str[i]);
//	}
//}
//void drawAxis() {
//	glLineWidth(3);
//	glBegin(GL_LINES);
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(3, 0, 0);
//
//	glColor3f(0.0, 1.0, 0.0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 3, 0);
//
//	glColor3f(0.0, 0.0, 1.0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 3);
//	glEnd();
//
//	drawText(3, 0, 0, "X");
//	drawText(0, 3, 0, "Y");
//	drawText(0, 0, 3, "Z");
//}
//void myReshape(int w, int h) {
//	float factor = 2;
//	glViewport(0, 0, w, h); //Kéo dãn theo màn hình thay đổi, có thể sẽ mất hình dạng ban đầu( hình cầu kéo ngang qua thì bị dãn)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-factor, factor, -factor * h / w, factor*h / w, -10.0, 10.0);
//	else
//		glOrtho(-factor * w / h, factor*w / h, -factor, factor, -10.0, 10.0);
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(1.5, 1.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1, 0);
//
//	glRotatef(angle, 0, 1, 0);
//	drawAxis();
//
//	double b = 0.05;
//	double inc = 0.1;
//	double R = 0.5;
//	glBegin(GL_LINE_STRIP);
//	for (double t = 0; t <= 2 * PI * 4; t += inc)
//	{
//		glVertex3f(R*cos(t), R*sin(t), b*t);
//	}
//	glEnd();
//	glBegin(GL_LINE_STRIP);
//	for (double t = 0; t <= 2 * PI * 4; t += inc)
//	{
//		glVertex3f(R*cos(t),  b*t, R*sin(t));
//	}
//	glEnd();
//	glBegin(GL_LINE_STRIP);
//	for (double t = 0; t <= 2 * PI * 4; t += inc)
//	{
//		glVertex3f(b*t, R*cos(t),  R*sin(t));
//	}
//	glEnd();
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-3, 3, -3, 3, 0.0, 1.0);
//
//}
//void mySpecial(int key, int x, int y) {
//	if (key == GLUT_KEY_LEFT)
//		angle += 5;
//	else if (key == GLUT_KEY_RIGHT)
//		angle -= 5;
//	glutPostRedisplay();
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutReshapeFunc(myReshape);
//	glutSpecialFunc(mySpecial);
//	glutMainLoop();
//}