#include<iostream>
using namespace std;

int n,m,a[100005]={0},ans=0,k;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int i=1;
	while(i<=n)
	{
		while(a[i]<=a[i-1]&&i<=n)
		{
			i++;
		}
		while(a[i]>=a[i-1]&&i<=n)
		{
			i++;
		}
		ans++;
	}
	cout<<ans-2;
	
    return 0;
}
