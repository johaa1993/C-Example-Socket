@echo off
:loop
del *.exe
@cls
gcc main_WSAAddressToString.c -o main_WSAAddressToString.exe -lws2_32
main_WSAAddressToString.exe
pause
goto loop
