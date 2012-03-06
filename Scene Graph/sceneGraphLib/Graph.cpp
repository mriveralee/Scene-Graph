// Graph.cpp

#include "Graph.h"
#include <queue>
	

///////////////////////
/**** CONSTRUCTORS ****/
///////////////////////
Graph::Graph(){
	root = NULL;
	clickedFrame = 0;
}

Graph::Graph(Node* _root){
	root = _root;
	clickedFrame = 0;
}

Graph::Graph(MyGLWidget* w){
	root = NULL;
	widget = w;
	clickedFrame = 0;
}


///////////////////////
/**** DESTRUCTOR *****/
///////////////////////
Graph::~Graph(){
// traverse and erase every node and it's children with a queue
	vector<Node*> toBeErased;
	queue<Node*> traversal;
	traversal.push(root);
	// Gets all of the children and sets them up to be erased
	while(!traversal.empty()){
		Node* n = traversal.front();
		toBeErased.push_back(n);
		for each (Node* child in n->getChildrenNodes()){
			traversal.push(child);
		}
		traversal.pop();
	}
	// Now erase all nodes. We set the node = 0, if it's been erases
	// Since Children can have multiple parents/ repeated children
	// And deleting repeatedly may cause heap errors.
	for each (Node* node in toBeErased){
		if (node != 0 || node != NULL){
			delete node;
			node = 0;
		}
	}	
}

//////////////////////////
/**** Traverse Node *****/
//////////////////////////
void Graph::traverse(Node* node, gMatrix3 trans){
	trans = trans*(node->getTransformation());
	for (int i =0; i<node->getChildrenNodes().size(); i++){
		Node* child = node->getChildNode(i);
		if (child->hasGeometry()){
			child->setModel(trans*(child->getTransformation()));
			widget->drawNode(child);
		}
		traverse(child, trans);
	}
}

///////////////////////////
/**** Set ROOT Node ******/
///////////////////////////
void Graph::setNode(Node* n){
	root = n;
}

///////////////////////////
/**** GET ROOT Node ******/
///////////////////////////
Node* Graph::getRootNode(){
	return root;	
}

////////////////////////////////
/****    Construct Test  ******/
////////////////////////////////
void Graph::constructTest(){
	//Test Shapes for Graph
	clickedFrame =0;
	gPolygon* pentagonR = new gPolygon(10, gVector3(0,1,0), 10);
	gPolygon* pentagonL = new gPolygon(10, gVector3(1,1,0), 10);
	gPolygon* squareR = new gPolygon(4, gVector3(0,0,1), 10);
	gPolygon* head = new gPolygon(12, gVector3(.4,.2,.8), 10);
	Node* root = new Node();
	setNode(root);
	Node* cR = new Node();
	Node* cL = new Node();
	root->join(cR);
	Node* c2 = new Node();
	c2->Scale(10,10);
	c2->setGeometry(pentagonR);
	cR->join(c2);
	Node* c3 = new Node();
	c3->Translate(100,100);
	cR->join(c3);
	Node* c4 = new Node();
	c4->setGeometry(squareR);
	c4->Scale(5,2);
	c3->join(c4);
}

