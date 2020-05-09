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
//float factor = 4.5;
//
//float vertex[15][2];
//void myReshape(int w, int h) {
//	
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
//	
//	float x, y;
//	float r = 2;		
//	int n = 6;
//	float angle = 360 / n;
//
//	glPointSize(5);
//	glBegin(GL_POINTS);
//	for (int i = 0; i < n; i++)
//	{
//		x = r * cos(PI / 2 - i * angle*DEC2RAG);
//		y = r * sin(PI / 2 - i * angle*DEC2RAG);
//		vertex[i][0] = x;
//		vertex[i][1] = y;
//		glVertex2f(x, y);
//	}
//	glEnd();
//	vertex[6][0] = vertex[0][0]; vertex[6][1] = vertex[0][1] + r;
//	vertex[7][0] = vertex[5][0]; vertex[7][1] = vertex[5][1] + r;
//	vertex[14][0] = vertex[1][0]; vertex[14][1] = vertex[1][1] + r;
//	
//	vertex[13][0] = r / tan(DEC2RAG*30.0); vertex[13][1] = 0;
//	vertex[12][0] = vertex[13][0]; vertex[12][1] = vertex[13][1] - r;
//	vertex[11][0] = vertex[2][0]; vertex[11][1] = vertex[2][1] - r;
//
//	vertex[8][0] = -vertex[13][0]; vertex[8][1] = 0;
//	vertex[9][0] = vertex[8][0]; vertex[9][1] = vertex[8][1] - r;
//	vertex[10][0] = vertex[4][0]; vertex[10][1] = vertex[4][1] - r;
//	
//	glBegin(GL_QUADS);
//	glColor3f(4 / 255.0, 43 / 255.0, 146 / 255.0);
//	glVertex2f(vertex[0][0], vertex[0][1]);
//	glVertex2f(vertex[6][0], vertex[6][1]);
//	glVertex2f(vertex[7][0], vertex[7][1]);
//	glVertex2f(vertex[5][0], vertex[5][1]);
//
//	glVertex2f(vertex[1][0], vertex[1][1]);
//	glVertex2f(vertex[2][0], vertex[2][1]);
//	glVertex2f(vertex[12][0], vertex[12][1]);
//	glVertex2f(vertex[13][0], vertex[13][1]);
//
//	glVertex2f(vertex[4][0], vertex[4][1]);
//	glVertex2f(vertex[3][0], vertex[3][1]);
//	glVertex2f(vertex[10][0], vertex[10][1]);
//	glVertex2f(vertex[9][0], vertex[9][1]);
//
//	glColor3f(20 / 255.0, 136 / 255.0, 219 / 255.0);
//	glVertex2f(vertex[0][0], vertex[0][1]);
//	glVertex2f(vertex[6][0], vertex[6][1]);
//	glVertex2f(vertex[14][0], vertex[14][1]);
//	glVertex2f(vertex[1][0], vertex[1][1]);
//
//	glVertex2f(vertex[5][0], vertex[5][1]);
//	glVertex2f(vertex[8][0], vertex[8][1]);
//	glVertex2f(vertex[9][0], vertex[9][1]);
//	glVertex2f(vertex[4][0], vertex[4][1]);
//
//	glVertex2f(vertex[2][0], vertex[2][1]);
//	glVertex2f(vertex[3][0], vertex[3][1]);
//	glVertex2f(vertex[11][0], vertex[11][1]);
//	glVertex2f(vertex[12][0], vertex[12][1]);
//	glEnd();
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-factor, factor,-factor, factor, -1.0, 1.0);
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