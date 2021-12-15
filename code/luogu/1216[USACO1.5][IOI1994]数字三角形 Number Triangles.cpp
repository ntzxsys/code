#include <bits/stdc++.h>
using namespace std;

int num[1005][1005]={0};
int dp[1005][1005]={0};
int r;

int dfs(int x,int y)
{
	if(dp[x][y]!=-1) return dp[x][y];
	if(x==1) return dp[x][y]=num[x][y];
	else return dp[x][y]=max(dfs(x-1,y),dfs(x-1,y-1))+num[x][y];
}

int main()
{
	
	int maxn=-1;
	memset(dp,-1,sizeof(dp));
	cin>>r;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>num[i][j];
		}
	}
	
	for(int i=1;i<=r;i++)
	{
		dfs(r,i);
		if(dp[r][i]>=maxn)
		{
			maxn=dp[r][i];
		}
	}
	cout<<maxn;
	
    return 0;
}

