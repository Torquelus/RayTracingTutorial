#include "Camera.h"

// Constructor
Camera::Camera() {
	lowerLeftCorner = Vector3(-2.0, -1.0, -1.0);
	horizontal = Vector3(4.0, 0.0, 0.0);
	vertical = Vector3(0.0, 2.0, 0.0);
	origin = Vector3(0.0, 0.0, 0.0);
}

// Ray function
Ray Camera::getRay(float u, float v) {
	return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}

// Destructor
Camera::~Camera() {
}