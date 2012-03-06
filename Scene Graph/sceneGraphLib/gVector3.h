//Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright and Tiantian Liu
//University of Pennsylvania

#ifndef GVECTOR3_H
#define GVECTOR3_H

#include <iostream>
#include <assert.h>			// Assert Functions'
using namespace std;

class gVector3{
private:
	float data[3];
public:
	///----------------------------------------------------------------------
	/// Constructors
	///----------------------------------------------------------------------
	gVector3();
	gVector3(float x, float y, float z);
	~gVector3();
	float* getData();
	///----------------------------------------------------------------------
	/// Getters/Setters
	///----------------------------------------------------------------------		
	/// Returns the value at index
	float operator[](unsigned int index) const;
	
	/// Returns a reference to the value at index
	float& operator[](unsigned int index);

	///----------------------------------------------------------------------
	/// Vector Operations
	///----------------------------------------------------------------------
	/// Returns the geometric length of the vector
	float length() const;
		
	///----------------------------------------------------------------------
	/// Operator Functions
	///----------------------------------------------------------------------		
	/// Checks if v1 == v2
	bool operator==(const gVector3& v2);
	
	/// Checks if v1 != v2
	bool operator!=(const gVector3& v2);
	
	/// Vector Addition (v1 + v2)
	gVector3 operator+(const gVector3& v2);
	
	/// Vector Subtraction (v1 - v2)
	gVector3 operator-(const gVector3& v2);
	
	/// Scalar Multiplication (v * c)
	gVector3 operator*(float c);	
	
	/// Scalar Multiplication (c * v)
	friend gVector3 operator*(float c, const gVector3& v);
	
	/// Scalar Division (v/c)
	gVector3 operator/(float c);
	
	/// Dot Product (v1 * v2)
	float operator*(const gVector3& v2);
	
	/// Cross Product (v1 % v2)
	gVector3 operator%(const gVector3& v2);

	/// Prints the vector to a stream in a nice format
	friend ostream &operator<<(ostream &stream, gVector3 v);

	
};

#endif