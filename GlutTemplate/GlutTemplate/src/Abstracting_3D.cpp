//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//#include "Mesh.h"
//#include "Build_in.cpp"
//
//#define screen_Width 1000
//#define screen_Height 500
//#define PI 3.14159265359
//using namespace std;
//
//Mesh myMesh;
//float angle = 0;
//Point3D a(0, 0, 0), b(1, 0, 0), c(0, 1, 0), d(0, 0, 1);
//
//
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-3, 3, -3, 3, -10.0, 10.0);
//
//	myMesh.CreateTetrahedron(a, b, c, d); // Đưa 4 cái mặt tương ứng vs 4 cái góc, lưu toàn bộ dữ liệu, Nhét vào init() cho tiện
//}
//static void myDisplay() {
//	
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(1.5, 1.5, 1.5, 0, 0, 0, 0, 1.0, 0.0);
//
//
//	glRotatef(angle, 0, 1, 0);
//	
//
//	//Point3D a(0, 0, 0), b(1, 0, 0), c(0, 1, 0), d(0, 0, 1);
//
//	//myMesh.CreateTetrahedron(a, b, c, d); // Đưa 4 cái mặt tương ứng vs 4 cái góc, lưu toàn bộ dữ liệu, Nhét vào init() cho tiện
//
//	//myMesh.DrawWireframe();
//	glViewport(0, 0, 500, 500);
//	drawAxis();
//	myMesh.DrawWireframe();
//
//	glViewport(500, 0, 500, 500);
//	drawAxis();
//	myMesh.DrawColor();
//
//	glFlush();
//}
//void mySpecialFunc(int key, int x, int y)
//{
//	if (key == GLUT_KEY_LEFT)
//		angle -= 5;
//	if (key == GLUT_KEY_RIGHT)
//		angle += 5;
//	glutPostRedisplay();
//}
//int main(int argc, char ** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(screen_Width, screen_Height);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutCreateWindow("Template");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutSpecialFunc(mySpecialFunc);
//	glutMainLoop();
//	return 0;
//}