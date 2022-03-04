#include<bits/stdc++.h>
using namespace std;

int pri[100001];
int check[100001];

int main()
{
    int a,b,p;
    cin>>a>>b>>p;
    pri[0]=1;
    pri[1]=1;
    for(int i=2;i<=100001;i++)
	{
        for(int j=i;j<=100001/i;j++)
		{
            pri[i*j]=1;
        }
    }
    int ans=0,sum=0;
    for(int i=p;i<=b;i++)
	{
        if(pri[i]) continue;
        int t;
        if(a%i==0) t=a;
        else t=i*(a/i+1);
        int w=0,q=0;
        for(int j=t;j<=b;j+=i)
		{
            if(!check[j])
			{
                check[j]=1;
                w=1;
                sum++;
            } 
            else q=1;
        }
        if(w==1&&q==0) ans++;
    }
    cout<<ans+(b-a-sum+1);
    
    return 0;
}
