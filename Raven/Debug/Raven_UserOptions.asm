; Listing generated by Microsoft (R) Optimizing Compiler Version 18.00.30723.0 

	TITLE	C:\Users\Menyueru\Desktop\Barcamp2014\Raven\Raven_UserOptions.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMTD
INCLUDELIB OLDNAMES

PUBLIC	??0Raven_UserOptions@@AAE@XZ			; Raven_UserOptions::Raven_UserOptions
PUBLIC	?Instance@Raven_UserOptions@@SAPAV1@XZ		; Raven_UserOptions::Instance
EXTRN	@__security_check_cookie@4:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
EXTRN	___CxxFrameHandler3:PROC
EXTRN	___security_cookie:DWORD
;	COMDAT ?instance@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4V2@A
_BSS	SEGMENT
?instance@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4V2@A DB 0eH DUP (?) ; `Raven_UserOptions::Instance'::`2'::instance
_BSS	ENDS
;	COMDAT ?$S1@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4IA
_BSS	SEGMENT
?$S1@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4IA DD 01H DUP (?) ; `Raven_UserOptions::Instance'::`2'::$S1
_BSS	ENDS
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
xdata$x	SEGMENT
__unwindtable$?Instance@Raven_UserOptions@@SAPAV1@XZ DD 0ffffffffH
	DD	FLAT:__unwindfunclet$?Instance@Raven_UserOptions@@SAPAV1@XZ$0
__ehfuncinfo$?Instance@Raven_UserOptions@@SAPAV1@XZ DD 019930522H
	DD	01H
	DD	FLAT:__unwindtable$?Instance@Raven_UserOptions@@SAPAV1@XZ
	DD	2 DUP(00H)
	DD	2 DUP(00H)
	DD	00H
	DD	01H
xdata$x	ENDS
; Function compile flags: /Odtp /RTCsu
; File c:\users\menyueru\desktop\barcamp2014\raven\raven_useroptions.cpp
_TEXT	SEGMENT
__$EHRec$ = -12						; size = 12
?Instance@Raven_UserOptions@@SAPAV1@XZ PROC		; Raven_UserOptions::Instance

; 5    : {

	push	ebp
	mov	ebp, esp
	push	-1
	push	__ehhandler$?Instance@Raven_UserOptions@@SAPAV1@XZ
	mov	eax, DWORD PTR fs:0
	push	eax
	mov	eax, DWORD PTR ___security_cookie
	xor	eax, ebp
	push	eax
	lea	eax, DWORD PTR __$EHRec$[ebp]
	mov	DWORD PTR fs:0, eax

; 6    :   static Raven_UserOptions instance; 

	mov	eax, DWORD PTR ?$S1@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4IA
	and	eax, 1
	jne	SHORT $LN1@Instance
	mov	ecx, DWORD PTR ?$S1@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4IA
	or	ecx, 1
	mov	DWORD PTR ?$S1@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4IA, ecx
	mov	DWORD PTR __$EHRec$[ebp+8], 0
	mov	ecx, OFFSET ?instance@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4V2@A
	call	??0Raven_UserOptions@@AAE@XZ		; Raven_UserOptions::Raven_UserOptions
	mov	DWORD PTR __$EHRec$[ebp+8], -1
$LN1@Instance:

; 7    :   return &instance;

	mov	eax, OFFSET ?instance@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4V2@A

; 8    : }

	mov	ecx, DWORD PTR __$EHRec$[ebp]
	mov	DWORD PTR fs:0, ecx
	pop	ecx
	add	esp, 12					; 0000000cH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_TEXT	ENDS
text$x	SEGMENT
__unwindfunclet$?Instance@Raven_UserOptions@@SAPAV1@XZ$0:
	mov	eax, DWORD PTR ?$S1@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4IA
	and	eax, -2					; fffffffeH
	mov	DWORD PTR ?$S1@?1??Instance@Raven_UserOptions@@SAPAV2@XZ@4IA, eax
	ret	0
__ehhandler$?Instance@Raven_UserOptions@@SAPAV1@XZ:
	mov	edx, DWORD PTR [esp+8]
	lea	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [edx-4]
	xor	ecx, eax
	call	@__security_check_cookie@4
	mov	eax, OFFSET __ehfuncinfo$?Instance@Raven_UserOptions@@SAPAV1@XZ
	jmp	___CxxFrameHandler3
text$x	ENDS
?Instance@Raven_UserOptions@@SAPAV1@XZ ENDP		; Raven_UserOptions::Instance
; Function compile flags: /Odtp /RTCsu
; File c:\users\menyueru\desktop\barcamp2014\raven\raven_useroptions.cpp
_TEXT	SEGMENT
_this$ = -4						; size = 4
??0Raven_UserOptions@@AAE@XZ PROC			; Raven_UserOptions::Raven_UserOptions
; _this$ = ecx

; 24   : {}

	push	ebp
	mov	ebp, esp
	push	ecx
	mov	DWORD PTR [ebp-4], -858993460		; ccccccccH
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+1], 0
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+2], 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+3], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+4], 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+5], 0
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+6], 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+7], 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+8], 0
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+9], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+10], 0
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+11], 0
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+12], 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+13], 0
	mov	eax, DWORD PTR _this$[ebp]
	mov	esp, ebp
	pop	ebp
	ret	0
??0Raven_UserOptions@@AAE@XZ ENDP			; Raven_UserOptions::Raven_UserOptions
_TEXT	ENDS
END
