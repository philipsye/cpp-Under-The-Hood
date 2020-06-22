#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>

char DEFAULT_SYMBOL = '$';
const char HASH_DEFAULT_SYMBOL = '#';
const char FLOAT_DOLLAR_DEFAULT_SYMBOL = '@';


/*/// TextFormatter ///////////*/
void* (*TextFormatterVPTR[])(void*) = {(TYPE)_Z13TextFormatter8VirtualDEs, (TYPE )_Z13TextFormatter12VirtualPrintEkc};



void _Z13TextFormatterCEs(TextFormatter* this){
    this->PTvptr = TextFormatterVPTR;
}
void _Z13TextFormatter8VirtualDEs(void* this){}
void _Z13TextFormatter12VirtualPrintEkc(const void * this, const char* text){}

/*/// DefaultTextFormatter Defs ///////////*/


/*/// DefaultTextFormatter Defs ///////////*/
void* (*DefaultTextFormatterVPTR[])(void*) = {(TYPE)_Z20DefaultTextFormatter8VirtualDEs, (TYPE)_Z20DefaultTextFormatter12VirtualPrintEkc};

int next_id = 0;


void _Z20DefaultTextFormatterCEs(DefaultTextFormatter* this){
    ((TextFormatter*)this)->PTvptr = DefaultTextFormatterVPTR;
    _Z13TextFormatterCEs((TextFormatter*)this);
    this->id = next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}


void _Z20DefaultTextFormatterCEskDefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*  other){
    _Z13TextFormatterCEs((TextFormatter*)this);
    ((TextFormatter*)this)->PTvptr = DefaultTextFormatterVPTR;
    this->id = next_id++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}


DefaultTextFormatter* _Z20DefaultTextFormatter14AssignOperatorEskDefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*  other){
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;
}


void _Z20DefaultTextFormatter8VirtualDEs(void * this){
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", ((DefaultTextFormatter*)this)->id);
    _Z13TextFormatter8VirtualDEs((TextFormatter*)this);
}


void _Z20DefaultTextFormatter12VirtualPrintEkc(const void * this, const char* text){
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}


DefaultTextFormatter* generateFormatterArray(){
    return (DefaultTextFormatter*) malloc(3 * sizeof(DefaultTextFormatter));
}


/*/// PrePostFixer ///////////*/

void* (*PrePostFixerVPTR[])(void*)= {(TYPE)_Z12PrePostFixer8VirtualDEs, (TYPE)_Z12PrePostFixer12VirtualPrintEkc, (TYPE)_Z12PrePostFixer12VirtualPrintEslc, (TYPE)_Z12PrePostFixer23VirtualgetDefaultSymbol};


void _Z12PrePostFixerCEs(PrePostFixer* this, const char* prefix, const char* postfix){
    ((TextFormatter*)this)->PTvptr = PrePostFixerVPTR;

    _Z20DefaultTextFormatterCEs((DefaultTextFormatter*)this);
    this->pre = prefix;
    this->post = postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}


void _Z12PrePostFixerCopyCEs(PrePostFixer* this,PrePostFixer* other){
    ((TextFormatter*)this)->PTvptr =PrePostFixerVPTR;
    _Z20DefaultTextFormatterCEskDefaultTextFormatter((DefaultTextFormatter*)this, (const DefaultTextFormatter*)other);
    this->pre = other->pre;
    this->post = other->post;
}


void _Z12PrePostFixer8VirtualDEs(void * this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->pre, ((PrePostFixer*)this)->post);
    _Z20DefaultTextFormatter8VirtualDEs((DefaultTextFormatter*)this);
}


void _Z12PrePostFixer12VirtualPrintEkc(const void * this, const char* text){
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", ((const PrePostFixer*)this)->pre, text, ((const PrePostFixer*)this)->post);
}


void _Z12PrePostFixer12VirtualPrintEslc(const void * this, long num, char symbol){
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");
    if (symbol){
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", ((const PrePostFixer*)this)->pre, symbol, num, ((const PrePostFixer*)this)->post);
    }

    else{
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", ((const PrePostFixer*)this)->pre, num, ((const PrePostFixer*)this)->post);
    }
}


char _Z12PrePostFixer23VirtualgetDefaultSymbol(const void * this){
    return '\0';
}


/*/// PrePostDollarFixer ///////////*/

void* (*PrePostDollarFixerVPTR[])(void*) = {(TYPE)_Z18PrePostDollarFixerDEs, (TYPE)_Z12PrePostFixer12VirtualPrintEkc, (TYPE)_Z18PrePostDollarFixer5printEkslc, (TYPE)_Z18PrePostDollarFixer16getDefaultSymbolEks};


