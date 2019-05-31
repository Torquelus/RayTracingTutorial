#include "SurfaceList.h"

// Constructor
SurfaceList::SurfaceList(){
	listSize = 0;
	list = nullptr;
}

// Constructor with values
SurfaceList::SurfaceList(Surface** l, int n){
	list = l;
	listSize = n;
}

// Hit everything in list
bool SurfaceList::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const{
	// Temporary HitRecord
	HitRecord tempRec;

	// Bool if it hit anything
	bool hitAnything = false;

	// Closest value found
	double closestSoFar = tMax;

	// Loop through each element of the list
	for (int i = 0; i < listSize; i++) {
		
		// Check if element is hit
		if (list[i]->hit(r, tMin, closestSoFar, tempRec)) {
			hitAnything = true;
			closestSoFar = tempRec.t;
			rec = tempRec;
		}

	}

	// Return if it hit anything
	return hitAnything;
}

// Destructor
SurfaceList::~SurfaceList(){
}
