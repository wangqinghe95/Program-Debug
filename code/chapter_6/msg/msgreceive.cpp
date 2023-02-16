#include<cstdio>
#include<cstdlib>
#include<sys/msg.h>
#include<errno.h>
#include<cstring>

struct msg_st
{
    int length;
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
    int len = 0;
    while(1){
        if(-1 == msgrcv(msgid, (void*)&data, BUFSIZ, len, 0)){
            fprintf(stderr, "msgrcv failed with errno:%d\n",errno);
            exit(EXIT_FAILURE);
        }
        printf("you receive: %s\n",data.text);
        if(0 == strncmp(data.text, "end", 3)){
            break;
        }
    }

    if(-1 == msgctl(msgid, IPC_RMID, 0)) {
        fprintf(stderr, "msgclt(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}