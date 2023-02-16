#include"semaphore.h"

// init semaphore
int set_semvalue(int sem_id, int count){
    semun sem_union;
    sem_union.val = count;
    if(semctl(sem_id, 0, SETVAL, sem_union) == -1){
        printf("set_semvalue failed\n");
        return -1;
    }
    return 0;
}

void del_semvalue(int sem_id){
    semun sem_union;
    if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1) {
        printf("del_semvalue failed\n");
    }
}

int semaphore_p(int sem_id){
    sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;
    sem_b.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sem_b, 1) == -1){
        printf("semphore_p failed\n");
        return -1;
    }
    return 0;
}

int semaphore_v(int sem_id){
    sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;
    sem_b.sem_flg = SEM_UNDO;
    if(semop(sem_id, &sem_b, 1) == -1) {
        printf("semaphore_v failed\n");
        return -1;
    }
    return 0;
}
