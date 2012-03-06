#include "scenegraph.h"
#include "glew.h"
#include "myglwidget.h"
#include "Graph.h"
#include "gMatrix3.h"

sceneGraph::sceneGraph(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	// Begin Making Widget & Character
	MyGLWidget* widget = new MyGLWidget();
	Graph* graph1 = widget->graph;
	gPolygon* pentagonR = new gPolygon(10, gVector3(0,1,0), 10);
	gPolygon* pentagonL = new gPolygon(10, gVector3(1,1,0), 10);
	gPolygon* squareR = new gPolygon(4, gVector3(0,0,1), 10);
	gPolygon* head = new gPolygon(12, gVector3(.4,.2,.8), 10);

	Node* root = new Node();
	graph1->setNode(root);

	Node* cR = new Node();
	Node* cL = new Node();
	root->addChild(cR);

	cout<<cR->getTransformation()<< endl;

	Node* c2 = new Node();
	c2->Scale(10,10);
	c2->setGeometry(pentagonR);
	cR->addChild(c2);

	
	Node* c3 = new Node();
	c3->Translate(100,100);
	cR->addChild(c3);

	Node* c4 = new Node();
	c4->setGeometry(squareR);
	c4->Scale(5,2);
	c3->addChild(c4);
	//graph1->traverse(graph1->getRootNode(), gMatrix3::identity());
	widget->paintGL(graph1);


}

sceneGraph::~sceneGraph()
{

}
