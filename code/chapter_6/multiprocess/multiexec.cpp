#include<iostream>
#include<cstdio>

int main(int argc, char* argv[]){
    std::cout << __FILE__ << " " << __func__ << " " << __LINE__ << std::endl;

    if(argc > 1) {
        for(int i = 0; i < argc; ++i){
            printf("argv[%d]: %s\n", i, argv[i]);
        }
    }
    return 0;
}