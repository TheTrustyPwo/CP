#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<pair<int, int>> v;

inline int readInt() {
	int x=0; char ch=getchar_unlocked(); bool s=1;
	while(ch<'0'||ch>'9'){if(ch=='-')s=0;ch=getchar_unlocked();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar_unlocked();}
	return s?x:-x;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	n = readInt();
	for (int i = 0; i < n; i++) {
		int x = readInt(), y = readInt(); bool b = 1;
		while (!v.empty()) {
			int tx = v.back().first, ty = v.back().second;
			if (x - tx <= ty - y) { b = 0; break; }
			if (x - tx <= y - ty) v.pop_back();
			else break;
		}
		if (b) v.push_back({x, y});
	}
	
	cout << v.size();
}
