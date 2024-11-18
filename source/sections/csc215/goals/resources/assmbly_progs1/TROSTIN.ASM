; CREATOR: TROSTIN GELES

; ASCII CHARACTERS
CR              EQU     0DH             ; CARRIAGE RETURN
LF              EQU     0AH             ; LINE FEED
SQT             EQU     27H             ; SINGLE QUOTE

; CP/M BDOS FUNCTIONS
RCONF           EQU     1               ; READ CON: INTO A
WCONF           EQU     2               ; WRITE A TO CON:
RBUFF           EQU     10              ; READ A CONSOLE LINE

; CP/M ADDRESSES
RBOOT           EQU     0               ; RE-BOOT CP/M SYSTEM
BDOS            EQU     5               ; SYSTEM CALL ENTRY
TPA             EQU     100H            ; TRANSIENT PROGRAM AREA

                ORG     TPA             ; ASSEMBLE PROGRAM FOR TPA

; PROGRAM
START           LXI     SP,STAK         ; SET UP USER'S STACK
START1:         CALL    TWOCR           ; DOUBLE SPACE LINES
                CALL    SPMSG           ; DISPLAY SIGN-ON MESSAGE
                DB      'WELCOME TO TROSTIN',SQT,'S MADLIB V1 PROGRAM',CR,LF,0
START2:         CALL    TWOCR           ; DOUBLE SPACE LINES
                CALL    PERNEWPROMPT    ; PROMPT FOR A NEW PERSON
                CALL    COMSG           ; ECHO PROMPT BACK TO USER
                CALL    SPMSG           ; DISPLAY RESPONSE MESSAGE
                DB      ' WALKED TO THE STORE IN HIS NEW OUTFIT.',0
                CALL    ADJNEWPROMPT
                CALL    SPMSG           ; DISPLAY RESPONSE MESSAGE
                DB      'THE CASHIER SAID THEIR OUTFIT WAS ',0
                CALL    COMSG           ; ECHO PROMPT BACK TO USER
                CALL    PERIOD          ; OUTPUT PERIOD TO CONSOLE
                CALL    NOUNEWPROMPT    ; PROMPT FOR A NOUN
                CALL    SPMSG
                DB      'WHILE AT THE STORE THEY WANTED TO BUY ',0
                CALL    COMSG
                CALL    PERIOD          ; OUTPUT PERIOD TO CONSOLE
                CALL    PLANEWPROMPT    ; PROMPT FOR A PLACE
                CALL    SPMSG
                DB      'AFTER THEY CHECKED OUT THEY REALIZED THEY HAD TO BE AT ',0
                CALL    COMSG
                CALL    SPMSG
                DB      ' IN AN HOUR.',0
                CALL    ADVNEWPROMPT    ; PROMPT FOR A ADVERB
                CALL    SPMSG   
                DB      'SO THEY ',0
                CALL    COMSG
                CALL    SPMSG
                DB      ' RAN TO THEIR DESTINATION SO THEY WOULDN',SQT,'T BE LATE.',0
                JMP     START2

; CONSOLE CHARACTER INTO REGISTER A MASKED TO 7 BITS
CI:             PUSH    B               ; SAVE REGISTERS
                PUSH    D
                PUSH    H        
                MVI     C,RCONF         ; READ FUNCTION
                CALL    BDOS
                ANI     7FH             ; MASK TO 7 BITS
                POP     H               ; RESTORE REGISTERS
                POP     D
                POP     B
                RET

; CHARACTER IN REGISTER A OUTPUT TO CONSOLE
CO:             PUSH    B               ; SAVE REGISTERS
                PUSH    D
                PUSH    H
                MVI     C,WCONF         ; SELECT FUNCTION
                MOV     E,A             ; CHARACTER TO E
                CALL    BDOS            ; OUTPUT BY CP/M
                POP     H               ; RESTORE REGISTERS
                POP     D
                POP     B
                RET

