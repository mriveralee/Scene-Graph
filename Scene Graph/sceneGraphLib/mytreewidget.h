/*********************|
|*** mytreewidget.h **|
|*********************/

#pragma once

#include "glew.h"
#include "Graph.h"
#include "Node.h"
#include <QTreeWidget>
#include <QtGui>
#include "myglwidget.h"
#include <qstring.h>

class Graph;
class MyGLWidget;
class MyTreeWidget : public QTreeWidget {
	Q_OBJECT;
public:
	Node* root;									// Link to root Node
	Graph* g;									// Link to scene graph
	MyTreeWidget(QWidget*);						// Constructor
	~MyTreeWidget(void);						// Destructor

public slots:
		void getTreeForBuilding(Graph*, bool);
	
signals:
	void sendGraphFromTree(Graph*);
};
