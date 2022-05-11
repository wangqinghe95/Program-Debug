#include<stdio.h>

int func_add(int first_number, int second_number){
    return first_number + second_number;
}

int func_sub(int first_number, int second_number){
    return first_number - second_number;
}

int func_mul(int first_number,int second_number)
{
    return first_number * second_number;
}

int func_div(int first_number,int second_number)
{
    if (0 == second_number) {
        return second_number;
    }
    return first_number / second_number;
}

int func_and(int first_number,int second_number)
{
    return first_number & second_number;
}

int func_or(int first_number,int second_number)
{
    return first_number | second_number;
}

int func_xor(int first_number,int second_number)
{
    return first_number ^ second_number;
}

int func_if(int first_number,int second_number)
{
    if (first_number > second_number) {
        return first_number;
    }
    else {
        return second_number;
    }
}


void func_operation(){
    int first_number = 10;
    int second_number = 2;

    int res_add = func_add(first_number,second_number);     // addition
    int res_sub = func_sub(first_number, second_number);    // substraction
    int res_mul = func_mul(first_number, second_number);    // multiply
    int res_div = func_div(first_number, second_number);    // division

    int res_and = func_and(first_number,second_number);     // and
    int res_or = func_or(first_number,second_number);       // or
    int res_xor = func_xor(first_number, second_number);    // xor

    int res_if = func_if(first_number, second_number);      // if 
}

int main(){

}