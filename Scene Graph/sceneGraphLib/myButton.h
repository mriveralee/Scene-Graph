/*******************|
|*** myButton.h ****|
|*******************/


#pragma once

#include <QPushButton>
#include <qobject.h>
#include <QWidget>
#include "Node.h"
#include "Graph.h"

class Graph;
class MyGLWidget;

class MyButton : public QPushButton {
	Q_OBJECT;

private:
	Graph* g;

public:
	MyButton(QWidget*);
	~MyButton();

public slots:
	void changeName(QString);

signals: 

};	

