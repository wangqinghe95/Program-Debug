#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int count = 3;
    int *p = nullptr;
    int *q = &count;
    for (int i = 0; i < 3; ++i) {
        if (i == 1) {
            *p = 1;
        }
        
        if(i == 0) {
            p = q;
        }

        if( i == 2) {
            count = 2;
        }
    }

    return 0;
}