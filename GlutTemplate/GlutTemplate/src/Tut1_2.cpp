//#include<iostream>
//#include<GL/glut.H>
//#include<vector>
//#include<math.h>
//#define DEC2RAD  3.14159265359f/180.0
//using namespace std;
//void drawLine(float x1, float y1, float len, float angle, float &x2, float &y2);
//void drawTriangle(float x1, float y1, float len, float angle);
//void drawRecangle( float len, float angle, vector<float>&data);
//void normalDraw(float x1, float y1, float x2, float y2) {
//
//	glLineWidth(5);
//	glBegin(GL_LINE_STRIP);
//	glVertex2f(x1, y1);
//	glVertex2f(x2, y2);
//	glEnd();
//}
//#define PI 3.1415926
//void drawArcs() {
//	//glColor3f(, 0, 0);
//	glLineWidth(5);
//	float R = 0.5;
//	
//
//	glBegin(GL_LINE_STRIP);
//	for (int i = 0; i <= 90; i++) {
//		float x = R * cos(i*PI / 180.0);
//		float y = R * sin(i*PI / 180.0);
//		glVertex2f(x, y);
//	
//	}
//	glEnd();
//	glBegin(GL_LINE_STRIP);
//	for (int i = 180; i <= 270; i++) {
//		float x = R * cos(i*PI / 180.0) + 1;
//		float y = R * sin(i*PI / 180.0) + 1;
//		glVertex2f(x, y);
//	}
//	glEnd();
//}
//void drawPlygon(float x1, float y1, float len, float n, float angle);
//
//void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	float x1 = 0.0;
//	float y1 = 0.0;
//	float len = 3;
//	float angle = 45;
//	float x2;
//	float y2;
//
//
//	
//	float n = 12;
//	float inc = 360.0 / n;
//	//for (int i = 0; i < 12; i++)
//	//	drawPlygon(0, 0, 3.0, 4, inc*i);
//
//	 n = 12;
//	 inc = 360.0 / n;
//	for (int i = 0; i < 12; i++)
//		drawPlygon(0, 0, 3.0, 10, inc*i);
//
//	
//	//for(int i =0;i<=360;i+=36)
//	//	drawTriangle(x1, y1, len, i);
//
//
//	vector<float> recangle;
//	
//	//drawRecangle(2, 0, recangle);
//	//drawRecangle(2, 30, recangle);
//	//drawRecangle(2, 60, recangle);
//
//	//drawArcs();
//	//normalDraw(0, 0, 2, 2);
//	
//	glFlush();
//}
//void drawLine(float x1, float y1, float len, float angle, float &x2, float &y2) {
//
//	x2 =x1+ len * cos(DEC2RAD*angle);
//	y2 =y1+ len * sin(DEC2RAD*angle);
//
//
//	//glLineWidth(5);
//	glBegin(GL_LINE_STRIP);
//		glVertex2f(x1, y1);
//		glVertex2f(x2, y2);
//	glEnd();
//}
//void drawPlygon(float x1, float y1, float len, float n, float angle)
//{
//	float x2, y2;
//	float inc = 360.0 / n;
//
//	for (int i = 0; i < n; i++)
//	{
//		drawLine(x1, y1, len, angle, x2, y2);
//		x1 = x2; y1 = y2;
//		angle += inc;
//	}
//}
//void drawTriangle(float x1, float y1, float len, float angle) {
//	float x2, y2;
//	float x3, y3;
//	float AC_angle = 60 + angle;
//	float AB_angle = angle;
//	float BC_angle = angle + 60;
//	drawLine(x1, y1, len, AB_angle, x2, y2);
//	drawLine(x1, y1, len, AC_angle, x3, y3);
//	drawLine(x2, y2, len, BC_angle, x3, y3);
//
//	//float x2, y2;
//	//drawLine(x1, y1, len, angle, x2, y2);
//	//x1 = x2;
//	//y1 = y2;
//	//angle = angle + 120;
//
//	//drawLine(x1, y1, len, angle, x2, y2);
//	//x1 = x2; y1 = y2;
//	//angle = angle + 120;
//
//	//drawLine(x1, y1, len, angle, x2, y2);
//}
//
//void drawRecangle( float len, float angle,vector<float> &data) {
//	float xa, ya;
//	float xb, yb;
//	float xc, yc;
//	float xd, yd;
//
//	float diagonal_line;
//	if (data.empty()) {
//		cout << "!!!!!!!!!!!!!!!!!!!!" << endl;
//		xb = len;
//		yb = len;
//		xa = len;
//		ya = -len;
//		xc = -len;
//		yc = len;
//		xd = -len;
//		yd = -len;
//		for (int i = 0; i < 8; i++)
//		{
//			data.push_back(0);
//		}
//		data[0] = xa;
//		data[1] = ya;
//		data[2] = xb;
//		data[3] = yb;
//		data[4] = xc;
//		data[5] = yc;
//		data[6] = xd;
//		data[7] = yd;
//	}
//	else { //Rotate formula
//		cout << "Calculate";
//		xa = data[0] * cos(DEC2RAD*angle) - data[1] * sin(DEC2RAD*angle);
//		ya = data[0] * sin(DEC2RAD*angle) + data[1] * cos(DEC2RAD*angle);
//
//		xb = data[2] * cos(DEC2RAD*angle) - data[3] * sin(DEC2RAD*angle);
//		yb = data[2] * sin(DEC2RAD*angle) + data[3] * cos(DEC2RAD*angle);
//
//		xc = data[4] * cos(DEC2RAD*angle) - data[5] * sin(DEC2RAD*angle);
//		yc = data[4] * sin(DEC2RAD*angle) + data[5] * cos(DEC2RAD*angle);
//
//		xd = data[6] * cos(DEC2RAD*angle) - data[7] * sin(DEC2RAD*angle);
//		yd = data[6] * sin(DEC2RAD*angle) + data[7] * cos(DEC2RAD*angle);
//	}
//	
//	normalDraw(xa, ya, xb, yb);
//	normalDraw(xa, ya, xd, yd);
//	normalDraw(xc, yc, xb, yb);
//	normalDraw(xc, yc, xd, yd);
//
//	float x_ab, y_ab;
//	float x_ad, y_ad;
//	float x_bc, y_bc;
//	float x_cd, y_cd;
//
//	x_ab = (xa + xb) / 2; y_ab = (ya + yb) / 2;
//	x_ad = (xa + xd) / 2; y_ad = (ya + yd) / 2;
//	x_bc = (xb + xc) / 2; y_bc = (yc + yb) / 2;
//	x_cd = (xc + xd) / 2; y_cd = (yd + yc) / 2;
//
//	normalDraw(x_ab, y_ab, x_cd, y_cd);	
//	normalDraw(x_bc, y_bc, x_ad, y_ad);	
//}
//void drawRecangle_Something(float xo, float yo, float len, float angle) {
//	float xa, ya;
//	float xb, yb;
//	float xc, yc;
//	float xd, yd;
//
//	float diagonal_line;
//	xa = xo;
//	ya = yo;
//	drawLine(xa, ya, len, angle, xb, yb);
//	drawLine(xa, ya, len, angle + 90, xd, yd);
//	cout << "xb,yb: " << xb << "," << yb << endl;
//	cout << "xd,yd: " << xd << "," << yd << endl;
//	diagonal_line = (cos(DEC2RAD * 45)*
//		sqrt((xb - xa)*(xb - xa) + (yb - ya)*(yb - ya))) * 2;
//	//cout << diagonal_line << endl;
//	//drawLine(xd, yd, len, angle, xb, yb);
//	//drawLine(xa, ya, diagonal_line, angle + 45, xc, yc);
//	xc = diagonal_line * cos(DEC2RAD*(angle + 45));
//	yc = diagonal_line * sin(DEC2RAD*(angle + 45));
//	cout << "xC,yC: " << xc << "," << yc << endl;
//	normalDraw(xd, yd, xc, yc);
//	normalDraw(xb, yb, xc, yc);
//
//	float x_AB, y_AB;
//	float x_BC, y_BC;
//	float x_AD, y_AD;
//	float x_DC, y_DC;
//
//	//x_AB = abs(xa + xb) / 2; y_AB = abs(ya + yb) / 2;
//	//x_BC = abs(xb + xc) / 2; y_BC = abs(yb + yc) / 2;
//	//x_AD = abs(xa + xd) / 2; y_AD = abs(ya + yd) / 2;
//	//x_DC = abs(xd + xc) / 2;  y_DC = abs(yd + yc) / 2;
//	x_AB = (xa + xb) / 2; y_AB = (ya + yb) / 2;
//	x_BC = (xb + xc) / 2; y_BC = (yb + yc) / 2;
//	x_AD = (xa + xd) / 2; y_AD = (ya + yd) / 2;
//	x_DC = (xd + xc) / 2;  y_DC = (yd + yc) / 2;
//	cout << "Len: " << len << endl;
//	cout << "(" << x_AB << " , " << y_AB << endl;
//	normalDraw(x_AB, y_AB, x_DC, y_DC);
//	cout << "(" << x_DC << " , " << y_DC << endl;
//	normalDraw(x_AD, y_AD, x_BC, y_BC);
//
//
//}
//void init() {
//	glMatrixMode(GL_PROJECTION);
//	//glClearColor(0.0, 0.0, 0.0,1.0); //set màu nền
//	glLoadIdentity();
//	
//	gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // scale lại góc nhìn thành các toạ độ tương ứng: Left - Right - Bottom - Top
//}
//int main() {
//	glutCreateWindow("Demo1");
//	init();
//	//glutDisplayFunc(Rec_Triangle);
//
//	glutDisplayFunc(myDisplay);
//	glutMainLoop();	
//	system("pause");
//	return 0;
//}