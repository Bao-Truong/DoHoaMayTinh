//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 640
//#define screen_Height 480
//#define PI 3.14159265359
//using namespace std;
//struct point2d {
//	float x;
//	float y;
//};
//void drawTeapot() {
//	glColor3d(1, 0, 0);
//	GLfloat mat_diffuse1[4] = { 1.0f,0.0f,0.0f,1.0f };
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glPushMatrix();
//	glTranslated(0, 0, -1.0);
//	glutSolidTeapot(0.5);
//	glPopMatrix();
//}
//void drawCube() {
//	glColor3d(0,0,1);
//	GLfloat mat_diffuse3[4] = { 0.0f,0.0f,1.0f,1.0f };
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse3);
//	glPushMatrix();
//	glTranslated(0, 0, -10.0);
//	glutSolidCube(1);
//	glPopMatrix();
//}
//void drawSphere() {
//	glColor3d(0, 1, 0 );
//	GLfloat mat_diffuse2[4] = { 0.0f,1.0f,0.0f,1.0f };
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
//	glPushMatrix();
//	glTranslated(0, 0, 1.0);
//	glutSolidSphere(0.3,50,50);
//	glPopMatrix();
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	//glEnable(GL_DEPTH_TEST);
//	
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0, 0, 20, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//	drawTeapot();
//	drawCube();
//	drawSphere();
//	
//	glFlush();
//}
//static void init() {
//	glEnable(GL_DEPTH_TEST);
//	//camera Volume
//	float aspect = 6.4 / 4.8;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.2*aspect, 1.2*aspect, -1.2, 1.2, 0.1, 100);
//
//	//set up light
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glShadeModel(GL_SMOOTH);
//
//	float lightIntensity[] = { 0.7f,0.7f,0.7f,1.0f };
//	float light_position[] = { 10,9,8.0f,0.0f };
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
//
//	float lightIntensity1[] = { 0.7f,0.7f,0.7f,1.0f };
//	float light_position1[] = { 10,9,-8.0f,0.0f };
//	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightIntensity1);
//
//	glClearColor(1.0, 1.0, 1.0, 1);
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//
//	glutMainLoop();
//}