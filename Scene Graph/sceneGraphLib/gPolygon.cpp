// gPolygon.cpp

#include "gPolygon.h"
#include <iostream>


using namespace std;
#define PI 3.14159265

//////////////////////////
/***** CONSTRUCTOR ******/
//////////////////////////
gPolygon::gPolygon(){
	sideCount =0;
}

/////////////////////////////////////////
/******* With Shape Constructor ********/
/////////////////////////////////////////
gPolygon::gPolygon(unsigned int sides, gVector3 color, float size){
	if (sides >= 3) 
	{	sideCount = sides;
		vertices = new float [sides*3];
		indices = new unsigned short int [3*(sides-2)];
		colors = new float [3*sides];

		int angle_count = 0;
		// Create the vertices based on the number of sides.
		for(int v = 0; v < (sides*3); v+=3) {
			vertices[v] = size*cos((2*PI*angle_count)/(sides));
			vertices[v+1] = (size)*sin((2*PI*angle_count)/(sides));
			vertices[v+2] = 1;
			angle_count ++;
			//cout << "vertex" << angle_count<<": ("<<vertices[v] <<", "<<vertices[v+1]<<", "<<vertices[v+2]<<endl;
		}
		// Create Color array for the shape
		for(int c = 0; c < (sides*3); c+=3){
			colors[c] = color[0];
			colors[c+1] = color[1];
			colors[c+2] = color[2];
		}
		// Create Indices for the Shape
		int v1 = 1;
		int v2 = 2;
		for(int i = 0; i<(sides-2)*3; i+=3){
			indices[i] = 0;
			indices[i+1] = v1;
			indices[i+2]= v2;
			v1++;
			v2++;
		}
		sideCount = sides;
		matrix = gMatrix3::identity();
	}
}


//////////////////////////
/***** DESTRUCTOR ******/
//////////////////////////
	gPolygon::~gPolygon(){
		delete[] vertices;
		delete[] colors;
		delete[] indices;
	}


//////////////////////////
/***** Get Matrix ******/
//////////////////////////
gMatrix3 gPolygon::getMatrix(){
	return matrix;
}


//////////////////////////
/***** Set Matrix ******/
//////////////////////////
void gPolygon::setMatrix(gMatrix3 mat){
	matrix = mat;
}

//////////////////////////
/***** Get Vertices ******/
//////////////////////////
float* gPolygon::getVertices(){
	return vertices;
}


//////////////////////////
/***** Get Indices ******/
//////////////////////////
unsigned short int* gPolygon::getIndices(){
	return indices;
}


//////////////////////////
/***** getSides *********/
//////////////////////////
float* gPolygon::getColors(){
	return colors;
}

unsigned int gPolygon::getSides(){
	return sideCount;
	cout<<"SIDE COUNT CALLED: " << sideCount << endl;
}

void gPolygon::setColors(float r, float g, float b){
	int place = 0;
	for(int c = 0; c < (getSides()*3); c+=3){
			colors[c] = r;
			colors[c+1] = g;
			colors[c+2] = b;
		}
}