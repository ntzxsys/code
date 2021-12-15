#include<iostream>
#include<cstdio>
#include<cstring>
int main()
{
    int m,n,l,k;
    int a[10005];
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        while(n--)
        {
            scanf("%d%d",&l,&k);
            for(int i=l; i<=k; i++)
            {
                a[i]=1;
            }
        }
        int count=0;
        for(int j=0; j<=m; j++)
        {
            if(a[j]==0)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
