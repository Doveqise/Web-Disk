#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
char ans[maxn],ch[maxn];
signed main()
{
	int n;
	scanf("%d",&n);
	cin>>(ans+1);
	int alen=strlen(ans+1);
	for(int i=2;i<=n;i++)
	{
		cin>>(ch+1);
		int len=strlen(ch+1);
		int cha=0;
		printf("%d\n",alen);
		for(int j=alen-len;j<=alen;j++)
		{
			if(ans[j+1]==ch[1])
			{
				int lim=alen-j,limm=len-alen+j;
				int flg=0;
				for(int k=1;k<=lim;k++)
				{
					if(ch[k]!=ans[j+k])
					{
						flg=1;
						break;
					}
				}
				if(!flg)
				{
					for(int k=limm;k<=len;k++)
						ans[k+j]=ch[k];
					alen+=len-limm;
					cha=1;
					break;
				}
			}
		}
		if(!cha)
		{
			for(int j=1;j<=len;j++)
			{
				ans[j+alen]=ch[j];
			}
			alen+=len;
		}
	}
	printf("%s",ans+1);
	return 0;
}
