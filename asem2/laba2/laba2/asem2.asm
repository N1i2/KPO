.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO :DWORD
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD

.STACK 4096										

.CONST													

.DATA				
		numb1 dd 5
		numb2 dd 4
		wind db "Окно", 0
		result db "Результат вычислений = < >", 0 

.CODE													

main PROC												
START :													
		mov eax, numb1
		add eax, numb2
		add eax, 30h
		
		mov result+24, al

		mov [result,24], al
;			то же самое
		
		invoke MessageBoxA, 0, offset result, offset wind, 0

		push 0
		call ExitProcess
main ENDP

end main		