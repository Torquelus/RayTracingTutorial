#pragma once
#include "Ray.h"

class Camera {
public:
	// Constructor
	Camera();

	// Ray Function
	Ray getRay(float u, float v);

	// Destructor
	~Camera();

	// Variables
	Vector3 origin;
	Vector3 lowerLeftCorner;
	Vector3 horizontal;
	Vector3 vertical;
};

