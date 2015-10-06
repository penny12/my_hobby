#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <error.h>
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
  int sfd;
  struct sockaddr_in addr;
  struct sockaddr_in client;
  int len;
  int sock;
  int n;

  // create socket
  sfd = socket(AF_INET, SOCK_STREAM, 0);

  // configure socket
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = INADDR_ANY;
  if(bind(sfd, (struct sockaddr*)&addr, sizeof(addr)) != 0)
  {
    perror("bind");
    return 1;
  }

  // wait listen connect demand port 
  listen(sfd, 5);


  // send message
  while(true)
  {
    len = sizeof(client);
    sock = accept(sfd, (struct sockaddr *)&client, (socklen_t *)&len);

    if(sock < 0)
    {
      perror("accept");
      break;
    }

    n = write(sock, "HELLO", 5);

    if(n < 1)
    {
      perror("write");
      break;
    }

    // close listen end socket
    close(sock);
  }


  // end session
  close(sfd);

  return 0;
}
