#include "scenegraphlib.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	sceneGraphLib w;
	w.show();
	return a.exec();
}
