#include<iostream>
#include<cstdio>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    // std::cout << __FILE__ << " " << __func__ << " " << __LINE__ << std::endl;
    printf("I'am a child exec start\n");

    if(argc > 1) {
        for(int i = 0; i < argc; ++i){
            printf("argv[%d]: %s\n", i, argv[i]);
        }
    }

    int fd = atoi(argv[1]);
    char ch;
    while(read(fd,&ch,1)>0){
        write(STDOUT_FILENO, &ch, 1);
    }

    write(STDOUT_FILENO, "\n", 1);

    // char buf[128] = {0};
    // read(fd, buf, 50);
    // printf("%s\n",buf);

    close(fd);
    printf("I'am a child end\n");
    return 0;
}