#include "zeta_socket_address_win32.h"

int
Zeta_Socket_Address_Set_IP_String4 (struct sockaddr_in * Address, const char * Name)
{
  int Result;
  Result = inet_pton (AF_INET, Name, &(Address->sin_addr));
  return Result;
}

int
Zeta_Socket_Address_Set_IP_String6 (struct sockaddr_in6 * Address, const char * Name)
{
  int Result;
  Result = inet_pton (AF_INET6, Name, &(Address->sin6_addr));
  return Result;
}

int
Zeta_Socket_Address_Set_IP_String (struct_Zeta_Socket_Address * Address, const char * Name)
{
  int Result;
  switch (Address->ss_family)
  {
    case AF_INET:
      Result = Zeta_Socket_Address_Set_IP_String4 ((struct sockaddr_in *) Address, Name);
    break;
    case AF_INET6:
      Result = Zeta_Socket_Address_Set_IP_String6 ((struct sockaddr_in6 *) Address, Name);
    break;
    default:
      assert (0 && "Family not supported");
    break;
  }
  return Result;
}



void
Zeta_Socket_Address_Set_Family (struct_Zeta_Socket_Address * Address, Zeta_Socket_Address_Family Family)
{
  Address->ss_family = Family;
}









void
Zeta_Socket_Address_Set_Port4 (struct sockaddr_in * Address, Zeta_Port Port)
{
  Address->sin_port = htons (Port);
}

void
Zeta_Socket_Address_Set_Port6 (struct sockaddr_in6 * Address, Zeta_Port Port)
{
  Address->sin6_port = htons (Port);
}

int
Zeta_Socket_Address_Set_Port (struct_Zeta_Socket_Address * Address, Zeta_Port Port)
{
  int Result;
  switch(Address->ss_family)
  {
  case AF_INET:
    Zeta_Socket_Address_Set_Port4 ((struct sockaddr_in *) Address, Port);
    Result = 1;
  break;

  case AF_INET6:
    Zeta_Socket_Address_Set_Port6 ((struct sockaddr_in6 *) Address, Port);
    Result = 1;
  break;

  default:
    Result = 0;
  break;
  }
  return Result;
}
