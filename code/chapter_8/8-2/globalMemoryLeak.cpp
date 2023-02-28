#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

int g_data[100] = {0};

void overflowStack()
{
    int data = g_data[101];
}

int main()
{
    cout << "test overflow stack satrt" << endl;
    overflowStack();
    cout << "test overflow stack end" << endl;
    return 0;
}