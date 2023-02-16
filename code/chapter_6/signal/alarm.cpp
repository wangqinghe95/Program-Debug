#include<cstdio>
#include<unistd.h>
int main()
{
    int seconds = alarm(5);
    printf("seconds 1 = %d\n", seconds);

    sleep(2);

    seconds = alarm(2);
    printf("second 2 = %d\n", seconds);

    while(1){}

    return 0;
}