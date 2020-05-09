//#include <iostream>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 640
//#define screen_Height 480
//using namespace std;
//static  void drawPointf(float x, float y) {
//	glBegin(GL_POINTS);
//	glVertex2f(x, y);
//	glEnd();
//}
//void drawLinef(float x1, float y1, float x2, float y2) {
//	glBegin(GL_LINES);
//	glVertex2f(x1, y1);
//	glVertex2f(x2, y2);
//	glEnd();
//}
//void drawTrianglef(float* a, float* b, float* c)
//{
//	glBegin(GL_TRIANGLES);
//	glVertex2f(a[0], a[1]);
//	glVertex2f(b[0], b[1]);
//	glVertex2f(c[0], c[1]);
//	glEnd();
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	{
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		glColor3f(1.0, 0.0, 1.0);
//		glClearColor(1.0, 1.0, 1.0, 1.0);
//
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		glLineWidth(5);
//		glColor3f(1.0, 0.0, 0.0);
//	}
//	{
//		//glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
//		//glPointSize(5);
//	}	
//	glColor3f(1.0, 0.0, 0.0);
//	
//	//glBegin(GL_POINTS);
//	//glVertex2f(-0.5, 0.5);
//	//glVertex2f(0.5, 0.5);
//	//glVertex2f(-0.5, 0.0);
//	//glVertex2f(0.5, 0.0);
//	//glVertex2f(-0.5, -0.5);
//	//glVertex2f(0.5, -0.5);
//	//glEnd();
//	// 	glBegin(GL_LINES);
//	// 	glVertex2f(-0.5, 0.5);
//	// 	glVertex2f(0.5, 0.5);
//	// 	glVertex2f(-0.5, 0.0);
//	// 	glVertex2f(0.5, 0.0);
//	// 	glVertex2f(-0.5, -0.5);
//	// 	glVertex2f(0.5, -0.5);
//	// 	glEnd();
//		//glBegin(GL_LINE_STRIP);
//		//	glVertex2f(-0.5, 0.5);
//		//	glVertex2f(0.5, 0.5);
//		//	glVertex2f(-0.5, 0.0);
//		//	glVertex2f(0.5, 0.0);
//		//	glVertex2f(-0.5, -0.5);
//		//	glVertex2f(0.5, -0.5);
//		//glEnd();
//	//glBegin(GL_LINE_LOOP);
//	//glVertex2f(-0.5, 0.5);
//	//glVertex2f(0.5, 0.5);
//	//glVertex2f(-0.5, 0.0);
//	//glVertex2f(0.5, 0.0);
//	//glVertex2f(-0.5, -0.5);
//	//glVertex2f(0.5, -0.5);
//	//glEnd();
//		//glBegin(GL_TRIANGLES);
//		//glVertex2f(-0.5, 0.5);
//		//glVertex2f(0.5, 0.5);
//		//glVertex2f(-0.5, 0.0);
//		//glVertex2f(0.5, 0.0);
//		//glVertex2f(-0.5, -0.5);
//		//glVertex2f(0.5, -0.5);
//		//glEnd();
//	//glBegin(GL_TRIANGLE_STRIP);
//	//glVertex2f(-0.5, 0.5);
//	//glVertex2f(0.5, 0.5);
//	//glVertex2f(-0.5, 0.0);
//	//glVertex2f(0.5, 0.0);
//	//glVertex2f(-0.5, -0.5);
//	//glVertex2f(0.5, -0.5);
//	//glEnd();
//	
//	/*glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(-0.5, 0.5);
//	glVertex2f(0.5, 0.5);
//	glVertex2f(-0.5, 0.0);
//	
//	glVertex2f(-0.5, -0.5);
//	glVertex2f(0.5, -0.5);
//	glEnd();*/
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	glBegin(GL_TRIANGLE_STRIP);
//
//	glVertex2f(0.5, -0.5);
//
//	glVertex2f(0.5, 0.5);
//
//	glVertex2f(-0.5, -0.5);
//
//	glVertex2f(-0.5, 0.5);
//
//	glVertex2f(-1.0, 0);
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
//	//init();
//	glutDisplayFunc(myDisplay);
//
//	glutMainLoop();
//}