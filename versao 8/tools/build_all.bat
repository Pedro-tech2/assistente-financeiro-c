@echo off
rem Compila todos os fontes da versao 8/src para output\assistente.exe
if not exist ..\output mkdir ..\output
pushd "%~dp0..\src"
"C:\\mingw64\\bin\\gcc.exe" -Wall -Wextra -g3 "analise.c" "arquivo.c" "main.c" "menu.c" "metas.c" "simulacao.c" "utils.c" -I "..\include" -o "..\output\assistente.exe"
set EXIT_CODE=%ERRORLEVEL%
popd
exit /b %EXIT_CODE%