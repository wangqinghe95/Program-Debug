#include<iostream>
#include"static_lib.h"
// #include"./test/add.h"
int main()
{
    staticlib CMyStaticLib;
    CMyStaticLib.printNoParam();
    CMyStaticLib.printIntParam(10);

    CMyStaticLib.division(2,5);

    return 0;
}