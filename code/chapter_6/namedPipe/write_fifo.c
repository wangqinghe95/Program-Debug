#include<stdio.h>
#include<stdlib.h>   // exit
#include<fcntl.h>    // O_WRONLY
#include<sys/stat.h>
#include<time.h>     // time
#include<unistd.h>

#define PIPE_NAME "fifo1"

int main()
{
# if 0
    int fd;
    int n, i;
    char buf[1024];
    time_t tp;

    printf("I am %d process.\n", getpid()); // 说明进程ID

    if((fd = open(PIPE_NAME, O_WRONLY)) < 0) // 以写打开一个FIFO
    {
        perror("Open FIFO Failed");
        exit(1);
    }

    for(i=0; i<10; ++i)
    {
        time(&tp);
        int n = sprintf(buf, "Process %d's time is %s", getpid(), ctime(&tp));
        printf("Send message: %s",buf);
        if(write(fd, buf,n+1) < 0){
            perror("write FIFO failed");
            close(fd);
            return 0;
        }
        sleep(1);
    }
#else
    printf("I am %d process.\n",getpid());

    int fd = 0;
    if((fd = open(PIPE_NAME, O_WRONLY)) < 0) // 以写打开一个FIFO
    {
        perror("Open FIFO Failed");
        exit(1);
    }

    time_t tp;
    char buf[1024] = {0};
    for(int i = 0; i < 10; ++i){
        time(&tp);
        int n = sprintf(buf, "Process %d's time is %s", getpid(), ctime(&tp));
        printf("Send message: %s",buf);
        if(write(fd, buf,n+1) < 0){
            perror("write FIFO failed");
            close(fd);
            return 0;
        }
        sleep(1);
    }
#endif
    close(fd);  // 关闭FIFO文件
    return 0;
}