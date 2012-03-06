#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include <QtGui/QMainWindow>
#include "ui_scenegraph.h"

class sceneGraph : public QMainWindow
{
	Q_OBJECT

public:
	sceneGraph(QWidget *parent = 0, Qt::WFlags flags = 0);
	~sceneGraph();

private:
	Ui::sceneGraphClass ui;
};

#endif // SCENEGRAPH_H
