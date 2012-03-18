/**************************|
|**** myFrameWidget.cpp****|
|**************************/
#include "myframewidget.h"

////////////////////////////////////
/*********** Constructor **********/
////////////////////////////////////
MyFrameWidget::MyFrameWidget(QWidget* parent) : QTableWidget(parent){
	COL_WIDTH = 160;												// col width var
	ROW_HEIGHT = 100;												// row height var
	colCount = 1;													// col place
	clickedCol = 0;													// currently selected col
	setColumnCount(1);												// current number of cols
	setRowCount(1);													// current number of rows
	setRowHeight(0,ROW_HEIGHT);										// Set the default row height
	setColumnWidth(0,COL_WIDTH);									// Set col width for first col
	setEditTriggers(QAbstractItemView::EditTriggers(0));
	setHorizontalHeaderLabels(createHeaderList());// Prevent Editable Text
}

////////////////////////////////////
/************ Destructor **********/
////////////////////////////////////
MyFrameWidget::~MyFrameWidget(){
/* for each (KeyFrame* f in frames){
	 delete f;
 }
 */
}

////////////////////////////////////
/*********** get Image ************/
////////////////////////////////////
void MyFrameWidget::getImage(QImage image, int location){
	if (colCount == 0 || colCount == location-1) 
		location -= 0;
	insertColumn(location);
	setColumnCount(++colCount);										// add another column
	setColumnWidth(location, COL_WIDTH);								// Set New Column's Width
	KeyFrame* f = new KeyFrame(image, 0);								// new KeyFrame obj
//	frames.push_back(f);											// add to vector
	//cout<<"added image from glwidget!"<< endl;
	this->setItem(0, location, f);									// add to the table widget
	setHorizontalHeaderLabels(createHeaderList());
}

////////////////////////////////////
/********* Receive Graph **********/
////////////////////////////////////
void MyFrameWidget::receiveGraph(Graph* _graph){
	this->graph = _graph; 
}

////////////////////////////////////
/************ set Clicked *********/
////////////////////////////////////
void MyFrameWidget::setClicked(int row, int col){
	clickedCol = col;
	//cout<<"FrameWidget Selected Column" << col<<endl;
	emit changeFrame(col);
}

////////////////////////////////////
/********** Remove Frame **********/
////////////////////////////////////
void MyFrameWidget::removeFrame(){
	if (clickedCol >= 0){
		int i = 0;
		this->removeColumn(clickedCol);
		colCount--;
		if ( colCount >=  0 ){ 
			emit eraseFrame();
			setHorizontalHeaderLabels(createHeaderList());
		}
	}
	if (colCount <= 0) colCount = 0;
	this->selectColumn(-1);
	this->update();
	setHorizontalHeaderLabels(createHeaderList());
}

////////////////////////////////////
/********* Update Image ***********/
////////////////////////////////////
void MyFrameWidget::updateImage(QImage image, int location){
	KeyFrame* f = new KeyFrame(image, location);								// new KeyFrame obj
	//frames.push_back(f);											// add to vector
	this->setItem(0,location, f);
	this->update();
}


////////////////////////////////////
/********* reset Frames ***********/
////////////////////////////////////
void MyFrameWidget::resetFrames(){
	this->reset();
	for (int i=colCount; i>=0; i--){
		//frames.pop_back();
		this->removeColumn(i);
		colCount--;
	}
	colCount = 1;													// col place
	clickedCol = 0;													// currently selected col
	setColumnCount(1);												// current number of cols
	setRowCount(1);													// current number of rows
	setRowHeight(0,ROW_HEIGHT);										// Set the default row height
	setColumnWidth(0,COL_WIDTH);	
	setHorizontalHeaderLabels(createHeaderList());
	this->update();
}


/////////////////////////////////////////
/********* create HeaderList ***********/
/////////////////////////////////////////
QList<QString> MyFrameWidget::createHeaderList(){
	string output = "";
	for (int i = 0; i < colCount; i++){
		char buffer[33];
		itoa (i,buffer,10);
		if(i!=colCount-1){
			output = output.append(buffer);
			output.append(";");}
		else 
			output=output.append(buffer);
		//cout << "STRING VALUE i: " << output << endl;
	}
	return QList<QString>((QString::fromStdString(output)).split(";"));
}