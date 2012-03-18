/*******************************
 **** MyAnimationSlider.cpp ****
 *******************************/


#include "myanimationslider.h"



/*****************
*** Constructor **
******************/
MyAnimationSlider::MyAnimationSlider(QWidget* parent) : QSlider(parent){
	
}

/******************
 *** Destructor ***
 ******************/
MyAnimationSlider::~MyAnimationSlider(){
}

/*****************
*** SLOTS ***
******************/
void MyAnimationSlider::setMaxValue(int max){
	this->setMaximum(max);
	this->update();
	//cout<<"Max Value: "<< max<<endl;
}

