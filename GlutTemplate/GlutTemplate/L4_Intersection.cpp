//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 500
//#define screen_Height 500
//#define PI 3.14159265359
//#define DEC2RAG PI/180.0
//using namespace std;
//float factor = 2;
//
//class vector {
//public:
//	float x, y;
//public:
//	vector() { x = y = 0; }
//	vector(float xx, float yy) {
//		x = xx;
//		y = yy;
//	}
//	void set(float xx, float yy) {
//		x = xx;
//		y = yy;
//	}
//	float getX() { return x; }
//	float getY() { return y; }
//	float dotProduct(vector v)
//	{
//		return x * v.x + y * v.y;
//	}
//	vector scale(float f) {
//		vector tmp;
//		tmp.x = x * f;
//		tmp.y = y * f;
//		return tmp;
//	}
//};
//class point2 {
//public:
//	float x, y;
//	point2() { x = y = 0; }
//	point2(float xx, float yy) {
//		x = xx;
//		y = yy;
//	}
//	void set(float xx, float yy) {
//		x = xx;
//		y = yy;
//	}
//	float getX() { return x; }
//	float getY() { return y; }
//	point2 add(vector v)
//	{
//		point2 tmp;
//		tmp.set(x + v.x, y + v.y);
//		return tmp;
//	}
//	void draw() {
//		glBegin(GL_POINTS);
//			glVertex2f(x, y);
//		glEnd();
//	}
//
//};
//point2 p[4];
//int pointNum = 0;
//
//int intersectionNum = 0;
//point2 intersectionPoint[2];
//
//
//void findIntersection() {
//
//	for (int i = 0; i < 4; i++)
//	{
//		cout << p[i].x << " " << p[i].y << endl;
//	}
//
//	vector b, c, d, b_perp, d_perp;
//	b.set(p[1].x - p[0].x, p[1].y - p[0].y); // AB
//	d.set(p[3].x - p[2].x, p[3].y - p[2].y); // CD
//	c.set(p[2].x - p[0].x, p[2].y - p[0].y); // AC
//	
//	b_perp.set(-b.y, b.x);
//	d_perp.set(-d.y, d.x);
//
//	float dominator;
//	dominator = d_perp.dotProduct(b);
//	if (fabs(dominator) > 0.00001)
//	{
//		float t = d_perp.dotProduct(c) / dominator;
//		float u = b_perp.dotProduct(c) / dominator;
//		
//		if (t >= 0 && t <= 1 && u >= 0 && u <= 1)
//		{
//			intersectionNum = 1;
//			intersectionPoint[0] = p[0].add(b.scale(t));
//			cout << intersectionPoint[0].x << " " << intersectionPoint[0].y << endl;
//		}
//		else
//		{
//			intersectionNum = 0;
//		}
//	}
//	else {
//		if (fabs(b.x*(p[2].y - p[0].y) - b.y*(p[2].x - p[0].x)) > 0.00001)			
//		{		
//			intersectionNum = 0;
//		}
//		else {
//			float tc, td;
//			float t1, t2;
//			tc = (p[2].x - p[0].x) / b.x;
//			td = (p[3].x - p[0].x) / b.x;
//			cout << "tc,td" << tc << " " << td << endl;
//			t1 = 0;
//			if (tc >= t1)
//				t1 = tc;
//			t2 = 1;
//			if (t2 >= td)
//				t2 = td;
//
//			if (t1 <= t2)
//			{
//				intersectionNum = 2;
//				intersectionPoint[0] = p[0].add(b.scale(t1));
//				intersectionPoint[1] = p[0].add(b.scale(t2));
//			}
//			else
//				intersectionNum = 0;
//		}
//	}
//
//}
//void myReshape(int w, int h) {
//
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glPointSize(9);
//	glColor3f(1.0, 0.0, 0.0);
//	for (int i = 0; i < pointNum; i++)
//		p[i].draw();
//	
//	glLineWidth(1);
//	glColor3f(0, 0, 0);
//	if (pointNum >= 2)
//	{
//		glBegin(GL_LINES);
//		glVertex2f(p[0].x, p[0].y);
//		glVertex2f(p[1].x, p[1].y);
//		glEnd();
//	}
//	if (pointNum >= 4)
//	{
//		glBegin(GL_LINES);
//		glVertex2f(p[2].x, p[2].y);
//		glVertex2f(p[3].x, p[3].y);
//		glEnd();
//	}
//
//	if (intersectionNum == 1)
//	{
//		glColor3f(0, 0, 1);
//		glPointSize(6);
//		intersectionPoint[0].draw();
//	}
//	if (intersectionNum == 2)
//	{
//		cout << "s";
//		glColor3f(0, 0, 1);
//		glLineWidth(6);
//		glBegin(GL_LINES);
//		glVertex2f(intersectionPoint[0].x, intersectionPoint[0].y);
//		glVertex2f(intersectionPoint[1].x, intersectionPoint[1].y);
//		glEnd();
//	}
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0,screen_Width,0,screen_Height, -1.0, 1.0);
//
//}
//void myMouse(int button, int state, int x, int y) {
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		if (pointNum < 4)
//		{
//			p[pointNum].x = x;
//			p[pointNum].y = screen_Height-y;
//			pointNum++;
//			if (pointNum == 4)
//			{				
//				findIntersection();
//			}
//		}
//		glutPostRedisplay();
//	}
//}
//int main(int argc, char ** argv) {
//	pointNum = 4;
//	p[0].x = 50; p[0].y = 150;
//	p[1].x = 150; p[1].y = 350;
//	p[2].x = 100; p[2].y = 250;
//	p[3].x = 200; p[3].y = 450;
//	findIntersection();
//	glutInit(&argc, argv);
//	glutInitWindowSize(500, 500);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutReshapeFunc(myReshape);
//	glutMouseFunc(myMouse);
//	glutMainLoop();
//}