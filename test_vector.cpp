#include "BVector.h"
#include "list"



void testVecDfltCtor(){
    std::cout<<"---------------------------------testVecDfltCtor\n";
    Vector<int> Vint1{};
    std::cout<<Vint1;
    std::cout<<"Succeeded!!!\n\n";
}


void testVecCtor(){
    std::cout<<"---------------------------------testVecCtor\n";
    int i = 3;
    Vector<int> Vint2(5);
    Vector<double > Vint3(9);
    std::cout<<Vint2;
    std::cout<<Vint3;
    std::cout<<"Succeeded!!!\n\n";
}


void testVecItrCtor(){
    int arr[] = {1,2,3,4};
    int i1 = arr[0];
    int *i2 = arr+3;

}


void testVecCCtor(){
    std::cout<<"---------------------------------testVecCCtor\n";
    Vector<int> Vint4(2);
    const Vector<int>& Vint5(Vint4);
    std::cout<<Vint4;
    std::cout<<"Succeeded!!!\n\n";

}

void testVecAssigment(){
    std::cout<<"---------------------------------testVecAssigment\n";
    Vector<int> Vint5(2);
    Vector<int> Vint6(2);
    Vint6 = Vint5;
    std::cout<<Vint5;
    std::cout<<Vint6;
    std::cout<<"Succeeded!!!\n\n";
}


Vector<int> Vint5(2);

void testIndexOperator1(){
    std::cout<<"---------------------------------testIndexOperator1\n";
    std::cout<<Vint5[1]<<std::endl;
    std::cout<<"Succeeded!!!\n\n";
}


void testIndexOperator2(){
    std::cout<<"---------------------------------testIndexOperator2\n";
    Vint5[1] = 9;
    std::cout<<Vint5[1]<<std::endl;
    std::cout<<"Succeeded!!!\n\n";
}


void testAt1(){
    std::cout<<"---------------------------------testAt1\n";
    std::cout<<Vint5.at(1)<<std::endl;
    std::cout<<"Succeeded!!!\n\n";
}


void testAt2(){
    std::cout<<"---------------------------------testAt2\n";
    Vint5.at(1)=5;
    std::cout<<Vint5.at(1)<<std::endl;
    std::cout<<"Succeeded!!!\n\n";

}


void testFront1(){
    std::cout<<"---------------------------------testFront1\n";
    std::cout<<Vint5.front()<<std::endl;
    std::cout<<"Succeeded!!!\n\n";
}


void testFront2(){
    std::cout<<"---------------------------------testFront2\n";
    Vint5.front() = 1;
    std::cout<<Vint5.front()<<std::endl;
    std::cout<<"Succeeded!!!\n\n";
}


void testBack1(){
    std::cout<<"---------------------------------testBack1\n";
    std::cout<<Vint5.back()<<std::endl;
    std::cout<<"Succeeded!!!\n\n";
}


void testBack2(){
    std::cout<<"---------------------------------testBack2\n";
    Vint5.back() = 1;
    std::cout<<Vint5.back()<<std::endl;
    std::cout<<"Succeeded!!!\n\n";
}


void testData1(){
    std::cout<<"---------------------------------testData1\n";
    for(size_t i = 0 ; i<Vint5.size() ; i++){
        std::cout<<(Vint5.data())[i]<<" ";
    }
    std::cout<<"\nSucceeded!!!\n\n";
}


void testData2(){
    std::cout<<"---------------------------------testData2\n";

    for(size_t i = 0 ; i<Vint5.size() ; i++) {
        (Vint5.data())[i] = 99;
    }
    for(size_t i = 0 ; i<Vint5.size() ; i++) {
        std::cout << (Vint5.data())[i] << " ";
    }
    std::cout<<"\nSucceeded!!!\n\n";
}


void testAssign1(){
    std::cout<<"---------------------------------testAssign1\n";

    std::cout<<"Succeeded!!!\n\n";
}


