#ifndef Zeta_Socket_Address_Win32_H
#define Zeta_Socket_Address_Win32_H

#include "zeta_config.h"
#include <assert.h>
#include <ws2tcpip.h>
#include <Ws2ipdef.h>

typedef u_short Zeta_Port;
typedef struct sockaddr_storage struct_Zeta_Socket_Address;
typedef short Zeta_Socket_Address_Family;
#define Zeta_Socket_Address_Family_IPv4 AF_INET
#define Zeta_Socket_Address_Family_IPv6 AF_INET6

int
Zeta_Socket_Address_Set_IP_String (struct_Zeta_Socket_Address * Address, const char * Name);
#define Zeta_Socket_Address_Set_IP_String_Successful 1

int
Zeta_Socket_Address_Set_Port (struct_Zeta_Socket_Address * Address, Zeta_Port Port);
#define Zeta_Socket_Address_Set_Port_Successful 1

void
Zeta_Socket_Address_Set_Family (struct_Zeta_Socket_Address * Address, Zeta_Socket_Address_Family Family);



#endif
