/*****************|
|**** Node.h *****|
|*****************/

#pragma once

#include <vector>
#include "glew.h"
#include "gMatrix3.h"
#include "gPolygon.h"
#include <string>
#include <QTreeWidgetItem>
#include <QtGui>
#include <qstring.h>


class Node	: public QObject,  public QTreeWidgetItem {
	Q_OBJECT;
private:
	std::vector<Node*> children;				// Pointers to Children Nodes
	std::vector<Node*> parents;					// Pointers Parent Nodes
	std::vector<gMatrix3> scaleFrames;			// Xcale frame matrices holder
	std::vector<gMatrix3> translateFrames;		// Translate frame matrices holder
	std::vector<float> rotateFrames;			// Rotate frame matrices matrices holder
	std::vector<gMatrix3> transformationFrames; // Transformation frame matrices holder
	gPolygon* polygon;							// Shape that this Node links to-> if it does
	gMatrix3 transformation;					// Transformation Matrix-> Product of Scale, Translation, Rotation Matrices
	gMatrix3 scale;								// Sclae Matrix
	gMatrix3 translation;						// Translation Matrix
	gMatrix3 rotation;							// Rotation Matrix
	gMatrix3 model;								// model Matrix for paintGL	
	string name;								// Tree widget name
	bool hasPolygon;							// True if this Node has a shape
	
public:
	Node(void);
	Node(string);
	Node(gPolygon*, string);
	~Node(void);
	void addChildNode(Node*);					// Add a Child to the list of children
	void addParentNode(Node*);					// Add a parent to this node
	void removeParentNode(Node*);				// Remove a parent
	gPolygon* getPolygon(void);					// Get the polygon, if it haas one
	Node* getChildNode(int);					// Get a Child at Index
	void removeChildNode(Node*);				// remove a child
	void addChildrenNodes(std::vector<Node*>);	// Add a vector of Children Nodes
	std::vector<Node*> getChildrenNodes(void);	// Return all of the Children Nodes
	std::vector<Node*> getParentNodes(void);	// Return all of the Parent Nodes
	gMatrix3 getTransformation(void);			// Get the transformation matrix
	bool hasGeometry(void);						// Returns true if this node has a polygon
	void setModel(gMatrix3);					// Set the model matrix for paint gl
	void setGeometry(gPolygon*);				// Set the polygon
	void ScaleX(float);							// Change Scale factor for x	
	void ScaleY(float);							// Change Scale factor for y
	void Scale(float, float);					// Change Scale factor for x & y
	void TranslateX(float);						// Change Translate factor for x
	void TranslateY(float);						// Change Translate factor for y
	void Translate(float,float);				// Change Translate factor for x & y
	void Rotate(float);							// Change the rotation angle
	gMatrix3 getRotation(void);					// gets the currently 'loaded' rotation matrix (used for setting values in control boxes)
	gMatrix3 getScale(void);					// gets the currently 'loaded' rotation matrix (used for setting values in control boxes)
	gMatrix3 getTranslation(void);				// gets the currently 'loaded' rotation matrix (used for setting values in control boxes)
	gMatrix3 getModel(void);					// Get model matrix for paintGL
	void setName(string);						// Sets the name of this Widget
	QString getName(void);							// Returns the name of this node
	float rotateValue;							
	void join(Node*);							// Joins two nodes, parent(caller) and child input
	void joinMultiple(vector<Node*>);			// Joins a bunch of children to a parent

	int framePlace;								// The Current Frame selected in the Node
	void setFrame(int);							// Sets current frame number
	void updateFrame(int);						// Set the current Frame
	gMatrix3 getFrameRotate(int);				// Return the Rotation matrix at the framePlace
	gMatrix3 getFrameScale(int);				// Return the Scale matrix at the framePlace
	gMatrix3 getFrameTranslate(int);			// Return the Translation matrix at the framePlace
	gMatrix3 getFrameTransformation(int);		// Return the Transformation matrix at the framePlace
	void createFrame(int);						// Create a new frame by adding additional transformation matricies to each frame vector
	void insertFrame(int);						// Insert a frame between two
	void loadFrame(int);						// Load the matricies for a frame
	void initializeFrames(int);					// for creation of a new node  with matrices
	void removeFrame(int);						// remove frame at location, framePlace, in vectors
	void clone(int);
	
	void BatchInsertFrame(int, int);
	void BatchCreateFrame(int, int);


	std::vector<gMatrix3> scaleAnimated;			// Xcale frame matrices holder
	std::vector<gMatrix3> translateAnimated;		// Translate frame matrices holder
	std::vector<float> rotateAnimated;					// Rotate frame matrices matrices holder
	std::vector<gMatrix3> transformationAnimated;
	std::vector<bool> keyFrameAnimated;
	bool isKeyFrame;
	void makeKeyFrame(int);
	
	// IMPLEMENT THIS 
	int animatedPlace;
	gMatrix3 animatedModel;
	void loadAnimatedFrame(int);
	void setAnimatedModel(gMatrix3);
	void BatchCreateAnimated(int,int);
	void BatchInsertAnimated(int,int);
	void createAnimatedFrame(int);
	void updateAnimatedFrame(int);
	gMatrix3 getAnimatedTransformation(int);
	void traverseAnimated(int);
	void copyKeyFrames();
	void eraseAnimation();
	void createAnimatedFirst(int);

	
};
