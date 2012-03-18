/*****************|
|*** Node.cpp ****|
|*****************/

#include "Node.h"	
#include <QString>


/* Sub-class of QTreeWidgetItem and serves as a 'node' in the scene graph.
 * Each node can hold multiple scale, translation, and rotation matricies,
 * a single shape, and have multiple children or parents. 
 */	

////////////////////////////////////////////////////
/******************* CONSTRUCTORS *****************/
////////////////////////////////////////////////////
Node::Node() : QTreeWidgetItem(1001) {
	this->setText(0,QString::fromStdString("No Name Assigned"));
	polygon = NULL;
	children = vector<Node*>();
	transformation = gMatrix3::identity();
	scale =  gMatrix3::scale2D(1,1);
	translation =   gMatrix3::translation2D(0,0);
	rotation = gMatrix3::identity();
	model = gMatrix3::identity();
	hasPolygon = false;
	rotateValue = 0;
	framePlace =0;
	// Added for Frames
	translateFrames.push_back(translation);
	rotateFrames.push_back(0);
	scaleFrames.push_back(scale);
	transformationFrames.push_back(getTransformation());
	//
}

/////////////////////////////////////////////////
/***** Constructor for Root Node (Just Name)****/
/////////////////////////////////////////////////
Node::Node(string _name) : QTreeWidgetItem(1001) {
	this->setText(0,QString::fromStdString(_name));				// Super class is a QTreeWidget Item
	polygon = NULL;												// gPolygon
	name = _name;												// Name of Node
	rotateValue = 0;
	children = vector<Node*>();									// Vector of Children Nodes				
	transformation = gMatrix3::identity();						// Initial Transformation
	scale =  gMatrix3::identity();								// Initial Scale
	translation =   gMatrix3::identity();						// Initial Translation
	rotation = gMatrix3::identity();							// Initial Rotation
	model = gMatrix3::identity();								// Initial Model
	hasPolygon = false;											// true if this node has gPolygon				
	setText(0,QString::fromStdString(name));					// Set the Name in the TreeWidget
	//////// After Key Frame Addition
	translateFrames.push_back(translation);
	rotateFrames.push_back(0);
	scaleFrames.push_back(scale);
	transformationFrames.push_back(getTransformation());
	updateFrame(0);
	framePlace =0;
}

////////////////////////////////////////////////////
/****    Constructor for Node With Shape	*******/
////////////////////////////////////////////////////
Node::Node(gPolygon* _polygon, string _name) : QTreeWidgetItem(1001) {
	this->setText(0,QString::fromStdString(_name));
	polygon = _polygon;
	name = _name;
	children = vector<Node*>();
	gMatrix3 identity = gMatrix3::identity();
	transformation = gMatrix3::identity();
	scale =  gMatrix3::identity();
	translation =   gMatrix3::identity();
	rotation = gMatrix3::identity();

	translateFrames.push_back(translation);
	rotateFrames.push_back(0);
	scaleFrames.push_back(scale);
	model = gMatrix3::identity();
	hasPolygon = true;
	rotateValue = 0;
	framePlace =0;
	transformationFrames.push_back(getTransformation());
	
}

//////////////////////////
/***** DESTRUCTOR ******/
//////////////////////////
Node::~Node(){
	if (hasPolygon)
		delete polygon;
	for each (Node* child in children){
		if (child->getParentNodes().size() <= 1){
			if(child != 0 && child != NULL){
				delete child;
				child = 0;
			}
		}
	}
}

//////////////////////////
/****** ADD CHILD NODE *******/
//////////////////////////
void Node::addChildNode(Node* child){
	children.push_back(child);				// Add to our children vector
	insertChild(0,child);						// Add to the tree widget child
	//cout<< "NEW PARENT ASSIGNED:" <<this->getName().toStdString()<< "IN ADD CHILD NODE: " << child->getName().toStdString()<< endl;
}
//////////////////////////////////////
/****** ADD CHILDREN AS VECTOR ******/
//////////////////////////////////////
void Node::addChildrenNodes(std::vector<Node*> adding){
	for each (Node* child in adding){
		addChildNode(child);
		//cout<< "Parent: " << this->getName().toStdString() << "with Child: " << adding[i]->getName().toStdString()<<endl;
	}
}
//////////////////////////
/****** ADD PARENT *******/
//////////////////////////
void Node::addParentNode(Node* parent){
	parents.push_back(parent);
	//cout<< "ADDED PARENT NODE: " << parent->getName().toStdString() << endl; 
	//cout << "-->With Child Node: " << this->getName().toStdString()<<endl;
	parent->addChild(this);			
	//for each (Node* n in parents){
	//	n->addChild(this);
	//}
}



