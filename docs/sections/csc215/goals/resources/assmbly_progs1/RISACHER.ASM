; AHH.ASM – CP/M I/O Subroutines with Chapter 14 Enhancements
; ---------------------------------------------------------------

; ASCII Characters
CR      EQU     0DH     ; Carriage Return
LF      EQU     0AH     ; Line Feed
CTRLZ   EQU     1AH     ; Operator Interrupt

; CP/M BDOS Functions
RCONIN  EQU     1       ; Read Console (into A)
WCONOUT EQU     2       ; Write (A) to Console
RBUF    EQU     10      ; Read Buffered Input

; CP/M Addresses
RBOOT   EQU     0       ; Reboot CP/M System
BDOS    EQU     5       ; System Call Entry
TPA     EQU     100H    ; Transient Program Area

        ORG     TPA     ; Assemble program for TPA

; Main Program Start
START:  LXI     SP,STAK ; Set up user's stack
START1: CALL    CCRLF   ; Start a new line
        LXI     H,SIGNON ; With sign-on message
        CALL    COMSG
START2: CALL    TWOCR          ; Double space lines
        CALL    SPMSG          ; Prompt for test
        DB      'ENTER A LINE OF TEXT:', CR, LF, 0
        CALL    CIMSG          ; Input Console Message into INBUF
        CALL    REVERSE
        CALL    TWOCR
        CALL    SPMSG
        DB      'REVERSED STRING:', CR, LF, 0
        LXI     H,INBUF+2      ; Load Reversed String
        CALL    COMSG         ; Display Reversed String
        CALL    TWOCR

SIGNON: DB      'STRING REVERSAL PROGRAM', CR, LF, 0

; Console Character Input Routine
CI:     PUSH    B       ; Save registers
        PUSH    D
        PUSH    H
        MVI     C,RCONIN ; Read function
        CALL    BDOS
        ANI     7FH      ; Mask to 7 bits
        POP     H        ; Restore registers
        POP     D
        POP     B
        RET

; Console Output Character Routine
CO:     PUSH    B       ; Save registers
        PUSH    D
        PUSH    H
        MVI     C,WCONOUT ; Select function
        MOV     E,A     ; Character to E
        CALL    BDOS    ; Output by CP/M
        POP     H       ; Restore registers
        POP     D
        POP     B
        RET

; Carriage Return and Line Feed Routine
TWOCR:  CALL    CCRLF
CCRLF:  MVI     A,CR
        CALL    CO
        MVI     A,LF
        JMP     CO

; Print Message Pointed to by HL to Console
COMSG:  MOV     A,M     ; Get A character
        ORA     A       ; Check if zero
        RZ              ; Return on zero
        CALL    CO      ; Else output the character
        INX     H       ; Point to the next character
        JMP     COMSG   ; Repeat

; Input Console Message into INBUF
CIMSG:  PUSH    B       ; Save registers
        PUSH    D
        PUSH    H
        LXI     H,INBUF+1 ; Zero character counter
        MVI     M,0
        DCX     H
        MVI     M,80    ; Set maximum line length
        XCHG            ; INBUF pointer to DE registers
        MVI     C,RBUF  ; Set up read INBUF function
        CALL    BDOS    ; Input a line
        MOV     E,M     ; Get character count
        LXI     H,INBUF+1 ; Point HL to start
        MOV     E,M     ; INTO LSB OF DE REGISTER PAIR
        MVI     D,0     ; Zero MSB
        DAD     D       ; Add length to start
        INX     H       ; Point to end
        MVI     M,0     ; Insert null terminator
        POP     H       ; Restore registers
        POP     D
        POP     B
        RET

; Routine to display a message pointed to by the stack
SPMSG:  XTHL                   ; Get "RETURN ADDRESS" to HL
        XRA     A              ; Clear flags and accumulator
        ADD     M              ; Get one message character
        INX     H              ; Point to the next character
        XTHL                   ; Restore stack for return
        RZ                     ; Return if done (zero)
        CALL    CO             ; Else display character
        JMP     SPMSG          ; And do another

REVERSE:
        PUSH    B
        PUSH    D
        PUSH    H

FINDEND:
        LXI H, INBUF+2      ; HL points to the start of the string
FINDLOOP:
        MOV A, M            ; Load the value at [HL]
        ORA A               ; Check if the value is zero (null terminator)
        JZ SETUPSW          ; If null, jump to SETUPSWAP
        INX H               ; Increment HL to point to the next character
        JMP FINDLOOP        ; Repeat the loop
SETUPSW:
        MOV D, H            ; Copy HL to DE (DE now points to the null terminator)
        MOV E, L
        LXI H, INBUF+2      ; Reset HL to the start of the string
        DCX     D             ; DE now points to last character
REVLOOP:
        ; Compare HL and DE
        MOV     A,H
        CMP     D
        JC      SWAPCH    ; If H < D, swap characters
        JNZ     ENDREV   ; If H > D, done
        MOV     A,L
        CMP     E
        JC      SWAPCH    ; If L < E, swap characters
        JNZ     ENDREV   ; If L > E, done
        JMP     ENDREV   ; If H=L and D=E, reversal complete
SWAPCH:
        ; Swap Characters at HL and DE
        MOV     A,M           ; A = [HL]
        PUSH    H             ; Save HL
        MOV     H,D           ; H = D
        MOV     L,E           ; L = E
        MOV     B,M           ; B = [DE]
        MOV     M,A           ; [DE] = A
        POP     H             ; Restore HL
        MOV     M,B           ; [HL] = B
        INX     H             ; HL++
        DCX     D             ; DE--
        JMP     REVLOOP      ; Repeat Loop
ENDREV:
        POP H
        POP D
        POP B
        RET

INBUF:  DS      83            ; Line input INBUF

; Stack Setup
        DS      128            ; 40H locations for stack
STAK:   DB      0             ; Top of stack

        END