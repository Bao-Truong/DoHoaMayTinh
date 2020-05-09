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
//float factor = 4;
//
//float m[16];
//float vec[4][2] = {
//	{-3,1},
//{-2,3},
//{-1,1},
//{-2,2}
//};
//
//
//void drawfigure() {
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < 4; i++)
//		glVertex2fv(vec[i]);
//	glEnd();
//
//}
//struct point2d {
//	float x;
//	float y;
//};
//void printmat(float m[16])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		cout << m[i] << "\t\t" << m[i + 4] << "\t\t" << m[i + 8] << "\t\t" << m[i + 12] << endl;
//	}
//}
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
//	glEnable(GL_DEPTH_TEST);
//
//	glColor3f(1, 0, 0);
//	drawfigure();
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	//Method 1
//	{
//		//glPushMatrix();
//		//
//		//glScalef(0.5, 0.5, 1);
//		//drawfigure();
//		//glPopMatrix();
//
//		//glPushMatrix();	
//		//glRotatef(180, 0, 0, 1);
//		//glScalef(0.5, 0.5, 1);
//		//drawfigure();
//		//glPopMatrix();
//
//		glColor3f(0, 0, 1);
//		glPushMatrix();
//		glTranslatef(0, 1.5,0);
//		glRotatef(-180, 0, 0, 1);
//		glScalef(0.5, 0.5, 1);
//		drawfigure();
//		glGetFloatv(GL_MODELVIEW_MATRIX, m);
//		printmat(m);
//		glPopMatrix();
//	}
//	//Method2
//	
//	{
//		glColor3f(0, 1, 1);
//		glPushMatrix();
//		
//		glTranslatef(2, -2, 0);
//		drawfigure();
//		glPopMatrix();
//
//		glPushMatrix();
//	
//		glScalef(-0.5, -0.5, 1);
//		glTranslatef(2, -2, 0);
//		drawfigure();
//		glPopMatrix();
//
//		glPushMatrix();
//		glTranslatef(1, 0.5,0);
//		glScalef(-0.5, -0.5, 1);
//		glTranslatef(2, -2,0);
//		drawfigure();
//		glPopMatrix();
//	}
//
//
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-factor, factor, -factor, factor, -1.0, 1.0);
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