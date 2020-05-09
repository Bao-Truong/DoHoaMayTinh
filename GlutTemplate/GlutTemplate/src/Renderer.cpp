#include"Renderer.h"
#include<iostream>
using namespace std;
void GLClearError() {	
	while (glGetError() != GL_NO_ERROR) {
		cout << glGetError();
	}; // clear all the error
}
bool GLLogCall(const char* function, const char *file, int line) {
	while (GLenum error = glGetError())
	{
		cout << "[Opengl error]: " << "( " << error << " ): " << function <<
			" " << file << " inline: " << line << endl;
		return false;
	}
	return true;
}

