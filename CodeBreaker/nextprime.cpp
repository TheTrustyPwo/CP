#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<bool> is_prime(100100, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= 100100; i++)
		if (is_prime[i] && (long long)i * i <= 100100)
			for (int j = i * i; j <= 100100; j += i)
				is_prime[j] = false;
	int ans = n;
	while (!is_prime[ans]) ans++;
	cout << ans;
}
