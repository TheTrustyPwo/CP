#include <bits/stdc++.h>
#include "lampposts.h"
using namespace std;
typedef long long ll;

const int MAX_L = 100000;
const int MAX_N = 1000;

int L, N, Q;
int X[MAX_N];

void find_lampposts(int L, int N, int X[]) {
    for (int i = 0; i < N; i++) {
        int left = 0, right = L;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int nl = nearest_lamppost(mid);
            if (nl <= i) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        X[i] = left;
    }
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> L >> N >> Q;
    find_lampposts(L, N, X);
    for (int i = 0; i < N; i++)
        cout << X[i] << " ";
}
