//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 640
//#define screen_Height 480
//#define PI 3.14159265359
//#define DEC2RAG PI/180.0
//using namespace std;
//float factor = 2;
//
//void myReshape(int w, int h) {
//
//	//glViewport(0, 0, w, h); //Kéo dãn theo màn hình thay đổi, có thể sẽ mất hình dạng ban đầu( hình cầu kéo ngang qua thì bị dãn)
//	//glMatrixMode(GL_PROJECTION);
//	//glLoadIdentity();
//	//if (w <= h)
//	//	glOrtho(-factor, factor, -factor * h / w, factor*h / w, -10.0, 10.0);
//	//else
//	//	glOrtho(-factor * w / h, factor*w / h, -factor, factor, -10.0, 10.0);
//}
//void drawTeapot() {
//	glColor3f(1, 0, 0);
//	float mat_diffuse1[] = { 1.0,0.0,0.0,1.0 };
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glPushMatrix();
//	glutSolidTeapot(0.5);
//	glPopMatrix();
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//	
//	float aspect = 640.0 / 480;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.2*aspect, 1.2*aspect, -1.2, 1.2, 0.1, 100); //Thể tích nhìn và phép chiếu
//	//Chiếu trực giao
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1.0, 1.0, - 1.0 ,1.0 ,4, 20.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
//
//	
//	//gluLookAt(-6,-7,8, 0, 0, 0, 0, 1 , 0);//1
//	//gluLookAt(-6, -7, -8, 0, 0, 0, 0, 1, 0);//2
//	//gluLookAt(-6, -7, -8, 0, 0, 0, 1, 1, 0); //3
//	//gluLookAt(6, -7, -8, 0, 0, 0, 0, 1, 0);//4
//
//	drawTeapot();
//
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glShadeModel(GL_SMOOTH);
//
//	float lightIntensity[] = {0.7f, 0.7, 0.7, 1.0};
//	float light_position[] = { 10,9,8.0,0.0 };
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
//
//	float lightIntensity1[] = { 0.7f, 0.7, 0.7, 1.0 };
//	float light_position1[] = { 10,9,-8.0,0.0 };
//	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightIntensity1);
//
//	//glMatrixMode(GL_PROJECTION);
//	//glLoadIdentity();
//	//glOrtho(-factor, factor, -factor, factor, -1.0, 1.0);
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