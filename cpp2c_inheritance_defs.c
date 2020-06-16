#include "cpp2c_inheritance_defs.h"


//// Materials ////////////

void _Z9MaterialsCEs(Materials* this){}


void _Z9MaterialsDEs(Materials* this){}


void _Z10Material_tCEs(Material_t* this , enum Types mat){
    this->_Z10Material_t8materialVE = mat;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[this->_Z10Material_t8materialVE]);
    }
}


void _Z10Material_t5CopyCEs(Material_t* this , Material_t* other ){
    *this = *other;
}


Material_t* _Z10Material_t14AssignOperatorEs(Material_t* this , Material_t* other ){
    *this = *other;
    return this;
}


void _Z10Material_tDEs(Material_t* this){}


//// PhysicalBox ////////////

void _Z11PhysicalBoxCEsddd(PhysicalBox* this, double l, double w, double h){
    _Z3BoxCEddd((Box*)this, l, w, h);
    _Z10Material_tCEs((Material_t*)this + sizeof(Box) , OTHER);
    _Z11PhysicalBox6printpEs(this);
}


void _Z11PhysicalBoxCEsdddTypes(PhysicalBox* this, double l, double w, double h, enum Types t){
    _Z3BoxCEddd((Box*)this, l, w, h);
    _Z10Material_tCEs((Material_t*)this + sizeof(Box)  , t);
    _Z11PhysicalBox6printpEs(this);
}


void _Z11PhysicalBoxCEsTypes(PhysicalBox* this, enum Types t){
    _Z3BoxCE((Box*)this);
    _Z10Material_tCEs((Material_t*)this + sizeof(Box)  , t);
    _Z11PhysicalBox6printpEs(this);
}


void _Z11PhysicalBox5CopyCEsPhysicalBox(PhysicalBox* this, PhysicalBox* other){
    _Z10Material_t5CopyCEs((Material_t*)this + sizeof(Box), (Material_t*)other + sizeof(Box));
    *this = *other;
}


PhysicalBox* _Z11PhysicalBox14AssifnOperatorEsPhysicalBox(PhysicalBox* this, PhysicalBox* other){
    _Z10Material_t5CopyCEs((Material_t*)this + sizeof(Box), (Material_t*)other + sizeof(Box));
    *this = *other;
    return this;
}


void _Z11PhysicalBoxDEs(PhysicalBox* this){
    {
        const char* names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox dtor, %f x %f x %f, %s; ", ((Box*)this)->length, ((Box*)this)->height, ((Box*)this)->width, names[((Material_t*)this+sizeof(Box))->_Z10Material_t8materialVE]);

        _Z10Material_tDEs((Material_t*)this + sizeof(Box));
        _Z3BoxDEv((Box*)this);
    }
}


void _Z11PhysicalBox6printpEs(const PhysicalBox* this){
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox, made of %s; ", names[((Material_t*)this+sizeof(Box))->_Z10Material_t8materialVE]);
    }


    _Z3Box7PrintEv((Box*)this);
}


//// WeightBox ////////////

void _Z9WeightBoxCEsdddd(WeightBox* this, double l, double w, double h, double wgt){
    _Z3BoxCEddd((Box*)this, l, w, h);
    this->weight = wgt;
    _Z9WeightBox6PrintwEs(this);
}


void _Z9WeightBox5CopyCEsWeightBox(WeightBox* this, WeightBox* other){
//    _ZC3BoxEsbox((Box*)this , (Box*)other);

    _Z3BoxCE((Box*)this);
    this->weight = other->weight;
    _Z9WeightBox6PrintwEs(this);
}


WeightBox* _Z9Weight14AssignOperatorECsWeightBox(WeightBox* this, WeightBox* other){
   // _ZC3BoxEsbox((Box*)this , (Box*)other);
    _Z3BoxCE((Box*)this);
    this->weight = other->weight;
    return this;
}


void _Z9WeightBoxDs(WeightBox* this){
    printf("Destructing WeightBox; ");
    _Z9WeightBox6PrintwEs(this);
    _Z3BoxDEv((Box*)this);
}


void _Z9WeightBox6PrintwEs(const WeightBox* this){
    printf("WeightBox, weight: %f; ", this->weight);
    _Z3Box7PrintEv((Box*)this);
}

