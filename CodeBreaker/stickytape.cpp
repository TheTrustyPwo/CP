#include <bits/stdc++.h>
using namespace std;
#define int long long

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, m, x;
priority_queue<int, vector<int>, greater<int>> pq;

inline int readInt() {
	int x=0; char ch=getchar_unlocked(); bool s=1;
	while(ch<'0'||ch>'9'){if(ch=='-')s=0;ch=getchar_unlocked();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar_unlocked();}
	return s?x:-x;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	n = readInt(), m = readInt();
	for (int i = 0; i < m; i++) pq.push(readInt());
	
	int ans = 0;
	while (pq.size() > 1) {
		int u = pq.top(); pq.pop();
		int s = u + pq.top(); pq.pop();
		ans += s;
		pq.push(s);
	}
	
	cout << ans;
}
