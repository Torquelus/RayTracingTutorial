#include "Sphere.h"

// Constructor
Sphere::Sphere(){
	center = Vector3(0, 0, 0);
	radius = 0;
	material = nullptr;
}

// Constructor with Initialisation
Sphere::Sphere(Vector3 cen, float r, Material* mat) {
	center = cen;
	radius = r;
	material = mat;
}

// Sphere Hit Function
bool Sphere::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const {

	// Vector from ray origin to center
	Vector3 oc = r.origin() - center;

	// Solving for discriminant
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - a * c;

	// Check if positive discriminant
	if (discriminant > 0) {

		// Find result 1 to equation
		float temp = (-b - sqrt(b * b - a * c)) / a;

		// Check if temp is between min and max, update HitRecord
		if (temp > tMin && temp < tMax) {
			rec.t = temp;
			rec.p = r.pointAtParameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat = material;
			return true;
		}
		
		// Find result 2 to equation
		temp = (-b + sqrt(b * b - a * c)) / a;

		// Check if temp is between min and max, update HitRecord
		if (temp > tMin && temp < tMax) {
			rec.t = temp;
			rec.p = r.pointAtParameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat = material;
			return true;
		}

	}

	// If not positive return false
	return false;

}

// Destructor
Sphere::~Sphere(){
}
