/***********************|
|*** myglwidget.cpp ****|
|***********************/

#include "myglwidget.h"
#include <QDebug>
#include <cmath>
#include <iostream>
#include "mytreewidget.h"

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif
#define DEG2RAD (M_PI/180.0)

/********************************************|
|*************** CONSTRUCTOR  ***************|
|********************************************/
MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent) {
	graph = new Graph(this);
	graph->constructCharacter();	
	// Editing
	clickedNode = graph->getRootNode();
	updateDisplay =1;
	nodeMode =1;								// 1 is For Editor ; 0 is For Creator
	selectedFrame = 0;							// Currently Selected Frame
	numFrames =1;
	interpolateMode = 1; // 1 -> copy, 0-> interpolation
	playMode = 1;
	//We can set our vertex attributes rather than requesting their locations
	//I chose to do so in this constructor, maybe you would in your init() function?
	// Buffer
	positionLocation = 0;
	colorLocation = 1;
	// Animator
	numMultiAddFrames = 1;						// Number of multiple frames to be added
	animateViewMode = 0;
	//animator = new Animator(graph);
	// Timer
	timer = new QTimer(this);
	playbackSpeed = 40;
	isLooped = false;
	connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
	timer->stop();
	
}

/**********************************************|
|*************** DESTRUCTOR *******************|
|**********************************************/
MyGLWidget::~MyGLWidget() {
	//Release your resources, just like you'd delete pointers
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &cbo);
	glDeleteBuffers(1, &ibo);
	//delete &graph;
	//graph = 0;
	//Tear down the shader program in reverse of building it
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteProgram(shaderProgram);
}
/************************************************|
|*************** INTIALIZE GL *******************|
|************************************************/
//this is the function i referred to as "init" in my lecture - Cory
void MyGLWidget::initializeGL() {
	updateDisplay = 1;
	emit buildTree(graph, true);
	//Initialize GLEW to get access to latest OpenGL support on your computer
	//GLEW 1.7.0 supplied with this starter code, it's always a good idea to update
	//about once every year or so as OpenGL is updated
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		qDebug() << "GLEW is not initialized!";
	}
	//Create the VBOs and IBO we'll be using to render images in OpenGL
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &cbo);
	//glGenBuffers(1, &nbo);
	glGenBuffers(1, &ibo);
	//Everybody does this
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);
	//here is stuff for setting up our shaders
	const char* fragFile = "diffuseFrag.frag";
	const char* vertFile = "diffuseVert.vert";
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	shaderProgram = glCreateProgram();
	
	//load up the source, compile and link the shader program
	const char* vertSource = textFileRead(vertFile);
	const char* fragSource = textFileRead(fragFile);
	glShaderSource(vertexShader, 1, &vertSource, 0);
	glShaderSource(fragmentShader, 1, &fragSource, 0);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);
	//For your convenience, i decided to throw in some compiler/linker output helper functions
	//from CIS 565
	GLint compiled;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compiled);
	if (!compiled){
		printShaderInfoLog(vertexShader);
	} 
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compiled);
	if (!compiled){
		printShaderInfoLog(fragmentShader);
	} 
	//set the attribute locations for our shaders
	glBindAttribLocation(shaderProgram, positionLocation, "vs_position");
	//glBindAttribLocation(shaderProgram, normalLocation, "vs_normal");
	glBindAttribLocation(shaderProgram, colorLocation, "vs_color");
	//finish shader setup
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//check for linking success
	GLint linked;
	glGetProgramiv(shaderProgram,GL_LINK_STATUS, &linked);
	if (!linked){
		printLinkInfoLog(shaderProgram);
	}
	//Get the uniform locations for our shaders, unfortunately they can not be set by us, we have
	u_scr_widthLocation = glGetUniformLocation(shaderProgram, "u_scr_width");
	u_scr_heightLocation = glGetUniformLocation(shaderProgram, "u_scr_height");
	u_modelMatrixLocation = glGetUniformLocation(shaderProgram, "u_modelMatrix");

	//Always remember that it doesn't do much good if you don't have OpenGL actually use the shaders
	glUseProgram(shaderProgram);

}

