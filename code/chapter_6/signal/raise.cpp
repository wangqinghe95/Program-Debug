#include<signal.h>
#include<cstdio>
#include<cstdlib>

void signalHandle1(int para){
    int sum = 0;
    printf("in  %s, and num : %d\n", __func__, para);
}

void signalHandle2(int para){
    printf("in  %s, and num : %d", __func__, para);
    exit(0);
}

int main()
{
    signal(SIGUSR1, signalHandle1);
    signal(SIGUSR2, signalHandle2);

    // while(1){
        printf("press any key to send a signall\n");
        // getchar();
        raise(SIGUSR1);
    // }

    return 0;
}