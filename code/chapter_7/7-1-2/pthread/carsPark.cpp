#include<cstdio>
#include<cstdlib>
#include<pthread.h>
#include<unistd.h>

#define NUM_THREADS 4
#define ONE_SECOND 1000000
#define RANGE 10
#define PERIOD 2

struct CarPark{
    int* mPCarPark;
    int mNCarParkSize;
    int mNCarParkOccuiped;
    int mNNextInPosition;
    int mNNextOutPosition;
    int mNCarInTotal;
    int mNCarOutTotal;
    pthread_mutex_t mMutexLock;
    pthread_cond_t mCondEmptyPositionInPark;
    pthread_cond_t mCondCarInPark;
    pthread_barrier_t mBar;
};

void initCarPark(CarPark& carPark, int size);
void* handleCarIn(void* carParkIn);
void* handleCarOut(void* carParkOut);
void* handleMonitor(void* carParkIn);

int main(int argc ,char* argv[]){
    printf("car park version 1.0\n");
    if(argc != 2) {
        printf("Usage: %s carpark size not afferent\n", argv[0]);
        return 0;
    }

    CarPark outpark;
    initCarPark(outpark, atoi(argv[1]));

    pthread_t car_in, car_out, m;
    pthread_t car_in1, car_out1;

    pthread_create(&car_in, NULL, handleCarIn, (void*)&outpark);
    pthread_create(&car_out, NULL, handleCarOut, (void*)&outpark);
    pthread_create(&car_in1, NULL, handleCarIn, (void*)&outpark);
    pthread_create(&car_out1, NULL, handleCarOut, (void*)&outpark);
    pthread_create(&m, NULL, handleMonitor, (void*)&outpark);

    pthread_join(car_in, NULL);
    pthread_join(car_out, NULL);
    pthread_join(car_in1, NULL);
    pthread_join(car_out1, NULL);
    pthread_join(m, NULL);

    return 0;
}

void* handleMonitor(void* carParkIn)
{
    CarPark *tmp = (CarPark*)carParkIn;

    while (1)
    {
        sleep(PERIOD);
        pthread_mutex_lock(&tmp->mMutexLock);

        printf("Delta:%d\n", tmp->mNCarInTotal - tmp->mNCarOutTotal - tmp->mNCarParkOccuiped);
        printf("Number of cars in carpark : %d\n", tmp->mNCarParkOccuiped);
        pthread_mutex_unlock(&tmp->mMutexLock);
    }

    return ((void*) NULL);
    
}

void* handleCarOut(void* carParkOut)
{
    CarPark *tmp = (CarPark*)carParkOut;
    pthread_barrier_wait(&tmp->mBar);

    unsigned int seed;
    while (1)
    {
        usleep(rand_r(&seed) % ONE_SECOND);
        pthread_mutex_lock(&tmp->mMutexLock);

        while(tmp->mNCarParkOccuiped == 0) {
            pthread_cond_wait(&tmp->mCondCarInPark, &tmp->mMutexLock);
        }

        tmp->mNCarParkOccuiped--;
        tmp->mNNextOutPosition++;
        tmp->mNCarOutTotal %= tmp->mNCarParkSize;
        tmp->mNCarOutTotal++;

        pthread_cond_signal(&tmp->mCondEmptyPositionInPark);
        pthread_mutex_unlock(&tmp->mMutexLock);
    }

    return ((void*)NULL);
    
}

void* handleCarIn(void* carParkIn)
{
    CarPark* tmp = (CarPark*)carParkIn;

    pthread_barrier_wait(&tmp->mBar);

    unsigned int seed;
    while (1)
    {
        usleep(rand_r(&seed) % ONE_SECOND);
        pthread_mutex_lock(&tmp->mMutexLock);
        while (tmp->mNCarParkOccuiped == tmp->mNCarParkSize)
        {
            pthread_cond_wait(&tmp->mCondEmptyPositionInPark, &tmp->mMutexLock);
        }

        tmp->mPCarPark[tmp->mNNextInPosition] = rand_r(&seed) % RANGE;
        tmp->mNCarParkOccuiped++;
        tmp->mNNextInPosition++;
        tmp->mNNextInPosition %= tmp->mNCarParkSize;
        tmp->mNCarInTotal++;

        pthread_cond_signal(&tmp->mCondCarInPark);
        pthread_mutex_unlock(&tmp->mMutexLock);
    }
    
    return ((void*)NULL);
}

void initCarPark(CarPark& carPark, int size)
{
    carPark.mNCarInTotal = carPark.mNCarOutTotal = carPark.mNCarParkOccuiped = carPark.mNNextInPosition = carPark.mNNextOutPosition = 0;
    carPark.mNCarParkSize = size;
    carPark.mPCarPark = (int*)malloc(size * sizeof(carPark.mPCarPark));
    if(NULL == carPark.mPCarPark){
        perror("car park malloc error");
        exit(1);
    }

    pthread_barrier_init(&carPark.mBar, NULL, NUM_THREADS);

    srand((unsigned int) getpid());
    pthread_mutex_init(&carPark.mMutexLock, NULL);
    pthread_cond_init(&carPark.mCondCarInPark, NULL);
    pthread_cond_init(&carPark.mCondEmptyPositionInPark, NULL);
}