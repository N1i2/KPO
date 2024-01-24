.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA

MB_OK	EQU 0
STR1	DB "Программа", 0
HW		DD ?
sh0 DW 120
sh1 DW -120
sh2 DW 32536
ush0 DW 33000
ush1 DW 1464
.CODE

main PROC

START: 
	push 0
	call ExitProcess
main ENDP
end main
