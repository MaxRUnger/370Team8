@echo off
REM Build Lyfestyle project with MinGW Makefiles (NO Ninja)
cd /d "%~dp0"
if exist build rmdir /s /q build
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
pause
