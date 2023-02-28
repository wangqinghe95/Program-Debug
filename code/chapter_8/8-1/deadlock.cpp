#include<cstdio>
#include<cstdlib>

#include<mutex>
#include<thread>

std::mutex mutex1;
std::mutex mutex2;

int data1;
int data2;

int doWork_1(){
    printf("thread function one start\n");
    std::lock_guard<std::mutex> locker1(mutex1);
    data1++;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::lock_guard<std::mutex> locker2(mutex2);
    data2++;
    printf("thread function one start\n");
    return 0;
}

int doWork_2()
{
    printf("thread function two start\n");

    std::lock_guard<std::mutex> locker2(mutex2);
    data2++;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::lock_guard<std::mutex> locker1(mutex1);
    data1++;

    printf("thread function two start\n");
    return 0;   
}

int main()
{
    std::thread t1(doWork_1);
    std::thread t2(doWork_2);
    t1.join();
    t2.join();
    printf("main thread end\n");
    return 0;
}
