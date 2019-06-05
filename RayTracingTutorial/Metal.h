#pragma once
#include "Material.h"

class Metal : public Material{

public:

	// Constructor
	Metal(const Vector3& a, float f) { 
		albedo = a;
		fuzz = f;
	}

	// Override Scatter Function
	virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const {

		// Reflected ray
		Vector3 reflected = reflect(unitVector(rIn.direction()), rec.normal);

		// Scattered ray
		scattered = Ray(rec.p, reflected + fuzz * randomInUnitSphere());

		// Colour data
		attenuation = albedo;

		// Exit function
		return (dot(scattered.direction(), rec.normal) > 0);

	}

	// Destructor
	~Metal(){}

	// Variables
	Vector3 albedo;
	float fuzz;

};
