//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include<iostream>
//#include "Renderer.h"
//using namespace std;
//#define Screen_Width 640
//#define Screen_Height 480
//GLfloat rotationX = 0.0f;
//GLfloat rotationY = 0.0f;
//void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
//void drawCube(float centerX, float centerY, float centerZ, float EdgeLength) {
//
//	float halfedge = EdgeLength / 2;
//	float Vertices[]{
//		centerX + halfedge, centerY + halfedge, centerZ + halfedge, //v0
//		centerX - halfedge, centerY + halfedge, centerZ + halfedge, //v1
//		centerX - halfedge, centerY - halfedge, centerZ + halfedge, //v2
//		centerX + halfedge, centerY - halfedge, centerZ + halfedge, //v3
//
//		centerX + halfedge, centerY - halfedge, centerZ - halfedge, //v4
//		centerX + halfedge, centerY + halfedge, centerZ - halfedge, //v5
//		centerX - halfedge, centerY + halfedge, centerZ - halfedge, //v6		
//		centerX - halfedge, centerY - halfedge, centerZ - halfedge, //v7
//	};
//
//	unsigned int Indices[]{
//		0,1,2,
//		0,2,3,
//
//		0,4,3,
//		0,4,5,
//
//		0,1,5,
//		1,5,6,
//
//		4,7,5,
//		7,5,6,
//
//		7,1,2,
//		1,7,6,
//
//		7,2,3,
//		7,3,4,
//	};
//
//	unsigned int buffer;
//	GLCall(glGenBuffers(1, &buffer));
//	GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
//	GLCall(glBufferData(GL_ARRAY_BUFFER, 8 * 3 * sizeof(float), Vertices, GL_STATIC_DRAW));
//
//	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr));
//	GLCall(glEnableVertexAttribArray(0));
//
//	unsigned int index;
//	GLCall(glGenBuffers(1, &index));
//	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index));
//	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * 12 * sizeof(unsigned int), Indices, GL_STATIC_DRAW));
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	GLCall(glDrawElements(GL_TRIANGLES, 3 * 12, GL_UNSIGNED_INT, nullptr));
//}
//
//int main(void)
//{
//	GLFWwindow* window;
//
//	/* Initialize the library */
//	if (!glfwInit())
//		return -1;
//
//	/* Create a windowed mode window and its OpenGL context */
//	window = glfwCreateWindow(Screen_Width, Screen_Height, "Hello World", NULL, NULL);
//
//	glfwSetKeyCallback(window, keyCallback);
//	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
//	if (!window)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	/* Make the window's context current */
//	glfwMakeContextCurrent(window);
//
//	glViewport(0.0f, 0.0f, Screen_Width, Screen_Height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0f, Screen_Width, 0.0f, Screen_Height, -1000, 1000);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//
//	if (glewInit() != GLEW_OK) {
//		cout << "Error";
//	}
//	else {
//		cout << glGetString(GL_VERSION) << endl;
//	}
//
//
//	int halfWidth = Screen_Width / 2, halfHeight = Screen_Height / 2;
//	/* Loop until the user closes the window */
//
//	while (!glfwWindowShouldClose(window))
//	{
//		/* Render here */
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glPushMatrix();
//		glTranslatef(halfWidth, halfHeight, -500);
//		glRotatef(rotationX, 1, 0, 0);
//		glRotatef(rotationY, 0, 1, 0);
//		glTranslatef(-halfWidth, -halfHeight, 500);
//
//		drawCube(halfWidth + 100, halfHeight + 100, -500, 50);
//		drawCube(halfWidth + 100, halfHeight, -500, 50);
//		drawCube(halfWidth + 100, halfHeight - 100, -500, 50);
//
//		drawCube(halfWidth, halfHeight + 100, -500, 50);
//		drawCube(halfWidth, halfHeight, -500, 50);
//		drawCube(halfWidth, halfHeight - 100, -500, 50);
//
//		drawCube(halfWidth - 100, halfHeight + 100, -500, 50);
//		drawCube(halfWidth - 100, halfHeight, -500, 50);
//		drawCube(halfWidth - 100, halfHeight - 100, -500, 50);
//
//		glPopMatrix();
//
//		/* Swap front and back buffers */
//		glfwSwapBuffers(window);
//
//		/* Poll for and process events */
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}
//void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
//{
//	//std::cout << key << std::endl;
//
//	const GLfloat rotationSpeed = 10;
//
//	// actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
//	if (action == GLFW_PRESS || action == GLFW_REPEAT)
//	{
//		switch (key)
//		{
//		case GLFW_KEY_UP:
//			rotationX -= rotationSpeed;
//			break;
//		case GLFW_KEY_DOWN:
//			rotationX += rotationSpeed;
//			break;
//		case GLFW_KEY_RIGHT:
//			rotationY += rotationSpeed;
//			break;
//		case GLFW_KEY_LEFT:
//			rotationY -= rotationSpeed;
//			break;
//		}
//
//
//	}
//}