#include "Ray.h"

// Default Constructor
Ray::Ray()
{
}

// Constructor
Ray::Ray(const Vector3& a, const Vector3& b) {
	A = a;
	B = b;
}

// Get Origin
Vector3 Ray::origin() const {
	return A;
}

// Get Direction of Ray
Vector3 Ray::direction() const {
	return B;
}

Vector3 Ray::pointAtParameter(float t) const {
	return A + t * B;
}

// Destructor
Ray::~Ray()
{
}