void testSize(){
    std::cout<<"---------------------------------testSize\n";
    std::cout<<Vint5.size();
    std::cout<<"\nSucceeded!!!\n\n";
}


void testMax_size(){
    std::cout<<"---------------------------------testMax_size\n";
   size_t i=18446744073709551615;
   std::cout<<i<<"\n";
    std::cout<<Vint5.max_size();
    std::cout<<"\nSucceeded!!!\n\n";
}


void testCapacity(){
    std::cout<<"---------------------------------testCapacity\n";
    std::cout<<Vint5.capacity();
    std::cout<<"\nSucceeded!!!\n\n";
}


void testResize(){
    std::cout<<"---------------------------------testResize\n";
    std::cout<<"Before:\n";

    for(size_t i = 0 ; i<Vint5.capacity() ; i++) {
        std::cout << (Vint5.data())[i] << " ";
    }
    Vint5.resize(6);

    std::cout<<"\nAfter:\n";

    for(size_t i = 0 ; i<Vint5.capacity() ; i++) {
        std::cout << (Vint5.data())[i] << " ";
    }
    std::cout<<"\nSucceeded!!!\n\n";
}


void testEmpty(){
    std::cout<<"---------------------------------testEmpty\n";
    if(Vint5.empty()){
        std::cout<<"True";
    }

    else{
        std::cout<<"False";
    }
    std::cout<<"\nSucceeded!!!\n\n";
}


void testReserve(){
    std::cout<<"---------------------------------testReserve\n";
    std::cout<<"Before:\n";

    for(size_t i = 0 ; i<Vint5.capacity() ; i++) {
        std::cout << (Vint5.data())[i] << " ";
    }
    Vint5.reserve(12);

    std::cout<<"\nAfter:\n";

    for(size_t i = 0 ; i<Vint5.capacity() ; i++) {
        std::cout << (Vint5.data())[i] << " ";
    }
    std::cout<<"\nSucceeded!!!\n\n";
}


void testPush_back(){
    std::cout<<"---------------------------------testPush_back\n";
    std::cout<<"Before:\n";
    std::cout<<Vint5;
    Vint5.push_back(2);
    std::cout<<"\nAfter:\n";
    std::cout<<Vint5;
    std::cout<<"Succeeded!!!\n\n";
}


void testPop_back(){
    std::cout<<"---------------------------------testPop_back\n";

    std::cout<<"Before:\n";
    std::cout<<Vint5;
    Vint5.pop_back();
    std::cout<<"\nAfter:\n";
    std::cout<<Vint5;
    std::cout<<"Succeeded!!!\n\n";
}


void testClear(){
    std::cout<<"---------------------------------testClear\n";

    std::cout<<"Before:\n";
    std::cout<<Vint5;
    Vint5.clear();
    std::cout<<"\nAfter:\n";
    std::cout<<Vint5;
    std::cout<<"Succeeded!!!\n\n";
}


void testSwap(){
    std::cout<<"---------------------------------testSwap\n";
    Vector<int> vInt2(7);


    std::cout<<"vector 1 Before:\n";
    std::cout<<Vint5;
    std::cout<<"vector 2 Before:\n";
    std::cout<<vInt2;

    vInt2.swap(Vint5);

    std::cout<<"vector 1 After:\n";
    std::cout<<Vint5;
    std::cout<<"vector 2 After:\n";
    std::cout<<vInt2;
    std::cout<<"Succeeded!!!\n\n";
}



void toMain(){

    testVecDfltCtor();
    testVecCtor();
    /*testVecItrCtor();*/
    testVecCCtor();
    testVecAssigment();
    testIndexOperator1();
    testIndexOperator2();
    testAt1();
    testAt2();
    testFront1();
    testFront2();
    testBack1();
    testBack2();
    testData1();
    testData2();
    /*testAssign1();*/
    testSize();
    testMax_size();
    testCapacity();
    testResize();
    testEmpty();
    testReserve();
    testPush_back();
    testPop_back();
    testClear();
    testSwap();

}