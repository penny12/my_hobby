#include <iostream>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <error.h>
#include <cstdio>
#include <cstring>

// #include <stdio.h>                                 
// #include <sys/types.h>                               
// #include <sys/socket.h>                               
// #include <netinet/in.h>                               
                                                                                    
int                                         
main()                                       
{                                          
  int sock0;                                     
  struct sockaddr_in addr;                              
  struct sockaddr_in client;                             
  int len;                                      
  int sock;                                     
  int yes = 1;                                    
                                                                                    
  char buf[2048];                                  
  char inbuf[2048];                                 
                                                                                    
  sock0 = socket(AF_INET, SOCK_STREAM, 0);                      
  if (sock0 < 0) {                                  
    perror("socket");                             
    return 1;                                 
  }                                         
                                                                                    
  addr.sin_family = AF_INET;                             
  addr.sin_port = htons(12345);                           
  addr.sin_addr.s_addr = INADDR_ANY;                         
                                                                                    
  setsockopt(sock0,                                 
             SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(yes));           
                                                                                    
  if (bind(sock0, (struct sockaddr *)&addr, sizeof(addr)) != 0) {          
    perror("bind");                              
    return 1;                                 
  }                                         
                                                                                    
  if (listen(sock0, 5) != 0) {                            
    perror("listen");                             
    return 1;                                 
  }                                         
                                                                                    
  // 応答用HTTPメッセージ作成                            
  memset(buf, 0, sizeof(buf));                            
  snprintf(buf, sizeof(buf),                            
            "HTTP/2.0 200 OK\n"                           
            "Content-Length: 20\n"                          
            "Content-Type: text/html\n"                       
            "\n"                                   
            "HELLO\n");                               
                                                                                    
  while (1) {                                    
    len = sizeof(client);                              
    sock = accept(sock0, (struct sockaddr *)&client, (socklen_t* )&len);             
    if (sock < 0) {                                 
      perror("accept");                            
      break;                                  
    }                                        
                                                                                    
    memset(inbuf, 0, sizeof(inbuf));                         
    recv(sock, inbuf, sizeof(inbuf), 0);                       
    // 本来ならばクライアントからの要求内容をパースすべきです            
    printf("%s", inbuf);                               
                                                                                    
    // 相手が何を言おうとダミーHTTPメッセージ送信                  
    send(sock, buf, (int)strlen(buf), 0);                      
                                                                                    
    close(sock);                                   
  }                                         
                                                                                    
  close(sock0);                                   
                                                                                    
  return 0;                                     
}                                          
// #include <iostream>
// #include <arpa/inet.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <error.h>
// #include <cstdio>
// #include <cstring>
// using namespace std;

// int main(int argc, char** argv)
// {
//   int sfd;
//   struct sockaddr_in addr;
//   struct sockaddr_in client;
//   int len;
//   int sock;
//   // int n;
//   int yes = 1;

//   char buf[1024];
//   char inbuf[2048];

//   // create socket
//   sfd = socket(AF_INET, SOCK_STREAM, 0);

//   // configure socket
//   addr.sin_family = AF_INET;
//   addr.sin_port = htons(12345);
//   addr.sin_addr.s_addr = INADDR_ANY;

//   setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(yes));
  
//   if(bind(sfd, (struct sockaddr*)&addr, sizeof(addr)) != 0)
//   {
//     perror("bind");
//     return 1;
//   }

//   // wait listen connect demand port 
//   if(listen(sfd, 5) != 0)
//   {
//     perror("listen");
//     return 1;
//   }

//   memset(buf, 0, sizeof(buf));
//   snprintf(buf, sizeof(buf),
//             "HTTP/1.0 200 OK\r\n"
//             "Content-Length: 20\r\n"
//             "Content-Type: text/html\r\n"
//             "\r\n"
//             "HELLO\r\n");

//   // send message
//   while(true)
//   {
//     // cout << "ad" << endl;
//     len = sizeof(client);
//     sock = accept(sfd, (struct sockaddr *)&client, (socklen_t *)&len);

//     // cout << "accepted connection from " << inet_ntoa(client.sin_addr) << "port = " << ntohs(client.sin_port) << endl;

//     // printf("accepted connection from %s, port = %d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
//     // cout << flush;
//     if(sock < 0)
//     {
//       perror("accept");
//       break;
//     }

//     memset(inbuf, 0, sizeof(inbuf));
//     recv(sock, inbuf, sizeof(inbuf), 0);

//     printf("%s", inbuf);

//     // dummy message
//     send(sock, buf, (int)strlen(buf), 0);

//     // n = write(sock, "HELLO", 5);

//     // if(n < 1)
//     // {
//     //   perror("write");
//     //   break;
//     // }

//     // close listen end socket
//     close(sock);
//   }


//   // end session
//   close(sfd);

//   return 0;
// }
