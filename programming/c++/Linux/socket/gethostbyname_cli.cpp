#include <iostream>
#include <cstdio>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
using namespace std;

int main(int argc, char** argv)
{
  struct sockaddr_in cfd;
  int sock;
  char buf[32];
  int n;
  char *deststr;
  unsigned int **addrptr;

  if(argc != 2) {
    printf("Usage : %s dest\n", argv[0]);
    return 1;
  }
  deststr = argv[1];

  sock = socket(AF_INET, SOCK_STREAM, 0);

  cfd.sin_family = AF_INET;
  cfd.sin_port = htons(12345);

  cfd.sin_addr.s_addr = inet_addr(deststr);
  if(cfd.sin_addr.s_addr == 0xffffffff)
  {
    struct hostent *host;
    host = gethostbyname(deststr);
    if(host == NULL)
    {
      return 1;
    }

    addrptr = (unsigned int **)host->h_addr_list;

    while(*addrptr != NULL)
    {
      cfd.sin_addr.s_addr = *(*addrptr);

      // if success connect() after exit loop
      if(connect(sock, (struct sockaddr *) &cfd, sizeof(cfd)) == 0) {
        break;
      }
      addrptr++;
    }
  } else {
    if(connect(sock, (struct sockaddr* ) &cfd, sizeof(cfd)) != 0) {
      perror("connect");
      return 1;
    }
  }

  // get data from cfd
  memset(buf, 0, sizeof(buf));
  n = read(sock, buf, sizeof(buf));

  printf("%d, %s\n", n, buf);
  close(sock);

  return 0;
}
