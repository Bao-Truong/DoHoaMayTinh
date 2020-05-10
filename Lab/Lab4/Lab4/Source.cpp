// Lab3.cpp : Defines the entry point for the console application.
//

#include "supportClass.h"
#include "Mesh.h"

#include <iostream>
#include <windows.h>
#include <gl.h>
#include <glut.h>
#include <math.h>


using namespace std;

#define PI		3.1415926
#define DEC2RAG PI/180.0
int		screenWidth = 1200;
int		screenHeight = 600;

float camera_angle;
float camera_height;
float camera_dis;
float camera_x, camera_y, camera_z;
float lookAt_x, lookAt_y, lookAt_z;
float camera_angle_m[16];

bool	bWireFrame = false;

float	baseRadius = 0.6;
float	baseHeight = 0.5;
float	baseRotateStep = 5;

float	cylRadius = 0.3;
float	cylHeight = 1.5;
float   cylMaxScaleY = 2.0;
float	cylScaleStep = 0.05;

float	body1SizeX = 3;
float	body1SizeY = 0.1;
float	body1SizeZ = 1.2;

float	holder1SizeX = 1.2;
float	holder1SizeY = 0.3;
float	holder1SizeZ = 0.5;
float	holder1Cutlength = 0.3;

float	holder2SizeX = 1.0;
float	holder2SizeY = 0.9;
float	holder2SizeZ = 0.5;
float	holder2Cutlength = 0.3;

float slider1SizeX = 0.4, slider2SizeX = 0.4;
float slider1SizeY = 0.2, slider2SizeY = 0.4;
float slider1SizeZ = 0.5, slider2SizeZ = 0.5;
float slider1Ulength = 0.45, slider2Ulength = 0.38;
float slider1Llength = 0.25, slider2Llength = 0.2;

float	holder3Size = 0.2;

float	tayquaySizeX = 0.5;
float	tayquaySizeY = 0.25;
float	tayquayfRadius = 0.1;
float	tayquaynRadius = 0.05;
float	tayquayfHeight = 0.35;

float	taynoi1SizeX = 1.9;
float	taynoi1SizeY = 0.25;
float	taynoi1fRadius = 0.1;
float	taynoi1nRadius = 0.05;
float	taynoi1fHeight = 0.35;

float	taynoi2SizeX = taynoi1SizeX;
float	taynoi2SizeY = taynoi1SizeY;
float	taynoi2fRadius = taynoi1fRadius;
float	taynoi2nRadius = taynoi1nRadius;
float	taynoi2fHeight = taynoi1fHeight;

float	taynoi3SizeX = taynoi1SizeX;
float	taynoi3SizeY = taynoi1SizeY;
float	taynoi3fRadius = taynoi1fRadius;
float	taynoi3nRadius = taynoi1nRadius;
float	taynoi3fHeight = taynoi1fHeight;

float	key1fHeight = tayquayfHeight - 0.01;
float	key1fRadius = tayquaynRadius - 0.01;

float	key2fHeight = 2 * taynoi1fHeight - 0.01;
float	key2fRadius = tayquaynRadius - 0.01;

float	key3fHeight = taynoi2fHeight - 0.01;
float	key3fRadius = taynoi2nRadius - 0.01;

float	key4fHeight = taynoi3fHeight - 0.01;
float	key4fRadius = taynoi3nRadius - 0.01;

float	key5fHeight = 3 * taynoi1fHeight - 0.01;
float	key5fRadius = taynoi2nRadius - 0.01;

Mesh	base; // đế
Mesh	cyl; //trụ nối đế và mặt bàn
Mesh	body1; // mặt bàn
Mesh	holder1;
Mesh	holder2;
Mesh	holder3;
Mesh	slider1;
Mesh	slider2;

Mesh	TayNoi1;
Mesh	TayNoi2;
Mesh	TayNoi3;
Mesh	TayQuay;

Mesh	Key1; //Noi bar do voi de^' xanh bien
Mesh	Key2;// Noi bar do voi bar xanh bien nhat
Mesh	Key3; //Noi bar Xanh Dam va slider1
Mesh	Key4; // Noi Bar Xam vs slider 2
Mesh	Key5; // Noi 3 cai Tay Noi 1 2 3

