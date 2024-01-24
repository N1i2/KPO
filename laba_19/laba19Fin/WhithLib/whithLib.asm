.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib


ExitProcess PROTO: DWORD
getmin PROTO:DWORD,:DWORD
getmax PROTO:DWORD,:DWORD

.STACK 4096

.CONST 
Arr sdword 17, 23, 45, -12, 15, 3, 43, -5, 9, 10

.DATA
min sdword ?
max sdword ?

.CODE

main PROC
START:

push lengthof Arr
push offset Arr
call getmin
mov min, eax

push lengthof Arr
push offset Arr
call getmax
mov max, eax

push 0
call ExitProcess
main ENDP

END main