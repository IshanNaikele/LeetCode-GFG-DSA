// You are given an integer N. Now, you need to find if there exists two prime numbers (X,Y) such that 
// X^2+y^2=N. If (X,Y) exists then output the minimum value of X+Y otherwise print -1. 
// Input format: The first line contains an integer, N, denoting the value of N described in the problem. 
// Constraints: 1<=N<=10^9. 
// Sample Input: 
// input: 7 
// output: -1 
// explanation: for N=7 no such X,Y exists. 
// input: 34 
// output: 8 
// explanation: X=5 and Y=3 satisfy the condition 25+9=34. 
// input: 13 
// output: 5 
// explanation: X=2 and Y=3 satisfy the condition 4+9=13.

#include <iostream>
#include <cmath>

using namespace std;

// Fast primality check O(sqrt(num))
bool isPrime(long long num) {
    if (num < 2) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

long long solve(long long N) {
    // ==================== CASE 1: ODD N ====================
    if (N % 2 != 0) {
        // One prime MUST be 2. Check X = 2 directly.
        long long rem = N - 4; // 2^2 = 4
        if (rem <= 0) return -1;

        long long Y = round(sqrt(rem));
        if (Y * Y == rem && isPrime(Y)) {
            return 2 + Y;
        }
        return -1; // O(1) check - No loop needed!
    }

    // ==================== CASE 2: EVEN N ====================
    if (N == 8) return 4; // Special case: 2^2 + 2^2 = 8

    // Any sum of two odd prime squares MUST leave remainder 2 modulo 4.
    if (N % 4 != 2) return -1; // Rejects 12, 16, 20, 24, 28, 32... in O(1)!

    // For remaining valid even N, iterate ONLY over odd numbers starting at X = 3
    for (long long X = 3; X * X <= N / 2; X += 2) {
        if (!isPrime(X)) continue;

        long long rem = N - X * X;
        long long Y = round(sqrt(rem));

        if (Y * Y == rem && isPrime(Y)) {
            return X + Y; // First valid X gives the global minimum sum
        }
    }

    return -1;
}