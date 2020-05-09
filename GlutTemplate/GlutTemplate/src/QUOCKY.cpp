//#include<iostream>
//#include<GL/glut.h>
//#include <math.h>
//#define screen_Width 600
//#define screen_Height 400
//using namespace std;
//
//#define PI 3.1415926
//#define R 2
//struct Point2D {
//	float x;
//	float y;
//	Point2D() :x{ 0 }, y{ 0 }{}
//};
//Point2D point[10];
//Point2D lineIntersection(Point2D p0, Point2D p1, Point2D p2, Point2D p3) {
//	Point2D point;
//	float a1, b1, a2, b2;
//	a1 = (p0.y - p1.y) / (p0.x - p1.x);
//	b1 = p0.y - a1 * p0.x;
//
//	a2= (p2.y - p3.y) / (p2.x - p3.x);
//	b2=  p2.y - a2 * p2.x;
//
//	point.x = (b2 - b1) / (a1 - a2);
//	point.y = a1 * point.x + b1;
//
//	return point;
//}
//static void drawPointf(Point2D point) {
//	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
//	glPointSize(5);
//	glColor3f(1.0, 1.0, 1.0);
//	glBegin(GL_POINTS);
//	glVertex2f(point.x, point.y);
//	glEnd();
//}
//void calculatePoint() {
//	for (int i = 0; i < 5; i++)
//	{
//		point[i].x = R * cos(PI / 2 + i * 2 * PI / 5);
//		point[i].y = R * sin(PI / 2 + i * 2 * PI / 5);
//	}
//	point[5] = lineIntersection(point[0], point[2], point[1], point[4]);
//	point[6] = lineIntersection(point[0], point[2], point[1], point[3]);
//	point[7] = lineIntersection(point[4], point[2], point[1], point[3]);
//	point[8] = lineIntersection(point[4], point[2], point[0], point[3]);
//	point[9] = lineIntersection(point[0], point[3], point[1], point[4]);
//}
//static void init() {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-4.5, 4.5, -3, 3, 0.0, 1.0);
//	glClearColor(1.0, 0.0, 0.0, 1);
//}
//
//void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 0.0);
//	glBegin(GL_LINES);
//	glVertex2f(-4.5, 0);
//	glVertex2f(4.5, 0);
//	glEnd();
//	calculatePoint();
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(0.0, 0.0);
//	glVertex2f(point[0].x, point[0].y);
//	glVertex2f(point[5].x, point[5].y);
//	glVertex2f(point[1].x, point[1].y);
//	glVertex2f(point[6].x, point[6].y);
//	glVertex2f(point[2].x, point[2].y);
//	glVertex2f(point[7].x, point[7].y);
//	glVertex2f(point[3].x, point[3].y);
//	glVertex2f(point[8].x, point[8].y);
//	glVertex2f(point[4].x, point[4].y);
//	glVertex2f(point[9].x, point[9].y);
//	glVertex2f(point[0].x, point[0].y);
//	glEnd();
//	glFlush();
//}
//int main(int argc, char**argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutCreateWindow("QuocKy");
//	init();
//	
//	glutDisplayFunc(myDisplay);
//	glutMainLoop();
//}