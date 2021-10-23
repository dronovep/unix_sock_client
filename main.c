#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SOCKFILENAME "/tmp/msock.1"



int main() {

    const char* message  = "mother father sister brother";
    const char* message2 = "Kia Mi So La Vida macarena a";

    struct sockaddr_un sock_address = {
            AF_UNIX,
            SOCKFILENAME
    };

    struct sockaddr_un cl_addr;
    socklen_t addrlen;

    int sock = socket(PF_UNIX, SOCK_STREAM, 0);
    int connect_result = connect(sock, (struct sockaddr*)&sock_address, sizeof(sock_address));
    send(sock, message, strlen(message), 0);
    send(sock, message2, strlen(message2), 0);

    printf("socket descriptor = %d\n", sock);
    printf("connect_result = %d\n", connect_result);
    printf("Work finished!\n");
    return 0;
}