point2 A, B, C, center;
float radius;
bool bFinish;
void findExCircle()
{
	A.set(TayNoi1.slideX, TayNoi1.slideZ);
	B.set(TayNoi2.slideX, TayNoi2.slideZ);
	C.set(TayNoi3.slideX, TayNoi3.slideZ);
	glPointSize(10);
	glColor3f(1, 0, 1);
	A.draw();
	B.draw();
	C.draw();
	vector a, b, c, a_perp, c_perp;
	float t, u;

	a.set(B.x - A.x, B.y - A.y);
	b.set(C.x - B.x, C.y - B.y);
	c.set(A.x - C.x, A.y - C.y);

	a_perp.set(-a.y, a.x);
	c_perp.set(-c.y, c.x);

	float factor = b.dotProduct(c) / a_perp.dotProduct(c);
	vector tmp = a.add(a_perp.scale(factor));
	tmp = tmp.scale(0.5);
	center = A.add(tmp);
	//radius = sqrt((A.x - center.x)*(A.x - center.x) +
	//	(A.y - center.y)* (A.y - center.y));
	center.draw();
	bFinish = true;
}
void drawAxis()
{
	glPushMatrix();

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(-4, 0, 0);//x
	glVertex3f(4, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);//y
	glVertex3f(0, 4, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -4);//z
	glVertex3f(0, 0, 4);
	glEnd();

	glPopMatrix();
}
void myKeyboard(unsigned char key, int x, int y)
{
	float	fRInc;
	float	fAngle;
	switch (key)
	{
	case '1':
		base.rotateY += baseRotateStep;

		if (base.rotateY > 360)
			base.rotateY -= 360;
		break;
	case '2':
		base.rotateY -= baseRotateStep;
		if (base.rotateY < 0)
			base.rotateY += 360;
		break;
	case '3':
		TayNoi1.rotateY -= baseRotateStep;
		Key1.rotateY += baseRotateStep;
		if (Key1.rotateY > 360)
		{
			Key1.rotateY -= 360;

		}

		break;
	case '4':
		TayNoi1.rotateY += baseRotateStep;
		Key1.rotateY -= baseRotateStep;
		if (TayQuay.rotateY < 0)
			TayQuay.rotateY += 360;
		break;
	case '5':
		if (holder2SizeX*holder2.scaleX / 2 + slider2.slideX < (body1SizeX * body1.scaleX - slider2SizeX))
		{
			slider1.slideX += 0.1;
			slider2.slideX += 0.1;
		}
		break;
	case '6':
		if (-body1SizeX * body1.scaleX + slider1SizeX * slider1.scaleX / 2.0 + slider1.slideX > (-body1SizeX * body1.scaleX + slider1SizeX))
		{
			slider1.slideX -= 0.1;
			slider2.slideX -= 0.1;
		}
		break;
	case 'w':
	case 'W':
		bWireFrame = !bWireFrame;
		break;
	case '7':
		if (cyl.slideY*cyl.scaleY + baseHeight < 2)
		{
			cyl.scaleY += 0.1;
		}
		break;
	case '8':
		if (cyl.slideY*cyl.scaleY + baseHeight > 1)
			cyl.scaleY -= 0.1;
		break;
	case '+':
		camera_dis += 0.1;
		break;
	case '-':
		camera_dis -= 0.1;
		break;
	}
	glutPostRedisplay();
}
void mySpecial(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		camera_height += 0.5;
		
	}
	if (key == GLUT_KEY_DOWN)
	{
		camera_height -= 0.5;
		
	}
	if (key == GLUT_KEY_RIGHT)
		camera_angle += 1;
	if (key == GLUT_KEY_LEFT)
		camera_angle -= 1;
	
	glutPostRedisplay();
}
void drawBase() //Đế dưới cùng
{
	glPushMatrix();

	glTranslated(0, base.slideY, 0);
	glRotatef(base.rotateY, 0, 1, 0);

	if (bWireFrame)
		base.DrawWireframe();
	else
		base.DrawColor();

	glPopMatrix();
}
void drawCyl() //Trụ nối đế và mặt bàn
{
	glPushMatrix();

	glTranslated(0, cyl.slideY*cyl.scaleY + baseHeight, 0);
	glScalef(cyl.scaleX, cyl.scaleY, cyl.scaleZ);
	glTranslated(0, -(cyl.slideY*cyl.scaleY + baseHeight), 0);

	glTranslated(0, cyl.slideY*cyl.scaleY + baseHeight, 0);
	glRotatef(base.rotateY, 0, 1, 0);


	if (bWireFrame)
		cyl.DrawWireframe();
	else
		cyl.DrawColor();

	glPopMatrix();
}
void drawBody1()// Mặt bàn
{
	glPushMatrix();
	base.scaleX = base.scaleY = base.scaleZ = 2;
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(0,  cylHeight * cyl.scaleY + baseHeight, 0);
	glScalef(base.scaleX, base.scaleY, base.scaleZ);
	if (bWireFrame)
		body1.DrawWireframe();
	else
		body1.DrawColor();

	glPopMatrix();
}
void drawHolder1()// Mặt bàn
{
	glPushMatrix();
	holder1.scaleX = 2;
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(-body1SizeX * body1.scaleX + holder1SizeX * holder1.scaleX / 2 - .0001, holder1SizeY / 2.0 + body1SizeY + cylHeight * cyl.scaleY + baseHeight, -body1SizeZ * body1.scaleZ);
	glScalef(holder1.scaleX, holder1.scaleY, holder1.scaleZ);
	if (bWireFrame)
		holder1.DrawWireframe();
	else
		holder1.DrawColor();
	glPopMatrix();
}
void drawHolder2()// Mặt bàn
{
	glPushMatrix();
	holder2.scaleX = 2;
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(body1SizeX * body1.scaleX - holder2SizeX * holder2.scaleX / 2 - .0001, holder1SizeY / 2.0 + body1SizeY + cylHeight * cyl.scaleY + baseHeight, -body1SizeZ * body1.scaleZ);
	glScalef(holder2.scaleX, holder2.scaleY, holder2.scaleZ);
	if (bWireFrame)
		holder2.DrawWireframe();
	else
		holder2.DrawColor();
	glPopMatrix();
}

