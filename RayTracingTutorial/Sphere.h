#pragma once
#include "Surface.h"

class Sphere : public Surface {
public:
	// Constructors
	Sphere();
	Sphere(Vector3 cen, float r, Material* mat);

	// Hit Function
	virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const;
	
	// Destructor
	~Sphere();

	// Variables
	Vector3 center;
	float radius;
	Material* material;
};

