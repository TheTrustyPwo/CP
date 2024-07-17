#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MN_BOUND = 8e7;
const int MX_BOUND = 1e8;
const int LIM = sqrt(MX_BOUND) + 1;

vector<int> primes;
bitset<MX_BOUND - MN_BOUND + 1> is_prime;
bitset<LIM> mark;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	is_prime.set();
	is_prime.reset(0);
	is_prime.reset(1);
	
	auto start = chrono::high_resolution_clock::now();
	
	for (int i = 2; i < LIM; i++) {
		if (mark.test(i)) continue;
		primes.push_back(i);
		for (int j = i * i; j < LIM; j += i)
			mark.reset(j);
	}
	
	for (const int i : primes) {
		for (int j = max(i * i, (MN_BOUND + i - 1) / i * i); j < MX_BOUND; j += i)
			is_prime.reset(j - MN_BOUND);
	}
	if (MN_BOUND == 1) is_prime.reset(0);

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	
	for (int i = MN_BOUND; i < MX_BOUND; i++)
		if (is_prime.test(i - MN_BOUND)) cout << i << '\n';
	cout << "done\n";
	cout << duration.count() / 1000 << "ms\n";
}
