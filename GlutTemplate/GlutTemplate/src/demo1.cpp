//#include<iostream>
//#include<GL/glew.h>
//#include<GLFW/glfw3.h>
//#include<GL/glut.h>
//
//
//using namespace std;
//
//void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	glBegin(GL_POLYGON);
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex2f(-0.5, -0.5);
//
//	glColor3f(0.0, 1.0, 0.0);
//	glVertex2f(-0.5, 0.5);
//
//	glColor3f(0.0, 0.0, 1.0);
//	glVertex2f(0.5, 0.5);
//
//	glColor3f(1.0, 1.0, 0.0);
//	glVertex2f(0.5, -0.5);
//	glEnd();
//
//	glFlush();
//
//}
//void draw() {
//	glBegin(GL_LINE_STRIP);
//	glVertex2f(-2.0, -4.0);
//	glVertex2f(-2.0, 2.0);
//	glEnd();
//	glBegin(GL_POLYGON);
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex2f(-2.0, 0.0);
//
//	glColor3f(0.0, 1.0, 0.0);
//	glVertex2f(-2.0, 2.0);
//
//	glColor3f(0.0, 0.0, 1.0);
//	glVertex2f(0.0, 2.0);
//
//	glColor3f(1.0, 1.0, 0.0);
//	glVertex2f(0.0, 0.0);
//	glEnd(); 
//	glBegin(GL_TRIANGLES);
//	glVertex2f(0.0, -4.0);
//	glVertex2f(2.0, 0.0);
//	glVertex2f(4.0, -4.0);
//	glEnd();
//}
//void draw_triangle() {
//	glBegin(GL_TRIANGLES);
//	glVertex2f(-0.5,1.0);
//	glVertex2f(0.5, 1.0);
//	glVertex2f(-0.5, 0.0);
//	glEnd();
//}
//void Rec_Triangle() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glViewport(320, 240, 320, 240);//Dùng chung vs WindowSize, (x,y,h,w): (x,y) là toạ độ theo windowsize (h,w) 
//	// Từ toạ độ (x,y) + thêm cho (h,w) xem nó như 1 khung hình.
//	draw();
//
//	glViewport(0, 0, 320, 240);
//	draw();
//
//	glFlush();
//}
//void polygon_fill() {
//	
//	glClearColor(0.0, 1.0, 0.0, 1.0); 
//	glClear(GL_COLOR_BUFFER_BIT);//Clear 
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glColor3f(0.0, 1.0, 1.0);
//	draw_triangle();
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glColor3f(1.0, 0.0, 0.0);
//	glLineWidth(5);
//	draw_triangle();			
//	
//	glFlush();
//}
//void init() {
//	glMatrixMode(GL_PROJECTION);
//	//glClearColor(0.0, 0.0, 0.0,1.0); //set màu nền
//	glLoadIdentity();
//	gluOrtho2D(-2.0, 4.0, -4.0, 2.0); // scale lại góc nhìn thành các toạ độ tương ứng: Left - Right - Bottom - Top
//
//}
//int main(int argc, char**argv) {
//	glutInit(&argc, argv);
//	//glutInitDisplayMode(GLUT_DOUBLE | GL_RGBA);
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(100, 300);
//	glutCreateWindow("Demo1");
//	init();
//	//glutDisplayFunc(Rec_Triangle);
//	glutDisplayFunc(polygon_fill);
//	glutMainLoop();
//}