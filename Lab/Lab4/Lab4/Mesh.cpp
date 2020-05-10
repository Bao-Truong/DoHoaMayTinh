
#include "Mesh.h"
#include <math.h>

#define PI			3.1415926
#define	COLORNUM		14


float	ColorArr[COLORNUM][3] = { {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, { 0.0,  0.0, 1.0},
								{1.0, 1.0,  0.0}, { 1.0, 0.0, 1.0},{ 0.0, 1.0, 1.0},
								 {0.3, 0.3, 0.3}, {0.5, 0.5, 0.5}, { 0.9,  0.9, 0.9},
								{1.0, 0.5,  0.5}, { 0.5, 1.0, 0.5},{ 0.5, 0.5, 1.0},
									{0.0, 0.0, 0.0}, {1.0, 1.0, 1.0} };





void Mesh::CreateCube(float	fSize)
{
	int i;

	numVerts = 8;
	pt = new Point3[numVerts];
	pt[0].set(-fSize, fSize, fSize);
	pt[1].set(fSize, fSize, fSize);
	pt[2].set(fSize, fSize, -fSize);
	pt[3].set(-fSize, fSize, -fSize);
	pt[4].set(-fSize, -fSize, fSize);
	pt[5].set(fSize, -fSize, fSize);
	pt[6].set(fSize, -fSize, -fSize);
	pt[7].set(-fSize, -fSize, -fSize);


	numFaces = 6;
	face = new Face[numFaces];

	//Left face
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 5;
	face[0].vert[2].vertIndex = 6;
	face[0].vert[3].vertIndex = 2;
	for (i = 0; i < face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;

	//Right face
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 3;
	face[1].vert[2].vertIndex = 7;
	face[1].vert[3].vertIndex = 4;
	for (i = 0; i < face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;

	//top face
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 2;
	face[2].vert[3].vertIndex = 3;
	for (i = 0; i < face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;

	//bottom face
	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 7;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 5;
	face[3].vert[3].vertIndex = 4;
	for (i = 0; i < face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;

	//near face
	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 4;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 1;
	face[4].vert[3].vertIndex = 0;
	for (i = 0; i < face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 4;

	//Far face
	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 3;
	face[5].vert[1].vertIndex = 2;
	face[5].vert[2].vertIndex = 6;
	face[5].vert[3].vertIndex = 7;
	for (i = 0; i < face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 5;

}


void Mesh::CreateCuboid(float fSizeX, float fSizeY, float fSizeZ)
{
	int i;
	float halfX = fSizeX / 2.0;
	float halfZ = fSizeZ / 2.0;
	numVerts = 8;
	pt = new Point3[numVerts];
	pt[0].set(halfX, 0, -halfZ);
	pt[1].set(halfX, fSizeY, -halfZ);
	pt[2].set(halfX, fSizeY, halfZ);
	pt[3].set(halfX, 0, halfZ);
	pt[4].set(-halfX, 0, -halfZ);
	pt[5].set(-halfX, fSizeY, -halfZ);
	pt[6].set(-halfX, fSizeY, halfZ);
	pt[7].set(-halfX, 0, halfZ);

	numFaces = 6;
	face = new Face[numFaces];

	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 1;
	face[0].vert[2].vertIndex = 2;
	face[0].vert[3].vertIndex = 3;
	for (i = 0; i < face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 1;
	// 
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 1;
	face[1].vert[1].vertIndex = 0;
	face[1].vert[2].vertIndex = 4;
	face[1].vert[3].vertIndex = 5;
	for (i = 0; i < face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 2;
	// 
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 7;
	face[2].vert[1].vertIndex = 6;
	face[2].vert[2].vertIndex = 5;
	face[2].vert[3].vertIndex = 4;
	for (i = 0; i < face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 3;

	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 2;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 7;
	face[3].vert[3].vertIndex = 3;
	for (i = 0; i < face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 4;

	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 1;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 6;
	face[4].vert[3].vertIndex = 2;
	for (i = 0; i < face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 5;

	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 0;
	face[5].vert[1].vertIndex = 4;
	face[5].vert[2].vertIndex = 7;
	face[5].vert[3].vertIndex = 3;
	for (i = 0; i < face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 6;
}

void Mesh::CreateTetrahedron()
{
	int i;
	numVerts = 4;
	pt = new Point3[numVerts];
	pt[0].set(0, 0, 0);
	pt[1].set(1, 0, 0);
	pt[2].set(0, 1, 0);
	pt[3].set(0, 0, 1);

	numFaces = 4;
	face = new Face[numFaces];

	face[0].nVerts = 3;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 2;
	face[0].vert[2].vertIndex = 3;
	for (i = 0; i < face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;


	face[1].nVerts = 3;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 2;
	face[1].vert[2].vertIndex = 1;
	for (i = 0; i < face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;


	face[2].nVerts = 3;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 3;
	face[2].vert[2].vertIndex = 2;
	for (i = 0; i < face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;


	face[3].nVerts = 3;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 1;
	face[3].vert[1].vertIndex = 3;
	face[3].vert[2].vertIndex = 0;
	for (i = 0; i < face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;
}


void Mesh::DrawWireframe()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;

			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}
void Mesh::CreateCylinder(int nSegment, float fHeight, float fRadius) {
	numVerts = nSegment * 2 + 2;
	pt = new Point3[numVerts];

	int		i;
	int		idx;
	float	fAngle = 2 * PI / nSegment;
	float	x, y, z;

	pt[0].set(0, fHeight / 2, 0);
	for (i = 0; i < nSegment; i++) {
		x = fRadius * cos(fAngle*i);
		z = fRadius * sin(fAngle*i);
		y = fHeight / 2;
		pt[i + 1].set(x, y, z);

		y = -fHeight / 2;
		pt[i + 1 + nSegment].set(x, y, z);
	}
	pt[numVerts - 1].set(0, -fHeight / 2, 0);

	numFaces = nSegment * 3;
	face = new Face[numFaces];

	idx = 0;
	for (i = 0; i < nSegment; i++) {
		face[idx].nVerts = 3;
		face[idx].vert = new VertexID[face[idx].nVerts];
		face[idx].vert[0].vertIndex = 0;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2;
		else
			face[idx].vert[1].vertIndex = 1;
		face[idx].vert[2].vertIndex = i + 1;
		idx++;
	}

	for (i = 0; i < nSegment; i++) {
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = i + 1;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2;
		else
			face[idx].vert[1].vertIndex = 1;
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment;

		idx++;
	}

	for (i = 0; i < nSegment; i++) {
		face[idx].nVerts = 3;
		face[idx].vert = new VertexID[face[idx].nVerts];
		face[idx].vert[0].vertIndex = numVerts - 1;
		if (i < nSegment - 1)
			face[idx].vert[2].vertIndex = i + 2 + nSegment;
		else
			face[idx].vert[2].vertIndex = 1 + nSegment;
		face[idx].vert[1].vertIndex = i + 1 + nSegment;
		idx++;
	}

}

void Mesh::CreateECylinder(int nSegment, float fHeight, float nRadius, float fRadius)
{
	numVerts = nSegment * 2 * 2 + 1;
	pt = new Point3[numVerts];

	int		i;
	int		idx;
	float	fAngle = 2 * PI / nSegment;
	float	x, y, z;

	//pt[0].set(0, fHeight / 2, 0);
	for (i = 0; i < nSegment; i++) {
		x = fRadius * cos(fAngle*i);
		z = fRadius * sin(fAngle*i);
		y = fHeight / 2;
		pt[i + 1].set(x, y, z);

		y = -fHeight / 2;
		pt[i + 1 + nSegment].set(x, y, z);

		x = nRadius * cos(fAngle*i);
		z = nRadius * sin(fAngle*i);
		y = fHeight / 2;
		pt[i + 1 + nSegment + nSegment].set(x, y, z);

		y = -fHeight / 2;
		pt[i + 1 + nSegment + nSegment + nSegment].set(x, y, z);
	}
	//[1 - 10] [11 20] [21 30] [31 40]
	//Upper		Lower	Upper	Lower
	//Fradius	Fradius	NRadius	NRadius


	numFaces = nSegment * 4 + 1;
	face = new Face[numFaces];

	idx = 0;

	for (i = 0; i < nSegment; i++) { //Vòng xoay tren cùng
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = i + 1;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2;
		else
		{
			face[idx].vert[1].vertIndex = 1;
		}
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment + nSegment;

		idx++;
	}
	for (i = 0; i < nSegment; i++) {// MẶt đứng phía ngoài
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = i + 1;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2;
		else
			face[idx].vert[1].vertIndex = 1;
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment;

		idx++;
	}
	for (i = 0; i < nSegment; i++) {// Vòng xoay phía dưới
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = i + 1 + nSegment;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2 + nSegment;
		else
			face[idx].vert[1].vertIndex = 1 + nSegment;
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment + nSegment;

		idx++;
	}

	for (i = 0; i < nSegment; i++) { // Mặt đứng phía tron
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = i + 1 + nSegment + nSegment;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2 + nSegment + nSegment;
		else
			face[idx].vert[1].vertIndex = 1 + nSegment + nSegment;
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment;

		idx++;
	}

}
void Mesh::CreateECylinder(float dis, int nSegment, float fHeight, float nRadius, float fRadius, int cont, int fcont)
{
	int		i;
	int		idx;
	float	fAngle = 2 * PI / nSegment;
	float	x, y, z;

	//pt[0].set(0, fHeight / 2, 0);
	for (i = 0; i < nSegment; i++) {
		x = fRadius * cos(fAngle*i);
		z = fRadius * sin(fAngle*i);
		y = fHeight / 2;
		pt[cont + i + 1].set(x + dis, y, z);

		y = -fHeight / 2;
		pt[cont + i + 1 + nSegment].set(x + dis, y, z);

		x = nRadius * cos(fAngle*i);
		z = nRadius * sin(fAngle*i);
		y = fHeight / 2;
		pt[cont + i + 1 + nSegment + nSegment].set(x + dis, y, z);

		y = -fHeight / 2;
		pt[cont + i + 1 + nSegment + nSegment + nSegment].set(x + dis, y, z);
	}
	//[1 - 10] [11 20] [21 30] [31 40]
	//Upper		Lower	Upper	Lower
	//Fradius	Fradius	NRadius	NRadius

	idx = fcont;
	for (i = 0; i < nSegment; i++) { //Vòng xoay tren cùng
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = cont + i + 1;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = cont + i + 2;
		else
		{
			face[idx].vert[1].vertIndex = cont + 1;
		}
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment + nSegment;

		idx++;
	}

	for (i = 0; i < nSegment; i++) {// Vòng xoay phía dưới
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = cont + i + 1 + nSegment;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = cont + i + 2 + nSegment;
		else
			face[idx].vert[1].vertIndex = cont + 1 + nSegment;
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment + nSegment;

		idx++;
	}

	for (i = 0; i < nSegment; i++) { // Mặt đứng phía tron
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = cont + i + 1 + nSegment + nSegment;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = cont + i + 2 + nSegment + nSegment;
		else
			face[idx].vert[1].vertIndex = cont + 1 + nSegment + nSegment;
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment;

		idx++;
	}
	for (i = 0; i < nSegment; i++) {// MẶt đứng phía ngoài
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = cont + i + 1;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = cont + i + 2;
		else
			face[idx].vert[1].vertIndex = cont + 1;
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment;
		idx++;
	}
}
void Mesh::CreateCuboid_R(float fSizeX, float fSizeY, float fSizeZ, float cutLength)
{
	int i;
	float halfX = fSizeX / 2.0;
	float halfY = fSizeY / 2.0;
	float pieces = (fSizeZ - cutLength) / 2;

	//float halfZ = fSizeZ / 2.0;
	numVerts = 16;
	pt = new Point3[numVerts];
	pt[0].set(halfX, 0, 0);
	pt[1].set(halfX, halfY, 0);
	pt[2].set(halfX, halfY, fSizeZ);
	pt[3].set(halfX, 0, fSizeZ);
	pt[4].set(-halfX, 0, 0);
	pt[5].set(-halfX, halfY, 0);
	pt[6].set(-halfX, halfY, fSizeZ);
	pt[7].set(-halfX, 0, fSizeZ);

	pt[8].set(halfX, fSizeY, 0);
	pt[9].set(halfX, fSizeY, pieces);
	pt[10].set(halfX, fSizeY, pieces + cutLength);
	pt[11].set(halfX, fSizeY, fSizeZ);

	pt[12].set(-halfX, fSizeY, 0);
	pt[13].set(-halfX, fSizeY, pieces);
	pt[14].set(-halfX, fSizeY, pieces + cutLength);
	pt[15].set(-halfX, fSizeY, fSizeZ);

	numFaces = 10;
	face = new Face[numFaces];

	face[0].nVerts = 4;//Font
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 1;
	face[0].vert[2].vertIndex = 2;
	face[0].vert[3].vertIndex = 3;

	// 
	face[1].nVerts = 4;//right
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 8;
	face[1].vert[1].vertIndex = 0;
	face[1].vert[2].vertIndex = 4;
	face[1].vert[3].vertIndex = 12;

	// 
	face[2].nVerts = 4;//behind
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 4;
	face[2].vert[1].vertIndex = 5;
	face[2].vert[2].vertIndex = 6;
	face[2].vert[3].vertIndex = 7;


	face[3].nVerts = 4;//left
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 11;
	face[3].vert[1].vertIndex = 15;
	face[3].vert[2].vertIndex = 7;
	face[3].vert[3].vertIndex = 3;


	face[4].nVerts = 4;//top
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 1;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 6;
	face[4].vert[3].vertIndex = 2;


	face[5].nVerts = 4;//down
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 0;
	face[5].vert[1].vertIndex = 4;
	face[5].vert[2].vertIndex = 7;
	face[5].vert[3].vertIndex = 3;


	face[6].nVerts = 4;//down
	face[6].vert = new VertexID[face[6].nVerts];
	face[6].vert[0].vertIndex = 8;
	face[6].vert[1].vertIndex = 12;
	face[6].vert[2].vertIndex = 13;
	face[6].vert[3].vertIndex = 9;


	face[7].nVerts = 4;//down
	face[7].vert = new VertexID[face[7].nVerts];
	face[7].vert[0].vertIndex = 9;
	face[7].vert[1].vertIndex = 13;
	face[7].vert[2].vertIndex = 5;
	face[7].vert[3].vertIndex = 1;


	face[8].nVerts = 4;//down
	face[8].vert = new VertexID[face[8].nVerts];
	face[8].vert[0].vertIndex = 10;
	face[8].vert[1].vertIndex = 14;
	face[8].vert[2].vertIndex = 15;
	face[8].vert[3].vertIndex = 11;


	face[9].nVerts = 4;//down
	face[9].vert = new VertexID[face[9].nVerts];
	face[9].vert[0].vertIndex = 14;
	face[9].vert[1].vertIndex = 10;
	face[9].vert[2].vertIndex = 2;
	face[9].vert[3].vertIndex = 6;

}

void Mesh::CreateCuboid_G(float fSizeX, float fSizeY, float fSizeZ, float ULength, float LLength)
{
	int i;
	float halfX = fSizeX / 2.0;
	float halfY = fSizeY / 2.0;
	float Lpieces = (fSizeZ - LLength) / 2;
	float Upieces = (fSizeZ - ULength) / 2;
	//float halfZ = fSizeZ / 2.0;
	numVerts = 16;
	pt = new Point3[numVerts];
	pt[0].set(halfX, 0, 0);
	pt[1].set(halfX, halfY, 0);
	pt[2].set(halfX, halfY, fSizeZ);
	pt[3].set(halfX, 0, fSizeZ);
	pt[4].set(-halfX, 0, 0);
	pt[5].set(-halfX, halfY, 0);
	pt[6].set(-halfX, halfY, fSizeZ);
	pt[7].set(-halfX, 0, fSizeZ);

	pt[8].set(halfX, halfY, Lpieces);
	pt[9].set(halfX, fSizeY, Upieces);
	pt[10].set(halfX, fSizeY, Upieces + ULength);
	pt[11].set(halfX, halfY, Lpieces + LLength);


	pt[12].set(-halfX, halfY, Lpieces);
	pt[13].set(-halfX, fSizeY, Upieces);
	pt[14].set(-halfX, fSizeY, Upieces + ULength);
	pt[15].set(-halfX, halfY, Lpieces + LLength);


	numFaces = 10;
	face = new Face[numFaces];

	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 1;
	face[0].vert[2].vertIndex = 2;
	face[0].vert[3].vertIndex = 3;


	// 
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 1;
	face[1].vert[1].vertIndex = 0;
	face[1].vert[2].vertIndex = 4;
	face[1].vert[3].vertIndex = 5;

	// 
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 4;
	face[2].vert[1].vertIndex = 5;
	face[2].vert[2].vertIndex = 6;
	face[2].vert[3].vertIndex = 7;


	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 2;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 7;
	face[3].vert[3].vertIndex = 3;


	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 1;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 6;
	face[4].vert[3].vertIndex = 2;


	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 0;
	face[5].vert[1].vertIndex = 4;
	face[5].vert[2].vertIndex = 7;
	face[5].vert[3].vertIndex = 3;

	face[6].nVerts = 4;//down
	face[6].vert = new VertexID[face[5].nVerts];
	face[6].vert[0].vertIndex = 9;
	face[6].vert[1].vertIndex = 10;
	face[6].vert[2].vertIndex = 11;
	face[6].vert[3].vertIndex = 8;

	face[7].nVerts = 4;//down
	face[7].vert = new VertexID[face[5].nVerts];
	face[7].vert[0].vertIndex = 9;
	face[7].vert[1].vertIndex = 13;
	face[7].vert[2].vertIndex = 14;
	face[7].vert[3].vertIndex = 10;

	face[8].nVerts = 4;//down
	face[8].vert = new VertexID[face[5].nVerts];
	face[8].vert[0].vertIndex = 10;
	face[8].vert[1].vertIndex = 14;
	face[8].vert[2].vertIndex = 15;
	face[8].vert[3].vertIndex = 11;

	face[9].nVerts = 4;//down
	face[9].vert = new VertexID[face[5].nVerts];
	face[9].vert[0].vertIndex = 9;
	face[9].vert[1].vertIndex = 13;
	face[9].vert[2].vertIndex = 12;
	face[9].vert[3].vertIndex = 8;
}

void Mesh::CreateCuboid_Cylin(float fSizeX, float fSizeY, float	fSizeZ, int nSegment, float fRadius)
{
	float halfX = fSizeX / 2.0;
	float halfY = fSizeY / 2.0;
	float x, y, z;
	numVerts = (nSegment) * 4;
	pt = new Point3[numVerts];

	int		i;
	int		idx;
	float	fAngle = PI / nSegment;


	float o1, o2;
	o1 = halfX;
	o2 = -halfX;
	for (int i = 0; i < nSegment; i++)
	{
		x = o1 + fRadius * cos(PI / 2 + fAngle * (i + 1));
		z = fRadius * sin(PI / 2 + fAngle * i);
		y = halfY;
		pt[i].set(x, y, z);
		y = -halfY;
		pt[i + nSegment].set(x, y, z);


		x = o2 + fRadius * cos(PI / 2 - fAngle * i);
		z = fRadius * sin(PI / 2 - fAngle * i);
		y = halfY;
		pt[i + nSegment + nSegment].set(x, y, z);
		y = -halfY;
		pt[i + nSegment + nSegment + nSegment].set(x, y, z);
	}

	numFaces = nSegment * 3;
	face = new Face[numFaces];
	int d = 0;
	for (int i = 0; i < nSegment; i++)
	{
		face[i].nVerts = 4;
		face[i].vert = new VertexID[face[i].nVerts];
		face[i].vert[0].vertIndex = i;
		face[i].vert[1].vertIndex = i + nSegment;
		face[i].vert[2].vertIndex = i + nSegment * 3;
		face[i].vert[3].vertIndex = i + nSegment * 2;
		d++;
	}
	for (int i = 0; i < nSegment - 1; i++)
	{
		face[d].nVerts = 4;
		face[d].vert = new VertexID[4];
		face[d].vert[0].vertIndex = i;
		face[d].vert[1].vertIndex = i + 1;
		face[d].vert[2].vertIndex = i + nSegment + 1;
		face[d].vert[3].vertIndex = i + nSegment;
		d++;
	}
	for (int i = 0; i < nSegment - 1; i++)
	{
		face[d].nVerts = 4;
		face[d].vert = new VertexID[4];
		face[d].vert[0].vertIndex = i + 2 * nSegment;
		face[d].vert[1].vertIndex = i + 2 * nSegment + 1;
		face[d].vert[2].vertIndex = i + 3 * nSegment + 1;
		face[d].vert[3].vertIndex = i + 3 * nSegment;
		d++;
	}
}
void Mesh::CreateHalfMoon(float distance, float fHeight, int nSegment1, float nRadius1, int nSegment2, float nRadius2) {
	//distance là khoảng cách giữa 2 tâm
	numVerts = nSegment1 * 2 + nSegment2 * 2;
	pt = new Point3[numVerts];
	float x, y, z;
	float fAngle1 = PI / nSegment1;
	float fAngle2 = PI / nSegment2;
	for (int i = 0; i < nSegment1; i++)
	{
		x = nRadius1 * cos(PI / 2 + fAngle1 * (i));
		z = nRadius1 * sin(PI / 2 + fAngle1 * (i));
		y = fHeight / 2;
		pt[i].set(x, y, z);
		y = -fHeight / 2;
		pt[i + nSegment1].set(x, y, z);

	}

	for (int i = 0; i < nSegment2; i++)
	{
		x = distance + nRadius2 * cos(PI / 2 - fAngle2 * i);
		z = nRadius2 * sin(PI / 2 - fAngle2 * i);
		y = fHeight / 2;
		pt[i + 2 * nSegment1].set(x, y, z);
		y = -fHeight / 2;
		pt[i + 2 * nSegment1 + nSegment2].set(x, y, z);
	}

	numFaces = nSegment1 + nSegment2 + 4;
	face = new Face[numFaces];
	int d = 0;
	for (int i = 0; i < nSegment1 - 1; i++)
	{
		face[i].nVerts = 4;
		face[i].vert = new VertexID[face[i].nVerts];
		face[i].vert[0].vertIndex = i;
		face[i].vert[1].vertIndex = i + 1;
		face[i].vert[2].vertIndex = i + nSegment1 + 1;
		face[i].vert[3].vertIndex = i + nSegment1;
		d++;
	}

	for (int i = 0; i < nSegment2 - 1; i++)
	{
		face[d].nVerts = 4;
		face[d].vert = new VertexID[face[d].nVerts];
		face[d].vert[0].vertIndex = i + 2 * nSegment1;
		face[d].vert[1].vertIndex = i + 1 + 2 * nSegment1;
		face[d].vert[2].vertIndex = i + nSegment2 + 1 + 2 * nSegment1;
		face[d].vert[3].vertIndex = i + nSegment2 + 2 * nSegment1;
		d++;
	}
	//Vòng bo phía ngoài ben trái
	face[d].nVerts = 4;
	face[d].vert = new VertexID[face[d].nVerts];
	face[d].vert[0].vertIndex = 0;
	face[d].vert[1].vertIndex = nSegment1;
	face[d].vert[2].vertIndex = 2 * nSegment1 + nSegment2;
	face[d].vert[3].vertIndex = 2 * nSegment1;
	d++;
	//vòng bo phía ngoài ben phải
	face[d].nVerts = 4;
	face[d].vert = new VertexID[face[d].nVerts];
	face[d].vert[0].vertIndex = nSegment1 - 1;
	face[d].vert[1].vertIndex = 2 * nSegment1 - 1;
	face[d].vert[2].vertIndex = 2 * nSegment1 + 2 * nSegment2 - 1;
	face[d].vert[3].vertIndex = 2 * nSegment1 + nSegment2 - 1;
	d++;

	//Vẽ mặt úp ở trên
	face[d].nVerts = nSegment1 + nSegment2;
	face[d].vert = new VertexID[face[d].nVerts];
	int k = 0;
	for (int i = 0; i < nSegment1; i++) {
		face[d].vert[k].vertIndex = i;
		k++;
	}
	for (int i = 2 * nSegment1 + nSegment2 - 1; i >= 2 * nSegment1; i--)
	{
		face[d].vert[k].vertIndex = i;
		k++;
	}
	d++;
	//Vẽ mặt úp ở dưới
	face[d].nVerts = nSegment1 + nSegment2;
	face[d].vert = new VertexID[face[d].nVerts];
	k = 0;
	for (int i = nSegment1; i < 2 * nSegment1; i++) {
		face[d].vert[k].vertIndex = i;
		k++;
	}
	for (int i = 2 * nSegment1 + 2 * nSegment2 - 1; i >= 2 * nSegment1 + nSegment2; i--)
	{
		face[d].vert[k].vertIndex = i;
		k++;
	}
	d++;
}
void Mesh::CreateBarTool(float fSizeX, float fSizeY, int nSegment1, float fRadius, float nRadius, float fHeight, int nSegment2)
{
	////////////
	float halfX = fSizeX / 2.0;	float halfY = fSizeY / 2.0;	float x, y, z;	numVerts = (nSegment1) * 4 + 2 * (nSegment2 * 2 * 2 + 1);	pt = new Point3[numVerts];	numFaces = nSegment1 * 3 + 2 * (nSegment2 * 4 + 1);	face = new Face[numFaces];	int		i;	int		idx;	float	fAngle = PI / nSegment1;	float o1, o2;	o1 = halfX;	o2 = -halfX;	for (int i = 0; i < nSegment1; i++)	{		x = o1 + fRadius * cos(PI / 2 + fAngle * (i + 1));		z = fRadius * sin(PI / 2 + fAngle * i);		y = halfY;		pt[i].set(x, y, z);		y = -halfY;		pt[i + nSegment1].set(x, y, z);		x = o2 + fRadius * cos(PI / 2 - fAngle * i);		z = fRadius * sin(PI / 2 - fAngle * i);		y = halfY;		pt[i + nSegment1 + nSegment1].set(x, y, z);		y = -halfY;		pt[i + nSegment1 + nSegment1 + nSegment1].set(x, y, z);	}	int d = 0;	for (int i = 0; i < nSegment1; i++)	{		face[i].nVerts = 4;		face[i].vert = new VertexID[face[i].nVerts];		face[i].vert[0].vertIndex = i;		face[i].vert[1].vertIndex = i + nSegment1;		face[i].vert[2].vertIndex = i + nSegment1 * 3;		face[i].vert[3].vertIndex = i + nSegment1 * 2;		d++;	}	for (int i = 0; i < nSegment1 - 1; i++)	{		face[d].nVerts = 4;		face[d].vert = new VertexID[4];		face[d].vert[0].vertIndex = i;		face[d].vert[1].vertIndex = i + 1;		face[d].vert[2].vertIndex = i + nSegment1 + 1;		face[d].vert[3].vertIndex = i + nSegment1;		d++;	}	for (int i = 0; i < nSegment1 - 1; i++)	{		face[d].nVerts = 4;		face[d].vert = new VertexID[4];		face[d].vert[0].vertIndex = i + 2 * nSegment1;		face[d].vert[1].vertIndex = i + 2 * nSegment1 + 1;		face[d].vert[2].vertIndex = i + 3 * nSegment1 + 1;		face[d].vert[3].vertIndex = i + 3 * nSegment1;		d++;	}
	///////////
	CreateECylinder(-halfX, nSegment2, fHeight, fRadius, nRadius, (nSegment1) * 4, nSegment1 * 3);
	CreateECylinder(halfX, nSegment2, fHeight, fRadius, nRadius, (nSegment1) * 4 + nSegment2 * 2 * 2 + 1, nSegment1 * 3 + nSegment2 * 4 + 1);
}
void Mesh::DrawColor()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;
			int		ic = face[f].vert[v].colorIndex;

			//ic = f % COLORNUM;

			glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]);
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}

void Mesh::SetColor(int colorIdx) {
	for (int f = 0; f < numFaces; f++)
	{
		for (int v = 0; v < face[f].nVerts; v++)
		{
			face[f].vert[v].colorIndex = colorIdx;
		}
	}
}


