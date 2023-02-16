#include<cstdlib>
#include<pthread.h>
#include<cstdio>

void *func(void* arg){
    printf("func run....\n");
    return NULL;
}

int main()
{
    pthread_t tid1, tid2;
    int err = pthread_create(&tid1, NULL, func, NULL);  // 以默认的线程属性创建线程，并且将该线程命名为 tid1，执行函数名为 func 的函数
    if(0 != err){
        printf("thread_create failed\n");
    }
    else{
        printf("thread_create\n");
    }

    pthread_join(tid1,NULL);    // 等待名为 tid1 的函数执行结束 
    return 0;
}