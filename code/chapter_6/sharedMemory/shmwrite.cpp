#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<sys/shm.h>
#include<cstring>

#define TEXT_SZ 2048
struct shared_use_st{
    int written;
    char text[TEXT_SZ];
};

int main()
{

    // create shared memory
    int shmid = shmget((key_t)1234, sizeof(shared_use_st), 0666|IPC_CREAT);
    if(-1 == shmid){
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }

    // attach shared memory to current process
    void* shm = shmat(shmid, (void*)0, 0);
    if(shm == (void*)-1){
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    // printf("Memory attached at %X\n",(int)shm);

    // write data to shared memory
    shared_use_st *st_shared = (shared_use_st*)shm;
    char buffer[BUFSIZ+1] = {0};
    while (1)
    {
        if(st_shared->written == 1){
            sleep(1);
            printf("Wait...\n");
        }

        printf("Enter data: ");
        fgets(buffer, BUFSIZ, stdin);
        strncpy(st_shared->text, buffer, TEXT_SZ);
        st_shared->written = 1;
        if(0 == strncmp(buffer,"end",3)){
            break;
        }
    }

    if(shmdt(shm) == -1){
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    sleep(2);
    exit(EXIT_SUCCESS);
}