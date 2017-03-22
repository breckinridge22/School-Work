#lang racket

;; The following are necessary for our grading script to see your functions.
;; Do not change.
(provide solve-driver)
(provide get-board-from-file)
(provide print-board)


;;; Name: Breck Stodghill
;;; VUnet id: stodghbs
;;; Email: breckinridge.s.stodghill@vanderbilt.edu
;;; Class: CS3270
;;; Date: 03/15/2017
;;; Honor Stetement:

;;; Description:  <your job to write this>

;;; sudoku-solver is the main entry point.
;;; user types (sudoku-solver) at the Racket command prompt to run the program.



; define some global constants
(define BOARD-SIZE 9)   ; the size of the board
(define ROWS 9)         ; the number of rows
(define COLS 9)         ; the number of columns
(define GRID-SIZE 3)    ; the size of a subgrid

; specify default file to load puzzle from
(define defaultFileName "sudoku-test1.txt")




;;;;;;;;;;;;;;;;;;;;;;
;;;
;;; Supplied functions
;;;
;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; print-board 
;; prints a board
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (print-board board)
  (begin
    (print-row (list-ref board 0))
    (print-row (list-ref board 1))
    (print-row (list-ref board 2))
    (printf "------+-------+------ ~n")
    (print-row (list-ref board 3))
    (print-row (list-ref board 4))
    (print-row (list-ref board 5))
    (printf "------+-------+------ ~n")
    (print-row (list-ref board 6))
    (print-row (list-ref board 7))
    (print-row (list-ref board 8))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; print-row  
;; print a row of the board with dividing lines
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (print-row row)
  (printf "~a ~a ~a | ~a ~a ~a | ~a ~a ~a ~n"
          (list-ref row 0)
          (list-ref row 1)
          (list-ref row 2)
          (list-ref row 3)
          (list-ref row 4)
          (list-ref row 5)
          (list-ref row 6)
          (list-ref row 7)
          (list-ref row 8)))

 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; get-board 
;; loads a board
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (get-board)
  (begin
    (printf "~nEnter the name of the file containing the Sudoku puzzle, or ")
    (printf "~npress enter for the default file (~a): " defaultFileName)
    (let
        ([fileName (string-trim (read-line))])
      (if (string=? fileName "")
          (get-board-from-file defaultFileName)
          (get-board-from-file fileName)))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; get-board-from-file
;; loads a board from the given file
;; it expects the board to be in the format of a single S-expression:
;; a list of nine lists, each containing nine numbers
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (get-board-from-file fileName)
  (let ([in (open-input-file fileName #:mode 'text)])
    (read in)))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; get-value  
;; return the value on the board at a specified row & col
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (get-value board row col)
  (list-ref (list-ref board row) col))

  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; set-value 
;; place a given value in the specified row & col and return the new board
;; Note: non-destructive! It returns a new board.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (set-value board row col value)
  (list-set board row (list-set (list-ref board row) col value)))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; main entry point to the sudoku solver.
;; times the solution function.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (sudoku-solver)
  (let ([board (get-board)])
    (if board
        (begin
          (displayln "")
          (displayln "Here is the initial board:")
          (print-board board)
          (displayln "")
          (let ([solution (time (solve-driver board))])
            (if (null? solution)
                (displayln "No solution")
                (begin
                  (displayln "")
                  (displayln "Here is the solution:")
                  (print-board solution)
                  (displayln "")))))
        (displayln "There is no board to process"))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; driver routine
;;
;; It is your job to write this and necessary helper functions
;;
;; This function should call your recursive backtracking solver
;; and, depending upon the result, either return the solved puzzle
;; or return null if the puzzle has no solution
;;
;; DO NOT change the name/signature of this function, as our
;; testing script depends upon it.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; solve-driver
; Finds each zero in the board
; if there are no zeros return the solved board
; otherwise try different numbers at the zero locations until
; the board is solved or there is no solution.
; If there is no solution return null.
;
(define (solve-driver board)
  (let ([x (listzeros board 0 0)])
    (if (null? x) board
        (let ([new-board (try-num board (car x) (cdr x) 1)])
          (if (null? new-board)
              null
              new-board)))))

; not-in-row?
; Checks the board to see if the num exists in the row specified
; Returns true if the number is not found
; Returns false if the number is found
;
(define (not-in-row? board row col num)
   (cond [(eq? col COLS) #t]
         [(eq? (get-value board row col) num) #f]
         [else (not-in-row? board row (add1 col) num)]
   ))

; not-in-col?
; Checks the board to see if the num exists in the col specified
; Returns true if the number is not found
; Returns false if the number is found in the column
;
(define (not-in-col? board row col num)
    (cond [(eq? row ROWS) #t]
          [(eq? (get-value board row col) num) #f]
          [else (not-in-col? board (add1 row) col num)]
     ))

; not-in-subgrid?
; Checks the subgrid of a board to see if the num exists in it
; Returns true if the num does not exist in the subgrid
; Returns false if the num does exist within the subgrid
;
(define (not-in-subgrid? board startRow startCol num)
  (cond  
        [(eq? (get-value board startRow startCol) num) #f]
        [(and (eq? (modulo startRow GRID-SIZE) (- GRID-SIZE 1)) (eq? (modulo startCol GRID-SIZE) (- GRID-SIZE 1))) #t]
        [(eq? (modulo startCol GRID-SIZE) (- GRID-SIZE 1))(not-in-subgrid? board (add1 startRow) (- startCol (modulo startCol GRID-SIZE)) num)]
        [else (not-in-subgrid? board startRow (add1 startCol) num)]))

; valid-num?
; Uses not-in-row? not-in-col? and not-in-subgrid?
; to see if a number is valid. If the number at the specified location passes
; each test then it will return true. Otherwise it will return false.
;
(define (valid-num? board row col num)
  (if  (and (not-in-row? board row 0 num) 
            (not-in-col? board 0 col num)
            (not-in-subgrid? board (- row (modulo row GRID-SIZE)) (- col (modulo col GRID-SIZE)) num)) #t #f))
; listzeros
; Lists all of the zeros on the board and returns a list of pairs
; in the form (row, col) of each 0 location
;
;
(define (listzeros board row col)
  (cond [(eq? col COLS) (listzeros board (add1 row) 0)]
        [(eq? row ROWS) null]
        [else (if (zero? (get-value board row col))
              (cons row col)
              (listzeros board row (add1 col)))]))
; try-num
; Tries a specified number on the board
; First checks to see if the number is within the range 1-Board-Size
; Then checks to see if the number is valud at the specific location
; The creates a new board with a call on Solve
; If the new board is null and the algorithm hasn't tried every number in range it
; will recurse, otherwise it will return the solved board. 
;
(define (try-num board row col num)
   (if (eq? num (add1 BOARD-SIZE)) null
       (cond 
         [(valid-num? board row col num)
         (let ([newer-board (solve-driver (set-value board row col num))])
             (if (and (null? newer-board) (< num (add1 BOARD-SIZE)))
                 (try-num board row col (add1 num))
                 newer-board))]
         [else (try-num board row col (add1 num))])))
      

;; The following should be at the bottom of your file
;;
;; the following was added to automatically start your solver when 
;; the "Run" button is pressed in DrRacket.

(sudoku-solver)

;; the following was added for generating an executable so window stays open
;(printf "~npress enter to exit")
;(read-line)

