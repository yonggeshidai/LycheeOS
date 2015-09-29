;��������
;usage:
;      descriptor base,limit,segattr,attribute
;      base:dd
;      limit:dd(only low 20 bits are avaiable)
;      segattr:db
;      attribute:db(lower 4 bits of higher byte are 0)
%macro descriptor 4
			dw		%2 & 0x0ffff
			dw		%1 & 0x0ffff
			db		(%1 >> 16) & 0x0ff
			db		%4 & 0x0ff
			db		(%3 & 0xf0) | ((%2 >> 16) & 0x0f)
			db		(%1 >> 24) & 0x0f
%endmacro

;��������
;usage:
;      gate offset,selector,pcount,attribute
;      offset:dd
;      selector:dw
;			   pcount:db
;      attribute:dw
%macro gate 4
			dw		%1 & 0x0ffff
			dw		%2 & 0x0ffff
			db		%3 & 0x0ff
			db		%4 & 0x0ff
			dw		(%1 >> 16) & 0x0ffff
%endmacro

;ֻ�������ݡ�����Σ�������32λ���ݻ����
DA_G4KB  equ   0x80     ;������ô�λ����ʹ��4KB�ķ������ȣ�����Ϊ�ֽ�
DA_32			equ		0x40     ;����Щλ��ʹ��32λ��

;���������ԣ�ֻ���ڴ��롢���ݶΣ����õ���D/Bλ
;��ͼ�������ֶ�
;������λ����ݶ��������������ֶ���һ����
;����ֻ����8�ֽ��е�λ�ò�ͬ
;
;|---|------|---|------------|
;|___|______|___|____________|

;��Ȩ��
DA_DPL0		equ		0x00
DA_DPL1		equ		0x20
DA_DPL2		equ		0x40
DA_DPL3		equ		0x60

;ϵͳ��
DA_SYSSEG_LDT		equ		0x82
DA_SYSGATE_TSS	equ		0x89
;��
DA_GATE_TASK   equ   0x85
DA_GATE_CALL		equ		0x8C
DA_GATE_INT			equ		0x8E
DA_GATE_TRAP		equ		0x8F

;ϵͳ����γ���
SYS_CODELEN     equ     4096*4   ;4KB,total = 16MB
;ϵͳ���ݶγ���
SYS_DATALEN     equ     4096*4   ;4KB,total = 16MB