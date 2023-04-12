#include <bits/stdc++.h>
using namespace std;
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	int t; cin >> t;
	t %= 1440;
	int hours = t / 60, minutes = t % 60;
	cout << setfill('0') << setw(2) << hours << setfill('0') << setw(2) << minutes;
}
