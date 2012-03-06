/****************************|
|**** myFrameWidget.cpp *****|
|****************************/

#pragma once
#include <qtablewidget.h>
#include <qimage.h>
#include <qicon.h>
#include <qpixmap.h>
#include "KeyFrame.h"
#include "Graph.h"
#include <vector>

class MyFrameWidget: public QTableWidget{
	Q_OBJECT;
private:
	int clickedCol;
	int colCount;
	int selectedTime;
	int ROW_HEIGHT;
	int COL_WIDTH;
	Graph* graph;
	//vector<KeyFrame*> frames;
	//KeyFrame selectedKeyFrame()


public:
	MyFrameWidget(QWidget*);
	~MyFrameWidget();
	QList<QString> createHeaderList();

public slots:
	void getImage(QImage, int);
	void receiveGraph(Graph*);
	void removeFrame();
	void setClicked(int,int);
	void updateImage(QImage, int);
	void resetFrames();

signals:
	void sendTime(int);
	void changeFrame(int);
	void eraseFrame();
	
};