void drawHolder3() {
	glPushMatrix();

	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(0, 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight, body1SizeZ * body1.scaleZ - holder3Size / 2.0);

	glScalef(holder3.scaleX, holder3.scaleY, holder3.scaleZ);
	if (bWireFrame)
		holder3.DrawWireframe();
	else
		holder3.DrawColor();
	glPopMatrix();
}
void drawSlider1() {
	glPushMatrix();
	slider1.scaleY = -1;
	slider1.scaleX = 2;
	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(-body1SizeX * body1.scaleX + slider1SizeX * slider1.scaleX / 2.0 + slider1.slideX,
		0.01 + slider1SizeY + holder1SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight,
		-body1SizeZ * body1.scaleZ);

	glScalef(slider1.scaleX, slider1.scaleY, slider1.scaleZ);
	if (bWireFrame)
		slider1.DrawWireframe();
	else
		slider1.DrawColor();
	glPopMatrix();
}
void drawSlider2() {
	glPushMatrix();
	slider2.scaleY = -1;
	slider2.scaleX = 2;

	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(holder2SizeX*holder2.scaleX / 2 + slider2.slideX,
		0.01 + slider2SizeY + holder2SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight,
		-body1SizeZ * body1.scaleZ);
	glScalef(slider2.scaleX, slider2.scaleY, slider2.scaleZ);
	if (bWireFrame)
		slider2.DrawWireframe();
	else
		slider2.DrawColor();
	glPopMatrix();
}
void drawTayQuay() {
	glPushMatrix();

	{ // Xoay quanh de
		glRotatef(base.rotateY, 0, 1, 0);
	}
	{ // Xoay quanh Chot Key1
		glTranslated(0, tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight, body1SizeZ * body1.scaleZ - holder3Size / 2.0);
		glRotatef(Key1.rotateY, 0, 1, 0);
		glTranslated(0, -(tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight), -(body1SizeZ * body1.scaleZ - holder3Size / 2.0));
	}
	{// Di chuyen toi vi tri cu
		glTranslated(tayquaySizeX / 2.0, tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight, body1SizeZ * body1.scaleZ - holder3Size / 2.0);
		glScalef(TayQuay.scaleX, TayQuay.scaleY, TayQuay.scaleZ);
	}

	if (bWireFrame)
		TayQuay.DrawWireframe();
	else
		TayQuay.DrawColor();
	glPopMatrix();
}

