#include<iostream>
#include<cstdlib>
using namespace std;

void testNew()
{
    int *pNew = new int[80];
}

void testMalloc()
{
    int* pMalloc = (int*) malloc(100);
}
int main()
{
    cout << "memory test" << endl;
    testMalloc();
    cout << "test malloc end" << endl;
    testNew();
    cout << "test new end" << endl;
    return 0;
}
