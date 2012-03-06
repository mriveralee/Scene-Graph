	/******************************/
	/******  Geometry CLASS *******/
	/******************************/

#include "Geometry.h"

	//////////////////////////
	/***** CONSTRUCTOR ******/
	//////////////////////////
	Geometry::Geometry(){
		vertices = 0;
		colors = 0;
		indices =0;
	}
	// Pass in all points
	Geometry::Geometry(float* vert, float* col, unsigned short* ind){
		vertices = vert;
		colors = col;
		indices = ind;
	}

	//////////////////////////
	/***** DESTRUCTOR ******/
	//////////////////////////
	Geometry::~Geometry(){
		delete vertices;
		delete colors;
		delete indices;
	}

	//////////////////////////
	/***** Get Vertices******/
	//////////////////////////
	float* Geometry::getVertices(){
		return vertices;
	}

	//////////////////////////
	/****** Get Color *******/
	//////////////////////////
	float* Geometry::getColors(){
		return colors;
	}


	//////////////////////////
	/***** Get Indices ******/
	//////////////////////////
	unsigned short* Geometry::getIndices(){
		return indices;
	}



