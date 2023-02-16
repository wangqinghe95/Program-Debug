#include<cstdio>
#include<cstdlib>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t p_pid = fork();
    if(p_pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (0 == p_pid) {
        printf("this process is child\n");
    }
    else{
        sleep(2);
        kill(p_pid,SIGKILL);
        printf("child process killed\n");
        sleep(1);
        printf("this is father process\n");
        wait(NULL);
        raise(SIGKILL);
    }
    return 0;
}