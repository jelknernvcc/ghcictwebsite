; TASKMGR.ASM: Simple Task Manager Program

ORG 100H       ; Start of program in memory

; External Subroutine Declarations
EXTRN TWOCR:   ; Double carriage return
EXTRN SPMSG:   ; Display inline message
EXTRN GETYN:   ; Get Yes/No input from user

; Data Section
TASK:       DB 0   ; Memory location for storing a task
PROMPT1:    DB 'Enter a task: ', 0
PROMPT2:    DB 'Current task is: ', 0
PROMPT3:    DB 'No task available!', 0
PROMPT4:    DB 'Would you like to exit (Y/N)? ', 0
PROMPT5:    DB 'Goodbye!', 0

; Program Start
START:      
    CALL TWOCR            ; Clear the screen with a double carriage return
    CALL SPMSG            ; Welcome message
    DB 'Welcome to Task Manager!', 0
    CALL TWOCR            ; Formatting

MAIN_MENU:
    CALL SPMSG            ; Display menu options
    DB '1. Add Task', 0
    CALL TWOCR
    CALL SPMSG
    DB '2. Show Task', 0
    CALL TWOCR
    CALL SPMSG
    DB '3. Exit', 0
    CALL TWOCR

    ; Get user choice
    CALL SPMSG
    DB 'Enter choice (1-3): ', 0
    CALL GETCHAR          ; Get input from console (user-defined subroutine)
    MOV B, A              ; Store user input in register B

    ; Handle menu options
    CMP '1'               ; Add Task
    JZ ADD_TASK
    CMP '2'               ; Show Task
    JZ SHOW_TASK
    CMP '3'               ; Exit
    JZ EXIT_PROGRAM

    ; Invalid input
    CALL SPMSG
    DB 'Invalid choice. Try again.', 0
    CALL TWOCR
    JMP MAIN_MENU

ADD_TASK:
    CALL SPMSG            ; Prompt for task
    DB 'Enter your task: ', 0
    CALL GETLINE          ; Get task input (user-defined subroutine)
    STA TASK              ; Store the task in memory
    CALL TWOCR
    JMP MAIN_MENU

SHOW_TASK:
    MOV A, TASK           ; Load the task from memory
    ORA A                 ; Check if a task exists
    JZ NO_TASK            ; If zero, no task is available

    CALL SPMSG            ; Display the current task
    DB 'Current task is: ', 0
    CALL SPMSG
    JMP MAIN_MENU

NO_TASK:
    CALL SPMSG            ; Message for no task available
    DB 'No task available!', 0
    CALL TWOCR
    JMP MAIN_MENU

EXIT_PROGRAM:
    CALL SPMSG            ; Confirm exit
    DB 'Would you like to exit (Y/N)? ', 0
    CALL GETYN
    JNZ MAIN_MENU         ; If No, go back to the main menu

    ; Exit
    CALL SPMSG
    DB 'Goodbye!', 0
    HLT                   ; Halt program

; Subroutines (user-defined)
GETCHAR:
    ; Get a single character from console input
    ; Store result in A
    CALL INBUF            ; Read input buffer
    MOV A, M              ; Load first character into A
    RET

GETLINE:
    ; Get a line of text from console input and store it in TASK
    CALL INBUF            ; Read input buffer
    LXI H, TASK           ; Point HL to TASK memory
    MOV M, A              ; Store first character in memory
    RET

END START
