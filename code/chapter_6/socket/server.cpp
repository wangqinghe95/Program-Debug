#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstdio>
#include<cstdlib>
#include<signal.h>

int main()
{
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(9736);

    bind(server_sockfd, (sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_sockfd, 5);

    signal(SIGCHLD, SIG_IGN);

    while (1)
    {
        // char ch = '\0';
        char str[1024] = {0};
        socklen_t  client_len = sizeof(client_addr);
        printf("Server waiting\n");
        int client_fd = accept(server_sockfd, (sockaddr*)&client_addr, &client_len);

        if(0 == fork()){
            read(client_fd, &str, 1024);
            printf("receive message from client_fd : %d, message : %s\n", client_fd, str);
            sleep(1);
            write(client_fd, str, 1024);
            close(client_fd);
            exit(0);
        }
        else{
            close(client_fd);
        }
    }
    
}