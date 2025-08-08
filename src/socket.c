#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    struct sockaddr_in serverInfo = {0}; // sockect address info
    serverInfo.sin_family = PF_INET;     // IPv4 sockect
    serverInfo.sin_addr.s_addr = 0;
    serverInfo.sin_port = htons(5555);

    int fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("Socekt failed!\n");
        return -1;
    }
    printf("%d\n", fd);
    return 0;
}