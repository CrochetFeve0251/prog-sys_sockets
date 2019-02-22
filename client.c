#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc , char *argv[])
{
  int socket_desc;
  struct sockaddr_in server;
  char * message , server_reply[2000];
  socket_desc = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  server.sin_addr.s_addr = inet_addr("172.217.18.195");
  server.sin_family = AF_INET;
  server.sin_port = htons(80);

  connect(socket_desc,(struct sockaddr *)&server,sizeof(server));
  puts("Connected\n");
  message = "GET / HTTP/1.1\r\n\r\n";
  send(socket_desc,message,strlen(message),0);

  puts("Data sent\n");

  read(socket_desc,server_reply,2000);
  printf("%s\n",server_reply);
  return 0;
}