/********************************************|
|*************** PAINT GL *******************|
|********************************************/
void MyGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);						// Clear The screen
	glewInit();
	if(graph->getRootNode() != NULL){
		if (graph->isAnimated && animateViewMode && !isPaused && playMode){
			if (currentAnimatedFrame > numAnimatedFrames && !isLooped) {stopAnimation(); }//currentAnimatedFrame = 0;}
			else if (currentAnimatedFrame > numAnimatedFrames && isLooped){currentAnimatedFrame = 0;}
			emit setAnimationSliderValue(currentAnimatedFrame);
			emit updateKeyFrameString(currentAnimatedFrame);
			graph->traverseAnimated(currentAnimatedFrame,graph->getRootNode(), gMatrix3::identity());
			currentAnimatedFrame++;
				
				//}
		}

		else if (graph->isAnimated && animateViewMode){
			graph->traverseAnimated(currentAnimatedFrame,graph->getRootNode(), gMatrix3::identity());
		}
		else {	
			if(selectedFrame < 0 ) graph->traverseFrame(0,graph->getRootNode(), gMatrix3::identity());
			else graph->traverseFrame(selectedFrame,graph->getRootNode(), gMatrix3::identity());
			updateFrameImage();
			//cerr<<"MADE IT PAST TRAVERSE FRAME"<< endl;
		}
	}
}

/********************************************|
|*************** Resize GL ** ***************|
|********************************************/
//This function is called automatically when the widget is resized, including the first "sizing"
void MyGLWidget::resizeGL(int width, int height) {
    //set the viewport, more boilerplate
	glViewport(0, 0, width, height);
	// reset the view parameters if the openGL window is resized
	glUniform1f(u_scr_widthLocation, width);
	glUniform1f(u_scr_heightLocation, height);
}

void MyGLWidget::keyPressEvent(QKeyEvent *e){
	//a good place to process keystrokes
}

/********************************************|
|*************** Text File Read *************|
|********************************************/
//from swiftless.com
char* MyGLWidget::textFileRead(const char* fileName) {
    char* text;
    if (fileName != NULL) {
        FILE *file = fopen(fileName, "rt");
        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            int count = ftell(file);
            rewind(file);       
            if (count > 0) {
                text = (char*)malloc(sizeof(char) * (count + 1));
                count = fread(text, sizeof(char), count, file);
                text[count] = '\0';	//cap off the string with a terminal symbol, fixed by Cory
            }
            fclose(file);
        }
    }
    return text;
}


/****************************************************|
|**************** Print Link Log Info ***************|
|****************************************************/
void MyGLWidget::printLinkInfoLog(int prog) 
{
	int infoLogLen = 0;
	int charsWritten = 0;
	GLchar *infoLog;

	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &infoLogLen);

	// should additionally check for OpenGL errors here

	if (infoLogLen > 0)
	{
		infoLog = new GLchar[infoLogLen];
		// error check for fail to allocate memory omitted
		glGetProgramInfoLog(prog,infoLogLen, &charsWritten, infoLog);
		qDebug() << "InfoLog:" << endl << infoLog << endl;
		delete [] infoLog;
	}
}




/********************************************************|
|*************** Print Shader Info Log ******************|
|********************************************************/
void MyGLWidget::printShaderInfoLog(int shader)
{
	int infoLogLen = 0;
	int charsWritten = 0;
	GLchar *infoLog;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLen);
	// should additionally check for OpenGL errors here
	if (infoLogLen > 0)
	{
		infoLog = new GLchar[infoLogLen];
		// error check for fail to allocate memory omitted
		glGetShaderInfoLog(shader,infoLogLen, &charsWritten, infoLog);
		qDebug() << "InfoLog:" << endl << infoLog << endl;
		delete [] infoLog;
	}
	// should additionally check for OpenGL errors here
}