void _Z18PrePostDollarFixerCEskcpkcp(PrePostDollarFixer* this, const char* prefix, const char* postfix){
    ((TextFormatter*)this)->PTvptr = PrePostDollarFixerVPTR;
    _Z12PrePostFixerCEs((PrePostFixer*)this, prefix, postfix);
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->pre, ((PrePostFixer*)this)->post);
}


void _Z18PrePostDollarFixer5CopyCEskPrePostDollarFixer(PrePostDollarFixer* this, const PrePostDollarFixer* other){
    ((TextFormatter*)this)->PTvptr = PrePostDollarFixerVPTR;
    _Z12PrePostFixerCopyCEs((PrePostFixer*)this, (PrePostFixer*)other);
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->pre, ((PrePostFixer*)this)->post);
}


void _Z18PrePostDollarFixerDEs(void * this){
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n",((PrePostDollarFixer*)this)->_Z18PrePostDollarFixer12prePostFixer.pre, ((PrePostDollarFixer*)this)->_Z18PrePostDollarFixer12prePostFixer.post);
    _Z12PrePostFixer8VirtualDEs((PrePostFixer*)this);
}


void _Z18PrePostDollarFixer5printEksic(const PrePostDollarFixer* this, int num, char symbol){
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    ((pPrintLong)((((TextFormatter*)this)->PTvptr)[printEklc]))(this,num,symbol);
}


void _Z18PrePostDollarFixer5printEkslc(const void * this, long num, char symbol){
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
    _Z12PrePostFixer12VirtualPrintEslc((PrePostFixer*)this, num, symbol);
}


void _Z18PrePostDollarFixer5printEksdc(const PrePostDollarFixer* this, double num, char symbol){
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n",((PrePostFixer*)this)->pre,  symbol, num, ((PrePostFixer*)this)->post);
}


char _Z18PrePostDollarFixer16getDefaultSymbolEks(const void * this){
    return DEFAULT_SYMBOL;
}


/*/// PrePostHashFixer ///////////*/

void* (*PrePostHashFixerVPTR[])(void*) = {(TYPE)_Z16PrePostHashFixer8VirtualDEs, (TYPE)_Z12PrePostFixer12VirtualPrintEkc, (TYPE)_Z16PrePostHashFixer12VirtualprintEslc, (TYPE)_Z16PrePostHashFixer16getDefaultSymbol};


void _Z16PrePostHashFixerCEsi(PrePostHashFixer* this, int prc){
    ((TextFormatter*)this)->PTvptr =PrePostHashFixerVPTR;
    _Z18PrePostDollarFixerCEskcpkcp((PrePostDollarFixer*)this,"===> ", " <===" );
    this->precision = prc;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", ((PrePostFixer*)this)->pre, ((PrePostFixer*)this)->post, this->precision);
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->pre, HASH_DEFAULT_SYMBOL, this->precision, 9999.9999, ((PrePostFixer*)this)->post);
}


void _Z16PrePostHashFixer8VirtualDEs(void * this){
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->pre, ((PrePostFixer*)this)->post);
    _Z18PrePostDollarFixerDEs((PrePostDollarFixer*)this);
}


void _Z16PrePostHashFixer5printEsic(const PrePostHashFixer* this, int num, char symbol){
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*d]%s\n",((PrePostFixer*)this)->pre, symbol, this->precision, num, ((PrePostFixer*)this)->post);

}


void _Z16PrePostHashFixer12VirtualprintEslc(const void * this, long num, char symbol){
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->pre, symbol, ((PrePostHashFixer*)this)->precision, (double)num, ((PrePostFixer*)this)->post);
}


char _Z16PrePostHashFixer16getDefaultSymbol(const void* this){
    return HASH_DEFAULT_SYMBOL;
}


/*/// PrePostFloatDollarFixer ///////////*/

void* (*PrePostFloatDollarFixerVPTR[])(void*) = {(TYPE)_Z23PrePostFloatDollarFixerDEs, (TYPE)_Z12PrePostFixer12VirtualPrintEkc, (TYPE)_Z16PrePostHashFixer12VirtualprintEslc, (TYPE)_Z23PrePostFloatDollarFixer16getDefaultSymbol};


void _Z23PrePostFloatDollarFixerCEskcpkcp(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix){
    ((TextFormatter*)this)->PTvptr = PrePostFloatDollarFixerVPTR;
    _Z18PrePostDollarFixerCEskcpkcp((PrePostDollarFixer*)this, prefix, postfix);
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) this)->pre, ((PrePostFixer *) this)->post);
}


void _Z23PrePostFloatDollarFixerCopyCEskPrePostFloatDollarFixer(PrePostFloatDollarFixer* this,const PrePostFloatDollarFixer* other){
    ((TextFormatter*)this)->PTvptr = PrePostFloatDollarFixerVPTR;
    _Z18PrePostDollarFixer5CopyCEskPrePostDollarFixer((PrePostDollarFixer*)this,(PrePostDollarFixer*)other);
}


