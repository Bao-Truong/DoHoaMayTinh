#pragma once
#include "Point3D.h"
#include <iostream>
#include "Face.h"
//struct Face {
//	int numVerts;
//	Point3D* pointArr;
//
//};
class Mesh
{
	//int numFaces;
	//Face *faceArr;
public:
	int numVerts;
	Point3D *index_tab;

	int numFaces;
	Face *face_tab;

	Mesh(){
		numVerts = numFaces = 0;
		index_tab = NULL;
		face_tab = NULL;
	}
	~Mesh() {
		if (index_tab != NULL) delete[] index_tab;
		if (face_tab != NULL)delete[]face_tab;
		index_tab = NULL;
		face_tab = NULL;
		numVerts = numFaces = 0;
	}
	void DrawWireframe();
	void DrawColor();
	void CreateTetrahedron(Point3D &a, Point3D &b, Point3D &c, Point3D &d);
};

