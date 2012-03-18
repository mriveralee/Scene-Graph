/*********************|
|*** myButton.cpp ****|
|*********************/

#include "myButton.h"


/*****************
*** Constructor **
******************/
MyButton::MyButton(QWidget* parent) : QPushButton(parent){
}


/******************
 *** Destructor ***
 ******************/
MyButton::~MyButton(){
}

/**************
 *** SLOTS  ***
 **************/
void MyButton::changeName(QString _value){
	this->setText(_value);
}

