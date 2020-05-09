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
//struct point2d {
//	float x;
//	float y;
//};
//void MakeNGon(float fRadius, int n, float startAngle) {
//	float del_angle = 2 * PI / n;
//	float angle;
//	float x, y;
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0);
//	glLineWidth(4);
//	for (int i = 0; i <= n; i++) {
//		angle = i * del_angle + startAngle;
//		x = fRadius * cos(angle);
//		y = fRadius * sin(angle);
//		glVertex2f(x, y);
//	}
//	glEnd();
//
//	glColor3f(0, 0, 0);
//	glLineWidth(2);
//	glBegin(GL_LINES);
//	glVertex2f(-fRadius, 0);
//	glVertex2f(fRadius, 0);
//	glVertex2f( 0, -fRadius);
//	glVertex2f( 0 , fRadius);
//
//	glEnd();
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(1.5, 2.5, 0);
//	glRotatef(30, 0, 0, 1);
//	glScalef(1.5, 0.5, 1);
//	MakeNGon(2.5, 40, 0);
//	
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-5,5,-5,5, -1.0, 1.0);
//
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	//glutReshapeFunc(myReshape);
//	glutMainLoop();
//}