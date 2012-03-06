
#pragma once
#include <QTableWidget>
#include <qtablewidget.h>
#include <QImage>
#include <qicon.h>
#include <qpixmap.h>


class KeyFrame: public QObject,  public QTableWidgetItem {

	Q_OBJECT; 

private:
	int time;
	QImage image;


public:
	KeyFrame();
	KeyFrame(QImage);
	KeyFrame(QImage, int);
	~KeyFrame();
	int getTime();
	//QImage getImage();
};


