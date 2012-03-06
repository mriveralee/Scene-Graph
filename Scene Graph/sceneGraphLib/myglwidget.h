/*******************|
|*** myglwidget.h **|
|*******************/

/* Serves as the viewer class for the GLWidget.
 * Draws the scene graph in the GL window.
 */
#pragma once

#include "glew.h"
#include <QGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include "Graph.h"
#include "Node.h"
#include "gMatrix3.h"
#include "gVector3.h"
#include "gPolygon.h"
#include "mytreewidget.h"

class Graph;										// Needed for Dependencies
class MyTreeWidget;


class MyGLWidget : public QGLWidget {
	Q_OBJECT;

private:
	//vertex arrays needed for drawing
	unsigned int vbo;
	unsigned int cbo;
	unsigned int ibo;
	//attributes
	unsigned int positionLocation;
	unsigned int colorLocation;
	// uniforms
	unsigned int u_scr_widthLocation;
	unsigned int u_scr_heightLocation;
	unsigned int u_modelMatrixLocation;
	//needed to compile and link and use the shaders
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;
	//Animation/transformation stuff
	QTimer* timer;
	//float rotation;
	//helper function to read shader source and put it in a char array
	//thanks to Swiftless
	char* textFileRead(const char*);
	//some other helper functions from CIS 565
	void printLinkInfoLog(int);
	void printShaderInfoLog(int);

public:
	Node* clickedNode;						// Currently selected Node in the TreeWidget
	boolean nodeMode;						// Mode for editing nodes- 0 for Creator || 1 for Editor
	/* Storage Values for making a new node ********************************************************/
	Node* newNode;							/* Stores a pointer to a new Node */ 
	boolean newGeometry;					/* Stores the value for new geometry, for a new node */
	float newRedColor;						/* Stores the red color value for a new new node */		
	float newGreenColor;					/* Stores the green color value for a new node */
	float newBlueColor;						/* Stores a blue color value for a new node */
	float newTransX;						/* Stores a translateX value for a new node */
	float newTransY;						/* Stores a translateY value for a new node */
	float newScaleX;						/* Stores a scaleX value for a new node */
	float newScaleY;						/* Stores a ScaleY value for a new node */
	float newRotation;						/* Stores a rotation value for a new node */
	float newSides;							/* Stores the number of sides for a new node */
	string newName;							/* Stores the name for a new Node */
	/* End vars for new node                ******************************************************/ 									
	int selectedFrame;						// Currently selected Frame
	int numFrames;							// the current number of Frames in the animation 
	int interpolateMode;							// Mode for addings 0 if || 1 if || 2 if
	bool updateDisplay;						// Can we update the display nodes on changes of values; 0 if NodeMode => creator mode; 1 otherwise
	bool firstRun;	
	Graph* graph;							// Link to the Scene graph
	
	MyGLWidget(QWidget*);					// Constructor
	~MyGLWidget(void);						// Destructor
	void initializeGL(void);				// Initialize the openGL vars
	void paintGL(void);						// Paint the graph
	void resizeGL(int, int);				// Resize the GL
	void keyPressEvent(QKeyEvent*);			// Processes keyEvents
//	void MyGLWidget::drawPolygon(gPolygon*);
	void MyGLWidget::drawNode(Node*);		// Draws the scene graph by passing in the root node


public slots:									
	//void changeNode(void);
	//void refresh(void);
	void spin(int);								// Update rotation degrees value in the control box
	void translateX(double);					// Update translateX value in the control box
	void translateY(double);					// Update translateY value in the control box
	void scaleX(double);						// Update scaleX value in the control box
	void scaleY(double);						// Update scaleY degrees in the control box
	void resetGraph(void);						// Reset the graph/animation/tree widget viewer to the original character. (Reconstructs a character)
	void colorRed(int);							// Update red color value in the control box
	void colorGreen(int);						// Update green color value in the control box
	void colorBlue(int);						// Update blue color value in the control box
	void updateName(QString);					// Update Name in the control box
	void updateMode(int);						// Update Node mode (editor vs creator)
	void createNode();							// Create a new Node
	void saveGeometry(int);						// Save geometry for new Node
	void saveNewName(QString);					// Update name for new Node
	void saveTransX(double);					// Save TranslateX value for new Node
	void saveTransY(double);					// Save TranslateY value for new Node
	void saveScaleX(double);					// Save ScaleX value for new Node
	void saveScaleY(double);					// Save ScaleY value for new Node
	void saveRotation(int);						// Save Rotation value for new Node
	void saveSides(double);						// Save number of sides for polygon for new Node
	void saveRed(int);							// Save red color value for new Node
	void saveGreen(int);						// Save green color value value for new Node
	void saveBlue(int);							// Save blue color value value for new Node
	void deleteTreeNode();						// Delete a item from the scene graph & the treeWidget display
	void addFrame();							// Add a frame to the key frame animation view
	void updateSelectedFrame(int);				// update the image displayed to show frame at a framePlace (int)
	void deleteFrame();							// Delete a frame from the keyframe animation edition view
	void updateFrameImage();
	void updateInterpolateMode(bool);

signals:
	void buildTree(Graph*, bool);				// Displays scene graph in the tree view; True only for reset, or add/remove nodes
	void resetValues(double);					// Clears all values in the control box on reset
	void resetValues(int);
	void cNode();		
	void sendUpdatedImage(QImage, int);			// Updates the display image for an frame
	void sendImage(QImage, int);				
	void setSelectedColumn(int);				// Sets the selectedFrame
	void clearFrames();							// Erases all frames
	void clearSelection();
};