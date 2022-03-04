#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,k;
int a[100005];

int pd(int val)
{
    int sum=0;
    for(int i=1;i<=n;i++)  sum+=a[i]/val;
    return sum>=k;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {    
		double p;
		cin>>p;    
		a[i]=p*100;    
	}    
    int l=0,r=100000000,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mid==0) break;
        if(pd(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%.2lf",(double)ans/100);
    
     return 0;
}
