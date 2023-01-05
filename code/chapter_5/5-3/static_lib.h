#include<iostream>

class staticlib
{
private:
    /* data */
public:
    staticlib(/* args */);
    ~staticlib();

    void printNoParam();
    void printIntParam(int param);

    int add(int num1, int num2);
    int division(int divisor, int dividend);
};
