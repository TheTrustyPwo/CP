#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K, out = 0;
	cin >> N >> K;
	int array[N];
	for (int i = 0; i < N; i++)
		cin >> array[i];
	for (int i = 0; i <= N - K; i++) {
		int sum = 0;
		for (int j = 0; j < K; j++)
			sum += array[i + j];
		out = max(out, sum);
	}
	cout << out;
}
