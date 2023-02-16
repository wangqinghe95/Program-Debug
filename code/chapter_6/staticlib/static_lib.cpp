#include"static_lib.h"
#include<cstdio>
using namespace std;


staticlib::staticlib(/* args */)
{
}

staticlib::~staticlib()
{
}

void staticlib::printNoParam()
{
    cout << __func__ << __LINE__ << endl;
}
void staticlib::printIntParam(int param)
{
    cout << __func__ << __LINE__  << endl;
}

int staticlib::add(int num1, int num2)
{
    cout << __func__ << " " << __LINE__ << " " << endl;
    int result = num1 + num2;
    return result;
}
int staticlib::division(int divisor, int dividend)
{
    if(divisor == 0) {
        cout << "Error: the divisor can't be zero";
        return -999;
    }

    return (int)(dividend/divisor);
}