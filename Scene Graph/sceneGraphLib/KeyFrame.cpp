
#include "KeyFrame.h"


KeyFrame::KeyFrame(){
	//parent();
}


KeyFrame::KeyFrame(QImage image){
	parent();
	image = image.scaledToHeight(100);
	QPixmap pixels = QPixmap::fromImage(image);
	setData(Qt::DecorationRole, pixels);
	//QIcon icon = QIcon(pixels);
	//this->setIcon(icon);
	//this->setText("COOL!");
}


KeyFrame::KeyFrame(QImage image, int title){
	this->setText(QString(""+title));
	image = image.scaledToHeight(100);
	QPixmap pixels = QPixmap::fromImage(image);
	setData(Qt::DecorationRole, pixels);
	//QIcon icon = QIcon(pixels);
	//this->setIcon(icon);
	//this->setText("COOL!");
}


KeyFrame::~KeyFrame(){

}