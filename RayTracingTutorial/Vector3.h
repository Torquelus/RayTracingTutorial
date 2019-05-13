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

	// Basic Operator Overloads
	inline const Vector3& operator+() const { return *this; }
	inline Vector3 operator-() const { return Vector3(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) { return e[i]; }

	// Other Operator Overloads
	inline Vector3& operator+=(const Vector3& v2);
	inline Vector3& operator-=(const Vector3& v2);
	inline Vector3& operator*=(const Vector3& v2);
	inline Vector3& operator/=(const Vector3& v2);
	inline Vector3& operator*=(const float t);
	inline Vector3& operator/=(const float t);

	// Vector3 Methods
	inline float length() const;
	inline float squaredLength() const;
	inline void makeUnitVector();

	// Destructor
	~Vector3();

	// Holds Values
	float e[3];
};

