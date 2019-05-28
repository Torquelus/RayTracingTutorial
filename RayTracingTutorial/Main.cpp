#include <iostream>
#include <string>
#include <fstream>
#include "Ray.h"

// Function Predeclarations
Vector3 colour(const Ray& r);
float hitSphere(const Vector3& center, float radius, const Ray& r);

// Main Function
int main() {
	// Get Desired File Name
	std::string fileName;
	std::cout << "Enter File Name: ";
	std::cin >> fileName;

	// Open Output File
	std::ofstream outputFile;
	outputFile.open("images/" + fileName + ".ppm");

	// Height and Width of Image
	int nx = 800;
	int ny = 400;

	// Define Important Vector 3s
	Vector3 lowerLeftCorner(-2.0, -1.0, -1.0);
	Vector3 horizontal(4.0, 0.0, 0.0);
	Vector3 vertical(0.0, 2.0, 0.0);
	Vector3 origin(0.0, 0.0, 0.0);

	// Initialise PPM
	outputFile << "P3\n" << nx << " " << ny << "\n255\n";

	// Fill PPM Image
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			
			// Coordinates
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);

			// Create Ray for each coordinate
			Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical);

			// Vector3 of Values
			Vector3 col = colour(r);

			// Converted RGB Values 0-255
			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);

			// Add to PPM
			outputFile << ir << " " << ig << " " << ib << "\n";
		}
	}

	// Cleanup
	outputFile.close();
	return 0;
}

// Colour Function
Vector3 colour(const Ray& r) {
	// Get value where ray touches sphere, or return -1 if doesn't touch
	float t = hitSphere(Vector3(0, 0, -1), 0.5, r);

	// Check if hit sphere
	if (t > 0.0) {
		Vector3 N = unitVector(r.pointAtParameter(t) - Vector3(0, 0, -1));
		return 0.5 * Vector3(N.x() + 1, N.y() + 1, N.z() + 1);
	}

	// Define initial and final colours
	Vector3 initColour = Vector3(1.0F, 1.0F, 1.0F);
	Vector3 finalColour = Vector3(0.5F, 0.7F, 1.0F);

	// Turn direction to unit vector
	Vector3 unitDirection = unitVector(r.direction());

	// Float for lerping, top to bottom of screen from 0 to 1.0
	t = 0.5 * (unitDirection.y() + 1.0);

	// Return colour at specified position
	return (1.0 - t) * initColour + t * finalColour;
}

// Check if hit sphere
float hitSphere(const Vector3& center, float radius, const Ray& r) {
	Vector3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	
	// Check if real answers
	if (discriminant < 0) {
		return -1.0;
	}
	else {
		return (-b - sqrt(discriminant)) / (2.0 * a);
	}
}