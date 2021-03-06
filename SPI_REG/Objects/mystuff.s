; generated by Component: ARM Compiler 5.06 update 1 (build 61) Tool: ArmCC [4d35ad]
; commandline ArmCC [--c99 --split_sections --debug -c --asm -o.\objects\mystuff.o --depend=.\objects\mystuff.d --cpu=Cortex-M3 --apcs=interwork -O3 --diag_suppress=9931 -ID:\ele\STM\STM32F103\Projects\SPI_REG\RTE -ID:\ele\STM\STM32F103\Projects\SPI_REG\RTE\Device\STM32F103C8 -IC:\Keil_v5\ARM\PACK\ARM\CMSIS\4.5.0\CMSIS\Include -IC:\Keil_v5\ARM\PACK\Keil\STM32F1xx_DFP\2.0.0\Device\Include -D__UVISION_VERSION=518 -D_RTE_ -DSTM32F10X_MD --omf_browse=.\objects\mystuff.crf mystuff.c]
        THUMB
        REQUIRE8
        PRESERVE8

        AREA ||i.GpioConfig||, CODE, READONLY, ALIGN=1

GpioConfig PROC
        PUSH     {r4,lr}
        MOVS     r3,#0
        B        |L1.10|
|L1.6|
        ADDS     r3,r3,#4
        UXTH     r3,r3
|L1.10|
        LSRS     r1,r1,#1
        BNE      |L1.6|
        CMP      r3,#0x1c
        BLS      |L1.24|
        SUBS     r3,r3,#0x20
        UXTH     r3,r3
        ADDS     r0,r0,#4
|L1.24|
        LDR      r1,[r0,#0]
        MOVS     r4,#0xf
        LSLS     r4,r4,r3
        BICS     r1,r1,r4
        LSLS     r2,r2,r3
        ORRS     r2,r2,r1
        STR      r2,[r0,#0]
        POP      {r4,pc}
        ENDP


        AREA ||.arm_vfe_header||, DATA, READONLY, NOALLOC, ALIGN=2

        DCD      0x00000000

;*** Start embedded assembler ***

#line 1 "mystuff.c"
	AREA ||.rev16_text||, CODE
	THUMB
	EXPORT |__asm___9_mystuff_c_bff1bb0f____REV16|
#line 388 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include\\cmsis_armcc.h"
|__asm___9_mystuff_c_bff1bb0f____REV16| PROC
#line 389

 rev16 r0, r0
 bx lr
	ENDP
	AREA ||.revsh_text||, CODE
	THUMB
	EXPORT |__asm___9_mystuff_c_bff1bb0f____REVSH|
#line 402
|__asm___9_mystuff_c_bff1bb0f____REVSH| PROC
#line 403

 revsh r0, r0
 bx lr
	ENDP
	AREA ||.rrx_text||, CODE
	THUMB
	EXPORT |__asm___9_mystuff_c_bff1bb0f____RRX|
#line 587
|__asm___9_mystuff_c_bff1bb0f____RRX| PROC
#line 588

 rrx r0, r0
 bx lr
	ENDP

;*** End   embedded assembler ***

        EXPORT GpioConfig [CODE]

        IMPORT ||Lib$$Request$$armlib|| [CODE,WEAK]

        ATTR FILESCOPE
        ATTR SETVALUE Tag_ABI_PCS_wchar_t,2
        ATTR SETVALUE Tag_ABI_enum_size,1
        ATTR SETVALUE Tag_ABI_optimization_goals,3
        ATTR SETSTRING Tag_conformance,"2.06"
        ATTR SETVALUE AV,18,1

        ASSERT {ENDIAN} = "little"
        ASSERT {INTER} = {TRUE}
        ASSERT {ROPI} = {FALSE}
        ASSERT {RWPI} = {FALSE}
        ASSERT {IEEE_FULL} = {FALSE}
        ASSERT {IEEE_PART} = {FALSE}
        ASSERT {IEEE_JAVA} = {FALSE}
        END
