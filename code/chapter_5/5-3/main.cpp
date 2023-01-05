#include<iostream>
#include"static_lib.h"
int main()
{
    staticlib CMyStaticLib;
    int a = 5;
    int b = 2;
    std::cout << "a/b = " << CMyStaticLib.division(2,5) << std::endl;
    std::cout << "a+b = " << CMyStaticLib.add(2,5) << std::endl;
    return 0;
}