/////////////////////////////
/*********** JOIN **********/
/////////////////////////////
/* Parent is the caller & input in the child. 
 * Performs the addChildNode & AddParent Simultaneously.
 */
void Node::join(Node* child){
	this->addChildNode(child);
	child->addParentNode(this);			
	//this->addChild(child);
	//child->addParent
}
///////////////////////////////////
/********** JOIN MULTIPLE ********/
///////////////////////////////////
void Node::joinMultiple(vector<Node*> newChildren){
	for each (Node* child in newChildren){
		this->join(child);
	}
}

//////////////////////////
/**** REMOVE PARENT *****/
//////////////////////////
void Node::removeParentNode(Node* node){
	int position = 0;
	for(int i =0; i < parents.size() ; i++){
		if (parents[i] == node){
			parents[i]->removeChildNode(this);
			parents.erase(parents.begin()+i);
			i--;
		}
	}
}

//////////////////////////
/**** REMOVE CHILD ******/
//////////////////////////
void Node::removeChildNode(Node* removed){
	vector<Node*> childrenOfRemoved = removed->getChildrenNodes();	
	joinMultiple(childrenOfRemoved);
	int i = 0;
	for each (Node* child in children){
		if (child == removed){
			children.erase(children.begin()+i);									// Remove from this parent's child listing
			i--;
			break;
		}
		i++;
	}
	
	removeChild(removed);														// Remove from TreeWidgetItem
	//cout << "ADDED NODE OF CHILD: " << childrenOfRemoved[j]->getName().toStdString() << endl;
}


/////////////////////////////
/****** Get Geometry *******/
/////////////////////////////
gPolygon* Node::getPolygon(){
	return polygon;
}
//////////////////////////
/****** Get Child *******/
//////////////////////////
Node* Node::getChildNode(int index){
	return children[index];

}
/////////////////////////////
/****** Get T-Matrix *******/
/////////////////////////////
gMatrix3 Node::getTransformation(){
	transformation = translation*(scale*rotation);
	return transformation;
}


/////////////////////////////
/****** Get Scale    *******/
/////////////////////////////
gMatrix3 Node::getScale(){
	return scale;
}
/////////////////////////////
/****** Get Translation *******/
/////////////////////////////
gMatrix3 Node::getTranslation(){
	return translation;
}
/////////////////////////////
/****** Get Rotation *******/
/////////////////////////////
gMatrix3 Node::getRotation(){
	return rotation;
}


/////////////////////////////
/****** Get Model *******/
/////////////////////////////
gMatrix3 Node::getModel(){
	return model;
}

/////////////////////////////////
/****** Get All Children *******/
/////////////////////////////////
std::vector<Node*> Node::getChildrenNodes(){ 
	return children;
}

/////////////////////////////
/****** Has Geometry *******/
/////////////////////////////
bool Node::hasGeometry(){
	return hasPolygon;
}

///////////////////////////////////
/****** Set Model Matrix *********/
///////////////////////////////////
void Node::setModel(gMatrix3 _model){
	model = _model;
}


/////////////////////////////
/****** Set Geometry *******/
/////////////////////////////
void Node::setGeometry(gPolygon* _polygon){
		polygon = _polygon;
		hasPolygon = true;
}


/////////////////////////////
/********* Scale X *********/
/////////////////////////////
void  Node::ScaleX(float x){
	float y = scale[1][1];
	scale = gMatrix3::scale2D(x,y);
	updateFrame(framePlace);
}


/////////////////////////////
/********* Scale Y *********/
/////////////////////////////
void  Node::ScaleY(float y){
	float x = scale[0][0];
	scale = gMatrix3::scale2D(x,y);
	updateFrame(framePlace);
}
	