void drawKey1() {
	glPushMatrix();

	glRotatef(base.rotateY, 0, 1, 0);

	glTranslated(0, tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight, body1SizeZ * body1.scaleZ - holder3Size / 2.0);
	glScalef(TayQuay.scaleX, TayQuay.scaleY, TayQuay.scaleZ);
	//cout << tayquaySizeX << " " << tayquaySizeY <<" "<< TayQuay.scaleX << endl;
	if (bWireFrame)
		Key1.DrawWireframe();
	else
		Key1.DrawColor();
	glPopMatrix();
}
void drawKey2() {
	glPushMatrix();

	glRotatef(base.rotateY, 0, 1, 0);
	{ // Xoay quanh Chot Key1
		glTranslated(0, tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight, body1SizeZ * body1.scaleZ - holder3Size / 2.0);
		glRotatef(Key1.rotateY, 0, 1, 0);
		glTranslated(0, -(tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight), -(body1SizeZ * body1.scaleZ - holder3Size / 2.0));
	}
	glTranslated(tayquaySizeX, tayquayfHeight / 2 + tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight, body1SizeZ * body1.scaleZ - holder3Size / 2.0);
	glScalef(Key2.scaleX, Key2.scaleY, Key2.scaleZ);
	//cout << tayquaySizeX << " " << tayquaySizeY <<" "<< TayQuay.scaleX << endl;
	if (bWireFrame)
		Key2.DrawWireframe();
	else
		Key2.DrawColor();
	glPopMatrix();
}
void drawKey3() {
	glPushMatrix();

	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(-taynoi2SizeX / 2 + taynoi2SizeX / 2 + -body1SizeX * body1.scaleX + slider1SizeX * slider1.scaleX / 2.0 + slider1.slideX,
		taynoi2fHeight / 2 + 0.01 + slider1SizeY + holder1SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight,
		slider1SizeZ / 2 + -body1SizeZ * body1.scaleZ);

	glScalef(Key3.scaleX, Key3.scaleY, Key3.scaleZ);
	if (bWireFrame)
		Key3.DrawWireframe();
	else
		Key3.DrawColor();
	glPopMatrix();
}
void drawKey4() {
	glPushMatrix();

	glRotatef(base.rotateY, 0, 1, 0);
	glTranslated(+holder2SizeX * holder2.scaleX / 2 + slider2.slideX,
		taynoi3fHeight / 2 + 0.01 + slider2SizeY + holder2SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight,
		slider2SizeZ / 2 + -body1SizeZ * body1.scaleZ);
	glScalef(Key4.scaleX, Key4.scaleY, Key4.scaleZ);
	if (bWireFrame)
		Key4.DrawWireframe();
	else
		Key4.DrawColor();
	glPopMatrix();
}
void drawKey5() {
	glPushMatrix();
	glRotatef(base.rotateY, 0, 1, 0);

	if (bFinish == true)
	{
		bFinish = false;
		Key5.slideX = center.x;
		Key5.slideZ = center.y;
		//cout << Key5.slideX << " " << Key5.slideZ << " " << endl;
		glTranslated(Key5.slideX,
			TayNoi1.slideY,
			Key5.slideZ);
		glScalef(Key5.scaleX, Key5.scaleY, Key5.scaleZ);
		if (bWireFrame)
			Key5.DrawWireframe();
		else
			Key5.DrawColor();
	}
	glPopMatrix();
}
void drawTayNoi1() {
	glPushMatrix();
	TayNoi1.rotateY = -47.0;
	{
		glRotatef(base.rotateY, 0, 1, 0);
	}
	//

	{ // Xoay quanh Chot Key1
		glTranslated(0, tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight, body1SizeZ * body1.scaleZ - holder3Size / 2.0);

		glRotatef(Key1.rotateY, 0, 1, 0);

		glTranslated(0, -(tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight), -(body1SizeZ * body1.scaleZ - holder3Size / 2.0));
	}

	{ // Xoay quanh Chot Key2
		glTranslated(tayquaySizeX, tayquayfHeight / 2 + tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight, body1SizeZ * body1.scaleZ - holder3Size / 2.0);
		glRotatef(TayNoi1.rotateY, 0, 1.0, 0);
		glTranslated(-tayquaySizeX,
			-(tayquayfHeight / 2 + tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight),
			-(body1SizeZ * body1.scaleZ - holder3Size / 2.0));
	}
	{//Xoay quanh Key5

		glTranslatef(Key5.slideX, Key5.slideY, Key5.slideZ);
		glRotatef(Key1.rotateY, 0, 1.0, 0);

		glTranslatef(-Key5.slideX, -Key5.slideY, -Key5.slideZ);
	}

	TayNoi1.slideX = tayquaySizeX;
	TayNoi1.slideY = key1fHeight + tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight;
	TayNoi1.slideZ = body1SizeZ * body1.scaleZ - holder3Size / 2.0;

	glTranslatef(-(taynoi1SizeX / 2 - tayquaySizeX),
		key1fHeight + tayquayfHeight + 2 * holder3Size + body1SizeY + cylHeight * cyl.scaleY + baseHeight,
		body1SizeZ * body1.scaleZ - holder3Size / 2.0);
	glScalef(TayQuay.scaleX, TayQuay.scaleY, TayQuay.scaleZ);

	if (bWireFrame)
		TayNoi1.DrawWireframe();
	else
		TayNoi1.DrawColor();
	glPopMatrix();
}
void drawTayNoi2() {
	glPushMatrix();

	glRotatef(base.rotateY, 0, 1, 0);

	{
		TayNoi2.rotateY = -20;
		glTranslated(-taynoi2SizeX / 2 + taynoi2SizeX / 2 + -body1SizeX * body1.scaleX + slider1SizeX * slider1.scaleX / 2.0 + slider1.slideX,
			taynoi2fHeight / 2 + 0.01 + slider1SizeY + holder1SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight,
			slider1SizeZ / 2 + -body1SizeZ * body1.scaleZ);
		glRotatef(TayNoi2.rotateY, 0, 1, 0);
		glTranslated(-(-taynoi2SizeX / 2 + taynoi2SizeX / 2 + -body1SizeX * body1.scaleX + slider1SizeX * slider1.scaleX / 2.0 + slider1.slideX),
			-(taynoi2fHeight / 2 + 0.01 + slider1SizeY + holder1SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight),
			-(slider1SizeZ / 2 + -body1SizeZ * body1.scaleZ));

	}
	TayNoi2.slideX = -body1SizeX * body1.scaleX + slider1SizeX * slider1.scaleX / 2.0 + slider1.slideX;
	TayNoi2.slideY = taynoi2fHeight / 2 + 0.01 + slider1SizeY + holder1SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight;
	TayNoi2.slideZ = slider1SizeZ / 2 + -body1SizeZ * body1.scaleZ;

	glTranslated(taynoi2SizeX / 2 + -body1SizeX * body1.scaleX + slider1SizeX * slider1.scaleX / 2.0 + slider1.slideX,
		taynoi2fHeight / 2 + 0.01 + slider1SizeY + holder1SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight,
		slider1SizeZ / 2 + -body1SizeZ * body1.scaleZ);

	glScalef(TayNoi2.scaleX, TayNoi2.scaleY, TayNoi2.scaleZ);
	if (bWireFrame)
		TayNoi2.DrawWireframe();
	else
		TayNoi2.DrawColor();
	glPopMatrix();
}
void drawTayNoi3() {
	glPushMatrix();

	glRotatef(base.rotateY, 0, 1, 0);
	{
		TayNoi3.rotateY = 20;
		glTranslated(+holder2SizeX * holder2.scaleX / 2 + slider2.slideX,
			taynoi3fHeight / 2 + 0.01 + slider2SizeY + holder2SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight,
			slider2SizeZ / 2 + -body1SizeZ * body1.scaleZ);
		glRotated(TayNoi3.rotateY, 0, 1, 0);
		glTranslated(-(+holder2SizeX * holder2.scaleX / 2 + slider2.slideX),
			-(taynoi3fHeight / 2 + 0.01 + slider2SizeY + holder2SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight),
			-(slider2SizeZ / 2 + -body1SizeZ * body1.scaleZ));
	}
	TayNoi3.slideX = +holder2SizeX * holder2.scaleX / 2 + slider2.slideX;
	TayNoi3.slideY = taynoi3fHeight / 2 + 0.01 + slider2SizeY + holder2SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight;
	TayNoi3.slideZ = slider2SizeZ / 2 + -body1SizeZ * body1.scaleZ;
	glTranslated(-taynoi3SizeX / 2 + holder2SizeX * holder2.scaleX / 2 + slider2.slideX,
		taynoi3fHeight / 2 + 0.01 + slider2SizeY + holder2SizeY + body1SizeY + cylHeight * cyl.scaleY + baseHeight,
		slider2SizeZ / 2 + -body1SizeZ * body1.scaleZ);
	glScalef(TayNoi3.scaleX, TayNoi3.scaleY, TayNoi3.scaleZ);
	if (bWireFrame)
		TayNoi3.DrawWireframe();
	else
		TayNoi3.DrawColor();
	glPopMatrix();
}
void myDisplay()
{
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, camera_dis, 20.0);

	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(-8, 10, 8, 0, 1, 0, 0, 1, 0);	
	gluLookAt(camera_x , camera_y, camera_z , 0, 1, 0, 0, 1, 0);
	
	//glTranslatef(camera_x + camera_dis, 0, camera_z + camera_dis);
	glRotatef(camera_angle, 0, 1, 0);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, screenWidth, screenHeight);

	drawAxis();
	drawBase();
	drawCyl();

	drawBody1();

	drawHolder1();
	drawHolder2();
	drawHolder3();

	drawSlider1();
	drawSlider2();

	drawTayQuay();

	drawTayNoi1();
	drawTayNoi2();
	drawTayNoi3();

	findExCircle();

	drawKey1();
	drawKey2();
	drawKey3();
	drawKey4();
	drawKey5();
	glFlush();
	glutSwapBuffers();
}

