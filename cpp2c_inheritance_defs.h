#ifndef UNTITLED_CPP2C_INHERITANCE_DEFS_H
#define UNTITLED_CPP2C_INHERITANCE_DEFS_H

#include "cpp2c_encapsulation_defs.h"


//// Materials ////////////

typedef struct {
    bool isEmpty;
}Materials;

void _Z9MaterialsCEs(Materials* this);
void _Z9MaterialsDEs(Materials* this);

enum Types{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
};


typedef struct{
    enum Types _Z10Material_t8materialVE;
}Material_t;


void _Z10Material_tCEs(Material_t* this , enum Types mat);
void _Z10Material_t5CopyCEs(Material_t* this , Material_t* other );
Material_t* _Z10Material_t14AssignOperatorEs(Material_t* this , Material_t* other );
void _Z10Material_tDEs(Material_t* this);


//// PhysicalBox ////////////

typedef struct
{
    Box _Z11PhysicalBox3box;
    Material_t _Z11PhysicalBox8materialVE;
}PhysicalBox;


void _Z11PhysicalBoxCEsddd(PhysicalBox* this, double l, double w, double h);
void _Z11PhysicalBoxCEsdddTypes(PhysicalBox* this, double l, double w, double h, enum Types t);
void _Z11PhysicalBoxCEsTypes(PhysicalBox* this, enum Types t);
void _Z11PhysicalBox5CopyCEsPhysicalBox(PhysicalBox* this, PhysicalBox* other);
PhysicalBox* _Z11PhysicalBox14AssifnOperatorEsPhysicalBox(PhysicalBox* this, PhysicalBox* other);
void _Z11PhysicalBoxDEs(PhysicalBox* this);
void _Z11PhysicalBox6printpEs(const PhysicalBox* this);


//// WeightBox ////////////

typedef struct
{
    Box box;
    double weight;
}WeightBox;


void _Z9WeightBoxCEsdddd(WeightBox* this, double l, double w, double h, double wgt);
void _Z9WeightBox5CopyCEsWeightBox(WeightBox* this, WeightBox* other);
WeightBox* _Z9Weight14AssignOperatorECsWeightBox(WeightBox* this, WeightBox* other);
void _Z9WeightBoxDs(WeightBox* this);
void _Z9WeightBox6PrintwEs(const WeightBox* this);

#endif //UNTITLED_CPP2C_INHERITANCE_DEFS_H