/////////////////////////////////
/********* Scale BOTH  *********/
/////////////////////////////////
void  Node::Scale(float x, float y){
	scale = gMatrix3::scale2D(x,y);
	updateFrame(framePlace);
		
}
	
//////////////////////////////////
/********* Translate X *********/
/////////////////////////////////
void  Node::TranslateX(float x){
	float y = translation[1][2];
	translation = gMatrix3::translation2D(x,y);
	updateFrame(framePlace);
}

//////////////////////////////////
/********* Translate Y *********/
/////////////////////////////////
void  Node::TranslateY(float y){
	float x = translation[0][2];
	translation = gMatrix3::translation2D(x,y);
	updateFrame(framePlace);
}

///////////////////////////////////
/********* Translate BOTH ********/
///////////////////////////////////
void  Node::Translate(float  x,float  y){
	translation = gMatrix3::translation2D(x,y);
	updateFrame(framePlace);
}

//////////////////////////////////
/********* Rotate ***************/
//////////////////////////////////
void  Node::Rotate(float angle){
	this->rotateValue = angle;
	rotation = gMatrix3::rotation2D(angle);
	updateFrame(framePlace);
}

//////////////////////////////////
/********* Set Name *************/
//////////////////////////////////
void Node::setName(string _name){
	name = _name;
	setText(0,QString::fromStdString(_name));
}

//////////////////////////////////
/********* Get Name *************/
//////////////////////////////////
QString Node::getName(){
	return this->text(0);
}


////////////////////////////////////
/***********Get Parent Nodes ******/
////////////////////////////////////
std::vector<Node*> Node::getParentNodes(){
	return this->parents;
}


////////////////////////////////////
/*********** Update Frame *********/
////////////////////////////////////
void Node::updateFrame(int place){
	translateFrames[place] = translation;
	scaleFrames[place] = scale;
	rotateFrames[place] = rotateValue;
	transformationFrames[place] = getTransformation();
}


////////////////////////////////////
/*********** Load Frame  **********/
////////////////////////////////////
void Node::loadFrame(int place){
	translation = translateFrames[place];
	scale =	scaleFrames[place];
	rotation =	gMatrix3::rotation2D(rotateFrames[place]);
	rotateValue = rotateFrames[place];
}

////////////////////////////////////
/*******  Create New Frame  *******/
////////////////////////////////////
void Node::createFrame(int place){
	int previous = place-1;
	//if (previous == 0) previous = 1;
	updateFrame(previous);
	vector<gMatrix3>::iterator iT = translateFrames.begin();
	vector<gMatrix3>::iterator iS = scaleFrames.begin();
	vector<float>::iterator iR = rotateFrames.begin();
	vector<gMatrix3>::iterator iTrans = transformationFrames.begin();
	scaleFrames.insert(iS+place, scale);
	translateFrames.insert(iT+place,translation);
	rotateFrames.insert(iR+place, rotateValue);
	transformationFrames.insert(iTrans+place, getTransformation());
	loadFrame(place);
	//cout<< "CREATE FRAME AT PLACE: " << place << endl;
}

////////////////////////////////////
/*** Insert Interpolation Frame ***/
////////////////////////////////////
void Node::insertFrame(int place){
	//cout<<"BEFORE: " << place-1<< "MID: " << place << "AFTER: "<< place+1<< endl;
	loadFrame(place-1);	
	if ( place > 0 && place < translateFrames.size()){
		gMatrix3 t =  translateFrames[place-1] + translateFrames[place];
		gMatrix3 s = scaleFrames[place-1] + scaleFrames[place];
		float r = rotateFrames[place-1] + rotateFrames[place];
		t = t/2;
		s = s/2;
		r = r/2;
		translation = t;
		scale = s;
		rotateValue = r;
	}
	vector<gMatrix3>::iterator iT = translateFrames.begin();
	vector<gMatrix3>::iterator iS = scaleFrames.begin();
	vector<float>::iterator iR = rotateFrames.begin();
	vector<gMatrix3>::iterator iTrans = transformationFrames.begin();
	///Iterate to in
	scaleFrames.insert(iS+place, scale);
	translateFrames.insert(iT+place,translation);
	rotateFrames.insert(iR+place, rotateValue);
	transformationFrames.insert(iTrans+place, getTransformation());
	//updateFrame(place);
	loadFrame(place);
}