/********************************************|
|*************** DRAW NODE ** ***************|
|********************************************/
void MyGLWidget::drawNode(Node* node){
//	glewInit();
	gPolygon* polygon = node->getPolygon();
	////// ROTATION VAR BELONGS IN ROTATION2D(rotation) ^^
	//model = model * rotMat;
	
	//these four points define where the quad would be BEFORE transformations
	//this is referred to as object-space and it's best to center geometry at the origin for easier transformations
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);															//now we put the data into the Vertex Buffer Object for the graphics system to use
	glBufferData(GL_ARRAY_BUFFER, (polygon->getSides()*3)* sizeof(float), polygon->getVertices(), GL_STATIC_DRAW);				//the square vertices don't need to change, ever, while the program runs									
	glBindBuffer(GL_ARRAY_BUFFER, cbo);															//always make sure you are telling OpenGL the right size to make the buffer, color data doesn't have as much data!
	glBufferData(GL_ARRAY_BUFFER, (polygon->getSides()*3)* sizeof(float), polygon->getColors(), GL_STREAM_DRAW);					//the color is going to change every frame as it bounces between squares	// Delete colors
	
	glEnableVertexAttribArray(positionLocation);
	glEnableVertexAttribArray(colorLocation);
	//glEnableVertexAttribArray(normalLocation);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);															//we're using the vertex data first
	glVertexAttribPointer(positionLocation, 3, GL_FLOAT, 0, 0, static_cast<char*>(0));			//define how the vertex pointer should work, in our case we're accessing floats 4 at a time with no special pattern
	glBindBuffer(GL_ARRAY_BUFFER, cbo);															//now use color data, remember we're not using 4 at a time anymore
	glVertexAttribPointer(colorLocation, 3, GL_FLOAT, 0, 0, static_cast<char*>(0));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);							// Bind the Indices
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3*(polygon->getSides()-2) * sizeof(unsigned short), polygon->getIndices(), GL_STATIC_DRAW);
	/*	
	cout<< "\nindex 0: " << polygon->getIndices()[0]<< "   Vertices (0): " << polygon->getVertices()[0] << ", " << polygon->getVertices()[1] << ", "<< polygon->getVertices()[2] <<  endl ;
	cout<< "\n index 1: " << polygon->getIndices()[1]<< "   Vertices: (1) " << polygon->getVertices()[3] << ", " << polygon->getVertices()[4] << ", "<< polygon->getVertices()[5] <<  endl ;
	cout<< "\n index 2: " << polygon->getIndices()[2]<< "   Vertices: (2) " << polygon->getVertices()[6] << ", " << polygon->getVertices()[7] << ", "<< polygon->getVertices()[8] <<  endl ;
	cout<< "\nindex 3: " << polygon->getIndices()[3]<< "Colors: "<< polygon->getColors()[1]<< endl;
	*/
	glUniformMatrix3fv(u_modelMatrixLocation, 1, GL_TRUE, &(node->getModel()[0][0]));	//set the model uniform && GL_TRUE since we have row ordered matrix
	//draw the elements
	glDrawElements(GL_TRIANGLES, 3*(polygon->getSides()-2), GL_UNSIGNED_SHORT, 0);
	//shut off the information since we're done drawing
	glDisableVertexAttribArray(positionLocation);
	glDisableVertexAttribArray(colorLocation);
	
}

/***************************************************\
                        SLOTS
\****************************************************/

/********************
// Rotate 
/********************/
void MyGLWidget::spin(int d){
	if (updateDisplay && nodeMode && clickedNode != NULL){
		clickedNode->setFrame(selectedFrame);
		clickedNode->Rotate((float)d);
		clickedNode->updateFrame(selectedFrame);
		emit buildTree(graph, false);
	}
	updateGL();
}

/********************
// Translate X
/********************/
void MyGLWidget::translateX(double _x){
	if (updateDisplay && nodeMode && clickedNode != NULL){	
		clickedNode->setFrame(selectedFrame);
		clickedNode->TranslateX((float)_x);
		clickedNode->updateFrame(selectedFrame);
		emit buildTree(graph, false);
	}
	updateGL();
}