/*
 #include "cpp2c_inheritance_defs.h"


//// Materials ////////////

void _Z10Material_tCEs(Material_t* this , enum Types mat){
    this->_Z10Material_t8materialVE = mat;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[this->_Z10Material_t8materialVE]);
    }
}


void _Z10Material_t5CopyCEs(Material_t* this , Material_t* other ){
//    *this = *other;
this->_Z10Material_t8materialVE = other->_Z10Material_t8materialVE;
}


Material_t* _Z10Material_t14AssignOperatorEs(Material_t* this , Material_t* other ){
//    *this = *other;
    this->_Z10Material_t8materialVE = other->_Z10Material_t8materialVE;
    return this;
}


void _Z10Material_tDEs(Material_t* this){}


//// PhysicalBox ////////////

void _Z11PhysicalBoxCEsddd(PhysicalBox* this, double l, double w, double h){
    _Z3BoxCEddd((Box*)this, l, w, h);
    _Z10Material_tCEs((Material_t*)this + sizeof(Box) , OTHER);
    _Z11PhysicalBox6printpEs(this);
}


void _Z11PhysicalBoxCEsdddTypes(PhysicalBox* this, double l, double w, double h, enum Types t){
    _Z3BoxCEddd((Box*)this, l, w, h);
    _Z10Material_tCEs((Material_t*)this + sizeof(Box)  , t);
    _Z11PhysicalBox6printpEs(this);
}


void _Z11PhysicalBoxCEsTypes(PhysicalBox* this, enum Types t){
    _Z3BoxCE((Box*)this);
    _Z10Material_tCEs((Material_t*)this + sizeof(Box)  , t);
    _Z11PhysicalBox6printpEs(this);
}


void _Z11PhysicalBox5CopyCEsPhysicalBox(PhysicalBox* this, PhysicalBox* other){
    _ZC3BoxEsbox((Box*)&this, (Box*)&other);
    _Z10Material_t5CopyCEs((Material_t*)&this+ sizeof(Box) , (Material_t*)&other+ sizeof(Box));
}


PhysicalBox* _Z11PhysicalBox14AssifnOperatorEsPhysicalBox(PhysicalBox* this, PhysicalBox* other){
    _ZC3BoxEsbox((Box*)&this, (Box*)&other);
    _Z10Material_t5CopyCEs((Material_t*)&this+ sizeof(Box) , (Material_t*)&other+ sizeof(Box));

    return this;
}


void _Z11PhysicalBoxDEs(PhysicalBox* this){
    {
        const char* names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox dtor, %f x %f x %f, %s; ", ((Box*)this)->length, ((Box*)this)->width, ((Box*)this)->height, names[((Material_t*)this+sizeof(Box))->_Z10Material_t8materialVE]);

        _Z10Material_tDEs((Material_t*)this + sizeof(Box));
        _Z3BoxDEv((Box*)this);
    }
}


void _Z11PhysicalBox6printpEs(const PhysicalBox* this){
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox, made of %s; ", names[((Material_t*)this+sizeof(Box))->_Z10Material_t8materialVE]);
    }


    _Z3Box7PrintEv((Box*)this);
}


//// WeightBox ////////////

void _Z9WeightBoxCEsdddd(WeightBox* this, double l, double w, double h, double wgt){
    _Z3BoxCEddd((Box*)this, l, w, h);
    this->weight = wgt;
    _Z9WeightBox6PrintwEs(this);
}


void _Z9WeightBox5CopyCEsWeightBox(WeightBox* this, WeightBox* other){
    _ZC3BoxEsbox((Box*)this , (Box*)other);
    this->weight = other->weight;
    _Z9WeightBox6PrintwEs(this);
}


WeightBox* _Z9Weight14AssignOperatorECsWeightBox(WeightBox* this, WeightBox* other){
    _ZC3BoxEsbox((Box*)this , (Box*)other);
    this->weight = other->weight;
    return this;
}


void _Z9WeightBoxDs(WeightBox* this){
    printf("Destructing WeightBox; ");
    _Z9WeightBox6PrintwEs(this);
    _Z3BoxDEv((Box*)this);
}


void _Z9WeightBox6PrintwEs(const WeightBox* this){
    printf("WeightBox, weight: %f; ", this->weight);
    _Z3Box7PrintEv((Box*)this);
}

 */