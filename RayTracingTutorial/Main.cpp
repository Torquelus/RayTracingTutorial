#include <iostream>
#include <string>
#include <fstream>
#include <float.h>
#include "SurfaceList.h"
#include "Sphere.h"

// Function Predeclarations
Vector3 colour(const Ray& r, Surface* world);

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

	// List of Surfaces
	Surface* list[2];

	// Populate list
	list[0] = new Sphere(Vector3(0, 0, -1), 0.5);
	list[1] = new Sphere(Vector3(0, -100.5, -1), 100.0);

	// SurfaceList
	Surface* world = new SurfaceList(list, 2);

	// Fill PPM Image
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			
			// Coordinates
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);

			// Create Ray for each coordinate
			Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical);

			Vector3 p = r.pointAtParameter(2.0);

			// Vector3 of Values
			Vector3 col = colour(r, world);

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
Vector3 colour(const Ray& r, Surface* world) {
	// HitRecord to check
	HitRecord rec;

	// Check if hit
	if (world->hit(r, 0.0, FLT_MAX, rec)) {
		// Return normal colour
		return 0.5* Vector3(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);
	}
	// Otherwise return background gradient
	else {
		
		// Initial and final colours
		Vector3 initColour = Vector3(1.0, 1.0, 1.0);
		Vector3 finalColour = Vector3(0.5, 0.7, 1.0);

		// Unit y direction
		Vector3 unitDirection = unitVector(r.direction());

		// Gradient variable
		float t = 0.5 * (unitDirection.y() + 1.0);

		// Return gradient
		return (1.0 - t) * initColour + t * finalColour;


	}
}