#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i += 2) {
		for (int j = 0; j < (n - i) / 2; j++) cout << '*';
		for (int j = 0; j < i; j++) cout << 'D';
		for (int j = 0; j < (n - i) / 2; j++) cout << '*';
		cout << '\n';
	}
	for (int i = n - 2; i > 0; i -= 2) {
		for (int j = 0; j < (n - i) / 2; j++) cout << '*';
		for (int j = 0; j < i; j++) cout << 'D';
		for (int j = 0; j < (n - i) / 2; j++) cout << '*';
		cout << '\n';
	}
}
