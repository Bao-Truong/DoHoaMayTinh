#include "Face.h"

void Face::add3Vertex(int a, int b, int c)
{
	numVerts = 3;
	indices = new VertexID[numVerts];
	indices[0].index = a;
	indices[1].index = b;
	indices[2].index = c;
}
