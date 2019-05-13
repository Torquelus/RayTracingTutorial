#pragma once

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Vector3{
public:
	// Constructor
	Vector3(float e0, float e1, float e2);

	// X, Y, Z getters
	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	
	// R, G, B getters
	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }



	// Destructor
	~Vector3();
private:
	// Holds Values
	float e[3];
};

