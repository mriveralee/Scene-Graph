/********************
*** MyControlBox.h **
*********************/
#pragma once
#include <QDoubleSpinBox>
#include <qobject.h>
#include <QWidget>
#include "Node.h"
#include <QtGui>
#include <qstring.h>
#include "Graph.h"


class MyControlBox : public QDoubleSpinBox {
	Q_OBJECT;

private:

public: 
	Graph* g;
	MyControlBox();
	MyControlBox(QWidget*);
	~MyControlBox();

public slots:
	void grabNodeFromClick(QTreeWidgetItem*, int);
	void receiveGraphFromTree(Graph*);
	void receiveGraphFromControlBox(Graph*);
	void receiveClickedNode(Node*, int);


signals:
	void sendGraphFromControlBox(Graph*);
	void sendClickedNode(Node*, int);
	void sendName(QString);
	void passData(float, float, float, float, int, int);
	void saveNewNode();
	void saveNewNode(Graph*);
	
};