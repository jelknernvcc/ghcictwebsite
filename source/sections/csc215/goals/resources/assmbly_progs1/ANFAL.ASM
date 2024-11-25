; GET THE SMALLER NUMBER! REMIX OF MARIN
CR      EQU     0DH     
LF      EQU     0AH     
CTRLZ   EQU     1AH     

; CP/M BDOS Functions
RCONIN  EQU     1       
WCONOUT EQU     2       
RBUF    EQU     10      

; CP/M Addresses
RBOOT   EQU     0       
BDOS    EQU     5      
TPA     EQU     100H    

        ORG     TPA     

; Main Program Start
START:  LXI     SP,STAK ; Set up user's stack
START1: CALL    CCRLF   ; Start a new line
        LXI     H,SIGNON ; With sign-on message
        CALL    COMSG
START2: LXI     H,MSG1  ; MSG1 prompts for first number
        CALL    COMSG   
        CALL    GETNUM  ; GET FIRST NUMBER
        MOV     B,A     ; STORE IN B REGISTER
        CALL    CCRLF

START3: LXI     H,MSG2  ; MSG2 prompts for second number
        CALL    COMSG   
        CALL    GETNUM  ; GETS THE SECOND NUMBER
        MOV     C,A     ; STORE IN REGISTER C
        CALL    CCRLF
        CALL    COMPARE ; COMPARE NUMBERS

        JMP     START   ; RESTARTS PROGRAM
        

SIGNON: DB      'Number Comparison program (CTRL + Z to Exit)',CR,LF,0
MSG1:   DB      'Enter the first number (0-9): ',CR,LF,0
MSG2:   DB      'Enter the second number (0-9): ',CR,LF,0
MSG3:   DB      'The first number is smaller.', CR, LF, 0
MSG4:   DB      'The second number is smaller.', CR, LF, 0
MSG5:   DB      'The numbers are equal.', CR, LF, 0


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


; Compare routine
COMPARE:
        MOV A,B     ; Load first number
        CMP C       ; Compare with second number
        JC  FIRST   ; Jump if B < C
        JZ  EQUAL   ; Jump if B == C

SECOND:
        LXI H,MSG4  ; Message that second number is smaller
        CALL    COMSG
        JMP DONE
FIRST:
        LXI H,MSG3  ; Message that first number is smaller
        CALL    COMSG
        JMP DONE
EQUAL:
        LXI H,MSG5  ; Message that numbers are equal
        CALL    COMSG

DONE:
        CALL    CCRLF   ; Print new lines
        RET

; GETTING A SINGLE DIGIT NUMBER (ASCII TO NUMBER)
GETNUM: CALL    CI  
        CPI     CTRLZ
        JZ      RBOOT
        SUI     '0' ; Converting from ASCII to number by subtracting 0 which is 48 in decimal
        RET


    
; Stack Setup
        DS      64      
STAK:   DB      0       

        END
