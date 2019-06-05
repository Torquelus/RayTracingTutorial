#pragma once
#include "Surface.h"

class Material {
public:
	
	// Constructor
	Material(){}

	// Ray scattering
	virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const = 0;

	// Destructor
	~Material(){}

};

// Reflect ray
Vector3 reflect(const Vector3& v, const Vector3& n) {

	// Return reflection
	return v - 2 * dot(v, n) * n;

}

// Return random point in unit circle
Vector3 randomInUnitSphere() {

	// Point
	Vector3 p;

	// Try getting random point
	do {
		p = 2.0 * Vector3(((float)rand() / (RAND_MAX)), ((float)rand() / (RAND_MAX)), ((float)rand() / (RAND_MAX))) - Vector3(1, 1, 1);
	} while (p.squaredLength() >= 1.0);


	// Return point
	return p;

}

// Refract
bool refract(const Vector3& v, const Vector3& n, float niOverNt, Vector3& refracted) {
	
	// Create unit vector from v
	Vector3 uv = unitVector(v);

	// Find dot product with normal
	float dt = dot(uv, n);

	// Get discriminant of equation
	float discriminant = 1.0 - niOverNt * niOverNt * (1.0 - (dt * dt));

	// Check if discriminant is larger than 0
	if (discriminant > 0) {
		refracted = niOverNt * (uv - (n * dt)) - n * sqrt(discriminant);
		return true;
	}
	// Else didn't hit
	else {
		return false;
	}

}