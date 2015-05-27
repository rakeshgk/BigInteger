#include <iostream>
#include <string>
#include "BigInteger.hpp"

using namespace std;

int main()
{
    string return_value;

    BigInteger b1;
    cout << "Printing the bits of an empty BigInteger\n";
    b1.print_bits();
    cout << "Returning the resulting string\n";
    b1.return_bits(return_value);
    cout << return_value << "\n";

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

    return 0;
}
