#pragma once

#include "gMatrix3.h"
#include <string>

class Geometry {

private:
	float* vertices;
	float* colors;
	unsigned short* indices;
	
public:
	Geometry();
	Geometry(float*, float*,unsigned short*);
	~Geometry();
	float* getVertices();
	float* getColors();
	unsigned short* getIndices();
};



