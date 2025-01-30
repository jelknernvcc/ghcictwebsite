; Marin McCormack 2024-11-21
; Comparing two one digit numbers
; ASCII Characters
CR      EQU     0DH      ; Carriage Return
LF      EQU     0AH      ; Line Feed
CTRLZ   EQU     1AH      ; Operator Interrupt

; CP/M BDOS Functions
RCONIN  EQU     1        ; Read Console (into A)
WCONOUT EQU     2        ; Write (A) to Console
RBUF    EQU     10       ; Read Buffered Input

; CP/M Addresses
RBOOT   EQU     0        ; Reboot CP/M System
BDOS    EQU     5        ; System Call Entry
TPA     EQU     100H     ; Transient Program Area

        ORG     TPA      ; Assemble program for TPA

; Main Program Start
START:  LXI     SP,STAK  ; Set up user's stack
START1: CALL    CCRLF    ; Start a new line
        LXI     H,SIGNON ; With sign-on message
        CALL    COMSG
START2: LXI     H,MSG1   ; MSG1 prompts for first number
        CALL    COMSG   
        CALL    GETNUM   ; Get first number
        MOV     B,A      ; Store in b register
        CAll    CCRLF

START3: LXI     H,MSG2   ; MSG2 prompts for second number
        CALL    COMSG   
        CALL    GETNUM   ; Gets the second number
        MOV     C,A      ; Store in register C
        CALL    CCRLF
        CALL    COMPARE  ; Compare numbers

        JMP     START    ; Restarts program
        

SIGNON: DB      'Number Comparison program',CR,LF,0
MSG1:   DB      'Enter the first number (0-9): ',CR,LF,0
MSG2:   DB      'Enter the second number (0-9): ',CR,LF,0
MSG3    DB      'The first number is greater.', CR, LF, 0
MSG4    DB      'The second number is greater.', CR, LF,0
MSG5    DB      'The numbers are equal.', CR, LF, 0


; Console Character Input Routine
CI:     PUSH    B        ; Save registers
        PUSH    D
        PUSH    H
        MVI     C,RCONIN  ; Read function
        CALL    BDOS
        ANI     7FH       ; Mask to 7 bits
        POP     H         ; Restore registers
        POP     D
        POP     B
        RET

; Console Output Character Routine
CO:     PUSH    B         ; Save registers
        PUSH    D
        PUSH    H
        MVI     C,WCONOUT ; Select function
        MOV     E,A       ; Character to E
        CALL    BDOS      ; Output by CP/M
        POP     H         ; Restore registers
        POP     D
        POP     B
        RET

; Carriage Return and Line Feed Routine
CCRLF:  MVI     A,CR
        CALL    CO
        MVI     A,LF
        JMP     CO

; Print Message Pointed to by HL to Console
COMSG:  MOV     A,M       ; Get A character
        ORA     A         ; Check if zero
        RZ                ; Return on zero
        CALL    CO        ; Else output the character
        INX     H         ; Point to the next character
        JMP     COMSG     ; Repeat


; compare routine
COMPARE:
        MOV A,B           ; Load first number
        CMP C             ; compare with second number
        JC  LESS          ; Jump if B < C
        JZ  EQUAL         ; Jump if B == C

GREATER:
        LXI H,MSG3        ; Message that first nuber is greater 
        CALL    COMSG
        JMP DONE
LESS:
        LXI H,MSG4        ; Message that second number is greater
        CALL COMSG
        JMP DONE
EQUAL:
        LXI H,MSG5        ; Message that numbers are equal
        CALL COMSG

DONE:
        CALL    CCRLF     ; Print new lines
        RET

; Getting a single digit number (ASCII to number)
GETNUM: CALL    CI        ; Read character from console
        SUI     '0'       ; Converting from ASCII to number by subtracting 0
                          ' which is 48 in decimal
        RET

; Stack Setup
        DS      64        ; 40H locations for stack
STAK:   DB      0         ; Top of stack

        END

