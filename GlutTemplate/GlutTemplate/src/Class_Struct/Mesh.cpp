#include "Mesh.h"
#include<gl/glew.h>
static float colors[4][3] = {
	{1,1,0},
{0,1,0},
{0,0,1},
{1,0,0}
};

//void Mesh::DrawWireframe()
//{
//	for (int i = 0; i < numFaces; i++)
//	{
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		glBegin(GL_POLYGON);
//		for (int j = 0; j < faceArr[i].numVerts; j++)
//			glVertex3f(faceArr[i].pointArr[j].x, faceArr[i].pointArr[j].y, faceArr[i].pointArr[j].z);
//		glEnd();
//
//	}
//}
//
//void Mesh::DrawColor()
//{
//	for (int i = 0; i < numFaces; i++)
//	{
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		glColor3fv(colors[i % 4]);
//		glBegin(GL_POLYGON);
//		for (int j = 0; j < faceArr[i].numVerts; j++)
//			glVertex3f(faceArr[i].pointArr[j].x, faceArr[i].pointArr[j].y, faceArr[i].pointArr[j].z);
//		glEnd();
//
//	}
//}
//
//void Mesh::CreateTetrahedron(Point3D &a, Point3D &b, Point3D &c, Point3D &d)
//{
//	numFaces = 4;
//	faceArr = new Face[numFaces];
//
//	faceArr[0].numVerts = 3;
//	faceArr[0].pointArr = new Point3D[3];
//	faceArr[0].pointArr[0] = a;
//	faceArr[0].pointArr[1] = b;
//	faceArr[0].pointArr[2] = c;
//
//	faceArr[1].numVerts = 3;
//	faceArr[1].pointArr = new Point3D[3];
//	faceArr[1].pointArr[0] = a;
//	faceArr[1].pointArr[1] = b;
//	faceArr[1].pointArr[2] = d;
//
//	faceArr[2].numVerts = 3;
//	faceArr[2].pointArr = new Point3D[3];
//	faceArr[2].pointArr[0] = a;
//	faceArr[2].pointArr[1] = c;
//	faceArr[2].pointArr[2] = d;
//
//	faceArr[3].numVerts = 3;
//	faceArr[3].pointArr = new Point3D[3];
//	faceArr[3].pointArr[0] = b;
//	faceArr[3].pointArr[1] = c;
//	faceArr[3].pointArr[2] = d;
//}

void Mesh::DrawWireframe()
{
	for (int i = 0; i < numFaces; i++)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_POLYGON);
		for (int j = 0; j < face_tab[i].numVerts; j++)
		{
			int index = face_tab[i].indices[j].index;
			glVertex3f(index_tab[index].x, index_tab[index].y, index_tab[index].z);
		}
		glEnd();

	}
}

void Mesh::DrawColor()
{
	for (int i = 0; i < numFaces; i++)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glColor3fv(colors[i % 4]);
		glBegin(GL_POLYGON);
		for (int j = 0; j < face_tab[i].numVerts; j++)
		{
			int idx = face_tab[i].indices[j].index;
			glVertex3f(index_tab[idx].x, index_tab[idx].y, index_tab[idx].z);
		}
		glEnd();

	}
}

void Mesh::CreateTetrahedron(Point3D &a, Point3D &b, Point3D &c, Point3D &d)
{
	numVerts = 4;
	index_tab = new Point3D[numVerts];
	index_tab[0] = a;
	index_tab[1] = b;
	index_tab[2] = c;
	index_tab[3] = d;

	numFaces = 4;
	face_tab = new Face[numFaces];

	face_tab[0].add3Vertex(1, 2, 3);
	face_tab[1].add3Vertex(0, 2, 1);
	face_tab[2].add3Vertex(0, 2, 3);
	face_tab[3].add3Vertex(1, 3, 0);
}
