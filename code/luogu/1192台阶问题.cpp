#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

long long n,k;
long long dp[100005];
long long num[100005];

long long dfs(int n)
{
	if(n<0) return 0;
	if(dp[n]!=-1) return dp[n]%100003;
	long long cnt=0;
	for(int i=1;i<=k;i++)
	{
		cnt+=(dfs(n-i)%100003);
	}
	return dp[n]=cnt;
}

int main()
{
	
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	dp[0]=dp[1]=1;
	cout<<dfs(n)%100003;
	
		
	
	return 0;
}
