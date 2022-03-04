#include<bits/stdc++.h>
using namespace std;

int a[505][505];
int n,ans=0;

int main(){
	
	cin>>n;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cin>>a[i][j];
			a[j][i]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		sort(a[i]+1,a[i]+1+n);
		ans=max(ans,a[i][n-1]);
	}
	cout<<"1"<<endl<<ans;
	
	return 0;
}
