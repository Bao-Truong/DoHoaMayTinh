//
//#include <iostream>
//
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 500
//#define screen_Height 500
//#define PI 3.14159265359
//using namespace std;
//#define DEC2RAG PI/180.0
//
//float t = 0;
//float dt = 0.5;
//int menu_id;
//int coloridx = 0;
//float color[4][3] = { {1,0,0},{0,1,0},{0,0,1},{1,0,1} };
//struct point2d {
//	float x;
//	float y;
//};
//
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glLineWidth(2);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(1.5, 1.5, 1.5, 0, 0, 0, 0.0, 1.0, 0.0);
//
//	//drawQuad_Sphere(5);
//
//	float c = PI / 180.0;
//	float phir, phir20, theta, thetar;
//	float x, y, z;
//	float angle = 5;
//
//	glPushMatrix();
//	glRotated(t, 0, 1, 0);
//	//cout << coloridx << endl;
//	glColor3fv(color[coloridx]);
//	for (float phi = -90 + angle; phi <= 90 - angle; phi += angle)
//	{
//		phir = c * phi;
//		phir20 = c * (phi + angle);
//
//		glBegin(GL_QUAD_STRIP);
//		for (float theta = -180; theta <= 180; theta += angle)
//		{
//			thetar = c * theta;
//			x = sin(thetar)*cos(phir);
//			z = cos(thetar)*cos(phir);
//			y = sin(phir);
//			//cout << x << " " << y << " " << z << endl;
//			glVertex3f(x, y, z);
//			x = sin(thetar)*cos(phir20);
//			z = cos(thetar)*cos(phir20);
//			y = sin(phir20);
//			glVertex3f(x, y, z);
//		}
//		glEnd();
//	}
//	//cout << x << " " << y << " " << z << endl;
//
//	float c80;
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex3f(0, 1, 0);
//	c80 = c * (90 - angle);
//	y = sin(c80);
//	for (float theta = 180; theta >= -180; theta -= angle)
//	{
//		thetar = c * theta;
//		x = sin(thetar)*cos(c80);
//		z = cos(thetar)*cos(c80);
//		glVertex3f(x, y, z);
//	}
//	glEnd();
//
//
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex3f(0, -1, 0);
//	c80 = c * (90 - angle);
//	y = -sin(c80);
//	for (float theta = -180; theta <= -180; theta += angle)
//	{
//		thetar = c * theta;
//		x = sin(thetar)*cos(c80);
//		z = cos(thetar)*cos(c80);
//		glVertex3f(x, y, z);
//	}
//	glEnd();
//
//	glPopMatrix();
//	glutSwapBuffers();
//	glFlush();
//}
//void myMenu(int id) {
//	if (id == 1) coloridx =  4;
//	if (id == 2) exit(0);
//}
//void processColorMenu(int id) {
//	switch (id)
//	{
//	case 7: coloridx = 0; break;
//	case 8: coloridx = 1; break;
//	case 9: coloridx = 2; break;
//	case 10: coloridx = 3; break;
//
//	}
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glColor3f(0.0, 0.0, 0.0);
//
//
//	glFrontFace(GL_CW);
//	glEnable(GL_CULL_FACE);
//
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-2, 2, -2, 2, -10.0, 10.0);
//
//	int _id = glutCreateMenu(myMenu);
//	glutAddMenuEntry("Change color", 1);
//	glutAddMenuEntry("Exit", 2);
//
//	int 	colorMenu = glutCreateMenu(processColorMenu);
//	glutAddMenuEntry("Red", 7);
//	glutAddMenuEntry("Green", 8);
//	glutAddMenuEntry("Blue", 9);
//	glutAddMenuEntry("Pink", 10);
//
//	int menu_id = glutCreateMenu(myMenu);
//	glutAddSubMenu("Stuff", _id);
//	glutAddSubMenu("color", colorMenu);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//}
//void myReshape_1(int w, int h) {
//	float factor = 2;
//	glViewport(0, 0, w, h); //Kéo dãn theo màn hình thay đổi, có thể sẽ mất hình dạng ban đầu( hình cầu kéo ngang qua thì bị dãn)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-factor, factor, -factor * h / w, factor*h / w, -10.0, 10.0);
//	else
//		glOrtho(-factor * w / h, factor*w / h, -factor, factor, -10.0, 10.0);
//}
//void myReshape_2(int w, int h) {
//	glViewport(0, 0, w, h); //Kéo dãn theo màn hình thay đổi, có thể sẽ mất hình dạng ban đầu( hình cầu kéo ngang qua thì bị dãn)
//}
//void myIdle() {
//	t += 0.5;
//
//	glutPostRedisplay();
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutReshapeFunc(myReshape_1);
//	
//	glutIdleFunc(myIdle);
//	
//	glutMainLoop();
//}