/********************/
// Translate Y
/********************/
void MyGLWidget::translateY(double _y){
	if (updateDisplay && nodeMode && clickedNode != NULL){
		clickedNode->setFrame(selectedFrame);
		clickedNode->TranslateY((float)_y);
		clickedNode->updateFrame(selectedFrame);
		emit buildTree(graph, false);
	}
	updateGL();
}

/********************/
// SCALE X
/********************/
void MyGLWidget::scaleX(double _x){
	if (updateDisplay && nodeMode && clickedNode != NULL){
		clickedNode->setFrame(selectedFrame);
		clickedNode->ScaleX((float)_x);
		clickedNode->updateFrame(selectedFrame);
		emit buildTree(graph, false);
	}
	updateGL();
}
/********************/
// SCALE Y
/********************/
void MyGLWidget::scaleY(double _y){
	if (updateDisplay && nodeMode && clickedNode != NULL){
		clickedNode->setFrame(selectedFrame);
		clickedNode->ScaleY((float)_y);
		//clickedNode->setName("what");
		clickedNode->updateFrame(selectedFrame);
	}
	emit buildTree(graph, false);
	updateGL();
}
/********************/
// RESET GRAPH
/********************/
void MyGLWidget::resetGraph(){
	if(!isPaused){
		graph->constructCharacter();
		clickedNode = NULL;
		selectedFrame = 0;
		numFrames = 1;
		numMultiAddFrames = 0;
		//cout<< "WITHIN RESET" << (graph->getRootNode()->getName()).toStdString()<<endl;
		updateDisplay = 1;
		//addMode = 2;
		stopAnimation();
		graph->isAnimated = false;
		timer->stop();
		graph->eraseAnimation(graph->getRootNode());
		currentAnimatedFrame = 0;
		emit buildTree(graph, true);
		emit resetValues(0);
		emit resetValues(0.0);
		emit updateFrameImage();
		emit sendKeyFrameString(QString::fromStdString("None Selected"));
		updateGL();
	}

}
/********************/
// UPDATE COLOR RED
/********************/
void MyGLWidget::colorRed(int r){
	if(clickedNode != NULL && clickedNode->hasGeometry() && nodeMode && clickedNode != NULL){
		float g = clickedNode->getPolygon()->getColors()[1];
		float b = clickedNode->getPolygon()->getColors()[2];
		clickedNode->getPolygon()->setColors((float)r/100, g, b);
		updateGL();
	}
}


/********************/
// UPDATE COLOR GREEN
/********************/
void MyGLWidget::colorGreen(int g){
	if( clickedNode != NULL && clickedNode->hasGeometry() && nodeMode){
		float r = clickedNode->getPolygon()->getColors()[0];
		float b = clickedNode->getPolygon()->getColors()[2];
		clickedNode->getPolygon()->setColors(r, (float)g/100, b);
		updateGL();
	}

}
/********************/
// UPDATE COLOR BLUE
/********************/
void MyGLWidget::colorBlue(int b){
		if(clickedNode != NULL && clickedNode->hasGeometry() && nodeMode){
		float r = clickedNode->getPolygon()->getColors()[0];
		float g = clickedNode->getPolygon()->getColors()[1];
		clickedNode->getPolygon()->setColors(r, g, (float)b/100);
		updateGL();
		}
}
/********************/
// UPDATE NAME of NODE
/********************/
void MyGLWidget::updateName(QString g){
	if (clickedNode != NULL && nodeMode){
	string s = g.toStdString();
	clickedNode->setName(s);
	updateGL();
	}
}
////////////////////////////////////
/******** Create New Node *********/
////////////////////////////////////
void MyGLWidget::createNode(){
	if (nodeMode == 0 && clickedNode != NULL){
		if(newName == "" || newName == " ") newName = "Unnamed";
		Node* n;
		if(newGeometry == 1){
			if(newSides < 3) newSides = 3;
			n = new Node(new gPolygon(newSides, gVector3(newRedColor,newGreenColor,newBlueColor), 5), newName);
		}
		else {
			n = new Node(newName);
		}
			n->Scale(newScaleX,newScaleY);
			n->Translate(newTransX, newTransY);
			n->Rotate(newRotation);
			n->initializeFrames(numFrames);
			n->setFrame(selectedFrame);
			n->updateFrame(selectedFrame);
			clickedNode->join(n);	
			//clickedNode->setFrame(selectedFrame);
	}
	updateGL();
}

