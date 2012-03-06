/********************
*** MySlider.h **
*********************/
#pragma once
#include <QSlider>
#include <qobject.h>
#include <QWidget>
#include "Node.h"
#include <qstring.h>
#include "Graph.h"



class MySlider : public QSlider {
	Q_OBJECT;

private:
	Graph* g;

public:
	MySlider(QWidget*);
	~MySlider();

public slots:
		void receiveData(float,float,float, float, int, int);
		void receiveGeometry(int);
		void receiveRotation(float);

signals: 
		void passDataSlider(float, float, float, float, int, int);
};	
