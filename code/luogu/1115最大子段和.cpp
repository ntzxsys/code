#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n;
int a[200005]; 
int dp[200005];


int main(int argc, char** argv) {

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	dp[1]=a[1];
	int maxs=dp[1];
	for(int i=2;i<=n;i++)
	{
		dp[i]=max(a[i],dp[i-1]+a[i]);
		maxs=max(maxs,dp[i]);
	}
	cout<<maxs;
	
	return 0;
}
