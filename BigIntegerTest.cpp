#include <iostream>
#include <string>
#include "BigInteger.hpp"

using namespace std;

int main()
{
    string return_value;

    cout << "Running some test cases to make sure that the code is not broken\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    BigInteger b1;
    cout << "Printing the bits of an empty BigInteger\n";
    b1.print_bits();
    cout << "Returning the resulting string\n";
    b1.return_bits(return_value);
    cout << return_value << "\n";

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    BigInteger b2("123456789123456789123456789");
    cout << "Printing the bits of a non empty BigInteger\n";
    b2.print_bits();
    cout << "Returning the resulting string\n";
    b2.return_bits(return_value);
    cout << return_value << "\n";
    cout << "Multiplying the BigInteger by the normal number 7\n";
    b2.multiply(7);
    cout << "Returning the resulting string\n";
    b2.return_bits(return_value);
    cout << return_value << "\n";
    cout << "Counting the sum of all the bits in the resulting string\n";
    cout << b2.sum_of_bits() << "\n";

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    BigInteger b3("2");
    cout << "Running the HackerRank power digit sum test case\n";
    cout << "This test involves multiplying the number 2 utmost 10000 times\n";
    for(unsigned int i=0; i<10000; ++i)
    {
        b3.multiply(2);
    }
    cout << "Returning the resulting string\n";
    b3.return_bits(return_value);
    cout << return_value << "\n";
    cout << "Counting the sum of all the bits in the resulting string\n";
    cout << b3.sum_of_bits() << "\n";

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    return 0;
}
