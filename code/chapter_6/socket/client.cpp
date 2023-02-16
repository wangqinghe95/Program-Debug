#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstdio>
#include<cstdlib>
#include<signal.h>

int main()
{
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(9736);
    int len = sizeof(address);

    int result = connect(server_sockfd, (sockaddr*)&address, len);

    if(-1 == result){
        perror("ops: client\n");
        exit(1);
    }

    char str[1024] = {0};
    char rece_str[1024] = {0};
    printf("please input you want to type:%s",str);
    scanf("%s", str);
    write(server_sockfd, &str, 1024);
    read(server_sockfd, rece_str, 1024);

    printf("message from server:%s\n",rece_str);
    close(server_sockfd);
    return 0;
}