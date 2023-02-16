#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

#define PIPE_NAME "fifo1"

int main()
{
#if 0
    int fd;
    int len;
    char buf[1024];

    if(mkfifo(PIPE_NAME, 0666) < 0 && errno!=EEXIST) // 创建FIFO管道
        perror("Create FIFO Failed");

    if((fd = open(PIPE_NAME, O_RDONLY)) < 0)  // 以读打开FIFO
    {
        perror("Open FIFO Failed");
        exit(1);
    }

    while((len = read(fd, buf, 1024)) > 0) // 读取FIFO管道
        printf("Read message: %s", buf);
#else
    if(mkfifo(PIPE_NAME, 0666) < 0 && errno != EEXIST){
        perror("Create FIFO Failed");
    }

    int fd = open(PIPE_NAME, O_RDONLY);
    if(fd < 0){
        perror("Open FIFO failed");
        return -1;
    }

    int len = 0;
    char buf[1024] = {0};
    while((len = read(fd,buf,1024)) > 0){
        printf("Read Mesage: %s",buf);
    }
#endif
    close(fd);  // 关闭FIFO文件
    return 0;
}