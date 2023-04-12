#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, a;
	cin >> N;
	int arr[N+1];
	for (int i = 1; i <= N; i++) {
		cin >> a;
		arr[a] = i;
	}
	for (int i = 1; i <= N; i++)
		cout << arr[i] << endl;
}
