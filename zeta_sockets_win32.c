#include "zeta_sockets_win32.h"

int
Zeta_Sockets_Init ()
{
  WSADATA wsa_data;
  return WSAStartup (MAKEWORD (1,1), &wsa_data);
};



int
Zeta_Sockets_Close (Zeta_Sockets_Socket Item)
{
  int Status = 0;
  Status = shutdown (Item, SD_BOTH);
  //If no error.
  if (Status == 0)
  {
    Status = closesocket (Item);
  }
  return Status;
}

int
Zeta_Sockets_Connect_TCP_1 (Zeta_Sockets_Socket Item, char * Name, int Port)
{
  /*
  struct sockaddr_storage Address;
  int Result;
  Address.ss_family = AF_INET;
  inet_pton (AF_INET, Address_Name, &(Address.sin_addr));
  Address.sin_port = htons (Port);
  Result = connect (Item, (struct sockaddr *) (&Address), sizeof (struct sockaddr));
  */
}



int
Zeta_Sockets_Bind (Zeta_Sockets_Socket Socket, const struct sockaddr_storage * Address)
{
  int Result;
  Result = bind (Socket, (const struct sockaddr * ) Address, sizeof (struct sockaddr_storage));
  return Result;
}



Zeta_Sockets_Socket
Zeta_Sockets_Create_Socket_IPv4_TCP ()
{
  Zeta_Sockets_Socket Result;
  Result = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
  return Result;
}
