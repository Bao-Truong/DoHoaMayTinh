// Cau6.cpp : Defines the entry point for the console application.
//


#include <windows.h>
#include <math.h>
#include <glut.h>
#include <iostream>

using namespace std;
const int screenWidth = 600;
const int screenHeight = 600;

float viewMatrix[4][4];
float modelMatrix[4][4];
float modelviewMatrix[4][4];
float projectionMatrix[4][4];

void  MatrixMul(float a[4][4], float b[4][4], float c[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k<4; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
}
void  MatrixMul(float a[4][4], float b[4], float c[4])
{

	for (int i = 0; i < 4; i++)
	{
		c[i] = 0;
		for (int j = 0; j<4; j++)
		{
			c[i] += a[i][j] * b[j];
		}
	}
}
void printVector(float a[4])
{
	cout << a[0] << ", " << a[1] << ", " << a[2] << ", " << a[3] << ", " << endl;
}
void printMatrix(float a[4][4])
{
	cout << "print matrix" << endl;
	printVector(a[0]);
	printVector(a[1]);
	printVector(a[2]);
	printVector(a[3]);
}
void printMatrix(float m[])
{
	for (int i = 0; i< 4; i++)
	{
		for (int j = 0; j< 4; j++)
		{
			cout << m[j * 4 + i] << " ";
		}
		cout << endl;
	}
}
void TransposeMatrix(float m[], float b[4][4])
{
	for (int i = 0; i< 4; i++)
	{
		for (int j = 0; j< 4; j++)
		{
			b[i][j] = m[j * 4 + i];
		}
	}
}
/////////////////////////////////////////////////////////

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1, 0, 0);
}


void display()
{
	float m[16];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	///////////////////////////////////////////////////////
	/// (1)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glTranslatef(0, 4, 0);
	//glScalef(2, 1, 2);
	//glRotatef(90, 0, 1, 0);
	glTranslatef(1, 2, 0);
	glRotatef(45, 0, 1, 0);
	glRotatef(45, 0, 1, 0);

	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	TransposeMatrix(m, modelMatrix);
	cout << "Model Matrix " << endl;
	printMatrix(modelMatrix);
	cout << "/////////////////////////////////" << endl;

	///////////////////////////////////////////////////////
	/// (2)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-5, 0, 5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	TransposeMatrix(m, viewMatrix);
	cout << "View Matrix " << endl;
	printMatrix(viewMatrix);
	cout << "/////////////////////////////////" << endl;

	///////////////////////////////////////////////////////
	/// (3)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(-10, 0, 10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt(-5, 0, 5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//glTranslatef(0, 4, 0);
	//glScalef(2, 1, 2);
	//glRotatef(90, 0, 1, 0);
	glTranslatef(1, 2, 0);
	glRotatef(45, 0, 1, 0);
	glRotatef(45, 0, 1, 0);

	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	TransposeMatrix(m, modelviewMatrix);
	cout << "Model-View Matrix " << endl;
	printMatrix(modelviewMatrix);
	cout << "/////////////////////////////////" << endl;

	///////////////////////////////////////////////////////
	/// (4)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5, 5, -5, 5, 5, 15);
	
	glGetFloatv(GL_PROJECTION_MATRIX, m);
	TransposeMatrix(m, projectionMatrix);
	cout << "Projection Matrix " << endl;
	printMatrix(projectionMatrix);
	cout << "/////////////////////////////////" << endl;

	//////// Calculate point /////////////////////////////////
	// (5)
	float	pointB[4] = { -1, -1, 1, 1 };
	float	pointD[4] = { -1, 0, -1, 1 };

	float	pointBW[4], pointBV[4], pointBC[4];//world, view, clip
	float	pointDW[4], pointDV[4], pointDC[4];//world, view, clip

	MatrixMul(modelMatrix, pointB, pointBW);
	cout << "BWorld = ";
	printVector(pointBW);
	MatrixMul(viewMatrix, pointBW, pointBV);
	cout << "BView = ";
	printVector(pointBV);
	MatrixMul(projectionMatrix, pointBV, pointBC);
	cout << "BClip = ";
	printVector(pointBC);
	pointBC[0] /= pointBC[3]; pointBC[1] /= pointBC[3]; pointBC[2] /= pointBC[3]; pointBC[3] = 1;
	cout << "BClip = ";
	printVector(pointBC);
	////////////////////////////////////////////////////////////////////
	MatrixMul(modelMatrix, pointD, pointDW);
	cout << "DWorld = ";
	printVector(pointDW);
	MatrixMul(viewMatrix, pointDW, pointDV);
	cout << "DView = ";
	printVector(pointDV);
	MatrixMul(projectionMatrix, pointDV, pointDC);
	cout << "DClip = ";
	printVector(pointDC);
	pointDC[0] /= pointDC[3]; pointDC[1] /= pointDC[3]; pointDC[2] /= pointDC[3]; pointDC[3] = 1;
	cout << "DClip = ";
	printVector(pointDC);

	glFlush();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);//set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(0, 0); // set window position on screen
	glutCreateWindow("Cau 6"); // open the screen window

	glutDisplayFunc(display);

	init();
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 0;
}