void _Z23PrePostFloatDollarFixerDEs(void * this){
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer *) this)->pre, ((PrePostFixer *) this)->post);
    _Z18PrePostDollarFixerDEs((PrePostDollarFixer*)this);
}


void _Z23PrePostFloatDollarFixer5printEksf(const PrePostFloatDollarFixer* this, float num){
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    _Z23PrePostFloatDollarFixer5printEksfc(this, num, '@');
}


void _Z23PrePostFloatDollarFixer5printEksfc(const PrePostFloatDollarFixer* this, float num, char symbol){
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");
    printf("%s%c%.2f%s\n", ((PrePostFixer *) this)->pre, symbol, num, ((PrePostFixer *) this)->post);
}


char _Z23PrePostFloatDollarFixer16getDefaultSymbol(const void * this){
    return FLOAT_DOLLAR_DEFAULT_SYMBOL;
}


/*/// PrePostChecker ///////////*/

void* (*PrePostCheckerVPTR[])(void*) = {(TYPE)_Z14PrePostCheckerDEs, (TYPE)_Z12PrePostFixer12VirtualPrintEkc, (TYPE)_Z16PrePostHashFixer12VirtualprintEslc, (TYPE)_Z23PrePostFloatDollarFixer16getDefaultSymbol};

void _Z14PrePostCheckerCEs(PrePostChecker* this){
    ((TextFormatter*)((DefaultTextFormatter*)((PrePostFixer*)((PrePostDollarFixer*)((PrePostFloatDollarFixer*)this)))))->PTvptr = (void **) PrePostCheckerVPTR;
    _Z23PrePostFloatDollarFixerCEskcpkcp((PrePostFloatDollarFixer*)this, "[[[[ ", " ]]]]");
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",this->_Z14PrePostChecker23PrePostFloatDollarFixerEV._Z23PrePostFloatDollarFixer18PrePostDollarFixerEV._Z18PrePostDollarFixer12prePostFixer.pre,this->_Z14PrePostChecker23PrePostFloatDollarFixerEV._Z23PrePostFloatDollarFixer18PrePostDollarFixerEV._Z18PrePostDollarFixer12prePostFixer.post);
}


void _Z14PrePostCheckerDEs(PrePostChecker* this){
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",this->_Z14PrePostChecker23PrePostFloatDollarFixerEV._Z23PrePostFloatDollarFixer18PrePostDollarFixerEV._Z18PrePostDollarFixer12prePostFixer.pre,this->_Z14PrePostChecker23PrePostFloatDollarFixerEV._Z23PrePostFloatDollarFixer18PrePostDollarFixerEV._Z18PrePostDollarFixer12prePostFixer.post);
    _Z23PrePostFloatDollarFixerDEs((PrePostFloatDollarFixer*)this);
}


void _Z14PrePostChecker24printThisSymbolUsingFuncEs(const PrePostChecker* this){
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");
    printf("Default symbol is %c\n", '@');
}


void _Z14PrePostChecker23printThisSymbolDirectlyEs(const PrePostChecker* this){
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");
    printf("Default symbol is %c\n", '@');
}


void _Z14PrePostChecker32printDollarSymbolByCastUsingFuncEs(const PrePostChecker* this){
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
    printf("Default symbol is %c\n",((GetDefaultSymbol) ((TextFormatter *) (this))->PTvptr[getDefaultSymbol])(this));
}


void _Z14PrePostChecker33printDollarSymbolByScopeUsingFuncEs(const PrePostChecker* this){
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
    printf("Default symbol is %c\n", _Z18PrePostDollarFixer16getDefaultSymbolEks((PrePostDollarFixer *) (this)));
}


void _Z14PrePostChecker31printDollarSymbolByCastDirectlyEs(const PrePostChecker* this){
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]");
    printf("Default symbol is %c\n", DEFAULT_SYMBOL);
}


void _Z14PrePostChecker32printDollarSymbolByScopeDirectlyEs(const PrePostChecker* this){
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");
    printf("Default symbol is %c\n", DEFAULT_SYMBOL);
}


/*/// Multiplier ///////////*/

void* (*MultiplierVPTR[])(void*) = {(TYPE)_Z10Multiplier8VirtualDEs, (TYPE)_Z20DefaultTextFormatter12VirtualPrintEkc};


void _Z10Multiplier8VirtualDEs(void * this){
    printf("--- Multiplier DTOR: times = %d\n", ((Multiplier*)this)->_Z10Multiplier5timesVE);
}

void _Z10Multiplier5printEs(const void * this, const char* text){
    int i;
    printf("%-60s | ", "[Multiplier::print(const char*)]");

    for (i=0; i < ((Multiplier*)this)->_Z10Multiplier5timesVE; ++i)
        printf("%s", text);
    printf("\n");
}