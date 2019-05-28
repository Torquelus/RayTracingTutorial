#pragma once

#include "Ray.h"

struct HitRecord {
	float t;
	Vector3 p;
	Vector3 normal;
};

class Surface
{
public:
	// Constructor
	Surface();

	virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const = 0;

	// Destructor
	~Surface();
};

