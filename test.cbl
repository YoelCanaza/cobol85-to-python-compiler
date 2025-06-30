*===============================================================*
      * PROGRAMA: FERMAT.CBL                                         *
      * DESCRIPCIÓN: Implementación del último teorema de Fermat     *
      * AUTOR: Anónimo                                               *
      *==============================================================*

       IDENTIFICATION DIVISION.
       PROGRAM-ID. FERMAT.
       AUTHOR. ANONIMO.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01  n-INPUT             PIC 9(10).
       01  n                   PIC 9(9) COMP VALUE 3.
       01  total               PIC 9(9) COMP VALUE 3.
       01  x                   PIC 9(9) COMP.
       01  y                   PIC 9(9) COMP.
       01  z                   PIC 9(9) COMP.
       01  exp-x               PIC 9(18) COMP.
       01  exp-y               PIC 9(18) COMP.
       01  exp-z               PIC 9(18) COMP.
       01  suma                PIC 9(18) COMP.
       
       01  WS-BASE             PIC 9(18) COMP.
       01  WS-EXP              PIC 9(9) COMP.
       01  WS-RESULT           PIC 9(18) COMP.
       01  WS-J                PIC 9(9) COMP.

       PROCEDURE DIVISION.
       MAIN-PROCEDURE.
           ACCEPT n-INPUT
           MOVE n-INPUT TO n
           PERFORM 100-MAIN-LOOP
           STOP RUN.

       100-MAIN-LOOP.
           PERFORM UNTIL 1 = 0
               MOVE 1 TO x
               PERFORM UNTIL x > total - 2
                   MOVE 1 TO y
                   PERFORM UNTIL y > total - x - 1
                       COMPUTE z = total - x - y
                       
                       MOVE x TO WS-BASE
                       MOVE n TO WS-EXP
                       PERFORM CALCULA-EXP
                       MOVE WS-RESULT TO exp-x
                       
                       MOVE y TO WS-BASE
                       MOVE n TO WS-EXP
                       PERFORM CALCULA-EXP
                       MOVE WS-RESULT TO exp-y
                       
                       MOVE z TO WS-BASE
                       MOVE n TO WS-EXP
                       PERFORM CALCULA-EXP
                       MOVE WS-RESULT TO exp-z

                       COMPUTE suma = exp-x + exp-y
                       IF suma = exp-z
                           DISPLAY "hola, mundo"
                       END-IF

                       ADD 1 TO y
                   END-PERFORM
                   ADD 1 TO x
               END-PERFORM
               ADD 1 TO total
           END-PERFORM.

       CALCULA-EXP.
           MOVE 1 TO WS-RESULT
           MOVE 1 TO WS-J
           PERFORM UNTIL WS-J > WS-EXP
               COMPUTE WS-RESULT = WS-RESULT * WS-BASE
               ADD 1 TO WS-J
           END-PERFORM.

       END PROGRAM FERMAT.
