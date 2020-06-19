#pragma once
#if !defined (_MESH_CLASS)
#define _MESH_CLASS

#include "supportClass.h"
#include<iostream>

class VertexID
{
public:
	int		vertIndex;
	int		colorIndex;
};

class Face
{
public:
	int		nVerts;
	VertexID*	vert;
	Vector3	facenorm;
	
	Face()
	{
		nVerts = 0;
		vert = NULL;
	}
	~Face()
	{
		if (vert != NULL)
		{
			delete[] vert;
			vert = NULL;
		}
		nVerts = 0;
	}
};

class Mesh
{
public:
	int		numVerts;
	Point3*		pt;

	int		numFaces;
	Face*		face;

	float		slideX, slideY, slideZ;
	float		rotateX, rotateY, rotateZ;
	float		scaleX, scaleY, scaleZ;

public:
	Mesh()
	{
		numVerts = 0;
		pt = NULL;
		numFaces = 0;
		face = NULL;
		scaleX = scaleY = scaleZ = 1;
		slideX = slideY = slideZ = 0;
		rotateX = rotateY = rotateZ = 0;
	}
	~Mesh()
	{
		if (pt != NULL)
		{
			delete[] pt;
		}
		if (face != NULL)
		{
			delete[] face;
		}
		numVerts = 0;
		numFaces = 0;
	}
	void DrawWireframe();
	void DrawColor();
	void CalculateFacesNorm();
	void Draw();

	void CreateTetrahedron();
	void CreateCube(float	fSize);
	void CreateCuboid(float fSizeX, float fSizeY, float	fSizeZ);
	void CreateCylinder(int nSegment, float fHeight, float fRadius);
	void CreateECylinder(int nSegment, float fHeight, float nRadius, float fRadius);
	void CreateCuboid_R(float fSizeX, float fSizeY, float	fSizeZ, float cutLength);
	void CreateCuboid_G(float fSizeX, float fSizeY, float	fSizeZ, float ULength, float LLength);
	void CreateCuboid_Cylin(float fSizeX, float fSizeY, float	fSizeZ, int nSegment, float fRadius);
	void CreateHalfMoon(float distance, float fHeight, int nSegment1, float nRadius1, int nSegment2, float nRadius2);
	void CreateBarTool(float fSizeX, float fSizeY, int nSegment1, float fRadius, float nRadius, float fHeight, int nSegment2);
	void CreateECylinder(float dis, int nSegment, float fHeight, float nRadius, float fRadius, int cont, int fcont);
	void SetColor(int colorIdx);


};

#endif