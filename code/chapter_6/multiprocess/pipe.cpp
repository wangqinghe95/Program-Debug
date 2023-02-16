#include<cstdio>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int pipefd[2] = {0};

    if(-1 == pipe(pipefd)){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int cpid = fork();
    if(-1 == cpid) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (0 == cpid){
        close(pipefd[1]);
        char buf[128] = "0";

        sprintf(buf, "%d", pipefd[0]);
        execl("./pipeExec","pipeExec",buf,NULL);

        // printf("I'am a child start\n");
        // while(read(pipefd[0], &buf, 1) > 0){
        //     write(STDOUT_FILENO, &buf, 1);
        // }
        // write(STDOUT_FILENO, "\n", 1);
        // close(pipefd[0]);
        // printf("I'am a child end\n");

        exit(EXIT_SUCCESS);
    }
    else{
        close(pipefd[0]);
        printf("I'am a parent start\n");
        const char *buf = "hello, I'am parent";
        write(pipefd[1], buf, strlen(buf));
        printf("I'am a parent end\n");
        close(pipefd[1]);

        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}