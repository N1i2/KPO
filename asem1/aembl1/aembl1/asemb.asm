.586P											;системная команда
.MODEL FLAT, STDCALL							;Модель памяти, соглашение о вызове
includelib kernel32.lib							;компоновщику

ExitProcess PROTO:DWORD							;прототип функции для завершения процесса
MessageBoxA PROTO:DWORD,:DWORD,:DWORD,:DWORD	;прототип API функции

.STACK 4096										;выделение стека

.CONST											;сигмент констант

.DATA											;сегмент данных
MB_OK EQU 2										;EQU определяет константу
STR1 DB "Моя первая программа", 0				;стора с нулевого бита
STR2 DB "Привет всем", 0						;стора с нулевого бита
HW DD ?											;двойное слово не инициализированно

.CODE											;сигмент кода

main PROC										;точка входа в мейн
START:											;метка
		INVOKE MessageBoxA, HW, OFFSET STR2,OFFSET STR1,MB_OK ;вызов функции
	

	push -1										;код возврата
	call ExitProcess							;завершение любого процесса виндоус
main ENDP										;конец процедуры

end main										;конец мейна