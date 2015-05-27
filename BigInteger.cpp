#include "BigInteger.hpp"

void BigInteger::print_bits()
{
    for(unsigned int i = vector_start_idx; i<bits.size(); ++i)
    {
        cout << bits[i];
    }
    cout << "\n";
}

void BigInteger::return_bits(string& return_value)
{
    stringstream result;
    vector<unsigned int>::iterator begin = bits.begin() + vector_start_idx;
    vector<unsigned int>::iterator end = bits.end();
    copy(begin, end, ostream_iterator<unsigned int>(result, ""));
    return_value = result.str();
}

void BigInteger::multiply(const unsigned long number)
{
    unsigned int carry = 0, product;
    for(unsigned int i = bits.size()-1; i>=vector_start_idx; --i)
    {
        product = bits[i] * number;
        product += carry;
        bits[i] = product % 10;
        carry = product / 10;
    }
    while(carry)
    {
        vector_start_idx -= 1;
        bits[vector_start_idx] = carry % 10;
        carry /= 10;
    }
}

unsigned long BigInteger::sum_of_bits()
{
    vector<unsigned int>::iterator begin = bits.begin() + vector_start_idx;
    vector<unsigned int>::iterator end = bits.end();
    return accumulate(begin, end, 0);
}
