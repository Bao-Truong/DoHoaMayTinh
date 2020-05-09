#pragma once
class Point3D
{
public:
	float x, y, z;

	Point3D(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Point3D() { x = y = z = 0; }
	
};