void myInit()
{
	float	fHalfSize = 4;
	camera_angle = 0;
	camera_height = 0;
	camera_dis = 4;

	camera_x = -8;
	camera_y = 10;
	camera_z = 8;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 0.0f);

	//glFrontFace(GL_CCW);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);

	

}

int main(int argc, char* argv[])
{

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//set the display mode
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(100, 100); // set window position on screen
	glutCreateWindow("Lab3-2019-2020"); // open the screen window

	base.CreateCylinder(20, baseHeight, baseRadius);
	base.SetColor(2);
	base.slideY = baseHeight / 2.0;

	cyl.CreateCylinder(20, cylHeight, cylRadius);
	cyl.SetColor(0);
	cyl.slideY = cylHeight / 2.0;

	body1.CreateCuboid(body1SizeX, body1SizeY, body1SizeZ);//Mặt bàn
	body1.SetColor(4);

	holder1.CreateCuboid_R(holder1SizeX, holder1SizeY, holder1SizeZ, holder1Cutlength);
	holder1.SetColor(1);

	holder2.CreateCuboid_R(holder2SizeX, holder2SizeY, holder2SizeZ, holder2Cutlength);
	holder2.SetColor(2);

	holder3.CreateCube(holder3Size);
	holder3.SetColor(2);

	slider1.CreateCuboid_G(slider1SizeX, slider1SizeY, slider1SizeZ, slider1Ulength, slider1Llength);
	slider1.SetColor(3);
	slider2.CreateCuboid_G(slider2SizeX, slider2SizeY, slider2SizeZ, slider2Ulength, slider2Llength);
	slider2.SetColor(3);

	TayQuay.CreateBarTool(tayquaySizeX, tayquaySizeY, 20, tayquayfRadius, tayquaynRadius, tayquayfHeight, 20);
	TayQuay.SetColor(0);

	TayNoi1.CreateBarTool(taynoi1SizeX, taynoi1SizeY, 20, taynoi1fRadius, taynoi1nRadius, taynoi1fHeight, 20);
	TayNoi1.SetColor(5);
	TayNoi2.CreateBarTool(taynoi2SizeX, taynoi2SizeY, 20, taynoi2fRadius, taynoi2nRadius, taynoi2fHeight, 20);
	TayNoi2.SetColor(2);
	TayNoi3.CreateBarTool(taynoi3SizeX, taynoi3SizeY, 20, taynoi3fRadius, taynoi3nRadius, taynoi3fHeight, 20);
	TayNoi3.SetColor(7);

	Key1.CreateCylinder(20, key1fHeight, key1fRadius);
	Key1.SetColor(12);
	Key2.CreateCylinder(20, key2fHeight, key2fRadius);
	Key2.SetColor(12);
	Key3.CreateCylinder(20, key3fHeight, key3fRadius);
	Key3.SetColor(12);
	Key4.CreateCylinder(20, key4fHeight, key4fRadius);
	Key4.SetColor(12);
	Key5.CreateCylinder(20, key5fHeight, key5fRadius);
	Key5.SetColor(0);
	myInit();

	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(myDisplay);
	glutSpecialFunc(mySpecial);
	glutMainLoop();
	return 0;
}






