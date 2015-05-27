# BigInteger
A simple C++ Class that helps me work with Integers beyond the unsigned long

I found that when working on HackerRank challenges like [Power digit sum](https://www.hackerrank.com/contests/projecteuler/challenges/euler016) the generated integer number for some of the test cases exceeds the one that can be held in the unsigned long provided by C++

Though there were various alternatives available like
  1. Using a scripting language like Python
  2. Using [Boost BigInt](http://www.boost.org/doc/libs/1_58_0/libs/multiprecision/doc/html/index.html)

It hardly seemed right. A coding competition might just not allow Python for a similar problem type and there is no point talking about Boost as there is hardly any Online Judge out there that allows you to compile your code with Boost library.

While browsing for possible solutions to this problem I came across this [page](http://discuss.codechef.com/questions/7992/how-can-i-store-very-very-large-integers-accurately) where the following snippet in the discussion caught my attention - "...Some languages such as Java or Python have big integer classes built in. In other languages such as C/C++, the best way of handling these is to store them as strings. You can write methods to multiply, divide, add or subtract these just as you were taught in school using pen and paper."

This provided the inspiration for me to try and come up with my own library that can solve problems where there is a need to store BigIntegers