; PRINT TWO LINES BY CALLING CCRLF TWICE
TWOCR:          CALL    CCRLF

; CARRIAGE RETURN, LINE FEED TO CONSOLE
CCRLF:          MVI     A,CR
                CALL    CO
                MVI     A,LF
                JMP     CO

; MESSAGE POINTED TO BY HL OUT TO CONSOLE
COMSG:          MOV     A,M             ; GET A CHARACTER
                ORA     A               ; ZERO IS THE TERMINATOR
                RZ                      ; RETURN ON ZERO
                CALL    CO              ; ELSE OUTPUT THE CHARACTER
                INX     H               ; POINT TO THE NEXT ONE
                JMP     COMSG           ; AND CONTINUE

; INPUT CONSOLE MESSAGE INTO BUFFER
CIMSG:          PUSH    B               ; SAVE REGISTERS
                PUSH    D
                PUSH    H
                LXI     H,INBUF+1       ; ZERO CHARACTER COUNTER
                MVI     M,0
                DCX     H               ; SET MAXIMUM LINE LENGTH
                MVI     M,80
                XCHG                    ; INBUF POINTER TO DE REGISTER
                MVI     C,RBUFF         ; SET UP READ BUFFER FUNCTION
                CALL    BDOS            ; INPUT A LINE
                LXI     H,INBUF+1       ; GET CHARACTER COUNTER
                MOV     E,M             ; INTO LSB OF DE REGISTER PAIR
                MVI     D,0             ; ZERO MSB
                DAD     D               ; ADD LENGTH TO START
                INX     H               ; PLUS ONE POINTS TO END
                MVI     M,0             ; INSERT TERMINATOR AT END
                POP     H               ; RESTORE ALL REGISTERS
                POP     D
                POP     B
                RET

; MESSAGE POINTED TO BY STACK OUT TO CONSOLE 
SPMSG:          XTHL                    ; GET "RETURN ADDRESS" TO HL
                XRA     A               ; CLEAR FLAGS AND ACCUMULATOR
                ADD     M               ; GET ONE MESSAGE CHARACTER
                INX     H               ; POINT TO NEXT
                XTHL                    ; RESTORE STACK FOR
                RZ                      ; RETURN IF DONE
                CALL    CO              ; ELSE DISPLAY CHARACTER
                JMP     SPMSG           ; AND DO ANOTHER

; NEW PROMPT SUBROUTINES
PERNEWPROMPT:   CALL    CCRLF           ; NEW LINE
                CALL    SPMSG           ; START NEW MESSAGE
                DB      'GIVE A PERSON: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE

PLANEWPROMPT:   CALL    CCRLF           ; NEW LINE
                CALL    SPMSG           ; START NEW MESSAGE
                DB      'GIVE A PLACE: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE

NOUNEWPROMPT:   CALL    CCRLF           ; NEW LINE
                CALL    SPMSG           ; START NEW MESSAGE
                DB      'GIVE A NOUN: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE

ADJNEWPROMPT:   CALL    CCRLF           ; NEW LINE
                CALL    SPMSG           ; START NEW MESSAGE
                DB      'GIVE A ADJETIVE: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE

ADVNEWPROMPT:   CALL    CCRLF           ; NEW LINE
                CALL    SPMSG           ; START NEW MESSAGE
                DB      'GIVE A ADVERB: ',0
                CALL    CIMSG           ; GET THE INPUT LINE
                LXI     H,INBUF+2       ; POINT TO ITS TEXT
                RET                     ; ALL DONE

; CONSOLE TEXT SUBROUTINES
PERIOD:         CALL     SPMSG           ; DISPLAY RESPONSE MESSAGE
                DB      '.',0
                RET             ; ALL DONE

INBUF:          DS      83              ; LINE INPUT BUFFER

; SET UP STACK SPACE
                DS      128             ;
STAK:           DB      0               ; TOP OF STACK

                END
