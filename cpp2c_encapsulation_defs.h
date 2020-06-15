#include <stdbool.h>

typedef struct {
    double length;
    double width;
    double height;
}Box;

void _Z3BoxCE(Box* this);
void _Z3BoxCEd(Box* this ,double dim);
void _Z3BoxCEddd(Box* this ,double l, double w, double h);
void _Z3Box7PrintEv(const Box* this);
double _Z3Box8GetWidth(Box* this);
double _Z3Box9GetLength(Box* this);
double _Z3Box9GetHeight(Box* this);
double _Z3Box9GetVolume(Box* this);
Box* _Z3Box18multAssignOperator(Box* this,double mult);
Box multOperatorCboxd(const Box* box, double mult);
Box multOperatordCbox(double mult, const Box* box);
bool EqualEqualOperatorCboxCbox(const Box* lhs, const Box* rhs);
bool notEqualOperatorCboxCbox(const Box* lhs, const Box* rhs);