#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

int main()
{
    struct sockaddr_in serverInfo = {0}; // sockect address info
    struct sockaddr_in clientInfo = {0}; // client address info
    int clientSize = 0;

    serverInfo.sin_family = PF_INET; // IPv4 sockect
    serverInfo.sin_addr.s_addr = 0;
    serverInfo.sin_port = htons(5555);

    int fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("Socekt failed!\n");
        return -1;
    }
    printf("%d\n", fd);

    // bind
    if (bind(fd, (struct sockaddr *)&serverInfo, sizeof(serverInfo)) == -1)
    {
        perror("Binding failed!\n");
        close(fd);
        return -1;
    }
    printf("Successfully bind a sockect!\n");

    // listen
    if (listen(fd, 0) == -1)
    {
        perror("Listen failed!\n");
        close(fd);
        return -1;
    }
    printf("Successfully listen for further messages!\n");

    // accept
    int cfd = accept(fd, (struct sockaddr *)&clientInfo, (socklen_t *)&clientSize);
    if (cfd == -1)
    {
        perror("Failed to accept!\n");
        close(fd);
        return -1;
    }
    printf("Successfully accept!\n");
    close(cfd);

    return 0;
}