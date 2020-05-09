// #include <iostream>
// #include <math.h>
// #include <GL/glew.h>
// #include <GL/glut.h>
// 
// #define screen_Width 500
// #define screen_Height 500
// #define PI 3.14159265359
// #define DEC2RAG PI/180.0
// int n;
// typedef float point[4];
// point v[] = {
// 	{0.0,1.0,0.0},
// 	{0.0,-0.33333,0.942809},
// 	{0.816497,-0.33333,-0.471405},
// 	{-0.816497,-0.33333,-0.471405}
// };
// 
// using namespace std;
// 
// 
// void triangle(point a, point b, point c)
// {
// 	glBegin(GL_POLYGON);
// 	glVertex3fv(a);
// 	glVertex3fv(b);
// 	glVertex3fv(c);
// 	glEnd();
// }
// void normal(point p)
// {
// 	float d = 0.0;
// 	int i;
// 	for (i = 0; i < 3; i++)
// 	{
// 		d += p[i] * p[i];
// 	}
// 	d = sqrt(d);
// 	if (d > 0.0)
// 		for (i = 0; i < 3; i++)
// 			p[i] /= d;
// }
// void divide_triangle(point a, point b, point c, int m)
// {
// 	point v1, v2, v3;
// 	int j;
// 	if (m > 0)
// 	{
// 		for (j = 0; j < 3; j++) v1[j] = a[j] + b[j];
// 		normal(v1);
// 		for (j = 0; j < 3; j++) v2[j] = a[j] + c[j];
// 		normal(v2);
// 		for (j = 0; j < 3; j++) v3[j] = c[j] + b[j];
// 		normal(v3);
// 
// 		divide_triangle(a, v1, v2, m - 1);
// 		divide_triangle(c, v2, v3, m - 1);
// 		divide_triangle(b, v3, v1, m - 1);
// 		divide_triangle(v1, v2, v3, m - 1);
// 	}
// 	else {
// 		triangle(a, b, c);
// 	}
// }
// void tetrahedron(int m) {
// 	divide_triangle(v[0], v[1], v[2], m);
// 	divide_triangle(v[3], v[2], v[1], m);
// 	divide_triangle(v[0], v[3], v[1], m);
// 	divide_triangle(v[0], v[2], v[3], m);
// }
// static void myDisplay() {
// 	glMatrixMode(GL_MODELVIEW);
// 	glLoadIdentity();
// 	gluLookAt(1.5, -0.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
// 
// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 	glEnable(GL_DEPTH_TEST);
// 
// 	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
// 
// 	tetrahedron(n);
// 
// 	glFlush();
// }
// static void init() {
// 	glClearColor(1.0, 1.0, 1.0, 1);
// 	glColor3f(0.0, 0.0, 0.0);
// 	glFrontFace(GL_CCW);
// 	glEnable(GL_CULL_FACE);
// 
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	glOrtho(-1.2, 1.2, -1.2, 1.2, -10.0, 10.0);
// 
// }
// int main(int argc, char ** argv) {
// 	n = 1;
// 	glutInit(&argc, argv);
// 	glutInitWindowSize(screen_Width, screen_Height);
// 	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
// 	glutCreateWindow("Template");
// 	init();
// 	glutDisplayFunc(myDisplay);
// 
// 	glutMainLoop();
// }