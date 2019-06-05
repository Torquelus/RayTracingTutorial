#pragma once
#include "Material.h"

class Dielectric : public Material {
public:

	// Constructor
	Dielectric(float ri) {
		refIndex = ri;
	}

	// Override Scatter Function
	virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const {

		// Variable for normal
		Vector3 outwardNormal;

		// Reflected variable
		Vector3 reflected = reflect(rIn.direction(), rec.normal);

		// ni / nt
		float niOverNt;

		// Colour value
		attenuation = Vector3(1.0, 1.0, 1.0);

		// Refracted Vector3
		Vector3 refracted;

		// if outside the surface
		if (dot(rIn.direction(), rec.normal) > 0) {
			
			// Set outward normal and ni / nt
			outwardNormal = -rec.normal;
			niOverNt = refIndex;

		}
		else {
			outwardNormal = rec.normal;
			niOverNt = 1.0 / refIndex;
		}

		// Check if refracts
		if (refract(rIn.direction(), outwardNormal, niOverNt, refracted)) {
			scattered = Ray(rec.p, refracted);
		}
		// Else reflect
		else {
			scattered = Ray(rec.p, reflected);
			return false;
		}

		// Return from function
		return true;

	}

	// Variables
	float refIndex;

};

