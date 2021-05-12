//// Cau3.cpp : Defines the entry point for the console application.
////
//
//// Cau2.cpp : Defines the entry point for the console application.
////
//
//
//#include <iostream>
//#include <math.h>
//#include <glut.h>
//using namespace std;
//
//const int screenWidth = 320 * 2;
//const int screenHeight = 240;
//
//void drawText(float xPos, float yPos, float zPos, const char str[]) {
//	glRasterPos3f(xPos, yPos, zPos); //Position
//
//	void * font = GLUT_BITMAP_TIMES_ROMAN_24;
//	for (int i = 0; i<strlen(str); i++)
//		glutBitmapCharacter(font, str[i]);
//}
//
//void drawAxis() {
//	glLineWidth(3);
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(2, 0, 0);
//
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 2, 0);
//
//	glColor3f(0, 0, 1);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 2);
//	glEnd();
//	glColor3f(0, 0, 0);
//	//drawText(1.9, 0, 0, 'X');
//	//drawText(0, 1.3, 0, 'Y');
//	//drawText(0, 0, 1.9, 'Z');
//}
//
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
//void printMatrix(float m[16]) {
//	for (int i = 0; i < 4; i++) {
//		printf("%8.4f  %8.4f  %8.4f  %8.4f", m[i], m[i + 4], m[i + 8], m[i + 12]);
//		printf("\n");
//	}
//}
//void normalize(float &x, float &y, float &z)
//{
//	float d = sqrt(x*x + y*y + z*z);
//	x = x / d; y = y / d; z = z / d;
//}
//void calculateViewMatrix(float eyeX, float eyeY, float eyeZ,
//	float lookX, float lookY, float lookZ,
//	float upX, float upY, float upZ,
//	float matrix[16])
//
//{
//	float nX, nY, nZ;
//	float uX, uY, uZ;
//	float vX, vY, vZ;
//
//	nX = eyeX - lookX; nY = eyeY - lookY; nZ = eyeZ - lookZ;
//	uX = upY*nZ - upZ*nY; uY = -(upX*nZ - upZ*nX); uZ = upX*nY - upY*nX;
//	vX = nY*uZ - nZ*uY; vY = -(nX*uZ - nZ*uX); vZ = nX*uY - nY*uX;
//
//	normalize(nX, nY, nZ);
//	normalize(uX, uY, uZ);
//	normalize(vX, vY, vZ);
//
//	float dx, dy, dz;
//	dx = -(eyeX*uX + eyeY*uY + eyeZ*uZ);
//	dy = -(eyeX*vX + eyeY*vY + eyeZ*vZ);
//	dz = -(eyeX*nX + eyeY*nY + eyeZ*nZ);
//
//	matrix[0] = uX; matrix[1] = vX; matrix[2] = nX; matrix[3] = 0;
//	matrix[4] = uY; matrix[5] = vY; matrix[6] = nY; matrix[7] = 0;
//	matrix[8] = uZ; matrix[9] = vZ; matrix[10] = nZ; matrix[11] = 0;
//	matrix[12] = dx; matrix[13] = dy; matrix[14] = dz; matrix[15] = 1;
//}
//void display()
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	//Setup camera volume
//	float	aspect = 640.0 / 480;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.2*aspect, 1.2*aspect, -1.2, 1.2, 0.1, 100);
//
//	//Setup camera position, direction
//	glViewport(0, 0, screenWidth / 2, screenHeight);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(1, 2, 3, 0.0, 0.0, 0.0, 0, 1, 0);
//
//	glDisable(GL_LIGHTING);
//	drawAxis();
//
//	setupLight();
//
//	glColor3d(1, 0, 0);
//	GLfloat	mat_diffuse1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glPushMatrix();
//	glutSolidTeapot(0.5);
//	glPopMatrix();
//	//////////////////////////////////////////////////////////////
//	glViewport(screenWidth / 2, 0, screenWidth / 2, screenHeight);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	//gluLookAt(6, 7, 8, 0.0, 0.0, 0.0, 0, 1, 0);
//	float	matrix[16];
//	calculateViewMatrix(4, 4, 4, 8, 8, 8, -1/sqrt(6), 2/sqrt(6), -1/sqrt(6), matrix);
//	printMatrix(matrix);
//	glLoadMatrixf(matrix);
//
//	glDisable(GL_LIGHTING);
//	drawAxis();
//
//	setupLight();
//
//	glColor3d(1, 0, 0);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glPushMatrix();
//	glutSolidTeapot(0.5);
//	glPopMatrix();
//
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
//	glutCreateWindow("Cau 3"); // open the screen window
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
