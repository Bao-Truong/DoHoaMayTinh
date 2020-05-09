#pragma once
#include <stddef.h>
#include "Point3D.h"
#include "VertexID.h"
class Face
{
public:
		int numVerts;
		VertexID* indices;
		Face() :numVerts(0), indices(NULL){}
		~Face() { 
			if (indices != NULL)
			{
				delete[] indices;
				indices = NULL;
			}
			numVerts = 0;
		}

		void add3Vertex(int a, int b, int c);
};