////////////////////////////////////
/******** Get Rotate Frame ********/
////////////////////////////////////
gMatrix3 Node::getFrameRotate(int place){
	if(place >= 0)
		return gMatrix3::rotation2D(rotateFrames[place]);
	else
		return rotation;
}

// Get Scale Frame
gMatrix3 Node::getFrameScale(int place){
	if(place >= 0)
		return scaleFrames[place];
	else 
		return scale;
}

////////////////////////////////////
/****** Get Translate Frame  ******/
////////////////////////////////////
gMatrix3 Node::getFrameTranslate(int place){
	if(place >= 0)
		return translateFrames[place];
	else 
		return translation;
}

////////////////////////////////////
/**** Get Frame Transformation*****/
////////////////////////////////////
gMatrix3 Node::getFrameTransformation(int place){
	//sgMatrix3 trans = translation*(scale*rotation);
	return translateFrames[place]*(scaleFrames[place]*gMatrix3::rotation2D(rotateFrames[place]));

}


////////////////////////////////////////
/* initialize the frames of new Node  */
////////////////////////////////////////
void Node::initializeFrames(int places){
	int start = 1;
	while (start <= places){
		createFrame(start);
		start++;
	//	cout << "START: "<< start << endl;
	}
}

////////////////////////////////////
/********** REMOVE FRAME **********/
////////////////////////////////////
void Node::removeFrame(int place){
	if (place >0 ){
		vector<gMatrix3>::iterator iT = translateFrames.begin();
		vector<gMatrix3>::iterator iS = scaleFrames.begin();
		vector<float>::iterator iR = rotateFrames.begin();
		vector<gMatrix3>::iterator iTrans = transformationFrames.begin();
		scaleFrames.erase(iS+place);
		translateFrames.erase(iT+place);
		rotateFrames.erase(iR+place);
		transformationFrames.erase(iTrans+place);
		//updateFrame(place-1);
		//loadFrame(place-1);
		//cout << "REMOVED" << endl;
	}
}

////////////////////////////////////
/*********** CLONE FRAME **********/
////////////////////////////////////
void Node::clone(int signal){
	if (translateFrames.size() >=2){
			updateFrame(1);
			vector<gMatrix3>::iterator iT = translateFrames.begin();
			vector<gMatrix3>::iterator iS = scaleFrames.begin();
			vector<float>::iterator iR = rotateFrames.begin();
			vector<gMatrix3>::iterator iTrans = transformationFrames.begin();
		if (signal == 0) {							// clone first
		///Iterate to in
			scaleFrames.insert(iS+1, scaleFrames[1]);
			translateFrames.insert(iT+1, translateFrames[1]);
			rotateFrames.insert(iR+1, rotateFrames[1]);
			transformationFrames.insert(iTrans+1, transformationFrames[1]*(scaleFrames[1]*rotateFrames[1]));
			updateFrame(1);
			loadFrame(1);
		}
		else if (signal == 1) {						// clone last
			int last = translateFrames.size()-1;
			updateFrame(last);
			scaleFrames.push_back(scaleFrames[last]);
			translateFrames.push_back(translateFrames[last]);
			rotateFrames.push_back(rotateFrames[last]);
			transformationFrames.push_back(transformationFrames[last]*(scaleFrames[last]*rotateFrames[last]));
			updateFrame(last);
			loadFrame(last);

		}
	}

}


////////////////////////////////
/***** Set Frame Place ********/
////////////////////////////////
void Node::setFrame(int place){
	framePlace = place;
}



