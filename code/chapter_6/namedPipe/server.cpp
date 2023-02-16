#include<cstdio>
#include<cstring>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>
#include<errno.h>
#include<stdlib.h>   // exit

#define PIPE_NAME "file_fifo"

int main()
{
    printf("I am %d process.\n",getpid());

    int fd = 0;
    if((fd = open(PIPE_NAME,O_WRONLY)) < 0){
        perror("open FIFO error");
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

    close(fd);
    return 0;
}