///////////////////////////////
/** SAVE SIDES FOR ADD NODE **/
///////////////////////////////
void MyGLWidget::updateMode(int val){
	nodeMode = val;
	clickedNode = NULL;
	emit clearSelection();
	emit resetValues(0);
	emit resetValues(0.0);
}

void MyGLWidget::saveGeometry(int geo){
	newGeometry = geo;
}

void MyGLWidget::saveNewName(QString n){
	newName = n.toStdString();
}

void MyGLWidget::saveSides(double val){
	newSides = (int)val;
}

void MyGLWidget::saveTransX(double val){
	newTransX = (float)val;
}

void MyGLWidget::saveTransY(double val){
	newTransY = (float)val;
}

void  MyGLWidget::saveScaleX(double val){
	newScaleX = (float)val;
}

void  MyGLWidget::saveScaleY(double val){
	newScaleY = (float)val;
}

void MyGLWidget::saveBlue(int val){
	newBlueColor = (float)val/100;
}

void MyGLWidget::saveRed(int val){
	newRedColor = (float)val/100;
}

void MyGLWidget::saveGreen(int val){
	newGreenColor = (float)val/100;
}

void MyGLWidget::saveRotation(int val){
	newRotation = (float)val;
}


////////////////////////////
/**** DELETE TREE NODE ****/
////////////////////////////
void MyGLWidget::deleteTreeNode(){
	if(nodeMode==0 && clickedNode != NULL && clickedNode != graph->getRootNode()){
		Node* parent =  (dynamic_cast<Node*>(clickedNode->QTreeWidgetItem::parent()));
		//cout<< parent << "VALUE of STRING" << parent->getName().toStdString()<<endl;
		vector<Node*> parentsClicked = clickedNode->getParentNodes();					// Parents of Node to be deleted
		QList<QTreeWidgetItem*> childrenClicked = clickedNode->takeChildren();			// Children of Node to be deleted
		vector<Node*> nodeChildrenClicked;
		for each (QTreeWidgetItem* x in childrenClicked){								// Convert Children to Nodes
			parent->addChild(x);
			nodeChildrenClicked.push_back(dynamic_cast<Node*>(x));
		}
		//
		// Will not work if parents are null so prevents from deleting character main node :D
		for each (Node* p in parentsClicked){
			p->joinMultiple(nodeChildrenClicked);
			p->removeChildNode(clickedNode);
		}
		this->animate();
	}
	emit updateGL();
	emit buildTree(graph, true);	
	emit updateGL();
}

//////////////////////////////////////////
/******* Update Interpolation Mode ******/
/* 0 if we just want to duplicate
* 1 if we want to interpolate b/w frames
*/
//////////////////////////////////////////
void MyGLWidget::updateInterpolateMode(bool doInterpolate){
	interpolateMode = doInterpolate;
	//cout<< "Interpolate mode is now; " << doInterpolate << endl;
}


/////////////////////////////////////////////////
/** ADD FRAME, SENDING IMAGE TO FRAME WIDGET ***/
/* If we are adding our first node, we default
* to duplicate mode. And if we add to the end frame 
* we duplicate instead.
*/
/////////////////////////////////////////////////
void MyGLWidget::addFrame(){
		//updateGL();
		QImage image = grabFrameBuffer(false);
		int addPlace = selectedFrame+1;
		bool isFirstAddedFrame = (selectedFrame == numFrames-1 && selectedFrame == 0);
		bool isLastFrame = (selectedFrame == numFrames-1);										// SelectedFrame || Col selected is 0-based so subtract 1 from numFrames
		//cout << "NUM FRAMES BEFORE: " << numFrames << "& nextPlace: " << addPlace<< "& selectedFrame: " << selectedFrame << "NUMFRAMES AFTER: " << numFrames +1 <<endl;
		if (isFirstAddedFrame || isLastFrame || !interpolateMode){								 
			graph->addFrame(addPlace, false, graph->getRootNode(), gMatrix3::identity());}		// Duplicate Frame
		else{
			graph->addFrame(addPlace, true, graph->getRootNode(), gMatrix3::identity());		// Insertion Frame
		}
		numFrames++;
		emit sendImage(image, addPlace);	
		emit buildTree(graph, true);
		updateGL();
}

