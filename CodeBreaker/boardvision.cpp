#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline int readInt() {
	int x=0; char ch=getchar_unlocked(); bool s=1;
	while(ch<'0'||ch>'9'){if(ch=='-')s=0;ch=getchar_unlocked();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar_unlocked();}
	return s?x:-x;
}

ll n, x, y, ans = 0;
bitset<4000005> u1, u2;
bitset<8000005> u3, u4;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> x >> y;
		ans += u1.test(x) + u2.test(y) + u3.test(x - y + 4e6) + u4.test(x + y);
		u1.set(x);
		u2.set(y);
		u3.set(x - y + 4e6);
		u4.set(x + y);
	}
	cout << ans;
}
