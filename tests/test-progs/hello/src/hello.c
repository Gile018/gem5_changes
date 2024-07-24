/*
 * Copyright (c) 2006 The Regents of The University of Michigan
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
    printf("PROBA!\n");
    return 0;
}

// We will write Sieve of Erathostens here:
// Check how the binary is created:

// #define SET_BIT(arr, index) (arr[(index) / 8] |= (1 << ((index) % 8)))
// #define CHECK_BIT(arr, index) (arr[(index) / 8] & (1 << ((index) % 8)))


// int sieve_of_eratosthenes(int n) {
//     // Allocate memory for the bit array
//     int size = (n + 7) / 8;  // (n / 8) rounded up
//     unsigned char *prime = malloc(size);
//     if (!prime) {
//         fprintf(stderr, "Memory allocation failed\n");
//         return -1;
//     }
//     memset(prime, 0, size);  // Initialize all bits to 0 (true)

//     int p = 2;

//     while (p * p <= n) {
//         // If prime[p] is still true, then it's a prime
//         if (!CHECK_BIT(prime, p)) {
//             // Marking multiples of p as false (non-prime)
//             for (int i = p * p; i <= n; i += p) {
//                 SET_BIT(prime, i);
//             }
//         }
//         p++;
//     }

//     // Counting all prime numbers
//     int prime_count = 0;
//     for (int p = 2; p <= n; p++) {
//         if (!CHECK_BIT(prime, p)) {
//             prime_count++;
//         }
//     }

//     // Free the allocated memory
//     free(prime);

//     return prime_count;
// }

// int main() {
//     int n = 1000000;
//     int count = sieve_of_eratosthenes(n);
//     if (count != -1) {
//         printf("Number of prime numbers up to %d: %d\n", n, count);
//     }
//     return 0;
// }