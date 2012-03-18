/*******************|
|*** animator.h ****|
|*******************/

#pragma once
#include "Graph.h"
#include "myGLWidget.h"

class Graph;
class MyGLWidget;

class Animator {

public:
		Graph* animated;						// Animated Graph
		Graph* base;
		std::vector<boolean> isKeyFrame;		// Each place is the frame number 1 for keyframe 0 if not
		bool isAnimated;
		Animator(Graph*);
		~Animator(void);
		void animateGraph(int,int);							// Creates frames from Graph

};

