# Bracket_Checker
Is a cpp code that checks the brackets in the expression by using the stack
The idea is rather simple: You keep a Stack of braces, and every time you encounter an open brace, you push it into your stack. Every time you encounter a close brace, you pop the top element from your stack. At the end, you check your stack for being empty. If so, indeed your input string contained balanced braces. Otherwise, it didn't. 

## Expected Input :

+ 1 + 2 * (3 / 4)
+ 1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10) – 11 + (12*8)] + 14
+ 1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10)} – 11 + (12*8) / {13 +13}] + 14

## Expected Output :

+ This expression is correct.
+ This expression is NOT correct e.g. error at character # 10. ‘{‘- not closed.
+ This expression is correct.