////////////////////////////////
/***** Batch Insert Frame *****/
////////////////////////////////
void Node::BatchInsertFrame(int place, int numFrames){
	//cout<<"BEFORE: " << place-1<< "MID: " << place << "AFTER: "<< place+1<< endl;
	
	
	loadFrame(place-1);	
	if ( place > 0 && place < translateFrames.size()){
		gMatrix3 dT =  translateFrames[place] - translateFrames[place-1] ;
		gMatrix3 dS = scaleFrames[place] - scaleFrames[place-1];
		float dR =  rotateFrames[place] - rotateFrames[place-1];
		dT = dT/(numFrames+1);
		dS = dS/(numFrames+1);
		dR = dR/(numFrames+1);

		for (int i = numFrames+1; i>= 1; i--){
			int mult = i;														// first place is 2*i/numframes
			gMatrix3 t = (mult*dT)+ translateFrames[place-1];	 // +;
			gMatrix3 s = (mult*dS) + scaleFrames[place-1];
			float r = (mult*dR) + rotateFrames[place-1];
			
			translation = t;
			scale = s;
			rotateValue = r;

			vector<gMatrix3>::iterator iT = translateFrames.begin();
			vector<gMatrix3>::iterator iS = scaleFrames.begin();
			vector<float>::iterator iR = rotateFrames.begin();
			vector<gMatrix3>::iterator iTrans = transformationFrames.begin();
			
			scaleFrames.insert(iS+place, scale);
			translateFrames.insert(iT+place,translation);
			rotateFrames.insert(iR+place, rotateValue);
			transformationFrames.insert(iTrans+place+1, getTransformation());
		}
	loadFrame(place-1);
	}
}


/////////////////////////////////////////////
/************ Batch Create Frame  **********/
/////////////////////////////////////////////
void Node::BatchCreateFrame(int place, int numFrames){
	for (int i = 1; i <=numFrames; i++){
		createFrame(place);
	}
}

/////////////////////////////////////////////
/////////// ANIMATION FUNCTIONS /////////////
/////////////////////////////////////////////

/////////////////////////////////////////////
/*********** Load Animated Frame  **********/
/////////////////////////////////////////////
void Node::loadAnimatedFrame(int place){
	translation = translateAnimated[place];
	scale =	scaleAnimated[place];
	rotation =	gMatrix3::rotation2D(rotateAnimated[place]);
	rotateValue = rotateAnimated[place];
}
///////////////////////////////////////////
/*********** Set Animate Model  **********/
///////////////////////////////////////////
void Node::setAnimatedModel(gMatrix3 _model){
	animatedModel = _model;
}
///////////////////////////////////////
/**** Get Animated Transformation*****/
///////////////////////////////////////
gMatrix3 Node::getAnimatedTransformation(int place){
	return translateAnimated[place]*(scaleAnimated[place]*gMatrix3::rotation2D(rotateAnimated[place]));
}
/////////////////////////////////////////
/***** Batch Insert Animated Frame *****/
/////////////////////////////////////////
void Node::BatchInsertAnimated(int place, int numFrames){
	//cout<<"BEFORE: " << place-1<< "MID: " << place << "AFTER: "<< place+1<< endl;
	loadAnimatedFrame(place-1);	
	if ( place > 0 && place < translateAnimated.size()){
		gMatrix3 dT =  translateAnimated[place] - translateAnimated[place-1] ;
		gMatrix3 dS = scaleAnimated[place] - scaleAnimated[place-1];
		float dR =  rotateAnimated[place] - rotateAnimated[place-1];
		dT = dT/(numFrames+1);
		dS = dS/(numFrames+1);
		dR = dR/(numFrames+1);
		for (int i = numFrames+1; i>= 1; i--){
			int mult = i;														// first place is 2*i/numframes
			gMatrix3 t = (mult*dT)+ translateAnimated[place-1];	 // +;
			gMatrix3 s = (mult*dS) + scaleAnimated[place-1];
			float r = (mult*dR) + rotateAnimated[place-1];		
			translation = t;
			scale = s;
			rotateValue = r;
			isKeyFrame =0;
			vector<gMatrix3>::iterator iT = translateAnimated.begin();
			vector<gMatrix3>::iterator iS = scaleAnimated.begin();
			vector<float>::iterator iR = rotateAnimated.begin();
			vector<gMatrix3>::iterator iTrans = transformationAnimated.begin();
			vector<bool>::iterator iKeyFrame = keyFrameAnimated.begin();
			
			scaleAnimated.insert(iS+place, scale);
			translateAnimated.insert(iT+place,translation);
			rotateAnimated.insert(iR+place, rotateValue);
			transformationAnimated.insert(iTrans+place+1, getTransformation());
			keyFrameAnimated.insert(iKeyFrame+place, isKeyFrame);
		}
	loadAnimatedFrame(place-1);
	}
}
/////////////////////////////////////////
/***** Batch Create Animated Frame *****/
/////////////////////////////////////////
void Node::BatchCreateAnimated(int place, int numFrames){
	for (int i = 1; i < numFrames; i++){
		createAnimatedFrame(place);
	}
}

