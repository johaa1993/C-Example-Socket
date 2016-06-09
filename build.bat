@echo off
:loop
del *.exe
@cls
gcc main.c zeta_sockets_win32.c zeta_socket_address_win32.c -o main.exe -lws2_32 -lws2_32 -lNtdll
main.exe
pause
goto loop
