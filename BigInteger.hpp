#ifndef __BIG_INTEGER_HPP__
#define __BIG_INTEGER_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

class BigInteger
{
    public:
        explicit BigInteger()
        {
            /*
                With this constructor all the bits in "bits" will be set to 0
            */
            vector_start_size();
        }

        explicit BigInteger(const string& initial_number)
        {
            /*
                With this constructor assign from the right end of the vector the bits provided
                by the string "initial_number".
            */
            vector_start_size();
            load_vector_from_string(initial_number);
        }

        void print_bits();
        void return_bits(string& return_value);
        void multiply(const unsigned long number);
        unsigned long sum_of_bits();

    private:
        static const unsigned int VECTOR_START_LENGTH=512;

        vector<unsigned int> bits;
        unsigned int vector_start_idx;

        inline void vector_start_size()
        {
            vector_start_idx = VECTOR_START_LENGTH;
            // A reserve() doesn't provide a container of size 512. Do explicit push_back's
            bits.reserve(VECTOR_START_LENGTH);
            for(unsigned int i=0; i<VECTOR_START_LENGTH; ++i)
            {
                bits.push_back(0);
            }
        }

        inline void load_vector_from_string(const string& initial_number)
        {
            vector_start_idx = VECTOR_START_LENGTH - initial_number.size();
            for(unsigned int i=0; i<initial_number.size(); ++i, ++vector_start_idx)
            {
                bits[vector_start_idx] = initial_number[i] - '0';
            }
            vector_start_idx = VECTOR_START_LENGTH - initial_number.size();
        }
};

#endif
