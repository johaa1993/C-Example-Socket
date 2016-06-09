#ifndef Zeta_Sockets_Win32_H
#define Zeta_Sockets_Win32_H

#include "zeta_config.h"
#include "zeta_socket_address_win32.h"
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
Zeta_Sockets_Bind (Zeta_Sockets_Socket Socket, const struct_Zeta_Socket_Address * Address);
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms737550
#define Zeta_Sockets_Bind_Successful 0


Zeta_Sockets_Socket
Zeta_Sockets_Create_Socket_IPv4_TCP ();

int
Zeta_Sockets_Listen (Zeta_Sockets_Socket Socket, int Max_Pending_Connection_Count);
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms739168
#define Zeta_Sockets_Listen_Successful 0


Zeta_Sockets_Socket
Zeta_Sockets_Accept (Zeta_Sockets_Socket Socket, struct_Zeta_Socket_Address * Address);
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms737526


int
Zeta_Sockets_Receive  (Zeta_Sockets_Socket Socket, char * Buffer, int Length, int Flags);
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms737526
#define Zeta_Sockets_Receive_Error SOCKET_ERROR





#endif
