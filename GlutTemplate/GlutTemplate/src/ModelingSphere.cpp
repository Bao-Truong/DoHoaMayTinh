//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 640
//#define screen_Height 480
//#define PI 3.14159265359
//#define DEC2RAG PI/180.0
//#define print(x) { cout<<x;}
//using namespace std;
//struct point2d {
//	float x;
//	float y;
//};
//void drawQuad_Sphere(int angle) {
//
//	float x, y, z;
//	float phi20;
//	float phir, thetar;
//	for (float phi = -90 + angle; phi <= 90 - angle; phi += angle) // đo độ nâng của các vĩ tuyến (vẽ từ dưới lên) -90 -> 90
//	{
//		phir = DEC2RAG * phi;		
//		phi20 = (DEC2RAG)*(phi + angle);				
//		glBegin(GL_QUAD_STRIP);
//		for (float theta = -180; theta <= 180; theta += angle)
//		{
//			thetar = DEC2RAG * theta;			
//			x = sin(thetar)*cos(phir);
//			z = cos(thetar)*cos(phir);
//			y = sin(phir);
//			glVertex3d(x, y, z);
//			
//			x = sin(thetar)*cos(phi20);
//			z = cos(thetar)*cos(phi20);
//			y = sin(phi20);
//			glVertex3d(x, y, z);
//		
//		}
//		glEnd();
//	}
//}
//void drawtopbot_Sphere(int angle) {
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex3f(0, 1.0, 0.0);
//	float phi80 = DEC2RAG * (90-angle);
//	float x, y, z;
//	float thetar;
//	y = sin(phi80);
//	for (float theta = -180; theta <= 180; theta += 20)
//	{
//		thetar = DEC2RAG * theta;
//		x = sin(thetar)*cos(phi80);
//		z = cos(thetar)*cos(phi80);
//		glVertex3f(x, y, z);
//	}
//	glEnd();
//
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex3f(0, -1.0, 0.0);
//
//	y = -sin(phi80);
//	for (float theta = -180; theta <= 180; theta += 20)
//	{
//		thetar = DEC2RAG * theta;
//		x = sin(thetar)*cos(phi80);
//		z = cos(thetar)*cos(phi80);
//		glVertex3f(x, y, z);
//	}
//	glEnd();
//}
//void drawSphere() {
//	int angle = 10;
//	drawQuad_Sphere(angle);
//	drawtopbot_Sphere(angle);
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	//glEnable(GL_DEPTH_TEST);
//
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glLineWidth(2);
//	
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(1.5, 1.5, 1.5, 0, 0, 0, 0.0, 1.0, 0.0);
//	
//	drawSphere();
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glColor3f(0.0, 0.0, 0.0);
//	glFrontFace(GL_CW);
//	glEnable(GL_CULL_FACE);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.2, 1.2, -1.2, 1.2,-10.0, 10.0);
//
//
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(500, 500);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//
//	glutMainLoop();
//}