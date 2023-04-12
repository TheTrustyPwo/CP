#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	vector<int> primes;
	vector<bool> isPrime(1e6, true);
	int maxPrime = 1e6;
	range(i, 2, maxPrime) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (int j = i + i; j < maxPrime; j += i) {
				isPrime[j] = false;
			}
		}
	}

	int n; cin >> n;
	cout << primes[n-1];
}
