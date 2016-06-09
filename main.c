#include "zeta_sockets_win32.h"
#include "zeta_socket_address_win32.h"
#include <stdio.h>

int main (void)
{
  struct_Zeta_Socket_Address Address [1];
  Zeta_Sockets_Socket Socket;

  {
    int Result;
    Result = Zeta_Sockets_Init ();
    assert ("Socket init failed." && Result == Zeta_Sockets_Init_Successful);
  }

  {
    int Result;
    Zeta_Socket_Address_Set_Family (Address, Zeta_Socket_Address_Family_IPv4);
    Result = Zeta_Socket_Address_Set_IP_String (Address, "127.0.0.1");
    assert ("Setting IP string failed." && Result == Zeta_Socket_Address_Set_IP_String_Successful);
  }

  {
    int Result;
    Result = Zeta_Socket_Address_Set_Port (Address, 100);
    assert ("Setting port failed." && Result == Zeta_Socket_Address_Set_Port_Successful);
  }

  {
    Socket = Zeta_Sockets_Create_Socket_IPv4_TCP ();
    assert ("Creating IPv4 TCP socket failed." && Socket != Zeta_Sockets_Invalid_Socket);
  }

  {
    int Result;
    Result = Zeta_Sockets_Bind (Socket, Address);
    assert ("Binding socket failed." && Result == Zeta_Sockets_Bind_Successful);
  }

  {
    int Result;
    Result = Zeta_Sockets_Listen (Socket, 10);
    assert ("Listen socket failed." && Result == Zeta_Sockets_Listen_Successful);
  }

  {
    Zeta_Sockets_Socket Client;
    #define Buffer_Size 512
    char Buffer [Buffer_Size];
    int Count;
    Client = Zeta_Sockets_Accept (Socket, NULL);
    assert ("Accepting client failed." && Client != Zeta_Sockets_Invalid_Socket);
    while (1)
    {
      Count = Zeta_Sockets_Receive (Client, Buffer, Buffer_Size, 0);
      assert ("Receiving from client failed." && Count != Zeta_Sockets_Receive_Error);
      printf ("Count: %i\n", Count);
      if (Count == 0)
      {
        break;
      }
      else
      {
        printf ("%.*s", Count, Buffer);
      }
    }
    Zeta_Sockets_Close (Client);
  }


  return 0;
}
