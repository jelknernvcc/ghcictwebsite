; Comparing two one digit numbers
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
START2: LXI     H,MSG1  ; MSG1 propts for first number
        CALL    COMSG   
        CALL    GETNUM  ; GET FIRST NUMBER
        MOV     B,A     ; STORE IN B REGISTER

START3: LXI     H,MSG2  ; MSG2 PROPTS FOR SECOND NUMBER
        CALL    COMSG   
        CALL    GETNUM  ; GETS THE SECOND NUMBER
        MOV     C,A     ; STORE IN REGISTER C

        CALL    COMPARE ; COMPARE NUMBERS

        JMP     START   ; RESTARTS PROGRAM
        

SIGNON: DB      'Number Comparison program',CR,LF,0
MSG1:   DB      'Enter the first number (0-9): ',CR,LF,0
MSG2:   DB      'Enter the second number (0-9): ',CR,LF,0
MSG3    DB      'The first number is greater.', CR, LF, 0
MSG4    DB      'The second number is greater.', CR, LF,0
MSG5    DB      'The numbers are equal.', CR, LF, 0


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


; compare routine
COMPARE:
        MOV A,B     ; Load first number
        CMP C       ; compare with second number
        JC  LESS    ; JUMP IF B < C
        JZ  EQUAL   ; JUMP IF B == C

GREATER:
        LXI H,MSG3  ; MESSAGE THAT FIRST NUBER IS GREATER 
        CALL    COMSG
        JMP DONE
LESS:
        LXI H,MSG4  ; MESSAGE THAT SECOND NUMBER IS GREATER
        CALL COMSG
        JMP DONE
EQUAL:
        LXI H,MSG5  ;MESSAGE THAT NUMBERS ARE EQUAL
        CALL COMSG

DONE:
        CALL    CCRLF   ;PRINT NEW LINES
        RET

; GETTING A SINGLE DIGIT NUMBER (ASCII TO NUMBER)
GETNUM: CALL    CI  ;READ CHARACTER FROM CONSOLE
        SUI     '0' ;CONVERTING FROM ASCII TO NUMBER BY SUBTRACTING 0 WHICH IS 48 IN DECIMAL
        RET


    
; Stack Setup
        DS      64      ; 40H locations for stack
STAK:   DB      0       ; Top of stack

        END