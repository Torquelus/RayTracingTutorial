#pragma once

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Vector3{
public:
	// Default Constructor
	Vector3(){}

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
	inline float length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
	inline float squaredLength() const;
	inline void makeUnitVector();

	// Destructor
	~Vector3();

	// Holds Values
	float e[3];
};

// Other Functions

// Operator Overloads

inline std::istream& operator>>(std::istream& is, Vector3& v) {
	is >> v.e[0] >> v.e[1] >> v.e[2];
	return is;
}

inline std::ostream& operator<<(std::ostream& os, const Vector3& v) {
	os << v.e[0] << ", " << v.e[1] << ", " << v.e[2];
	return os;
}

inline Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	return Vector3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vector3 operator-(const Vector3 & v1, const Vector3 & v2) {
	return Vector3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vector3 operator*(const Vector3 & v1, const Vector3 & v2) {
	return Vector3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vector3 operator/(const Vector3 & v1, const Vector3 & v2) {
	return Vector3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vector3 operator*(const float t, const Vector3 & v) {
	return Vector3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vector3 operator*(const Vector3 & v, const float t) {
	return Vector3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vector3 operator/(const Vector3 & v, const float t) {
	return Vector3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}

// Dot Product
inline float dot(const Vector3 & v1, const Vector3 & v2) {
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

// Cross Product
inline Vector3 cross(const Vector3 & v1, const Vector3 & v2) {
	return Vector3((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]), (v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2]), (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}

// Unit Vector
inline Vector3 unitVector(Vector3 v) {
	return v / v.length();
}