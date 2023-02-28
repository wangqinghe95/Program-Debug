#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

void overflowHead()
{
    char* test = new char[10];
    const char* str = "this is a test string";
    strcpy(test,str);
    delete[] test;
}

int main()
{
    cout << "test overflow heap satrt" << endl;
    overflowHead();
    cout << "test overflow heap end" << endl;
    return 0;
}