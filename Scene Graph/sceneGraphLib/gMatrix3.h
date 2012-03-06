//Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright and Tiantian Liu
//University of Pennsylvania
 
#ifndef GMATRIX3_H
#define GMATRIX3_H

#include <iostream>
#include <assert.h>
#include "gVector3.h"
#include <math.h>

using namespace std;

class gMatrix3{
private:
	gVector3 data[3];

public:
	///----------------------------------------------------------------------
	/// Constructors
	///----------------------------------------------------------------------
	/// Default Constructor.  Initialize to matrix of all 0s.
	gMatrix3();
	//// Destructor
	~gMatrix3();
	/// Initializes matrix with each vector representing a row in the matrix
	gMatrix3(const gVector3& row1, const gVector3& row2, const gVector3& row3);

	///----------------------------------------------------------------------
	/// Getters
	///----------------------------------------------------------------------	
	/// Returns the values of the row at the index
	gVector3 operator[](unsigned int index) const;
	
	/// Returns a reference to the row at the index
	gVector3& operator[](unsigned int index);
	
	/// Returns a column of the matrix
	gVector3 getColumn(unsigned int index) const;

	///----------------------------------------------------------------------
	/// Matrix Operations
	///----------------------------------------------------------------------	
	/// Returns the transpose of the matrix (v_ij == v_ji)
	gMatrix3 transpose() const;

	///----------------------------------------------------------------------
	/// Static Initializers
	///----------------------------------------------------------------------	
	/// Creates a 3-D rotation matrix.
	/// Takes an angle in degrees and outputs a 3x3 rotation matrix
	static gMatrix3 rotation2D(float angle);
	
	/// Takes an x and y displacement and outputs a 3x3 translation matrix
	static gMatrix3 translation2D(float x, float y);
	
	/// Takes an x and y scale and outputs a 3x3 scale matrix
	static gMatrix3 scale2D(float x, float y);
	
	/// Generates a 3x3 identity matrix
	static gMatrix3 identity();	
	
	//static gMatrix3* identityPoint();


	///----------------------------------------------------------------------
	/// Friend Functions
	///----------------------------------------------------------------------
	/// Checks if m1 == m2
 	bool operator==(const gMatrix3& m2);
	
	/// Checks if m1 != m2
	bool operator!=(const gMatrix3& m2);
	
	/// Matrix addition (m1 + m2)
	gMatrix3 operator+(const gMatrix3& m2);
	
	/// Matrix subtraction (m1 - m2)
	gMatrix3 operator-(const gMatrix3& m2);
	
	/// Scalar multiplication (m * c)
	gMatrix3 operator*(float c);
	
	/// Scalar multiplication (c * m)
	friend gMatrix3 operator*(float c, const gMatrix3& m);
	
	/// Scalar division (m / c)
	gMatrix3 operator/(float c);
	
	/// Matrix multiplication (m1 * m2)
	gMatrix3 operator*(const gMatrix3& m2);
	
	/// Matrix/vector multiplication (m * v)
	/// Assume v is a column vector (ie. a 3x1 matrix)
	gVector3 operator*(const gVector3& v);

	// Return matrix of floats
	
	/// Vector/matrix multiplication (v * m)
	/// Assume v is a row vector (ie. a 1x3 matrix)
	friend gVector3 operator*(const gVector3& v, const gMatrix3& m);

	/// Prints the matrix to a stream in a nice format
	friend ostream &operator<<(ostream &stream, gMatrix3 m);
};

#endif