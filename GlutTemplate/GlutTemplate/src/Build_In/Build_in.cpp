#pragma once
#include <iostream>
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>

#define PI 3.14159265359
using namespace std;

static void drawText(float x, float y, float z, const char* str)
{
	glRasterPos3f(x, y, z);
	void * font = GLUT_BITMAP_9_BY_15;
	for (int i = 0; i < strlen(str); i++)
	{
		glutBitmapCharacter(font, str[i]);
	}
	return;
}


static void drawAxis() {
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(3, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 3, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 3);
	glEnd();

	glColor3f(0, 0, 0);
	drawText(3, 0, 0, "X");
	drawText(0, 3, 0, "Y");
	drawText(0, 0, 3, "Z");
	return;
}

static void drawcircle(float x0, float y0, float r, int n = 60)
{
	float x, y;
	float angleinc = 2 * PI / n;
	float angle;
	glBegin(GL_LINE_LOOP);
	angle = 0;
	x = r * cos(angle);
	y = r * sin(angle);
	glVertex2f(x, y);
	for (int i = 1; i < n; i++)
	{
		angle += angleinc;
		x = r * cos(angle);
		y = r * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	return;
}
struct point2d {
	float x;
	float y;
};
static void drawLine(point2d a, point2d  b) {
	glBegin(GL_LINES);
	glVertex2f(a.x, a.y);
	glVertex2f(b.x, b.y);
	glEnd();
}
static void drawGrid(int OrthoX, int OrthoY)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(2);
	glColor3f(164 / 255.0, 164 / 255.0, 164 / 255.0);
	for (int i = 0; i < OrthoX; i++)
	{
		point2d a, b;
		a.x = i; a.y = 0;
		b.x = i; b.y = OrthoY;
		drawLine(a, b);
	}
	for (int i = 0; i < OrthoY; i++)
	{
		point2d a, b;
		a.x = 0; a.y = i;
		b.x = OrthoX; b.y = i;
		drawLine(a, b);
	}
	return;
}