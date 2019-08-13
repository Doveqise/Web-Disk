#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
char ans[maxn],ch[maxn];
signed main()
{
    int n;
    scanf("%d",&n);
    int alen=strlen(ans+1);
    for(int ti=1;ti<=n;ti++)
    {
        cin>>(ch+1);
        int len=strlen(ch+1);
        if(!alen)
        {
            for(int i=1;i<=len;i++)
                ans[i]=ch[i];
            alen=len;
            continue;
        }
        int ap=max(1,alen-len+1),cp=1,fin=0;
        for(int i=0;i<min(len,alen);i++,ap++)
        {
            if(ans[ap]!=ch[cp])
                continue;
            int flg=1;
            for(int j=0;j<min(len-i,alen-i);j++)
            {
                if(ans[ap+j]!=ch[cp+j])
                {
                    flg=0;
                    break;
                }
            }
            if(flg)
            {
                for(int j=1;j<len;j++)
                    ans[ap+j]=ch[cp+j];
                fin=1;
                alen=max(alen+i,len);
                break;
            }
        }
        if(!fin)
        {
            ap=alen;
            for(int i=1;i<=len;i++)
                ans[ap+i]=ch[i];
            alen+=len;
        }
//        printf("%d\n",alen);
//        cout<<ans+1<<endl;
//        for(int i=1;i<=len;i++)
//        	ch[i]='\0';
    }
    cout<<ans+1<<endl;
}
