#include<iostream>
#include<cstring>
using namespace std;

int a[201][201];
int x;
int n;

int main()
{
	cin>>n;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j) a[i][j]=0;
			else
			{
				cin>>x;
				a[i][j]=x;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{	
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	
	cout<<a[1][n];
	
	return 0;
}
