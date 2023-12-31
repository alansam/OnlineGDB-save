
       IDENTIFICATION DIVISION.
        PROGRAM-ID. sums.
        DATA DIVISION.
          WORKING-STORAGE SECTION.
            01 WS-VALUE PIC 9(3) VALUE 0.
            01 WS-A PIC 9(3) VALUE 5.
            01 WS-B PIC 9(3) VALUE 5.
        PROCEDURE DIVISION.
          DISPLAY WS-VALUE.

          COMPUTE WS-VALUE = 5 + 5 * 5 + 5.
          DISPLAY WS-VALUE.

          SET WS-VALUE TO 0.
          DISPLAY WS-VALUE.

          MULTIPLY WS-A BY WS-B GIVING WS-VALUE.
          ADD WS-A TO WS-VALUE.
          ADD WS-B TO WS-VALUE.
          DISPLAY WS-VALUE.
          STOP RUN.
