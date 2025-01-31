#include <iostream>
#include <vector>
#include <chrono> // For time measurement
#include <math.h> // For sqrt function

using namespace std;

// Function implementing the prime number generation algorithm based on 6n ± 1
void generatePrimes(int64_t size)
{
    // Creating an 8-bit vector to mark prime numbers
    vector<uint8_t> A(size / 3 + 1, true); // Assume every number is potentially prime

    // Calculate the upper limit up to which multiples will be checked
    int64_t sqrtmax_value = sqrt(size) / 3 + 1;

    size_t a1, a2, a3, a4, r, c;
    size_t max_size = A.size(); // Maximum size of the vector

    // Iterate through the sequence values
    for (size_t i = 0; i < sqrtmax_value; i += 2) 
    {
        c = 3 * i * i;        // Common part for all sequence formulas
        a1 = c + 10 * i + 8;  // Formula odd odd
        a2 = c + 12 * i + 11; // Formula ood even
        a3 = c + 12 * i + 11; // Formula even odd 
        a4 = c + 14 * i + 16; // Formula even even 
        r = 6 * i + 10;       // Step difference in iteration

        // Eliminate multiples of prime numbers
        for (a1; a1 < max_size; a1 += r)
        {
            A[a1] = false; // Mark number as composite

            if (a2 < max_size)
            {
                A[a2] = false;
                a2 += r;
            }
            if (a3 < max_size)
            {
                A[a3] = false;
                a3 += r + 4;
            }
            if (a4 < max_size)
            {
                A[a4] = false;
                a4 += r + 4;
            }
        }
    }

    int primeCount = 2; // Consider 2 and 3 as prime numbers

    // Iterate through the vector and count prime numbers
     //cout << "2, 3, ";//remove "//" if you want to write prime numbers
    for ( int i = 1;i < A.size();++i)
    {
        if (A[i])
        //cout << ((i & 1) ? 3 * i + 2 : 3 * i + 1) << ", ";//remove "//" if you want to write prime numbers
        primeCount++;
    }
    // Print the number of found prime numbers
    cout << "Number of prime numbers: " << primeCount << endl;
}

int main()
{
    int64_t size = 1000000LL; // Range of numbers to search
    cout << "Range: " << size << endl;

    // Measure execution time of the algorithm
    auto start = chrono::high_resolution_clock::now();
    generatePrimes(size);
    auto end = chrono::high_resolution_clock::now();

    // Calculate and print execution time
    chrono::duration<double> executionTime = end - start;
    cout << "Execution time (prime number generation algorithm): " << executionTime.count() << " seconds" << endl;

    return 0;
}
