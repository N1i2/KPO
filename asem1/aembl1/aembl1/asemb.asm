.586P											;��������� �������
.MODEL FLAT, STDCALL							;������ ������, ���������� � ������
includelib kernel32.lib							;������������

ExitProcess PROTO:DWORD							;�������� ������� ��� ���������� ��������
MessageBoxA PROTO:DWORD,:DWORD,:DWORD,:DWORD	;�������� API �������

.STACK 4096										;��������� �����

.CONST											;������� ��������

.DATA											;������� ������
MB_OK EQU 2										;EQU ���������� ���������
STR1 DB "��� ������ ���������", 0				;����� � �������� ����
STR2 DB "������ ����", 0						;����� � �������� ����
HW DD ?											;������� ����� �� �����������������

.CODE											;������� ����

main PROC										;����� ����� � ����
START:											;�����
		INVOKE MessageBoxA, HW, OFFSET STR2,OFFSET STR1,MB_OK ;����� �������
	

	push -1										;��� ��������
	call ExitProcess							;���������� ������ �������� �������
main ENDP										;����� ���������

end main										;����� �����