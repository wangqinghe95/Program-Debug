#include<cstdio>
#include<fcntl.h>
#include<sys/stat.h>
#include<errno.h>
#include<unistd.h>

#define PIPE_NAME "file_fifo"

int main()
{
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

    close(fd);
    return 0;
}