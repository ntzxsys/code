#include <iostream>
using namespace std;

long long n,m,a[10001][101],b[10001][101],c[10001],sum,k,ans,q;

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
	{
	    for (int j=0;j<=m-1;j++)
	    {
	    	cin>>a[i][j]>>b[i][j];
	    	c[i]+=a[i][j];
	    } 
	}
    cin>>k;
    for (int j=1;j<=n;j++)
    {
        sum+=b[j][k];
        ans=0;
        q=k;
        b[j][q]=(b[j][q]-1)%c[j]+1;
        while (ans<b[j][q])
        {
            ans+=a[j][k];
            if (ans==b[j][q])
			{
            	break;
			}
            k++;
            if (k==m)
			{
				k=0;
        	}
    	}
    }
    cout<<sum%20123;
    
    return 0;
}
