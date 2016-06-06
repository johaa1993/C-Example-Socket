#ifndef Zeta_Sockets_Win32_H
#define Zeta_Sockets_Win32_H

#include "zeta_config.h"
#include <assert.h>
#include <ws2tcpip.h>
#include <Ws2ipdef.h>


typedef SOCKET Zeta_Sockets_Socket;
#define Zeta_Sockets_Invalid_Socket INVALID_SOCKET


int
Zeta_Sockets_Init ();
#define Zeta_Sockets_Init_Not_Ready WSASYSNOTREADY
#define Zeta_Sockets_Init_Not_Supported WSAVERNOTSUPPORTED
#define Zeta_Sockets_Init_Blocked WSAEINPROGRESS
#define Zeta_Sockets_Init_Max_Reached WSAEPROCLIM
#define Zeta_Sockets_Init_Successful 0

int
Zeta_Sockets_Close (Zeta_Sockets_Socket Item);

int
Zeta_Sockets_Connect_TCP_1 (Zeta_Sockets_Socket Item, char * Name, int Port);


int
Zeta_Sockets_Bind (Zeta_Sockets_Socket Socket, const struct sockaddr_storage * Address);
#define Zeta_Sockets_Bind_Successful 0


Zeta_Sockets_Socket
Zeta_Sockets_Create_Socket_IPv4_TCP ();




#endif
