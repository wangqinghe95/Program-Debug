#include<iostream>
#include<unistd.h>
#include<cstdio>
int main()
{
    int p = 10;
    pid_t pid = fork();
    if( 0 == pid ) {
        std::cout << "hi, I'am a child process and the process id is " << getpid() << std::endl;
        // execl("./multiexec","multiexec","arg1","arg2",NULL);
        // execlp("ps","aux",NULL);
        // const char *argv[] = {"arg1","arg2"};
        const char *envp[] = {"./","/bin/" ,"/home/user/",NULL};
        execle("./multiexec","arg1","arg2",NULL,envp);
    }
    else if(pid > 0){
        std::cout << "hi, I'am a parent process and the process id is " << getpid() << std::endl;
    }
    else{
        perror("fork");
    }
    return 0;    
}