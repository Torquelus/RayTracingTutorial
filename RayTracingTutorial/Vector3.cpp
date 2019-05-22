#include "Vector3.h"

// Constructor
Vector3::Vector3(float e0, float e1, float e2){
	e[0] = e0;
	e[1] = e1;
	e[2] = e2;
}

// Operator Overloads

inline Vector3& Vector3::operator+=(const Vector3& v2) {
	e[0] += v2.e[0];
	e[1] += v2.e[1];
	e[2] += v2.e[2];
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& v2) {
	e[0] -= v2.e[0];
	e[1] -= v2.e[1];
	e[2] -= v2.e[2];
	return *this;
}

inline Vector3& Vector3::operator*=(const Vector3& v2) {
	e[0] *= v2.e[0];
	e[1] *= v2.e[1];
	e[2] *= v2.e[2];
	return *this;
}

inline Vector3& Vector3::operator/=(const Vector3& v2) {
	e[0] /= v2.e[0];
	e[1] /= v2.e[1];
	e[2] /= v2.e[2];
	return *this;
}

inline Vector3& Vector3::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

inline Vector3& Vector3::operator/=(const float t) {
	float k = 1.0 / t;

	e[0] *= k;
	e[1] *= k;
	e[2] *= k;

	return *this;
}

// Vector3 Methods

// Length of Vector3
inline float Vector3::length() const{
	return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}

// Squared Length of Vector3
inline float Vector3::squaredLength() const {
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

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