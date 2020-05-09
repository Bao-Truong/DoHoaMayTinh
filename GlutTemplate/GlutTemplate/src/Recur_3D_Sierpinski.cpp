//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 640
//#define screen_Height 480
//#define PI 3.14159265359
//GLfloat rotationX = 0.0f;
//GLfloat rotationY = 0.0f;
//using namespace std;
//float v[4][3] = {
//		{1,1,0},
//		{0,1,0},
//		{0,0,1},
//		{1,0,0}
//};
//float color[4][3] = {
//	{1.0,0.0,0.0},
//	{0.0,1.0,0.0},
//	{0.0,0.0,1.0},
//	{0.0,1.0,1.0}
//};
//struct point2d {
//	float x;
//	float y;
//};
//void triangle(float *a, float*b, float*c) {
//	glVertex3fv(a);
//	glVertex3fv(b);
//	glVertex3fv(c);
//}
//void tetra(float *a, float*b, float*c, float *d) {
//	glColor3fv(color[0]);
//	triangle(a, b, c);
//	glColor3fv(color[1]);
//	triangle(a, d, c);
//	glColor3fv(color[2]);
//	triangle(d, b, c);
//	glColor3fv(color[3]);
//	triangle(a, b, d);
//}
//void divide_tetra(float *a, float*b, float*c, float *d, int m = 4)
//{
//	float mid[6][3];
//	if (m > 0) {
//		for (int i = 0; i < 3; i++) mid[0][i] = (a[i] + b[i]) / 2.0f;
//		for (int i = 0; i < 3; i++) mid[1][i] = (c[i] + b[i]) / 2.0f;
//		for (int i = 0; i < 3; i++) mid[2][i] = (a[i] + c[i]) / 2.0f;
//		for (int i = 0; i < 3; i++) mid[3][i] = (a[i] + d[i]) / 2.0f;
//		for (int i = 0; i < 3; i++) mid[4][i] = (b[i] + d[i]) / 2.0f;
//		for (int i = 0; i < 3; i++) mid[5][i] = (c[i] + d[i]) / 2.0f;
//
//		divide_tetra(a, mid[0], mid[2], mid[3], m - 1);
//		divide_tetra(b, mid[0], mid[1], mid[4], m - 1);
//		divide_tetra(c, mid[1], mid[2], mid[5], m - 1);
//		divide_tetra(d, mid[5], mid[4], mid[3], m - 1);
//	}
//	else {
//		tetra(a, b, c, d);
//	}
//}
//void drawLine(point2d a, point2d  b) {
//	glBegin(GL_LINES);
//	glVertex2f(a.x, a.y);
//	glVertex2f(b.x, b.y);
//	glEnd();
//}
//static  void drawPoint(point2d p) {
//	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
//	glPointSize(5);
//	glBegin(GL_POINTS);
//	glVertex2f(p.x, p.y);
//	glEnd();
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//	
//
//	float a[3] = { 0.0f,0.0f,0.0f };
//	float b[3] = { 1.0f,0.0f,0.0f };
//	float c[3] = { 0.0f,1.0f,0.0f };
//	float d[3] = { 0.0f,0.0f,1.0f };
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(-1, -1, -1, 0, 0, 0, 0, 1, 0);
//	//glTranslatef(screen_Width / 2, screen_Height / 2,0.0f);
//	glRotatef(rotationX, 1, 0, 0);
//	glRotatef(rotationY, 0, 1, 0);
//	//glTranslatef(-screen_Width / 2, -screen_Height / 2, 0.0f);
//	cout << "rotate: " << rotationX << endl;
//	glBegin(GL_TRIANGLES);
//	divide_tetra(a, b, c, d);
//	glEnd();	
//	glPopMatrix();
//	
//	glFlush();
//}
//static void init() {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, 0.1, 1000.0);
//	glClearColor(1.0, 1.0, 1.0, 1);
//
//	
//	
//}
//void myKeyboard(unsigned char key, int x, int y)
//{
//	const GLfloat rotationSpeed = 10;
//	cout << "Key: " << key << endl;
//	switch (key) {
//	case '8':
//		cout << "Ue" << endl;;
//		rotationX -= rotationSpeed;
//		break;
//	case '5':
//		rotationX += rotationSpeed;
//		break;
//	case '6':
//		rotationY += rotationSpeed;
//		break;
//	case '4':
//		rotationY -= rotationSpeed;
//		break;
//	}
//	glutPostRedisplay();
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB |  GLUT_DEPTH);
//	glutInitWindowSize(screen_Width, screen_Height);
//	
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutKeyboardFunc(myKeyboard);
//
//	glutMainLoop();
//}
