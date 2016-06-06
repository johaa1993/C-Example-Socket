#ifndef Zeta_sockaddr_Win32_H
#define Zeta_sockaddr_Win32_H

#include "zeta_config.h"
#include <assert.h>
#include <ws2tcpip.h>
#include <Ws2ipdef.h>

typedef u_short Zeta_Port;

int
Zeta_Sockets_Set_String_Address4 (struct sockaddr_in * Address, const char * Name);

int
Zeta_Sockets_Set_String_Address6 (struct sockaddr_in6 * Address, const char * Name);

int
Zeta_Sockets_Set_String_Address (struct sockaddr_storage * Address, const char * Name);
#define Zeta_Sockets_Set_String_Address_Successful 1

void
Zeta_Sockets_Set_Port4 (struct sockaddr_in * Address, Zeta_Port Port);

void
Zeta_Sockets_Set_Port6 (struct sockaddr_in6 * Address, Zeta_Port Port);

int
Zeta_Sockets_Set_Port (struct sockaddr_storage * Address, Zeta_Port Port);
#define Zeta_Sockets_Set_Port_Successful 1



#endif
