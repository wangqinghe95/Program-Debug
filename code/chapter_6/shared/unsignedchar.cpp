#include<iostream>
#include<cstdio>
using namespace std;

typedef unsigned char		uint8_t;

int main(){
    uint8_t rdata[1] = {0};
    uint8_t* p = rdata;
    *p = 100;
    printf("%x\n",*p);
}