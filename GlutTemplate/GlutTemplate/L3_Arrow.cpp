//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//
//#define screen_Width 600
//#define screen_Height 600
//#define PI 3.14159265359
//#define DEC2RAG PI/180.0
//using namespace std;
//struct point2 {
//	float x;
//	float y;
//};
//point2 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O;
//
//point2 lineIntersection(point2 p0, point2 p1, point2 p2, point2 p3) {
//	point2 point;
//	float a1, b1, a2, b2;
//	a1 = (p0.y - p1.y) / (p0.x - p1.x);
//	b1 = p0.y - a1 * p0.x;
//
//	a2 = (p2.y - p3.y) / (p2.x - p3.x);
//	b2 = p2.y - a2 * p2.x;
//
//	point.x = (b2 - b1) / (a1 - a2);
//	point.y = a1 * point.x + b1;
//
//	return point;
//}
//void drawFigure() {
//	glColor3f(0.5, 0.5, 0.5);
//	glBegin(GL_POLYGON);
//	glVertex2f(H.x, H.y);
//	glVertex2f(G.x, G.y);
//	glVertex2f(L.x, L.y);
//	glVertex2f(K.x, K.y);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glVertex2f(J.x, J.y);
//	glVertex2f(A.x, A.y);
//	glVertex2f(I.x, I.y);
//	glVertex2f(K.x, K.y);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glVertex2f(J.x, J.y);
//	glVertex2f(N.x, N.y);
//	glVertex2f(C.x, C.y);
//	glVertex2f(B.x, B.y);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glVertex2f(N.x, N.y);
//	glVertex2f(O.x, O.y);
//	glVertex2f(M.x, M.y);
//	glVertex2f(D.x, D.y);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//	glVertex2f(M.x, M.y);
//	glVertex2f(L.x, L.y);
//	glVertex2f(F.x, F.y);
//	glVertex2f(E.x, E.y);
//	glEnd();
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glColor3f(0, 0, 0);
//	glLineWidth(5);
//	glBegin(GL_LINES);
//	glVertex2f(A.x, A.y);
//	glVertex2f(D.x, D.y);
//	
//	glVertex2f(D.x, D.y);
//	glVertex2f(D.x, D.y);
//
//	glVertex2f(I.x, I.y);
//	glVertex2f(K.x, K.y);
//
//	glVertex2f(H.x, H.y);
//	glVertex2f(K.x, K.y);
//
//	glVertex2f(D.x, D.y);
//	glVertex2f(G.x, G.y);
//
//	glVertex2f(F.x, F.y);
//	glVertex2f(K.x, K.y);
//
//	glVertex2f(K.x, K.y);
//	glVertex2f(B.x, B.y);
//
//	glVertex2f(E.x, E.y);
//	glVertex2f(O.x, O.y);
//
//	glVertex2f(C.x, C.y);
//	glVertex2f(O.x, O.y);
//	glEnd();
//}
//void setCameraVolume(float l, float r, float b, float t) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
//}
//void setViewport(int l, int r, int b, int t) {
//	glViewport(l, b, r - l, t - b);
//}
//void myReshape(int w, int h) {
//	//float factor = 2;
//	//glViewport(0, 0, w, h); //Kéo dãn theo màn hình thay đổi, có thể sẽ mất hình dạng ban đầu( hình cầu kéo ngang qua thì bị dãn)
//	//glMatrixMode(GL_PROJECTION);
//	//glLoadIdentity();
//	//if (w <= h)
//	//	glOrtho(-factor, factor, -factor * h / w, factor*h / w, -10.0, 10.0);
//	//else
//	//	glOrtho(-factor * w / h, factor*w / h, -factor, factor, -10.0, 10.0);
//}
//static void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//
//	A.x = 4; A.y = 6;
//	B.x = 6; B.y = 4;
//	C.x = 6; C.y = 2;
//	D.x = 6; D.y = 0;
//	E.x = 4; E.y = 0;
//	F.x = 2; F.y = 0;
//	G.x = 0; G.y = 2;
//	H.x = 0; H.y = 4;
//	I.x = 2; I.y = 6;
//	J = lineIntersection(G, B, A, D);
//	K = lineIntersection(G, B, I, E);
//	L = lineIntersection(K, F, G, D);
//	M = lineIntersection(E, J, G, D);
//	N = lineIntersection(C, L, A, D);
//	O = lineIntersection(E, J, C, L);
//
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	//drawFigure();
//	int size = 600;
//	for (int i = 0; i < 4; i++)
//	{
//		int w = size / 2 * (i % 2);
//		int h = size / 2 * (i / 2);
//		cout << w << " " << h << endl;
//
//		setViewport(w, size / 4 + w, size / 4 + h, size / 2 + h);
//		setCameraVolume(0, 6, 0, 6);
//		drawFigure();
//
//		setViewport(size/4 + w, size /2 + w, size / 4 + h, size / 2 + h);
//		setCameraVolume(0, 6, 6,0);
//		drawFigure();
//
//		setViewport(size / 4 + w, size / 2 + w,  h, size / 4 + h);
//		setCameraVolume(6,0,6,0);
//		drawFigure();
//
//		setViewport(w, size / 4 + w,  h, size / 4 + h);
//		setCameraVolume(6,0,0,6);
//		drawFigure();
//		
//	}
//
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	int factor=6;
//	glOrtho(0, factor,0, factor, -1.0, 1.0);
//
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutReshapeFunc(myReshape);
//	glutMainLoop();
//}