////////////////////////////////////
// Update Selected Frame
////////////////////////////////////
/*	Updates the GL Widget to Display 
*	the graph from the currently 
*	selected frame.
*/
void MyGLWidget::updateSelectedFrame(int col){
	updateMode(nodeMode);									// Reset Values in the Editor & maintain node mode
	selectedFrame = col;
	emit buildTree(graph, true);
	updateGL();
}

////////////////////////////////////
/***** Delete Animation Frame ****/
// connected to signal: eraseFrame()
// Called in myFrameWidget()
////////////////////////////////////
void MyGLWidget::deleteFrame(){
	if (selectedFrame >= 0){
		graph->removeFrame(selectedFrame, graph->getRootNode(), gMatrix3::identity());
		clickedNode = NULL;
		if (selectedFrame > 0){
			selectedFrame--;
		}
		if (numFrames >0) 
			numFrames--;
		this->animate();
	}
	emit buildTree(graph,true);
	updateGL();
}

////////////////////////////////////
/******** Update Frame Image ******/
////////////////////////////////////
void MyGLWidget::updateFrameImage() {
		if (selectedFrame >= 0){	
		QImage image = grabFrameBuffer(false);
		emit sendUpdatedImage(image, selectedFrame);
	}
}



////////////////////////////////////
/**** Set MultiFramesValues ***/
////////////////////////////////////
void MyGLWidget::setMultiFramesValue(double value){
	numMultiAddFrames = (int)value;
	//cout << "ADD NUMBER: " << value << endl;
}

////////////////////////////////////
/********* Add Mult iFrames *******/
////////////////////////////////////
void MyGLWidget::addMultiFrames(){
	QImage image = grabFrameBuffer(false);
	int addPlace = selectedFrame+1;
	bool isFirstAddedFrame = (selectedFrame == numFrames-1 && selectedFrame == 0);
	bool isLastFrame = (selectedFrame == numFrames-1);										// SelectedFrame || Col selected is 0-based so subtract 1 from numFrames
	//cout << "NUM FRAMES BEFORE: " << numFrames << "& nextPlace: " << addPlace<< "& selectedFrame: " << selectedFrame << "NUMFRAMES AFTER: " << numFrames +1 <<endl;
	if (isFirstAddedFrame || isLastFrame || !interpolateMode){								 
		graph->batchAdd(addPlace, false, graph->getRootNode(), gMatrix3::identity(), numMultiAddFrames);}		// Duplicate Frame
	else{
		graph->batchAdd(addPlace, true, graph->getRootNode(), gMatrix3::identity(), numMultiAddFrames);		// Insertion Frame
	}

	for(int i = 1; i <= numMultiAddFrames; i++){
		numFrames++;
		QImage image = grabFrameBuffer(false);
		emit sendImage(image, addPlace+i);	
		emit buildTree(graph, true);
		updateGL();
	}
}


///////////////////////////////////////////////
/************** setAnimateViewMode ***********/
///////////////////////////////////////////////
void MyGLWidget::setAnimateViewMode(int value){
	animateViewMode = value;
	if (value == 0){
		selectedFrame = 0;			/// MAy not be needed
		//animator->isAnimated = 0;
	}
	//cout << "Animate View Mode: " << value << endl;
}

////////////////////////////////////////////////
/************** setNumAnimateFrames ***********/
////////////////////////////////////////////////
void MyGLWidget::setNumAnimateFrames(double value){
	numAnimatedFrames = value;
	//cout << "Num Animate Frames: " << value << endl;
}




