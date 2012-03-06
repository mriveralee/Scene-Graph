/* Michael Rivera
 * CIS 277 - HW #1 
 * PennKey - rimic
 * 'gMatrix3.cpp' - 3x3 Matrix of 3D vectors
 */


#include "gMatrix3.h"
#define PI 3.14159265



///----------------------------------------------------------------------
/// Constructors
///----------------------------------------------------------------------

// Base Constructor
gMatrix3::gMatrix3(){
	data[0] = gVector3(0,0,0);
	data[1] = gVector3(0,0,0);
	data[2] = gVector3(0,0,0);
}

// Vector Constructor
gMatrix3::gMatrix3(const gVector3& row0, const gVector3& row1, const gVector3& row2){
	data[0] = row0;
	data[1] = row1;
	data[2] = row2;
}


gMatrix3::~gMatrix3(){
}


// Print Function
ostream& operator<<(ostream &stream, gMatrix3 m){
	return stream << m.data[0] << "\n" << m.data[1] << "\n" << m.data[2] << "\n";
}


///----------------------------------------------------------------------
/// Functions
///----------------------------------------------------------------------

/// Returns the values of the row at the index
gVector3 gMatrix3::operator[](unsigned int index) const{
	assert(index >= 0 && index <= 2);
	return data[index];
}
	
/// Returns a reference to the row at the index
gVector3& gMatrix3::operator[](unsigned int index){
	assert(index >= 0 && index <= 2);
	return *(data+index);
}
	
/// Returns a column of the matrix
gVector3 gMatrix3::getColumn(unsigned int index) const{
	assert(index >= 0 && index <= 2);
	float col0 = data[0][index];
	float col1 = data[1][index];
	float col2 = data[2][index];
	return gVector3(col0, col1, col2);
}
 

// Matrix Equality Comparison 
bool gMatrix3::operator==(const gMatrix3& m2){
	bool row0 = (data[0] == m2.data[0]);
	bool row1 = (data[1] == m2.data[1]);
	bool row2 = (data[2] == m2.data[2]);
	return (row0 && row1 && row2);
}

// Matrix Inequality Comparison
bool gMatrix3::operator!=(const gMatrix3& m2){
	bool row0 = (data[0] == m2.data[0]);
	bool row1 = (data[1] == m2.data[1]);
	bool row2 = (data[2] == m2.data[2]);
	return !(row0 && row1 && row2);
}

// Return Transpose of a matrix (m^T)
gMatrix3 gMatrix3::transpose() const{
	gVector3 a(data[0][0], data[1][0], data[2][0]);
	gVector3 b(data[0][1], data[1][1], data[2][1]);
	gVector3 c(data[0][2], data[1][2], data[2][2]);
	return gMatrix3(a,b,c);
}

// Matrix Addition (m1 + m2)
gMatrix3 gMatrix3::operator+(const gMatrix3& m2){
	gVector3 row0((data[0][0] + m2.data[0][0]), (data[0][1] + m2.data[0][1]),(data[0][2] + m2.data[0][2]));	
	gVector3 row1((data[1][0] + m2.data[1][0]), (data[1][1] + m2.data[1][1]),(data[1][2] + m2.data[1][2]));	
	gVector3 row2((data[2][0] + m2.data[2][0]), (data[2][1] + m2.data[2][1]),(data[2][2] + m2.data[2][2]));	
	return gMatrix3(row0, row1, row2);
}


// Matrix Subtraction (m1 - m2)
gMatrix3 gMatrix3::operator-(const gMatrix3& m2){
	gVector3 row0((data[0][0] - m2.data[0][0]), (data[0][1] - m2.data[0][1]),(data[0][2] - m2.data[0][2]));	
	gVector3 row1((data[1][0] - m2.data[1][0]), (data[1][1] - m2.data[1][1]),(data[1][2] - m2.data[1][2]));	
	gVector3 row2((data[2][0] - m2.data[2][0]), (data[2][1] - m2.data[2][1]),(data[2][2] - m2.data[2][2]));	
	return gMatrix3(row0, row1, row2);
}

