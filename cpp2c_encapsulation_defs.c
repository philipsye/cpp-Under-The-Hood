#include "cpp2c_encapsulation_defs.h"
#include <stdio.h>
void _Z3BoxCE(Box* this){
    this->length = 1;
    this->height = 1;
    this->width = 1;
    _Z3Box7PrintEv(this);
}


void _Z3BoxCEd(Box* this ,double dim){
    this->length = dim;
    this->height = dim;
    this->width = dim;
    _Z3Box7PrintEv(this);
}


void _Z3BoxCEddd(Box* this ,double l, double w, double h){
    this->length = l;
    this->height = w;
    this->width = h;
    _Z3Box7PrintEv(this);
}

void _Z3Box7PrintEv(const Box* this){
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}

/*inline*/double _Z3Box8GetWidth(Box* this){
    return this->width;
}


/*inline*/double _Z3Box9GetLength(Box* this){
    return this->length;
}
/*inline*/double _Z3Box9GetHeight(Box* this){
    return this->width;
}

/*inline*/double _Z3Box9GetVolume(Box* this){
    return this->width * this->length * this->height;
}

Box* _Z3Box18multAssignOperator(Box* this,double mult){
    this->width *= mult;
    this->height *= mult;
    this->length *= mult;
    return this;
}


/*inline*/Box multOperatorCboxd(const Box* box, double mult){
    Box ret = *box;
    _Z3Box18multAssignOperator(&ret , mult);
    return ret;
}


/*inline*/Box multOperatordCbox(double mult, const Box* box){
    return multOperatorCboxd(box , mult);
}

bool EqualEqualOperatorCboxCbox(const Box* lhs, const Box* rhs){
    return _Z3Box8GetWidth(&lhs) == _Z3Box8GetWidth(rhs) && _Z3Box9GetHeight(lhs) == _Z3Box9GetHeight(rhs) && _Z3Box9GetLength(lhs) == _Z3Box9GetLength(rhs);
}
bool operatorNotEqualCBCB(const Box* lhs, const Box* rhs){
    return !(lhs == rhs);
}
