#include<iostream>
using namespace std;

#include<vector>
#include<math.h>
/*
time limited exceeded

change to sqrt(i):
get accepted
*/
class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2) {
			return 0;
		}
		vector<int> primes;
		primes.push_back(2);
		int count = 1;
		for (int i = 3; i < n; i++) {
			for (int j = 0; j < primes.size(); j++) {
				if (i%primes[j] != 0&& (j == primes.size() - 1||primes[j]>sqrt(i))) {
					primes.push_back(i);
					count++;
					break;
				}
				if (i%primes[j] != 0) {
					continue;
				}
				else {
					break;
				}
			}
		}
		return count;
	}
};


/*
The Sieve of Eratosthenes is one of the most efficient ways to find all prime numbers up to n.
*/
class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isPrime;
		/*
		why I use while here does not work
		while (n-- > 0) {
			isPrime.push_back(true);
		}
		*/
		for (int i = 0; i < n; i++) {
			isPrime.push_back(true);
		}

		for (int i = 2; i*i < n; i++) {
			if (!isPrime[i])continue;
			for (int j = i * i; j < n; j+=i) {
				isPrime[j] = false;
			}
		}

		int count = 0;
		for (int i = 2; i < n; i++) {
			if (isPrime[i]) count++;
		}
		return count;
	}
};