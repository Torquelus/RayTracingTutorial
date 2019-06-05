#include <iostream>
#include <string>
#include <fstream>
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "SurfaceList.h"
#include "Sphere.h"
#include "Camera.h"
#include "Metal.h"
#include "Lambertian.h"
#include "Dielectric.h"

// Function Predeclarations
Vector3 colour(const Ray& r, Surface* world, int depth);

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

	// Number of samples for antialiasing
	int ns = 100;

	// Total number of runs
	float total = float(nx) * float(ny);

	// Progress variable
	float progress = 0.0;

	// Reset random seed
	srand(time(NULL));

	// Define Important Vector 3s
	Vector3 lowerLeftCorner(-2.0, -1.0, -1.0);
	Vector3 horizontal(4.0, 0.0, 0.0);
	Vector3 vertical(0.0, 2.0, 0.0);
	Vector3 origin(0.0, 0.0, 0.0);

	// Initialise PPM
	outputFile << "P3\n" << nx << " " << ny << "\n255\n";

	// Set output format
	std::cout << std::fixed;
	std::cout << std::setprecision(1);

	// List of Surfaces
	Surface* list[4];

	// Populate list
	list[0] = new Sphere(Vector3(0, 0, -1), 0.5, new Lambertian(Vector3(0.8, 0.3, 0.3)));
	list[1] = new Sphere(Vector3(0, -100.5, -1), 100.0, new Lambertian(Vector3(0.8, 0.8, 0.0)));
	list[2] = new Sphere(Vector3(1, 0, -1), 0.5, new Metal(Vector3(0.8, 0.6, 0.2), 0.3));
	list[3] = new Sphere(Vector3(-1, 0, -1), 0.5, new Dielectric(1.5));

	// SurfaceList
	Surface* world = new SurfaceList(list, 4);

	// Create main camera
	Camera cam;

	// Fill PPM Image
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			// Initialise colour to 0, 0, 0
			Vector3 col(0, 0, 0);

			// Loop through for antialiasing
			for (int s = 0; s < ns; s++) {
				
				// Coordinates
				float u = float(i + ((float)rand() / (RAND_MAX))) / float(nx);
				float v = float(j + ((float)rand() / (RAND_MAX))) / float(ny);

				// Create ray
				Ray r = cam.getRay(u, v);

				// Find point at ray
				Vector3 p = r.pointAtParameter(2.0);

				// Add to colour
				col += colour(r, world, 0);

			}

			// Get average of colour
			col /= float(ns);

			// Fix gamma
			col = Vector3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

			// Converted RGB Values 0-255
			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);

			// Add to PPM
			outputFile << ir << " " << ig << " " << ib << "\n";

			// Print progress
			progress += 1.0;
			float percent = 100 * progress / total;
			std::cout << "Progress: " << percent << "%" << "\r";
		}
	}

	// Add newline
	std::cout << "\nCompleted!\n";

	// Cleanup
	outputFile.close();
	return 0;
}

// Colour Function
Vector3 colour(const Ray& r, Surface* world, int depth) {
	
	// HitRecord to check
	HitRecord rec;

	// Check if hit
	if (world->hit(r, 0.001, FLT_MAX, rec)) {
		
		// Holders of information
		Ray scattered;
		Vector3 attenuation;

		// Check if within depth and other stuff
		if (depth < 50 && rec.mat->scatter(r, rec, attenuation, scattered)) {
			return attenuation * colour(scattered, world, depth + 1);
		}
		// Else return default colour
		else {
			return Vector3(0, 0, 0);
		}

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