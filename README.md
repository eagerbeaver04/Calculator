# Calculator
Calculator on C++ with parser and dll support. 

This project is calculator based on Shunting yard algorithm which produce Reverse Polish notation for input expresiion. 

Base functions are : "+" , "-", "*", "/". 

From plugins folder download from dll files some new functions:
Pow function  - "^" 
Factorial - "!"
Sin - "sin"

Here I write example of input expression:
Your expression(input):  
(2! - sin(3 + 4^(1+2!) - sin(2)) - 9/4) * 3
Output:
(0) = 2 ! = 2
(1) = 2 ! = 2
(2) = 1 + (1) = 3
(3) = 4 ^ (2) = 64
(4) = 3 + (3) = 67
(5) = sin 2 = 0.909297
(6) = (4) - (5) = 66.0907
(7) = sin (6) = -0.116988
(8) = (0) - (7) = 2.11699
(9) = 9 / 4 = 2.25
(10) = (8) - (9) = -0.133012
(11) = (10) * 3 = -0.399035
Result : (11) = -0.399035
