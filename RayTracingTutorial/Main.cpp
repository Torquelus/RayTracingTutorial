#include <iostream>
#include <string>
#include <fstream>
#include "Vector3.h"

int main() {
	// Get Desired File Name
	std::string fileName;
	std::cout << "Enter File Name: ";
	std::cin >> fileName;

	// Open Output File
	std::ofstream outputFile;
	outputFile.open("images/" + fileName + ".ppm");

	// Height and Width of Image
	int nx = 200;
	int ny = 100;

	// Initialise PPM
	outputFile << "P3\n" << nx << " " << ny << "\n255\n";

	// Fill PPM Image
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			
			// Vector3 of Values
			Vector3 col(float(i) / float(nx), float(j) / float(ny), 0.2);

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