#include "zeta_sockets_win32.h"
#include "zeta_sockaddr_win32.h"
#include <stdio.h>

int main (void)
{
  struct sockaddr_storage Address [1];
  Zeta_Sockets_Socket Socket;

  {
    int Result;
    Result = Zeta_Sockets_Init ();
    assert (Result == Zeta_Sockets_Init_Successful);
  }

  {
    int Result;
    Address->ss_family = AF_INET;
    Result = Zeta_Sockets_Set_String_Address (Address, "127.0.0.1");
    assert (Result == Zeta_Sockets_Set_String_Address_Successful);
  }

  {
    int Result;
    Result = Zeta_Sockets_Set_Port (Address, 100);
    assert (Result == Zeta_Sockets_Set_Port_Successful);
  }

  {
    Socket = Zeta_Sockets_Create_Socket_IPv4_TCP ();
    assert (Socket != Zeta_Sockets_Invalid_Socket);
  }

  {
    int Result;
    Result = Zeta_Sockets_Bind (Socket, Address);
    assert (Result == Zeta_Sockets_Bind_Successful);
  }




  printf ("a = %u\n", sizeof (Zeta_Sockets_Socket));
  printf ("a = %u\n", sizeof (unsigned int));
  return 0;
}
