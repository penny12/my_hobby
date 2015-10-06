#include <iostream>
#include <sys/types.h>  /* Type definitions used by many programs */
#include <sys/un.h>
#include <sys/socket.h>
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Prototypes of commonly used library functions,
                           plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h>     /* Prototypes for many system calls */
#include <errno.h>      /* Declares errno and defines error constants */
#include <string.h>     /* Commonly used string-handling functions */
using namespace std;

const int BACKLOG = 5;
#define SV_SOCK_PATH "/tmp/us_xfr"
#define BUF_SIZE 100

int errExit(const char* error)
{
  cout << "errro: " << error << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
  struct sockaddr_un addr;
  int sfd, cfd;
  ssize_t numRead;
  char buf[BUF_SIZE];

  sfd = socket(AF_UNIX, SOCK_STREAM, 0);
  if(sfd == -1)
    errExit("socket");

  if(remove(SV_SOCK_PATH) == -1 && errno != ENOENT)
  {
    char p[100];
    sprintf(p, "remove-%s", SV_SOCK_PATH);
    errExit(p);
  }

  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);

  if(bind(sfd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1)
    errExit("bind");

  if(listen(sfd, BACKLOG) == -1)
    errExit("listen");

  for(;;)
  {
    cfd = accept(sfd, NULL, NULL);
    if(cfd == -1)
      errExit("accept");

    while((numRead = read(cfd, buf, BUF_SIZE)) > 0)
      if(write(STDOUT_FILENO, buf, numRead) != numRead)
        errExit("partial/failed write");

    if(numRead == -1)
      errExit("read");

    if(close(cfd) == -1)
      errExit("close");
  }

}
