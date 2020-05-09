//#include <iostream>
//#include <math.h>
//#include <GL/glew.h>
//#include <GL/glut.h>
//#include<vector>
//#define screen_Width 640
//#define screen_Height 480
//#define PI 3.14159265359
//#define DEC2RAG PI/180.0
//using namespace std;
//class Point2 {
//private:
//	float x, y;
//public:
//	Point2() { x = y = 0.0f; }
//	Point2(float a, float b) { x = a; y = b; }
//	void set(float a, float b){ x = a; y = b; }
//	float getX() { return x; }
//	float getY() { return y; }
//};
//Point2 CP;
//float CD;
//
//void moveTo(float x, float y) {
//	CP.set(x,y);
//}
//void lineTo(float x, float y) { //Draw
//
//	glBegin(GL_LINES);
//		glVertex2f(CP.getX(), CP.getY());
//		glVertex2f(x, y);
//	glEnd();
//
//	CP.set(x, y);
//	glFlush();
//}
//void turnTo(float angle) {
//	CD = angle;
//}
//void turn(float angle) {
//	CD += angle;
//}
//void forward(float dist, int isVisible) {
//	const float DEG2RAD = 3.14159265359 / 180.0;
//	float x = CP.getX() + dist * cos(DEG2RAD*CD);
//	float y = CP.getY() + dist * sin(DEG2RAD*CD);
//
//	if (isVisible) lineTo(x, y);
//	else
//		moveTo(x, y); 
//}
//
//
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
//	glClear(GL_COLOR_BUFFER_BIT);
//	glClearColor(1.0, 0.0, 0.0, 0.0);
//	glColor3f(1.0, 0.0, 0.0);
//	CP.set(0, 0);
//	CD = 0;
//	int count= 10;
//	int n = 3;
//	//for (int i = 0; i < count; i++) {
//	//	for (int j = 0; j < n; j++) {
//	//		forward(2, 1);
//	//		turn(360.0 / n);
//	//	}
//	//	turn(360 / count);
//	//}
//
//	CP.set(0, 0);
//	CD = 0;
//	 count = 4 * 3;
//	 n = 4;
//	//for (int i = 0; i < count; i++)
//	//{
//	//	for (int j = 0; j < n; j++)
//	//	{
//	//		forward(1, 1);
//	//		turn(360.0 / n);
//	//	}
//	//	turn(360.0 / 12);
//	//}
//
//	CP.set(0, 0);
//	CD = 0;
//	count = 12;
//	n = 10;
//	//for (int i = 0; i < count; i++)
//	//{
//	//	for (int j = 0; j < n; j++)
//	//	{
//	//		forward(0.5, 1);
//	//		turn(360.0 / n);
//	//	}
//	//	turn(360.0 / 12);
//	//}
//
//	CP.set(0, 0);
//	CD = 0;
//	float len = 0.05;
//	float inc = 0.01;
//
//	 n = 250;
//	for (int i = 0; i < n; i++)
//	{
//		//forward(len, 1);
//		//turn(60); //xoắn ốc thoi
//		//turn(-89.5); //Spin
//		//turn(-144); //Star
//		//turn(170); //Sun
//		//len += inc;
//	}
//
//	 CP.set(-2.5, 0.5);
//	 CD = -90.0;
//
//	 count = 15;
//	 n = 3; //đa diện đều
//	 //for (int i = 0; i < count; i++)
//	 //{
//		// for (int j = 0; j < n; j++)
//		// {
//		//	 forward(1, 1);
//		//	 turn(360.0 / n);
//		// }
//		// n++;
//		// 
//	 //}
//
//	
//	glFlush();
//}
//static void init() {
//	glClearColor(1.0, 1.0, 1.0, 1);
//	
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-3,3,-3,3, -1.0, 1.0);
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
