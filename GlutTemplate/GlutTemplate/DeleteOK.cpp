//#include<iostream>
//#include<glut.h>
//
//#define PI 3.1415
//using namespace std;
//
//void makegon(float x, float y, float len, int n)
//{
//	float inc = 360.0 / n;
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < n; i++)
//	{
//		float a = x + len * cos(PI / 2.0 + i * inc* PI/180.0);
//		float b = y + len * sin(PI / 2.0 + i * inc* PI / 180.0);
//		glVertex2f(a, b);
//	}
//	glEnd();
//
//}
//void myDisplay() {
//	glClearColor(0, 0, 0,1);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1, 0, 0);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
//	glLineWidth(5);
//	makegon(0, 0, 0.5, 5);
//	
//	glFlush();
//
//}
//
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(600, 600);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//
//	glutDisplayFunc(myDisplay);
//	
//	glutMainLoop();
//}
