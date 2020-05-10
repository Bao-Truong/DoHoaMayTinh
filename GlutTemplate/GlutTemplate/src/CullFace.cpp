#include <iostream>
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>

#define screen_Width 640
#define screen_Height 480
#define PI 3.14159265359
using namespace std;
struct point3d {
	float x,y,z;
	point3d(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	point3d() {
		x = y = z =0;
	}
};
point3d p0(0, 0, 0), p1(0, 0, 1), p2(1, 0, 1), p3(1, 0, 0); 
point3d p4(0, 1, 0), p5(0, 1, 1), p6(1, 1, 1), p7(1, 1, 0);
float angleY = 0;
float angleX = 0;
float angleZ = 0;
float colors[6][3] = {
	{1,1,0},
{0,1,0},
{0,0,1},
{1,0,0},
{1,0,1},
{0,1,1},
};

void drawText(float xPos, float yPos, float zPos, const char str[]) {
	glRasterPos3f(xPos, yPos, zPos);
	void* font = GLUT_BITMAP_9_BY_15;
	for (int i = 0; i < strlen(str); i++)
	{
		glutBitmapCharacter(font, str[i]);
	}
}
void drawSquare(point3d a, point3d b, point3d c, point3d d, float color[3]) {
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
	glLineWidth(4);
	glColor3fv(color);
	glBegin(GL_POLYGON);
	glVertex3f(a.x, a.y, a.z);
	glVertex3f(b.x, b.y, b.z);
	glVertex3f(c.x, c.y, c.z);
	glVertex3f(d.x, d.y, d.z);
	glEnd();
}
void drawVertexName() {
	glColor3f(0.0, 0.0, 0.0);
	drawText(p0.x, p0.y, p0.z, "0");
	drawText(p1.x, p1.y, p1.z, "1");
	drawText(p2.x, p2.y, p2.z, "2");
	drawText(p3.x, p3.y, p3.z, "3");

	drawText(p4.x, p4.y, p4.z, "4");
	drawText(p5.x, p5.y, p5.z, "5");
	drawText(p6.x, p6.y, p6.z, "6");
	drawText(p7.x, p7.y, p7.z, "7");
}
void drawAxis() {
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
}
static void myDisplay() {
	glFrontFace(GL_CCW); //Mặt định ko khai báo là CCW
	glEnable(GL_CULL_FACE); //Loại bỏ mặt sau - BACK

	//glCullFace(GL_FRONT); // mặt dịnh9 là GL_BACK

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.5, 1.5, 1.5, 0, 0, 0, 0, 1.0, 0.0);
	//gluLookAt(angleX, angleY, 1.5, 0, 0, 0, 0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	

	drawAxis();
	drawVertexName();
	drawSquare(p0, p3, p2, p1, colors[0]); //Dùng tay phải, ngón cái trỏ đâm vào mặt nào thì phía bên kia mặt đó sẽ là font, sau đó liệt kê theo chiều các ngón khác gập lại
	//drawSquare(p4, p7, p3, p0, colors[1]);
	//drawSquare(p4, p0, p1, p5, colors[2]);
	//drawSquare(p1, p2, p6, p5, colors[3]);
	//drawSquare(p7, p6, p2, p3, colors[4]);
	//drawSquare(p4, p5, p6, p7, colors[5]);


	glFlush();
}
static void init() {
	glClearColor(1.0, 1.0, 1.0, 1);
	glColor3f(0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3,3,-3,3, -1000,1000);

}
void mySpecialKey(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
		angleY -= 5;
	if (key == GLUT_KEY_RIGHT)
		angleY += 5;
	if (key == GLUT_KEY_UP)
		angleX -= 5;
	if (key == GLUT_KEY_DOWN)
		angleX += 5;
	glutPostRedisplay();
}
int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(screen_Width, screen_Height);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutCreateWindow("Template");
	init();
	glutDisplayFunc(myDisplay);
	glutSpecialFunc(mySpecialKey);

	glutMainLoop();
}