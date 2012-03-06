/*****************|
|*** Graph.h *****|
|*****************/

#pragma once

#include "Node.h"
#include "gMatrix3.h"
#include "glew.h"
#include "myglwidget.h"

class MyGLWidget;								// For dependencies in linking

class Graph{
private:
	Node* root;									// Root node of the graph
	int clickedFrame;							// The currently selected frame in the KeyFrame Animation Editor
public:
	MyGLWidget* widget;							// Widget to which this Scene graph can be drawn
	Graph();									// Constructor with no root node
	Graph(Node*);								// Constructor with Root Node
	Graph(MyGLWidget*);							// Constructor with pointer to a widget
	~Graph();									// Destructor
	void traverse(Node*, gMatrix3);				// Traverse every node in a SG and draw it applying Transformations
	void setNode(Node*);						// Set the root node to be
	Node* getRootNode();						// Get the root node
	void constructTest();						// Make graph of test shapes
	void constructCharacter();					// Make a graph with the puppet/character
	void traverseFrame(int,Node*, gMatrix3);	// Traverse every node in the graph at a particular framePlace (int) and draw the applied Transformations
	void addFrame(int, bool, Node*, gMatrix3);	// Traverse all nodes and add a frame at a framePlace
	void removeFrame(int, Node*, gMatrix3);		// Traverse all nodes and remove frame at a framePlace
	void setClickedFrame(int);					// set the frame to be drawn
};