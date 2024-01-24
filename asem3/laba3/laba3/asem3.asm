.586P

.MODEL FLAT, STDCALL
includelib kornel32.lib

ExitProcess PROTO: DWORD

.STACK 4096

.CONST

.DATA
myBytes BYTE 10h, 20h, 30h, 40h
myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
myDoubles DWORD 1, 2, 3, 4, 5, 6
myPointer DWORD myDoubles

Arr BYTE 2, 4, 6, 7, 9, 1, 5
Arr2 BYTE 2, 4, 6, 7, 9, 1, 0

.CODE

main PROC
START:
	mov ESI, 0
	mov EAX, myDoubles[ESI + 1] ;? EAX адрес первого элемента
	mov EDX, [myDoubles + ESI] ;? EDX сам првый элемент

	xor EAX, EAX

	add AL, [Arr]
	add AL, [Arr + 1]
	add AL, [Arr + 2]
	add AL, [Arr + 3]
	add AL, [Arr + 4]
	add AL, [Arr + 5]
	add AL, [Arr + 6]

	xor EAX, EAX
	mov EBX, 1

CYCLE:
	cmp EAX, 7
	je ENDOFCYCLE
	
	cmp [Arr + EAX], 0
	je TRUE
	jne FALSE

TRUE:
	add EBX, -1
	jmp ENDOFCYCLE

FALSE:
	add EAX, 1
	loop CYCLE

ENDOFCYCLE:


	push 0
	CALL ExitProcess

main ENDP
end main