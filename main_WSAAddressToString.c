#define WINVER 0x0A00
#define _WIN32_WINNT 0x0A00

#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <mstcpip.h>
#include <windows.h>
#include <w32api.h>



int main (void)
{

  printf ("%X\n", WINVER);
  printf ("%X\n", _WIN32_WINNT);


  struct addrinfo * Info;

  {
    WSADATA Data [1];
    int R;
    R = WSAStartup (MAKEWORD (2, 2), Data);
    assert (R == 0);
  }

  {
    struct addrinfo Hints [1];
    int R;
    ZeroMemory (Hints, sizeof (struct addrinfo));
    Hints->ai_family = AF_UNSPEC;
    Hints->ai_socktype = SOCK_STREAM;
    Hints->ai_protocol = IPPROTO_TCP;
    R = getaddrinfo ("127.0.0.1", NULL, Hints, &Info);
    assert (R == 0);
  }

  void * f = (void *) inet_pton;

  for (struct addrinfo * Index = Info; Index != NULL; Index = Index->ai_next)
  {
    printf ("Info\n");
  }

  /*
  {
    struct sockaddr_storage Destination [1];
    char R [100] = {0};
    DWORD L [1];
    WSAAddressToString ((LPSOCKADDR) Destination, sizeof (struct sockaddr_storage), NULL, R, L);
    printf ("R = \n%s", R);
  }
  */

  return 0;
}
