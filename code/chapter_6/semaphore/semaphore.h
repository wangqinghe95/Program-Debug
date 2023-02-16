#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/sem.h>
#include<cstdio>

union semun
{
    int val;
    semid_ds *buf;
    unsigned short* array;
};

int set_semvalue(int sem_id, int count);
void del_semvalue(int sem_id);
int semaphore_p(int sem_id);
int semaphore_v(int sem_id);