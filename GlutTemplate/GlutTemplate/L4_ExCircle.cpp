#include <iostream>
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>

#define screen_Width 500
#define screen_Height 500
#define PI 3.14159265359
#define DEC2RAG PI/180.0
using namespace std;
float factor = 2;

class vector {
public:
	float x, y;
public:
	vector() { x = y = 0; }
	vector(float xx, float yy) {
		x = xx;
		y = yy;
	}
	void set(float xx, float yy) {
		x = xx;
		y = yy;
	}
	float getX() { return x; }
	float getY() { return y; }
	float dotProduct(vector v)
	{
		return x * v.x + y * v.y;
	}
	vector scale(float f) {
		vector tmp;
		tmp.x = x * f;
		tmp.y = y * f;
		return tmp;
	}
	vector add(vector v) {
		vector tmp;
		tmp.set(x + v.x, y + v.y);
		return tmp;
	}
	float length()
	{
		return sqrt(x*x+y*y);
	}
};
class point2 {
public:
	float x, y;
	point2() { x = y = 0; }
	point2(float xx, float yy) {
		x = xx;
		y = yy;
	}
	void set(float xx, float yy) {
		x = xx;
		y = yy;
	}
	float getX() { return x; }
	float getY() { return y; }
	point2 add(vector v)
	{
		point2 tmp;
		tmp.set(x + v.x, y + v.y);
		return tmp;
	}
	void draw() {
		glBegin(GL_POINTS);
			glVertex2f(x, y);
		glEnd();
	}

};
point2 p[3];
int pointNum = 0;

point2 center;
float radius;
bool bFinish = false;

void ngon(int n, point2 center, float radius)
{

	float inc = 2 * PI / n;
	float x, y;
	float angle;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++) {
		angle = i * inc;
		x =center.x+ radius * cos(angle);
		y =center.y+ radius * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
}
void drawCircle(point2 Center, float radius)
{
	int n = 50;
	ngon(n, Center, radius);
}
void findExCircle()
{
	vector a, b, c, a_perp, c_perp;
	float t, u;

	a.set(p[1].x - p[0].x, p[1].y - p[0].y);
	b.set(p[2].x - p[1].x, p[2].y - p[1].y);
	c.set(p[0].x - p[2].x, p[0].y - p[2].y);

	a_perp.set(-a.y, a.x);
	c_perp.set(-c.y, c.x);

	float factor = b.dotProduct(c) / a_perp.dotProduct(c);
	vector tmp = a.add(a_perp.scale(factor));
	tmp = tmp.scale(0.5);
	center = p[0].add(tmp);
	radius = sqrt((p[0].x - center.x)*(p[0].x - center.x) +
		(p[0].y - center.y)* (p[0].y - center.y));
	bFinish = true;
}

void myReshape(int w, int h) {

}
static void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
	glColor3f(1, 0, 0);
	for (int i = 0; i < pointNum; i++)
		p[i].draw();

	glLineWidth(1);
	glColor3f(0, 0, 0);
	if (pointNum >= 2)
	{
		glBegin(GL_LINES);
		glVertex2f(p[0].x, p[0].y);
		glVertex2f(p[1].x, p[1].y);
		glEnd();
	}
	if (pointNum >= 3)
	{
		glBegin(GL_LINES);
		glVertex2f(p[0].x, p[0].y);
		glVertex2f(p[2].x, p[2].y);

		glVertex2f(p[1].x, p[1].y);
		glVertex2f(p[2].x, p[2].y);
		glEnd();
	}

	if (bFinish) {
		glPointSize(4);
		glColor3f(0, 0, 1);
		center.draw();
		
		glLineWidth(2);
		cout << center.x << " " << center.y << endl;
		drawCircle(center, radius);
	}
	glFlush();
}
static void init() {
	glClearColor(1.0, 1.0, 1.0, 1);
	glColor3f(0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,screen_Width,0,screen_Height, -1.0, 1.0);

}
void myMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (pointNum < 3)
		{
			p[pointNum].x = x;
			p[pointNum].y = screen_Height-y;
			pointNum++;
			if(pointNum==3)
				findExCircle();
		}
		glutPostRedisplay();
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		pointNum = 0;
		bFinish = false;
		glutPostRedisplay();
	}
}
int main(int argc, char ** argv) {
	
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutCreateWindow("Template");
	init();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutMouseFunc(myMouse);
	glutMainLoop();
}