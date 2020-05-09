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
//double minXVal, maxXVal;
//double minYVal, maxYVal;
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
//	//float factor = 2;
//	//glViewport(0, 0, w, h); //Kéo dãn theo màn hình thay đổi, có thể sẽ mất hình dạng ban đầu( hình cầu kéo ngang qua thì bị dãn)
//	//glMatrixMode(GL_PROJECTION);
//	//glLoadIdentity();
//	//if (w <= h)
//	//	glOrtho(-factor, factor, -factor * h / w, factor*h / w, -10.0, 10.0);
//	//else
//	//	glOrtho(-factor * w / h, factor*w / h, -factor, factor, -10.0, 10.0);
//}
//void FindMaxMinVal() {
//	minXVal = cos(0) - cos(80 * 0)*sin(0);
//	maxXVal = minXVal;
//
//	for (double t = 0; t <= 2 * PI; t += 0.001)
//	{
//		double tmp = cos(t) - cos(80 * t)*sin(t);
//		if (tmp > maxXVal)
//			maxXVal = tmp;
//		if (tmp < minXVal)
//			minXVal = tmp;
//	}
//
//	minYVal = 2 * sin(0) - sin(80 * 0);
//	maxYVal = minYVal;
//
//	for (double t = 0; t <= 2 * PI; t += 0.001)
//	{
//		double tmp = 2 * sin(t) - sin(80 * t);
//		if (tmp > maxYVal)
//			maxYVal = tmp;
//		if (tmp < minYVal)
//			minYVal = tmp;
//	}
//
//
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);	
//	glBegin(GL_LINE_STRIP);
//	float i, j;
//	float a, b, c;
//	float d, e;
//	i = 1;
//	j = 2;
//
//	//a = 1;
//	//b = 60;
//	//c = 1;
//	//d = 1;
//	//e = 60;
//
//	//a = 80;
//	//b = 1;
//	//c = 2;
//	//d = 1;
//	//e = 80;	
//	
//	a = 60;
//	b = 60;
//	c = 60;
//	d = 60;
//	e = 60;
//	
//	for (double t = 0; t <= PI; t += 0.001)
//	{
//		glVertex2f(
//			i*cos(a*t) - cos(b * t)*sin(c*t),
//		j * sin(d*t) - sin(e * t)
//		);
//	}
//	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Butterfly!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	//for (double t = 0; t <= 12 * PI; t += 0.01)
//	//{
//	//	glVertex2f(
//	//		sin(t)*(exp(cos(t)) - 2 * cos(4 * t) - pow(sin(t / 12.0), 5)),
//	//			cos(t)*(exp(cos(t)) - 2 * cos(4 * t) - pow(sin(t / 12.0), 5))
//	//	);
//	//}
//	glEnd();
//	glFlush();
//}
//static void init() {
//	float factor = 3;
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	FindMaxMinVal();
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-factor, factor,-factor, factor, -1.0, 1.0);
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