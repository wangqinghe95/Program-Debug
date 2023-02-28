#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

void overflowStack()
{
    int test[10] = {0};
    int a = test[11];
}

int main()
{
    cout << "test overflow stack satrt" << endl;
    overflowStack();
    cout << "test overflow stack end" << endl;
    return 0;
}