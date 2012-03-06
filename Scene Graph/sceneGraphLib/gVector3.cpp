/* Michael Rivera
 * CIS 277 - HW #1 
 * PennKey - rimic
 * 'gVector3.cpp' - Implementation of Class/functions
 */
#include "gVector3.h"		// Class Definition for gVector3


///----------------------------------------------------------------------
/// Constructors
///----------------------------------------------------------------------

// Base Constructor
gVector3::gVector3(){
	data[0] = 0.0;
	data[1] = 0.0;
	data[2] = 0.0;
}

// Defined Constructor
gVector3::gVector3(float ax, float by, float cz){
	data[0] = ax;
	data[1] = by;
	data[2] = cz;
}

// Destructor
gVector3::~gVector3(){
}


///----------------------------------------------------------------------
/// Functions
///----------------------------------------------------------------------

// Override [] operator & Return Component of Vector
float gVector3::operator[](unsigned int index) const{
	assert(index >= 0 && index <= 2);		// Checks bounds
	return data[index];
}


// Return Component og Vector
float& gVector3::operator[](unsigned int index){
	assert(index >= 0 && index <= 2);
	return *(data+index);
}

// Print out the 3D Vector
ostream& operator<<(ostream &stream, gVector3 v){
	return stream << "[" << v.data[0] << ", " << v.data[1] << ", " << v.data[2] << "]";
}

// Get Length of a 3D Vector
float gVector3::length() const{
	float x = data[0]*data[0];
	float y = data[1]*data[1];
	float z = data[2]*data[2];
	float ans = x+y+z;
	return powf(ans, 0.5);
}

// Checks if v1 == v2
bool gVector3::operator==(const gVector3& v2){
	float x = fabs(data[0]-(v2.data[0]));
	float y = fabs(data[1]-(v2.data[1]));
	float z = fabs(data[2]-(v2.data[2]));
	if (x < 0.00001 && y < 0.00001 && z < 0.00001){
		return true;
	}
	else 
		return false;
}

//Checks if v1 != v2
bool gVector3::operator!=(const gVector3& v2){
	float x = fabs(data[0]-(v2.data[0]));
	float y = fabs(data[1]-(v2.data[1]));
	float z = fabs(data[2]-(v2.data[2]));
	if (x < 0.00001 && y < 0.00001 && z < 0.00001){
		return false;
	}
	else 
		return true;
}


// Vector Addition
gVector3 gVector3::operator+(const gVector3& v2){
	float x = data[0] + v2.data[0];  
	float y = data[1] + v2.data[1];  
	float z = data[2] + v2.data[2];  
	return gVector3(x, y, z);
}

// Vector Subtraction
gVector3 gVector3::operator-(const gVector3& v2){
	float x = data[0] - v2.data[0];  
	float y = data[1] - v2.data[1];  
	float z = data[2] - v2.data[2];  
	return gVector3(x, y, z);
}

// Scalar Multiplication (v * c)
gVector3 gVector3::operator*(float c){
	float x = data[0]*c; 
	float y = data[1]*c;
	float z = data[2]*c; 
	return gVector3(x, y, z);
}



// Scalar Multiplication (c * v)
gVector3 operator*(float c, const gVector3& v){
	float x = (v.data[0])*c; 
	float y = (v.data[1])*c;
	float z = (v.data[2])*c; 
	return gVector3(x, y, z);
}

// Scalar Division (v1 / c)
gVector3 gVector3::operator/(float c){
	float x = data[0]/c; 
	float y = data[1]/c;
	float z = data[2]/c; 
	return gVector3(x, y, z);
}


// Dot Product (v1 * v2)
float gVector3::operator*(const gVector3& v2){
	float x = data[0]*(v2.data[0]);
	float y = data[1]*(v2.data[1]);
	float z = data[2]*(v2.data[2]);
	return x+y+z;
}


// Cross Product ( v1 % v2)
gVector3 gVector3::operator%(const gVector3& v2){
	float x = (data[1]*v2.data[2]) - (data[2]*v2.data[1]);
	float y = (data[2]*v2.data[0]) - (data[0]*v2.data[2]);
	float z = (data[0]*v2.data[1]) - (data[1]*v2.data[0]);

return gVector3(x,y,z);
}


float* gVector3::getData(){
	return data;
}

