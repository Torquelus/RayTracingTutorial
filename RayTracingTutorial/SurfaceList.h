#pragma once
#include "Sphere.h"

class SurfaceList : public Surface {
public:
	// Constructors
	SurfaceList();
	SurfaceList(Surface** l, int n);

	// Hit function
	virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const;

	// Destructor
	~SurfaceList();

	// Variables
	Surface** list;
	int listSize;
};

