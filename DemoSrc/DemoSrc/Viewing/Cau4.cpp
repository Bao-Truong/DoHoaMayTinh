//// Cau4.cpp : Defines the entry point for the console application.
////
//// 3-ViewingNTransformation.cpp : Defines the entry point for the console application.
////
//
//#include <iostream>
//#include <math.h>
//#include <glut.h>
//using namespace std;
//
//#define		PI		3.1415926
//const int unit = 400;
//const int screenWidth = unit * 3;
//const int screenHeight = unit;
//
//void drawGrid(float inc = 0.1)
//{
//	float start = -20;
//	float end = -start;
//
//	glLineWidth(1);
//	glColor3f(0, 0, 0);
//	float current = start;
//	glBegin(GL_LINES);
//	while (current <= end)
//	{
//		glVertex3f(-200, 0, current);
//		glVertex3f(200, 0, current);
//		current += inc;
//	}
//	current = start;
//	while (current <= end)
//	{
//		glVertex3f(current, 0, -200);
//		glVertex3f(current, 0, 200);
//		current += inc;
//	}
//	glEnd();
//}
//void setupLight()
//{
//	//Set up light
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glShadeModel(GL_SMOOTH);
//
//	GLfloat	lightIntensity[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//	GLfloat light_position[] = { 10, 9, 8.0f, 0.0f };
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
//
//	GLfloat	lightIntensity1[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//	GLfloat light_position1[] = { 10, 9, -8.0f, 0.0f };
//	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightIntensity1);
//}
//
//void display()
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	GLfloat	mat_diffuse1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//
//	//Ortho
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-2.5, 1.5, -2.3, 2.7, 0.3, 300);
//
//	//Setup camera position, direction
//	glViewport(0, 0, screenWidth / 3, screenHeight);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, 0, 1, 0);
//
//	glDisable(GL_LIGHTING);
//	drawGrid();
//
//	setupLight();
//
//	glColor3d(1, 0, 0);
//
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glPushMatrix();
//	glutSolidCube(0.5);
//	glPopMatrix();
//	//////////////////////////////////////////////////////////////
//	glViewport(1.0*screenWidth / 3, 0, screenWidth / 3, screenHeight);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	float m[16] = { 0.5,  0,     0, 0,
//					0,    0.4,   0, 0,
//					0,    0,     -0.0067, 0,
//					0.25, -2.0 / 25.0, -1.0020, 1 }; 
//	glMultMatrixf(m);
//
//	//Setup camera position, direction
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, 0, 1, 0);
//
//	glDisable(GL_LIGHTING);
//	drawGrid();
//
//	setupLight();
//
//	glColor3d(1, 0, 0);
//
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glPushMatrix();
//	glutSolidCube(0.5);
//	glPopMatrix();
//	//////////////////////////////////////////////////////////////
//	glViewport(2.0*screenWidth / 3, 0, screenWidth / 3, screenHeight);
//	
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glScalef(0.5, 0.4, -0.0067);
//	glTranslatef(0.25, -2.0 / 25.0, -1.0020);
//
//
//	//Setup camera position, direction
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(2, 2, 2, 0.0, 0.0, 0.0, 0, 1, 0);
//
//	glDisable(GL_LIGHTING);
//	drawGrid();
//
//	setupLight();
//
//	glColor3d(1, 0, 0);
//
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glPushMatrix();
//	glutSolidCube(0.5);
//	glPopMatrix();
//	//////////////////////////////////////////////////////////////////
//	
//	glFlush();
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv); //initialize the tool kit
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);//set the display mode
//	glutInitWindowSize(screenWidth, screenHeight); //set window size
//	glutInitWindowPosition(100, 100); // set window position on screen
//	glutCreateWindow("Cau 4"); // open the screen window
//
//	glutDisplayFunc(display);
//
//	glEnable(GL_DEPTH_TEST);
//
//
//	glutMainLoop();
//	return 0;
//}
//
//
//
//
//
//
