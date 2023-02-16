#include<cstdio>
#include<cstdlib>
#include<pthread.h>
#include<cstring>

void* thread(void* arg){
    char* buffer = (char*)arg;
    printf("the data from main and print in thread '%s'\n", buffer);
    char* ret = (char*)malloc(100);
    strcpy(ret,"test data from thread");
    pthread_exit(ret);
}

int main(){
    pthread_t pid;
    char buffer[1024] = "test data from main";
    pthread_create(&pid, NULL, thread, (void*)buffer);
    void* ret = NULL;
    pthread_join(pid,&ret);
    printf("the data from thread and print in main  '%s'\n", (char*)ret);
    return 0;
}