/////////////////////////////////////////
/*******  Create Animated Frame  *******/
/////////////////////////////////////////
void Node::createAnimatedFrame(int place){
	int previous = place-1;
	//if (previous == 0) previous = 1;
	//updateAnimatedFrame(previous);
	vector<gMatrix3>::iterator iT = translateAnimated.begin();
	vector<gMatrix3>::iterator iS = scaleAnimated.begin();
	vector<float>::iterator iR = rotateAnimated.begin();
	vector<gMatrix3>::iterator iTrans = transformationAnimated.begin();
	vector<bool>::iterator iKeyFrame = keyFrameAnimated.begin();
	isKeyFrame =0;
	scaleAnimated.insert(iS+place, scaleAnimated[previous]);
	translateAnimated.insert(iT+place,translateAnimated[previous]);
	rotateAnimated.insert(iR+place, rotateAnimated[previous]);
	transformationAnimated.insert(iTrans+place, getAnimatedTransformation(previous));
	keyFrameAnimated.insert(iKeyFrame+place, isKeyFrame);
	//loadAnimatedFrame(place);
	//cout<< "CREATE FRAME AT PLACE: " << place << endl;
}





	void Node::createAnimatedFirst(int numTimes){
		isKeyFrame =0;
		for(int i = 0; i < numTimes; i++){
			scaleAnimated.push_back(scaleAnimated[0]);
			translateAnimated.push_back(translateAnimated[0]);
			rotateAnimated.push_back(rotateAnimated[0]);
			transformationAnimated.push_back(getAnimatedTransformation(0));
			keyFrameAnimated.push_back(0);
		}

	}

//////////////////////////////////////////////////////
/*******  copy Key Frames to Animated Frames  *******/
//////////////////////////////////////////////////////
void Node::copyKeyFrames(){
	for each (gMatrix3 matrix in translateFrames){
		translateAnimated.push_back(matrix);
	}
	for each (gMatrix3 matrix in scaleFrames){
		scaleAnimated.push_back(matrix);
	}
	for each (gMatrix3 matrix in transformationFrames){
		transformationAnimated.push_back(matrix);
	}
	for each (float value in rotateFrames){
		rotateAnimated.push_back(value);
	}
	for (int i = 0; i < rotateFrames.size(); i++){
		keyFrameAnimated.push_back(true);
	}
}

///////////////////////////////////
/*******  Erase Animation  *******/
///////////////////////////////////
void Node::eraseAnimation(){
		translateAnimated.clear();
		rotateAnimated.clear();
		scaleAnimated.clear();
		transformationAnimated.clear();
		keyFrameAnimated.clear();
}


///////////////////////////////////
/*******  Make Key Frame  *******/
///////////////////////////////////
void Node::makeKeyFrame(int place){
	int numKeyFramesPassed = 0;
	for (int i = 0; i < keyFrameAnimated.size() && i <= place; i++){
		if (keyFrameAnimated[i])
			numKeyFramesPassed++;
	}
	//isKeyFrame =0;
	vector<gMatrix3>::iterator iT = translateFrames.begin();
	vector<gMatrix3>::iterator iS = scaleFrames.begin();
	vector<float>::iterator iR = rotateFrames.begin();
	vector<gMatrix3>::iterator iTrans = transformationFrames.begin();
	
	scaleFrames.insert(iS+numKeyFramesPassed, scaleAnimated[place]);
	translateFrames.insert(iT+numKeyFramesPassed,translateAnimated[place]);
	rotateFrames.insert(iR+numKeyFramesPassed, rotateAnimated[place]);
	transformationFrames.insert(iTrans+numKeyFramesPassed, getAnimatedTransformation(place));


}