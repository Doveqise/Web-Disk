#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
struct node
{
	int a,b;
	bool operator < (const node y) const
	{
		return min(a,y.b)==min(y.a,b)?a<y.a:min(a,y.b)<min(y.a,b);
	}
}
a[maxn];
int b[maxn],c[maxn];
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i].a,&a[i].b);
		sort(a+1,a+1+n);
		b[1]=a[1].a;
		for(int i=2;i<=n;i++)
			b[i]=b[i-1]+a[i].a;
		int ans = 0;
		c[1]=a[1].a+a[1].b;
		for(int i=2;i<=n;i++)
			c[i]=max(c[i-1],b[i])+a[i].b;
		for(int i=1;i<=n;i++)
			ans=max(ans,c[i]);
		printf("%d\n",ans);
	}
}
