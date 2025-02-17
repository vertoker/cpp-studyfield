#include <iostream>

int main()
{
    int i = 42;
    int* pi = &i;
    int** ppi = &pi;
    int*** pppi = &ppi;
    int**** ppppi = &pppi;
    int***** pppppi = &ppppi;
    int****** ppppppi = &pppppi;
    int******* pppppppi = &ppppppi;
    int******** ppppppppi = &pppppppi;
    int********* pppppppppi = &ppppppppi;
    int********** ppppppppppi = &pppppppppi;
    int*********** pppppppppppi = &ppppppppppi;
    int************ ppppppppppppi = &pppppppppppi;
    int************* pppppppppppppi = &ppppppppppppi;
    int************** ppppppppppppppi = &pppppppppppppi;
    int*************** pppppppppppppppi = &ppppppppppppppi;
    int**************** ppppppppppppppppi = &pppppppppppppppi;
    int***************** pppppppppppppppppi = &ppppppppppppppppi;
    int****************** ppppppppppppppppppi = &pppppppppppppppppi;
    int******************* pppppppppppppppppppi = &ppppppppppppppppppi;
    int******************** ppppppppppppppppppppi = &pppppppppppppppppppi;
    int********************* pppppppppppppppppppppi = &ppppppppppppppppppppi;
    int********************** ppppppppppppppppppppppi = &pppppppppppppppppppppi;
    int*********************** pppppppppppppppppppppppi = &ppppppppppppppppppppppi;
    int************************ ppppppppppppppppppppppppi = &pppppppppppppppppppppppi;
    int************************* pppppppppppppppppppppppppi = &ppppppppppppppppppppppppi;
    int************************** ppppppppppppppppppppppppppi = &pppppppppppppppppppppppppi;
  //and*how*tf*does*it*even*exist* pppppppppppppppppppppppppppi = &ppppppppppppppppppppppppppi;
    std::cout << **************************ppppppppppppppppppppppppppi << std::endl; // 42
    return 0;
}