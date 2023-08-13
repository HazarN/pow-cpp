# pow_cpp
A program that calculates the nth power of a, in logN time complexity

Program includes a test with the math.h function pow. You can see that myPow() funciton is faster than the library function.
The reason is, myPow() function uses divide and conquer approach, it checkes the exponent whether is odd or even. If it is even, then
it calculates a^2^(n/2), if it is odd then calculates a * a^2((n-1) / 2). Every time we divide by 2 to calculate. So in the end we have
a running time that fits in O(LogN) time complexity.

Program uses also sh scripts and a json file, if you have a linux distro or a wsl(i have this), you can use this project. config.json stores
the program configurations such as; name of the file, name of the output file, compile and run operations. Then sh file reads the json values
with a tool jq(you need to install it before using) and builds the project. (by typing the terminal "./build.sh" in the projects directory)
