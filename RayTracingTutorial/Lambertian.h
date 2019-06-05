#pragma once
#include "Material.h"

class Lambertian : public Material{
public:
	
	// Constructor
	Lambertian(const Vector3 a) { albedo = a; }

	// Overloaded Scatter Function
	virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const {
		
		// Target Scattering
		Vector3 target = rec.p + rec.normal + randomInUnitSphere();

		// Scattered ray
		scattered = Ray(rec.p, target - rec.p);

		// Colour information
		attenuation = albedo;

		// Exit function
		return true;

	}

	// Destructor
	~Lambertian(){}

	// Variables
	Vector3 albedo;

};