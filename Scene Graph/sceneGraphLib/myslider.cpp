/********************
*** MySlider.cpp   **
*********************/


#include "myslider.h"


/*****************
*** Constructor **
******************/
MySlider::MySlider(QWidget* parent) : QSlider(parent){
}


/*****************
*** Destructor ***
******************/
MySlider::~MySlider(){
}

/*****************
*** SLOTS ***
******************/


//////////////////
// Receive Colors
//////////////////
	void MySlider::receiveData(float _red,float _green,float _blue, float _rotation, int hasGeometry, int count){
		if (count == 0){
			setValue(100*_red);
			emit passDataSlider(_red, _green, _blue, _rotation, hasGeometry, ++count);
		}
		else if (count == 1){
			setValue(100*_green);
			emit passDataSlider(_red, _green, _blue, _rotation, hasGeometry, ++count);
		}
		else if (count == 2){
			setValue(100*_blue);
			emit passDataSlider(_red, _green, _blue, _rotation, hasGeometry, ++count);
		}
		else if (count == 3){
			float r = (int)_rotation%361;
			setValue(r);
			emit passDataSlider(_red, _green, _blue, _rotation, hasGeometry, ++count);
		}
		else if (count == 4){
			setValue(hasGeometry);
		}
	}	

//////////////////
// Receive Geometry
//////////////////
void MySlider::receiveGeometry(int hasGeometry){
		this->setValue(hasGeometry);

}
	
////////////////////
// Receive Rotation
////////////////////
void MySlider::receiveRotation(float _rotation){
		this->setValue(_rotation);
}