/////////////////////////////////////
/*****   Construct Character   *****/
/////////////////////////////////////
void Graph::constructCharacter(){
	glewInit();
	clickedFrame = 0;
	// Begin Making Widget & Character
	Node* body = new Node("Character");
		//body->Translate(-100,-80);
		Node* torso = new Node(new gPolygon(40,gVector3(.6,.8,0.7), 20), "Torso");
			torso->Scale(5.5,5.3); torso->Rotate(22.5); 
			body->join(torso);
			Node* belly = new Node(new gPolygon(40,gVector3(0.6,0.2,0.2), 10), "Belly");
			belly->Scale(1.2,1.2);
			//character->join(body); 
			torso->join(belly);
		// Neck
		Node* neck = new Node(new gPolygon(4, gVector3(.7,.4,.1), 5), "Neck");
			neck->Scale(3.4,3.8); 
			neck->Translate(0,119);	
			neck->Rotate(45);					
			body->join(neck);
			// Head
			Node* head = new Node(new gPolygon(4, gVector3(0.6,0.45,0.5), 20), "Head");	
				//head->Rotate(45); 
				head->Scale(1.2,1.2); 
				head->Translate(12,14);
				neck->join(head);
			// Left Eye
			Node* leftEye = new Node(new gPolygon(100, gVector3(.5,.9,0), 5), "Left Eye");
				leftEye->Translate(-5,5);
				leftEye->Scale(.7,.7);
				head->join(leftEye);
			// Right Eye
			Node* rightEye = new Node(new gPolygon(100, gVector3(.5,.9,0), 5), "Right Eye");
				rightEye->Translate(5,-5);
				rightEye->Scale(.7,.7);
				head->join(rightEye);
			// Mouth
			Node* mouth = new Node(new gPolygon(4, gVector3(1,1,0), 5), "Mouth");
				mouth->Translate(-5,-7);
				mouth->Scale(1,1);
				mouth->Rotate(2);
				head->join(mouth);
		// Right Arm
				
			Node* rightUpperArm = new Node(new gPolygon(5, gVector3(.8,.1,.1), 5), "Right Arm (Upper)");
				rightUpperArm->Scale(9.5,8.2);
				rightUpperArm->Translate(115, 75);
				rightUpperArm->Rotate(-30);
				body->join(rightUpperArm);
				Node* rightLowerArm = new Node(new gPolygon(5, gVector3(.2,.4,.6), 5), "Right Arm (Lower)");
					rightLowerArm->Scale(0.67,1.9);
					rightLowerArm->Translate(1, 10);
					rightLowerArm->Rotate(-205);
					rightUpperArm->join(rightLowerArm);
		// right Leg
			Node* rightUpperLeg = new Node(new gPolygon(6, gVector3(.7,.4,.5), 4.5), "Right Leg (Upper)");
				rightUpperLeg->Scale(11.5,11.5);
				rightUpperLeg->Translate(84, -110);
				rightUpperLeg->Rotate(265);
				body->join(rightUpperLeg);
				Node* rightLowerLeg = new Node(new gPolygon(3, gVector3(.6,.3,.2), 4.5), "Right Leg (Lower)");
					rightLowerLeg->Scale(1.2,1);
					rightLowerLeg->Translate(5, 0);
					rightLowerLeg->Rotate(484);
					rightUpperLeg->join(rightLowerLeg);
					Node* rightFoot = new Node(new gPolygon(6, gVector3(.1,.3,.45), 3.6), "Right Foot");
						rightFoot->Scale(.8,1);
						rightFoot->Translate(-3, -2);
						rightFoot->Rotate(-434);
						rightLowerLeg->join(rightFoot);	
		// Left Arm
			Node* leftUpperArm = new Node(new gPolygon(5, gVector3(.8,.1,.1), 5), "Left Arm (Upper)");
				leftUpperArm->Scale(9.5,8.2);
				leftUpperArm->Translate(-115, 75);
				leftUpperArm->Rotate(0);
				body->join(leftUpperArm);
				Node* leftLowerArm = new Node(new gPolygon(5, gVector3(.2,.4,.6), 5), "Left Arm (Lower)");
					leftLowerArm->Scale(0.67,1.9);
					leftLowerArm->Translate(-1, 10);
					leftLowerArm->Rotate(300);
					leftUpperArm->join(leftLowerArm);							
		// left Leg
			Node* leftUpperLeg = new Node(new gPolygon(6, gVector3(.7,.4,.5), 4.5), "Left Leg (Upper)");
				leftUpperLeg->Scale(11.5,11.5);
				leftUpperLeg->Translate(-84, -110);
				leftUpperLeg->Rotate(265);
				body->join(leftUpperLeg);
				Node* leftLowerLeg = new Node(new gPolygon(3, gVector3(.6,.3,.2), 4.5), "Left Leg (Lower)");
					leftLowerLeg->Scale(1.2,1);
					leftLowerLeg->Translate(5, 0);
					leftLowerLeg->Rotate(494);
					leftUpperLeg->join(leftLowerLeg);
				Node* leftFoot = new Node(new gPolygon(6, gVector3(.1,.3,.45), 3.6), "Left Foot");
						leftFoot->Scale(.8,1);
						leftFoot->Translate(-3, -2);
						leftFoot->Rotate(-434);
						leftLowerLeg->join(leftFoot);
	this->setNode(body);	 // Add the character node to the graph
}

////////////////////////////////
/**** Traverse Frame Node *****/
////////////////////////////////
void Graph::traverseFrame(int selectedFrame, Node* node, gMatrix3 trans){
	//clickedFrame =0;
	//node->setFrame(clickedFrame);
	node->framePlace = selectedFrame;
	node->loadFrame(selectedFrame);
	
	trans = trans*(node->getFrameTransformation(selectedFrame));
	//cout<<"TRAVERSE FRAME  - TRANS \n" << trans << endl;
	for (int i =0; i<node->getChildrenNodes().size(); i++){
		Node* child = node->getChildNode(i);
		if (child->hasGeometry()){
			child->setModel(trans*(child->getFrameTransformation(selectedFrame)));
			widget->drawNode(child);
		}
		traverseFrame(selectedFrame, child, trans);
	}
}

/////////////////////////////////
/** Add a Frame to every node **/
/////////////////////////////////
void Graph::addFrame(int addPlace, bool insertion, Node* node, gMatrix3 trans){
	node->framePlace = addPlace;
	if (insertion){ node->insertFrame(addPlace);
		//cout<<"INSERTION" << endl;
	}
	else {node->createFrame(addPlace);
		//cout<<"standard add" << endl;
	}
	for (int i =0; i<node->getChildrenNodes().size(); i++){
		Node* child = node->getChildNode(i);
		addFrame(addPlace, insertion, child, trans);
	}
	//cout<< "added Frame in Graph" << endl;
}

/////////////////////////////////
/* REMOVE FRAME from all Nodes */
/////////////////////////////////
void Graph::removeFrame(int place, Node* node, gMatrix3 trans){
	if(place>=0){
		cout<<"GRAPH REMOVED FRAME: " << place<<endl;
		node->removeFrame(place);
		for (int i =0; i<node->getChildrenNodes().size(); i++){
			Node* child = node->getChildNode(i);
			removeFrame(place, child, trans);
		}
	}
}

/////////////////////////////////
/***** Set Clicked Frame  ******/
/////////////////////////////////
void Graph::setClickedFrame(int place){
	clickedFrame = place;
}