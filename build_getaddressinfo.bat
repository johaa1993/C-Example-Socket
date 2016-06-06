@echo off
:loop
del *.exe
@cls
gcc main_getaddressinfo.c -o main_getaddressinfo.exe -lws2_32
main_getaddressinfo.exe
pause
goto loop
