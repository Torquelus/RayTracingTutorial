#include "Vector3.h"

// Constructor
Vector3::Vector3(float e0, float e1, float e2){
	e[0] = e0;
	e[1] = e1;
	e[2] = e2;
}

// Vector3 Methods

// Make Unit Vector
inline void Vector3::makeUnitVector() {
	// Find Multiplier
	float k = 1.0 / length();

	// Apply Multiplier
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

// Destructor
Vector3::~Vector3(){
}