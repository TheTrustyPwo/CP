#include "lampposts.h"
#include <bits/stdc++.h>
using namespace std;

static int L, N, A[100005], userans[100005], Q, userQ;

int nearest_lamppost(int X) {
	if (X < 0 || X > L) {
		printf("gug_reporting_string\nX out of range.\n");
		exit(0);
	}
	userQ++;
	if (userQ > Q) {
		printf("gug_reporting_string\nToo many queries made.\n");
		exit(0);
	} 
	int pos = lower_bound(A, A + N, X) - A;
	if (pos == N) return pos - 1;
	else if (pos == 0) return pos;
	else {
		if (abs(A[pos] - X) < abs(A[pos - 1] - X)) return pos;
		else return pos - 1;
	}
}

int main() {
	scanf("%d%d%d", &L, &N, &Q);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	find_lampposts(L, N, userans);
	printf("gug_reporting_string\n");
	for (int i = 0; i < N; i++) printf("%d ", userans[i]);
	printf("\n");
	printf("%d queries made (out of %d).\n", userQ, Q);
}

