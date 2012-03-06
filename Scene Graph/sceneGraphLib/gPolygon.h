//gPolygon.h

#pragma once

#include "gMatrix3.h"
#include "gVector3.h"
#include <math.h>


class gPolygon{

private:
	gMatrix3 matrix;					
	float* vertices;										// Vertices values for shape (sets of 3)
	float* colors;											// Color values for verticies (sets of 3)
	unsigned short int* indices;							// Number of indices for verticies
	int sideCount;											// Number of sides present in the polygon

public:
	gPolygon();												// Constructor
	~gPolygon();											// Destructor
	gPolygon(unsigned int, gVector3, float);				// Constructor with number of sides, color vector, and indices
	gMatrix3 getMatrix();									// get the Matrix for shape
	float* getVertices();									// Return the vertices in shape
	float* getColors();										// Return the colors in the shape
	void setColors(float r, float g, float b);				// set the color values for all vertices
	unsigned short int* getIndices();						// Return the number of indivies
	unsigned int getSides();								// Return the number of sides
	void setMatrix(gMatrix3);								// Set the matrix
	//float* correctRotation(int, float*);
};