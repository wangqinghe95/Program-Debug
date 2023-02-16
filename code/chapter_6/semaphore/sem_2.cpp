#include"semaphore.h"
/*
union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */
};
*/
int main()
{
    key_t key = ftok("./tmp",2);
    int sem_id = semget(key, 1, 0666 | IPC_CREAT);

    for(int i = 0; i < 10; ++i){
        printf("sem2 semaphore_v i:%d\n",i);
        semaphore_v(sem_id);
        sleep(1);
    }

    printf("%d -- finished\n",getpid());
    return 0;
}