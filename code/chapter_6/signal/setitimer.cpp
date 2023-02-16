#include<cstdio>
#include<signal.h>
#include<cstdlib>
#include<sys/time.h>


static int times = 0;
void mysignal(int num){
    printf("times : %d -- recv signal : %d\n", times++, num);
}

int main()
{
    signal(SIGALRM, mysignal);

    itimerval neval;
    neval.it_interval.tv_sec = 2;
    neval.it_interval.tv_usec = 0;

    neval.it_value.tv_sec = 5;
    neval.it_value.tv_usec = 0;

    int ret = setitimer(ITIMER_REAL, &neval, NULL);
    printf("start alarm\n");

    if(-1 == ret) {
        perror("setimer");
        exit(0);
    }

    // while(1){}
    getchar();

    return 0;
}
