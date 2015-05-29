CC = g++

all:BigIntegerTest

BigIntegerTest:BigIntegerTest.cpp BigInteger.cpp BigInteger.hpp
	$(CC) BigIntegerTest.cpp BigInteger.cpp -o BigIntegerTest

clean:
	rm BigIntegerTest
