# Calculator
## Calculator on C++ with parser and dll support. 

This project is calculator based on Shunting yard algorithm which produce Reverse Polish notation for input expresiion. 

## Base functions are: 
1. Addition - "+"
2. Substraction - "-"
3. Multiplication - "*"
4. Division - "/"

## Download dll files from plugins folder for some new functions:
1. Pow - "^" 
2. Factorial - "!"
3. Sine - "sin"

## Example of input expression:
+ Your expression(input):  
1. (2! - sin(3 + 4^(1+2!) - sin(2)) - 9/4) * 3

+ Output:
1. (0) = 2 ! = 2
2. (1) = 2 ! = 2
3. (2) = 1 + (1) = 3
4. (3) = 4 ^ (2) = 64
5. (4) = 3 + (3) = 67
6. (5) = sin 2 = 0.909297
7. (6) = (4) - (5) = 66.0907
8. (7) = sin (6) = -0.116988
9. (8) = (0) - (7) = 2.11699
10. (9) = 9 / 4 = 2.25
11. (10) = (8) - (9) = -0.133012
12. (11) = (10) * 3 = -0.399035
13. Result : (11) = -0.399035
