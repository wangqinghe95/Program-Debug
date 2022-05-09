#include<stdio.h>

int function_return(){
    return 0;
}

int function_return_int(){
    int a = 0;
    return (int)a;
}

double func_return_double(){
    return (double)(0.0);
}

int func_return_add(){
    return 3+5;
}

int func_return_variable_add(){
    int a = 3;
    int b = 4;
    return a + b;
}

int main(){
    function_return();
    return 0;
}
