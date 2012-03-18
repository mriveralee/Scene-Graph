/*******************************
 **** MyAnimationSlider.cpp ****
 *******************************/
#pragma once


#include <QSlider>
#include <qobject.h>
#include <QWidget>
#include "Node.h"
#include "Graph.h"

class Graph;
class MyGLWidget;

class MyAnimationSlider : public QSlider {
	Q_OBJECT;

private:
	Graph* g;

public:
	MyAnimationSlider(QWidget*);
	~MyAnimationSlider();

public slots:
	void setMaxValue(int);

signals: 

};	

