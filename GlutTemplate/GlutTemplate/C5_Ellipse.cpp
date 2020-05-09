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
//	glClear(GL_COLOR_BUFFER_BIT);
//	double W = 1.5, H = 1.2;
//	int N = 50;// chấm bao nhiêu đỉnh
//	double inc = 2 * PI / N;
//	glBegin(GL_LINE_STRIP);
//	for (double t = 0; t <= 2 * PI+inc; t += inc) {
//		glVertex2f(W*cos(t),H*sin(t));
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
//	glOrtho(-3,3,-3,3, 0.0, 1.0);
//
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