////////////////////////////////////
/************** Animate ***********/
////////////////////////////////////
void MyGLWidget::animate(){
	if(numAnimatedFrames >= numFrames){
		stopAnimation();
		graph->eraseAnimation(graph->getRootNode());
		isPaused = 1;
		graph->eraseAnimation(graph->getRootNode());
		graph->copyKeyFrames(graph->getRootNode());
		graph->animateGraph(numAnimatedFrames, numFrames);
		currentAnimatedFrame = 0;
		updateGL();
		if (numFrames <= 1)
			emit setAnimationSliderMax(numAnimatedFrames-1);
		else 
			emit setAnimationSliderMax(numAnimatedFrames);
	}
}



//////////////////////////// TIMER FUNCTIONS //////////////////////


///////////////////////////////////////////
/************** Stop Animation ***********/
///////////////////////////////////////////
void MyGLWidget::stopAnimation(){
	timer->stop();
	isPaused = 1;
	currentAnimatedFrame = 0;
	emit setAnimationSliderValue(currentAnimatedFrame);
	emit sendPlayString(QString::fromStdString("Play"));
}


//////////////////////////////////////////////
/************** Change is Paused ************/
//////////////////////////////////////////////
void MyGLWidget::changeIsPaused(){
	//cout<< "isPaused Before: " << isPaused << endl; 
	if (isPaused){
		playAnimation();
		isPaused = 0;
		emit sendPlayString(QString::fromStdString("Pause"));
	}
	else {
		pauseAnimation();
		isPaused = 1;
		emit sendPlayString(QString::fromStdString("Play"));
	}
}



///////////////////////////////////////////
/************** Play Animation ***********/
///////////////////////////////////////////
void MyGLWidget::playAnimation(){
    timer->start(playbackSpeed);           //start with 17ms delay between signals, roughly 60 FPS
    updateGL();
}

////////////////////////////////////////////
/************** Pause Animation ***********/
////////////////////////////////////////////
void MyGLWidget::pauseAnimation(){
	timer->stop();
}



//////////////////////////////////////////////
/************** Change Play Mode ************/
//////////////////////////////////////////////
void MyGLWidget::changePlayMode(int _mode){
	//cout<<"PlayMode: " << _mode<< endl;
	playMode = _mode;
}


/////////////////////////////////////////////////////
/************** set CurrentAnimateFrame ************/
/////////////////////////////////////////////////////
void MyGLWidget::setCurrentAnimateFrame(int value){
		this->currentAnimatedFrame = value;
		updateKeyFrameString(value);
		updateGL();
}


void MyGLWidget::updateKeyFrameString(int value){
		if(graph->getRootNode()->keyFrameAnimated[value]){
			emit sendKeyFrameString(QString::fromStdString("Key Frame Selected"));
		}
		else
			emit sendKeyFrameString(QString::fromStdString("Animated Frame Selected"));
}

/////////////////////////////////////////////////////
/************** Make Key Frame ************/
/////////////////////////////////////////////////////
void MyGLWidget::makeKeyFrame(){
	if(graph->isAnimated){
		Node* root = graph->getRootNode();
		graph->makeKeyFrame(currentAnimatedFrame, root);
		QImage image = grabFrameBuffer(false);	
		int numKeyFramesPassed = 0;
		for (int i = 0; i < root->keyFrameAnimated.size() && i <= currentAnimatedFrame; i++){
			if (root->keyFrameAnimated[i]) numKeyFramesPassed++;
		}
		int addPlace = numKeyFramesPassed+1;	
		numFrames++;
		emit sendImage(image, addPlace);	
		emit buildTree(graph, true);
		updateGL();
		animate();
	}
}

////////////////////////////////////////////////
/************** Set PlayBack Speed ************/
////////////////////////////////////////////////
void MyGLWidget::setPlaybackSpeed(double speed){
	timer->stop();
	if(speed >=1){
		playbackSpeed = (1600/speed);
	}
	else playbackSpeed = 0;
	playAnimation();
}

//////////////////////////////////////
/************** set Loop ************/
//////////////////////////////////////
void MyGLWidget::setLoop(){
	if(isLooped){
		isLooped = false;
	}
	else
		isLooped = true;
}