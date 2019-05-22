#pragma once
#include "Vector3.h"

class Ray
{
public:
	// Default Constructor
	Ray();

	// Contructor
	Ray(const Vector3& a, const Vector3& b);

	// Origin of Ray
	Vector3 origin() const;

	// Direction of Ray
	Vector3 direction() const;

	// Return A + Bt for Given t
	Vector3 pointAtParameter(float t) const;

	// Destructor
	~Ray();

	// Vectors for Ray
	Vector3 A;
	Vector3 B;
};

