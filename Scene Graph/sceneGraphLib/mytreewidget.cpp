/***********************|
|*** mytreewidget.cpp **|
|***********************/



#include "mytreewidget.h"





MyTreeWidget::MyTreeWidget(QWidget* parent) : QTreeWidget(parent) {
	setColumnCount(1);
}

MyTreeWidget::~MyTreeWidget(){
}

void MyTreeWidget::getTreeForBuilding(Graph* _graph, bool update){
	if (update){											// Update only when in EDITOR MODE NOT CREATOR
		g = _graph;
		while (this->takeTopLevelItem(0) != 0){				// Erase all Old Nodes
			this->removeItemWidget(root, 0);
		}
		root = g->getRootNode();
		this->addTopLevelItem(root);						// Update tree with new node
		this->expandAll();
		this->update();
		emit sendGraphFromTree(_graph);
	}
}