// Matrix Scalar Multiplication (m*c)
gMatrix3 gMatrix3::operator*(float c){
	gVector3 row0(data[0][0]*c, data[0][1]*c, data[0][2]*c);
	gVector3 row1(data[1][0]*c, data[1][1]*c, data[1][2]*c);
	gVector3 row2(data[2][0]*c, data[2][1]*c, data[2][2]*c);
	return gMatrix3(row0, row1, row2);
}

// Matrix Scalar Multiplication (c*m)
gMatrix3 operator*(float c, const gMatrix3& m){
	gVector3 row0 = m[0]*c;
	gVector3 row1 = m[1]*c;
	gVector3 row2 = m[2]*c;
	return gMatrix3(row0, row1, row2);
}

// Matrix Scalar Division (m/c)
gMatrix3 gMatrix3::operator/(float c){
	return (gMatrix3(data[0], data[1], data[2])*(1/c));
}

// Matrix Multiplication (m1 * m2)
gMatrix3 gMatrix3::operator*(const gMatrix3& m1){
	gVector3 row0(data[0]*m1.getColumn(0),data[0]*m1.getColumn(1), data[0]*m1.getColumn(2));
	gVector3 row1(data[1]*m1.getColumn(0),data[1]*m1.getColumn(1), data[1]*m1.getColumn(2));
	gVector3 row2(data[2]*m1.getColumn(0),data[2]*m1.getColumn(1), data[2]*m1.getColumn(2));
	return gMatrix3(row0, row1, row2);
}

// Matrix/Vector Multiplication (m*v)
// v is a col-vector (3x1 matrix)

gVector3 gMatrix3::operator*(const gVector3& v){
	float el1 = v[0]*data[0][0] + v[1]*data[0][1] + v[2]*data[0][2];
	float el2 = v[0]*data[1][0] + v[1]*data[1][1] + v[2]*data[1][2];
	float el3 = v[0]*data[2][0] + v[1]*data[2][1] + v[2]*data[2][2];
	return gVector3(el1, el2, el3);
}


// Matrix/Vector Multiplication (v*m)
// v is a row-vector (1x3 matrix)
gVector3 operator*(const gVector3& v, const gMatrix3& m){
	float el1 = v[0]*m[0][0] + v[1]*m[1][0] + v[2]*m[2][0];
	float el2 = v[0]*m[0][1] + v[1]*m[1][1] + v[2]*m[2][1];
	float el3 = v[0]*m[0][2] + v[1]*m[1][2] + v[2]*m[2][2];
	return gVector3(el1, el2, el3);
}

/* Static Initializer Functions */


// Scale Matrix
gMatrix3 gMatrix3::scale2D(float x, float y){
	gVector3 row0(x,0,0);
	gVector3 row1(0,y,0);
	gVector3 row2(0,0,1);
	return gMatrix3(row0,row1,row2);
}
// Translation Matrix
gMatrix3 gMatrix3::translation2D(float x, float y){
	gVector3 row0(1,0,x);
	gVector3 row1(0,1,y);
	gVector3 row2(0,0,1);
	return gMatrix3(row0, row1, row2);
}

// Rotation Matrix
gMatrix3 gMatrix3::rotation2D(float angle){
	float rad = angle*PI/180;
	gVector3 row0(cos(rad), -sin(rad), 0);
	gVector3 row1(sin(rad), cos(rad), 0);
	gVector3 row2(0,0,1);
	return gMatrix3(row0, row1, row2);

}

// Identity Matrix
gMatrix3 gMatrix3::identity(){
	gVector3 row0(1,0,0), row1(0,1,0), row2(0,0,1);
	return gMatrix3(row0, row1, row2);
}

/*gMatrix3* gMatrix3::identityPoint(){
	gMatrix3* hold = new gMatrix3();
	hold = &gMatrix3::identity();
}
*/