#include <stdio.h>

#include "cpp2c_encapsulation_defs.h"
static Box largeBox;
int isBox99 = 0;
int isBox88 = 0;


void thisFunc()
{
    Box box99;
    if(isBox99 == 2){
        _Z3BoxDEv(&box99);
        return;
    }

    printf("\n--- thisFunc() ---\n\n");

    if(!isBox99){
        _Z3BoxCEddd(&box99 ,99, 99, 99 );
        isBox99 = 1;
    }

    _Z3Box18multAssignOperator(&box99 , 10);
}


void thatFunc()
{
    static Box box88;
    if(isBox88 == 2){
        _Z3BoxDEv(&box88);
        return;
    }

    printf("\n--- thatFunc() ---\n\n");

    if(!isBox88){
        _Z3BoxCEddd(&box88 ,88, 88, 88 );
        isBox88 = 1;
    }

    _Z3Box18multAssignOperator(&box88 , 10);
}


void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box b1, b2;
    _Z3BoxCEd(&b1, 3);
    _Z3BoxCEddd(&b2, 4, 5, 6);

    printf("b1 volume: %f\n", b1.width*b1.length*b1.height);
    printf("b2 volume: %f\n", b2.width*b2.length*b2.height);

    _Z3Box18multAssignOperator(&b1 , 1.5);
    _Z3Box18multAssignOperator(&b2 , 0.5);

    printf("b1 volume: %f\n", b1.width*b1.length*b1.height);
    printf("b2 volume: %f\n", b2.width*b2.length*b2.height);

    Box b3 , b4 , temp;
    _ZC3BoxEsbox(&b3 , &b2);
    _ZC3BoxEsbox(&temp , &b2);
    _Z3Box18multAssignOperator(&temp, 3);
    _ZC3BoxEsbox(&b4 , &temp);
    _Z3BoxDEv(&temp);

    printf("b3 %s b4\n", (b3.width == b4.width && b3.height == b4.height && b3.length == b4.length) ? "equals" : "does not equal");
    _Z3Box18multAssignOperator(&b3, 1.5);
    _Z3Box18multAssignOperator(&b4, 0.5);

    printf("Now, b3 %s b4\n", (b3.width == b4.width && b3.height == b4.height && b3.length == b4.length) ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");
    _Z3BoxDEv(&b1);
    _Z3BoxDEv(&b2);
    _Z3BoxDEv(&b3);
    _Z3BoxDEv(&b4);
}


void doShelves()
{
    printf("\n--- start doShelves() ---\n\n");

    Box aBox;
    _Z3BoxCEd(&aBox, 5);

    Shelf aShelf;
    _Z5ShelfCE(&aBox);

    _Z5Shelf5printEs(&aBox);
    _Z5Shelf6SetBoxEsiBox(&aBox,1, &largeBox);
    _Z5Shelf6SetBoxEsiBox(&aBox,0, &aBox);
    _Z5Shelf5printEs(&aBox);

    _Z5Shelf7message = "This is the total volume on the shelf:";
    _Z5Shelf5printEs(&aBox);

    _Z5Shelf7message = "Shelf's volume:";
    _Z5Shelf5printEs(&aBox);

    Box temp;
    _Z3BoxCEddd(&temp, 2, 4, 6);
    _Z5Shelf6SetBoxEsiBox(&aBox, 1, &temp);
    _Z3BoxDEv(&temp);

    Box temp2;
    _Z3BoxCEddd(&temp2, 2, 4, 6);
    _Z5Shelf6SetBoxEsiBox(&aBox, 2, &temp2);
    _Z3BoxDEv(&temp);
    _Z5Shelf5printEs(&aBox);

    printf("\n--- end doShelves() ---\n\n");
    _Z3BoxDEv(&aBox);
    _Z5ShelfDE(&aShelf);
}

int main()
{
    _Z3BoxCEddd(&largeBox, 10, 20, 30);
    printf("\n--- Start main() ---\n\n");
    doBoxes();
    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();
    doShelves();
    printf("\n--- End main() ---\n\n");
    _Z3BoxDEv(&largeBox);

    if(isBox99){
        isBox99 = 2;
        thisFunc();
    }

    if(isBox88){
        isBox88 = 2;
        thisFunc();
    }

    return 0;
}
