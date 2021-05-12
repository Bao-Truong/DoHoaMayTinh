//// Cau5.cpp : Defines the entry point for the console application.
////
//
//
//#include <iostream>
//#include <windows.h>
//#include <gl.h>
//#include <glut.h>
//#include <math.h>
//
//using namespace std;
//
//#define PI			3.1415926
//#define DEG2RAD		(PI/180.0)
//
//const int screenWidth = 600;
//const int screenHeight = 600;
//
//float viewMatrix[4][4];
//float modelMatrix[4][4];
//float modelviewMatrix[4][4];
//float projectionMatrix[4][4];
//
//float HMatrix[4][4];
//
//void  MatrixMul(float a[4][4], float b[4][4], float c[4][4])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			c[i][j] = 0;
//			for (int k = 0; k < 4; k++)
//				c[i][j] += a[i][k] * b[k][j];
//		}
//	}
//}
//void  MatrixMul(float a[4][4], float b[4], float c[4])
//{
//
//	for (int i = 0; i < 4; i++)
//	{
//		c[i] = 0;
//		for (int j = 0; j < 4; j++)
//		{
//			c[i] += a[i][j] * b[j];
//		}
//	}
//}
//void printVector(float a[4])
//{
//	cout << a[0] << ", " << a[1] << ", " << a[2] << ", " << a[3] << ", " << endl;
//}
//void printMatrix(float a[4][4])
//{
//	cout << "print matrix" << endl;
//	printVector(a[0]);
//	printVector(a[1]);
//	printVector(a[2]);
//	printVector(a[3]);
//}
//void printMatrix(float m[])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cout << m[j * 4 + i] << " ";
//		}
//		cout << endl;
//	}
//}
//void TransposeMatrix(float m[], float b[4][4])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			b[i][j] = m[j * 4 + i];
//		}
//	}
//}
///////////////////////////////////////////////////////////
//
//void init()
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glColor3f(1, 0, 0);
//}
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
//	float m[16];
//	float theta = 135;
//	float phi = 45;
//	//float theta = 90;
//	//float phi = 90;
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	float A[4] = { -2.5, 1.5, -1, 1 };
//	float B[4] = { 1.5, 1.5, -1 , 1 };
//	float C[4] = { 1.5, -2.5, -1 , 1 };
//	float D[4] = { -2.5, -2.5,-1, 1 };
//
//	float E[4] = { -102.5, 101.5, -101, 1 };
//	float F[4] = { -98.5, 101.5, -101 , 1 };
//	float G[4] = { -98.5, 97.5, -101 , 1 };
//	float H[4] = { -102.5, 97.5,-101, 1 };
//
//	float A1[4], B1[4], C1[4], D1[4], E1[4], F1[4], G1[4], H1[4];
//
//	/*float HMatrix[4][4] = { { 1, 0, cos(theta*DEG2RAD)/sin(theta*DEG2RAD), 0 },
//							{0, 1, cos(phi*DEG2RAD)/sin(phi*DEG2RAD), 0},
//							{0, 0, 1, 0},
//							{0, 0, 0, 1} };*/
//
//	float HMatrix[4][4] = { { 1.0, 0.0, -1.0, 0 },
//							  { 0.0, 1.0,  1.0, 0 },
//							  { 0.0, 0.0,  1.0, 0 },
//							  { 0.0, 0.0,  0.0, 1 } };
//
//	float left = -1.5, right = 2.5;
//	float bottom = -3.5, top = 0.5;
//	float Near = 1, Far = 101;
//
//	MatrixMul(HMatrix, A, A1);
//	cout << "A1 = ";
//	printVector(A1);
//	MatrixMul(HMatrix, B, B1);
//	cout << "B1 = ";
//	printVector(B1);
//	MatrixMul(HMatrix, C, C1);
//	cout << "C1 = ";
//	printVector(C1);
//	MatrixMul(HMatrix, D, D1);
//	cout << "D1 = ";
//	printVector(D1);
//	MatrixMul(HMatrix, E, E1);
//	cout << "E1 = ";
//	printVector(E1);
//	MatrixMul(HMatrix, F, F1);
//	cout << "F1 = ";
//	printVector(F1);
//	MatrixMul(HMatrix, G, G1);
//	cout << "G1 = ";
//	printVector(G1);
//	MatrixMul(HMatrix, H, H1);
//	cout << "H1 = ";
//	printVector(H1);
//
//	float NMatrix[16] = { 2.0 / (right - left), 0, 0, 0,
//						0, 2.0 / (top - bottom), 0, 0,
//						0, 0, 2.0 / (Near - Far), 0,
//						-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(Far + Near) / (Far - Near), 1 };
//	float MMatrix[4][4] = { { 2.0 / (right - left), 0, 0, -(right + left) / (right - left) },
//							{0, 2.0 / (top - bottom), 0, -(top + bottom) / (top - bottom) },
//							{0, 0, 2.0 / (Near - Far), -(Far + Near) / (Far - Near) },
//							{0, 0, 0, 1}
//	};
//	float PMatrix[4][4];
//	MatrixMul(MMatrix, HMatrix, PMatrix);
//	printMatrix(PMatrix);
//
//	float A2[4], B2[4], C2[4], D2[4];
//	float E2[4], F2[4], G2[4], H2[4];
//
//	MatrixMul(PMatrix, A, A2);
//	cout << "A2 = ";
//	printVector(A2);
//
//	MatrixMul(PMatrix, B, B2);
//	cout << "B2 = ";
//	printVector(B2);
//
//	MatrixMul(PMatrix, C, C2);
//	cout << "C2 = ";
//	printVector(C2);
//
//	MatrixMul(PMatrix, D, D2);
//	cout << "D2 = ";
//	printVector(D2);
//
//	MatrixMul(PMatrix, E, E2);
//	cout << "E2 = ";
//	printVector(E2);
//
//	MatrixMul(PMatrix, F, F2);
//	cout << "F2 = ";
//	printVector(F2);
//
//	MatrixMul(PMatrix, G, G2);
//	cout << "G2 = ";
//	printVector(G2);
//
//	MatrixMul(PMatrix, H, H2);
//	cout << "H2 = ";
//	printVector(H2);
//	///////////////////////////////////////////////////////////////////
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glLoadMatrixf(NMatrix);
//
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
//	GLfloat	mat_diffuse1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glPushMatrix();
//	glutSolidCube(0.5);
//	glPopMatrix();
//
//	glFlush();
//}
//
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv); //initialize the tool kit
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);//set the display mode
//	glutInitWindowSize(screenWidth, screenHeight); //set window size
//	glutInitWindowPosition(0, 0); // set window position on screen
//	glutCreateWindow("Cau 5"); // open the screen window
//
//	glutDisplayFunc(display);
//
//	init();
//	glEnable(GL_DEPTH_TEST);
//
//	glutMainLoop();
//	return 0;
//}
//
//
