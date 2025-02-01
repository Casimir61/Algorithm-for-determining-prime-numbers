#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

/**
 * Function to generate prime-like numbers using a sieve-like algorithm.
 * The algorithm efficiently marks non-prime numbers using a bit vector.
 */
void generatePrimes(int64_t size) {
    // Create a bit-array (8-bit vector) for marking numbers
    vector<uint8_t> sieve(size / 3 + 1, true);
    int64_t sqrtLimit = sqrt(size) / 3 + 1;
    size_t sieveSize = sieve.size();
    
    // Iterating through numbers in steps of 2 to mark non-primes
    for (size_t i = 0; i < sqrtLimit; i += 2) {
        size_t c = 3 * i * i; // Common base calculation for all formulas
        size_t step = 6 * i + 10; // Step size for marking multiples

        // Compute indices for marking:
        size_t index_oo = c + 10 * i + 8;  // odd-odd 
        size_t index_oe = c + 12 * i + 11; // odd-even 
        size_t index_eo = c + 12 * i + 11; // even-odd  
        size_t index_ee = c + 14 * i + 16; // even-even 

        // Marking non-prime numbers in the sieve
        for (; index_oo < sieveSize; index_oo += step) {
            sieve[index_nn] = false;
            if (index_oe < sieveSize) { sieve[index_np] = false; index_oe += step; }
            if (index_eo < sieveSize) { sieve[index_pn] = false; index_eo += step + 4; }
            if (index_ee < sieveSize) { sieve[index_pp] = false; index_ee += step + 4; }
        }
    }

    // Output prime numbers
    int primeCount = 2;
    cout << "2, 3, ";

    string outputBuffer;
    for (size_t i = 1; i < sieve.size(); ++i) {
        if (sieve[i]) {
            outputBuffer += to_string((i & 1) ? 3 * i + 2 : 3 * i + 1) + ", ";
            primeCount++;
        }
    }
    
    cout << outputBuffer << endl;
    cout << "Total prime-like numbers: " << primeCount << endl;
}

int main() {
    int64_t size = 1000LL;  
    cout << "Range: " << size << endl;

    // Measure execution time of prime number generation
    auto startTime = chrono::high_resolution_clock::now();
    generatePrimes(size);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double> executionTime = endTime - startTime;
    cout << "Execution time: " << executionTime.count() << " seconds" << endl;

    return 0;
}
