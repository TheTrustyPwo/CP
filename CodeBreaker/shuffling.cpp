#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=2100000000,N=3000+5,mods=1e9+7;
int n,m;
int s[N],maxr[N],F[2][N];

int main() {
	cin>>n>>m;
	char ch;
	for(int i=1; i<=n; ++i)
		cin>>ch,s[i]=s[i-1]+(ch-'0');
	int l,r;
	iota(maxr+1,maxr+1+n,1);
	for(int i=1; i<=m; ++i)
		scanf("%d%d",&l,&r),maxr[l]=max(maxr[l],r);
	for(int i=1; i<=n; ++i)
		maxr[i]=max(maxr[i-1],maxr[i]);
	int *f=F[0],*g=F[1];
	g[0]=1;
	for(int i=1; i<=n; ++i)
	{
		l=max(0,i-(maxr[i]-s[maxr[i]]));
		r=min(i,s[maxr[i]]);
		fill(f,f+1+n,0);
		for(int j=l; j<=r; ++j)
			f[j]=(g[j]+(j?g[j-1]:0))%mods;
		swap(f,g);
	}
	cout<<g[s[n]];
	return 0;
}
