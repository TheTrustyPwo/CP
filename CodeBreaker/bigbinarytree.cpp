#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, d; cin >> n >> d;
	if (d > (n * (n - 1)) / 2) { cout << "NO\n"; return 0; }
	
	int chain = n - 2, cur = (n * (n - 1)) / 2;
	int size = 2, layer = 2, left = 1, last = -1;
	
	for (int i = n - 1; i > 1; i--) {
		if (cur - i + layer - 1 < d) {
			last = cur - d;
			if (last != 0) chain--;
			break;
		}
		
		if (left == 0) left = (1 << layer) - 1, layer++, size++, chain--;
		size++, chain--;
		cur += layer - i - 1;
		left--;
	}
	
	for (int i = 0; i < size - 1; i++) cout << (i / 2) + 1 << ' ';
	for (int i = 0; i < chain; i++) cout << i + size << ' ';
	if (last != 0) cout << n - 1 - last;
}
