#ifndef SCENEGRAPHLIB_H
#define SCENEGRAPHLIB_H

#include <QtGui/QMainWindow>
#include "ui_scenegraphlib.h"

class sceneGraphLib : public QMainWindow
{
	Q_OBJECT

public:
	sceneGraphLib(QWidget *parent = 0, Qt::WFlags flags = 0);
	~sceneGraphLib();

private:
	Ui::sceneGraphLibClass ui;
};

#endif // SCENEGRAPHLIB_H
