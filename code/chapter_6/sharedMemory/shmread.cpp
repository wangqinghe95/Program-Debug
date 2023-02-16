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
    void* shm = shmat(shmid, 0, 0);
    if(shm == (void*)-1){
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    // printf("Memory attached at %X\n",(int)shm);

    shared_use_st *st_shared = (shared_use_st*)shm;
    st_shared->written = 0;
    // read data from shared memory
    while (1)
    {
        if(st_shared->written != 0) {
            printf("read text:%s\n",st_shared->text);
            sleep(1);
            st_shared->written = 0;
            if(0 == strncmp(st_shared->text,"end",3)){
                break;
            }
        }
        else{
            sleep(1);
        }
    }

    // detach shared memory from current process
    if(-1 == shmdt(shm)){
        fprintf(stderr,"shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    // delete shared memory
    if(-1 == shmctl(shmid, IPC_RMID, 0)){
        fprintf(stderr,"shmctl failed\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}