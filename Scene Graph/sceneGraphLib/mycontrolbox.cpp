/***********************
*** MyControlBox.cpp ***
************************/

#include "mycontrolbox.h"
#include <assert.h>




MyControlBox::MyControlBox(QWidget* parent) : QDoubleSpinBox(parent) {
}

MyControlBox::~MyControlBox(){

	}

//// SLOTS ///
void MyControlBox::grabNodeFromClick(QTreeWidgetItem* n, int notUsed){
	Node* node = (Node*)n;
	g->widget->clickedNode = node;
	if(g->widget->nodeMode == 1){
	double passingVal = node->getScale()[0][0];
	if (g != NULL) {
		g->widget->updateDisplay = 0;
	}
	this->setValue(passingVal);	
	if (g!=NULL){
		g->widget->updateDisplay = 1;
	}
	emit sendClickedNode(node, 1);
	}
}


void MyControlBox::receiveGraphFromTree(Graph* _graph){
	g = _graph;
	emit sendGraphFromControlBox(_graph);

}

void MyControlBox::receiveGraphFromControlBox(Graph* _graph){
	g = _graph;
	emit sendGraphFromControlBox(_graph);
}


void MyControlBox::receiveClickedNode(Node* node, int control){
	if (g != NULL) {
		g->widget->updateDisplay = 0;
	}
	if (control == 1){
		setValue(node->getScale()[1][1]);
	}
	else if (control == 2) {
		setValue(node->getTranslation()[0][2]);
	}
	else if (control ==3){
		setValue(node->getTranslation()[1][2]);
		
	}
	else if( control == 4){
		float rotate = node->rotateValue;
		if (node->hasGeometry()){
			setValue(node->getPolygon()->getSides());
		//	cout<<"GEOMETRY FOUND" << node->getPolygon()->getSides()<<endl;
			float* colors = (node->getPolygon())->getColors();
			float red = colors[0];
			float green = colors[1];
			float blue = colors[2];
			emit passData(red, green, blue, rotate, node->hasGeometry(), 0 );
		}
		else {
			setValue(0);
			emit passData(0,0,0,rotate,0,0);
		}
		emit sendName(node->getName());
		


	}
	if (g != NULL) {
		g->widget->updateDisplay = 1;
	}
	emit sendClickedNode(node, (++control));
	
}


