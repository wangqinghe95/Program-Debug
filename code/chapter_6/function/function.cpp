#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Student{
    char name[10];
    int age;
}stu;

int getAgeNoParam()
{
    int age = 35;
    return age;
}

int getAge(int* nAge)
{
    int age = 15;
    *nAge = age;
    return age;
}

Student* callFunctionWithStruct(Student *pStu, Student struStu)
{
    Student* pTmpStu = pStu;

    char name[] = "changed name";
    memcpy(pTmpStu->name,name,strlen(name));

    int age = 20;
    pTmpStu->age = age;

    age = getAge(&age);

    return pTmpStu;    
}

void callFunctionWithStructCaller()
{
    char name[] = "wang.luis";
    memcpy(stu.name,name,sizeof(name));
    stu.age = 10;
    Student* pStu = callFunctionWithStruct(&stu, stu);

    return;
}

void callFunctionWithBasicData(int n_value, char * ch_str, int* arr_num)
{
    int l_nValue = n_value;
    const char* l_pStr = ch_str;
    int* l_pArrNum = arr_num; 

    callFunctionWithStructCaller();
}


int main(){
    int n_value = 10;
    char ch_str[] = "this is char string";
    int arr_number[] = {10,20,30};

    callFunctionWithBasicData(n_value, ch_str, arr_number);

    return 0;
}