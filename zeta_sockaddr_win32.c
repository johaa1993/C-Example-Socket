#include "zeta_sockaddr_win32.h"

int
Zeta_Sockets_Set_String_Address4 (struct sockaddr_in * Address, const char * Name)
{
  int Result;
  Result = inet_pton (AF_INET, Name, &(Address->sin_addr));
  return Result;
}

int
Zeta_Sockets_Set_String_Address6 (struct sockaddr_in6 * Address, const char * Name)
{
  int Result;
  Result = inet_pton (AF_INET6, Name, &(Address->sin6_addr));
  return Result;
}




#define Zeta_Sockets_Set_String_Address_Successful 1

int
Zeta_Sockets_Set_String_Address (struct sockaddr_storage * Address, const char * Name)
{
  int Result;
  switch (Address->ss_family)
  {
    case AF_INET:
      Result = Zeta_Sockets_Set_String_Address4 ((struct sockaddr_in *) Address, Name);
    break;
    case AF_INET6:
      Result = Zeta_Sockets_Set_String_Address6 ((struct sockaddr_in6 *) Address, Name);
    break;
    default:
      assert (0 && "Family not supported");
    break;
  }
  return Result;
}













void
Zeta_Sockets_Set_Port4 (struct sockaddr_in * Address, Zeta_Port Port)
{
  Address->sin_port = htons (Port);
}

void
Zeta_Sockets_Set_Port6 (struct sockaddr_in6 * Address, Zeta_Port Port)
{
  Address->sin6_port = htons (Port);
}

int
Zeta_Sockets_Set_Port (struct sockaddr_storage * Address, Zeta_Port Port)
{
  int Result;
  switch(Address->ss_family)
  {
  case AF_INET:
    Zeta_Sockets_Set_Port4 ((struct sockaddr_in *) Address, Port);
    Result = 1;
  break;

  case AF_INET6:
    Zeta_Sockets_Set_Port6 ((struct sockaddr_in6 *) Address, Port);
    Result = 1;
  break;

  default:
    Result = 0;
  break;
  }
  return Result;
}
