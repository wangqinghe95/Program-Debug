#include<cstdio>
#include<cstdlib>
#include<sys/msg.h>
#include<errno.h>
#include<cstring>

struct msg_st
{
    int type;
    char text[BUFSIZ];
};

int main()
{
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if(-1 == msgid) {
        fprintf(stderr, "Msgget failed with error:%d", errno);
        exit(EXIT_FAILURE);
    }

    msg_st data;
    char buffer[BUFSIZ] = {0};
    while(1){
        printf("Input text: ");
        fgets(buffer, BUFSIZ, stdin);
        data.type = 1;
        strcpy(data.text, buffer);
        if(-1 == msgsnd(msgid, (void*)&data,BUFSIZ, 0)){
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }

        if(0 == strncmp(buffer,"end", 3)){
            break;
        }
    }

    return 0;
}