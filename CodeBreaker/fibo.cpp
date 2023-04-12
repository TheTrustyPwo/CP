#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int M = 998244353;

int32_t main() {
	setup();
	int n;
    cin >> n;
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    range(i, 0, min(2, n)) cout << arr[i] << endl;
    range(i, 2, n + 1) {
        arr[i] = (arr[i - 2] % M + arr[i - 1] % M) % M;
        cout << arr[i] << endl;
    }
}
