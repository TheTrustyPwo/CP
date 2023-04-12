#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	stringstream ss(s);
	int a, b; char ch;
	ss >> a >> ch >> b;
	
	a -= b * 32;
	b *= 9; a *= 5;
	
	int gcd = __gcd(a < 0 ? -a : a, b < 0 ? -b : b);
	a /= gcd;
	b /= gcd;
	
	cout << a << '/' << b;
}
