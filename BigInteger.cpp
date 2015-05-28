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
        if(vector_start_idx == 0)
        {
            resize_container();
        }
        bits[vector_start_idx] = carry % 10;
        carry /= 10;
    }
}

void BigInteger::resize_container()
{
    unsigned int current_size = bits.size();
    unsigned int new_size = current_size * 2;
    bits.resize(new_size);

    // Move the bits from 0 to current_size - 1 TO current_size + 1 to new_size
    // Replace the bits from 0 to current_size - 1 with 0
    for(unsigned int i=0; i<current_size; ++i)
    {
        bits[new_size - i - 1] = bits[current_size - i - 1];
        bits[current_size - i - 1] = 0;
    }

    // Also change the vector_start_idx after resizing the container
    vector_start_idx = current_size;
}

unsigned long BigInteger::sum_of_bits()
{
    vector<unsigned int>::iterator begin = bits.begin() + vector_start_idx;
    vector<unsigned int>::iterator end = bits.end();
    return accumulate(begin, end, 0);
}
