/*********************|
|*** animator.cpp ****|
|**********************/

/* Serves as the viewer class for the GLWidget.
 * Draws the scene graph in the GL window.
 */

#include "animator.h"


Animator::Animator(Graph* _base){
	base = _base;
	animated = new Graph(base->widget);
	animated->constructCharacter();
	isAnimated = false;
}

Animator::~Animator(){

}

void Animator::animateGraph(int numFramesTotal, int numKeyFrames){
	int numAddedFrames = numFramesTotal - numKeyFrames;
	int numPerKey = numAddedFrames/numKeyFrames;
	
	cout << " num Added Frames: " << numAddedFrames <<endl;
	cout << "numPerKey" << numPerKey << endl;
	for (int i = 0; i < numAddedFrames; i+=numPerKey){
		cout<< "Animated at i: " << i << endl;
		animated->batchAdd(i+1, true, animated->getRootNode(), gMatrix3::identity(), numPerKey);		// Insertion Frame
		
	}
	animated->constructTest();
	isAnimated=true;
}