#pragma once
#include "Surface.h"

class Material {
public:
	
	// Ray scattering
	virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const = 0;

};

