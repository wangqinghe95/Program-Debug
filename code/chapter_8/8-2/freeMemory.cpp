#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

void useMemoryFreed()
{
    char* test = new char[10];
    const char* str = "this is a test string";
    strcpy(test,str);
    delete[] test;
    char c = test[0];
}

int main()
{
    cout << "test overflow stack satrt" << endl;
    useMemoryFreed();
    cout << "test overflow stack end" << endl;
    return 0;
}