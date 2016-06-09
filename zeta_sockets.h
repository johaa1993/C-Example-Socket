#ifndef Zeta_Sockets_H
#define Zeta_Sockets_H
/*
#ifdef __unix__
  #error __unix__ is not supported.

#elif __linux__
  #error __linux__ is not supported.

#elif __APPLE__
  #error __APPLE__ is not supported.

#elif _WIN32
  #include "Zeta_Sockets_win32.h"
  #ifdef _WIN64
  #endif

#else
  #error Your OS is not supported.
#endif






extern int
Zeta_Sockets_Init ();

extern int
Zeta_Sockets_Close (Zeta_Sockets_Socket Item);

extern int
Zeta_Sockets_Convert_Name_To_Address4 (const char * Name, struct sockaddr_in * Address);

extern int
Zeta_Sockets_Convert_Name_To_Address6 (const char * Name, struct sockaddr_in6 * Address);

extern int
Zeta_Sockets_Convert_Name_To_Address (const char * Name, struct_Zeta_Socket_Address * Address);

extern Zeta_Sockets_Socket
Zeta_Sockets_Create_Socket_IPv4_TCP ();

extern int
Zeta_Sockets_Bind (Zeta_Sockets_Socket Socket, const struct_Zeta_Socket_Address * Address);

extern int
Zeta_Socket_Address_Set_Port (struct_Zeta_Socket_Address * Address, Zeta_Port Port);

char *
Zeta_Sockets_Init_Info (int Info)
{
  switch (Info)
  {
    case Zeta_Sockets_Init_Not_Ready:
    return "Zeta_Sockets_Init_Not_Ready";
    case Zeta_Sockets_Init_Not_Supported:
    return "Zeta_Sockets_Init_Not_Supported";
    case Zeta_Sockets_Init_Blocked:
    return "Zeta_Sockets_Init_Blocked";
    case Zeta_Sockets_Init_Max_Reached:
    return "Zeta_Sockets_Init_Max_Reached";
    default:
    return "Zeta_Sockets_Init_Successful";
  }
}

*/

#endif
