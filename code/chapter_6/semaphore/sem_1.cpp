#include"semaphore.h"

int main()
{
    key_t key = ftok("./tmp",2);
    int sem_id = semget(key, 1, 0666 | IPC_CREAT);
    set_semvalue(sem_id,0);

    for(int i = 0; i < 10; ++i){
        semaphore_p(sem_id);
        printf("sem1 semaphore_p: %d\n",i);
    }

    printf("%d -- finished\n", getpid());

    del_semvalue(sem_id);
    return 0;
}

