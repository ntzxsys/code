#include<bits/stdc++.h>
using namespace std;

int n;
int happy[6005];
bool roots[6005];
int a[6005],b[6005];
int dp[6005][2];
int root;

vector <int> tree[6005];

void dfs(int root)
{
	dp[root][0]=0;
	dp[root][1]=happy[root];
	for(int i=0;i<tree[root].size();i++)
	{
		int j=tree[root][i];
		dfs(j);
		dp[root][0]+=max(dp[j][1],dp[j][0]);
		dp[root][1]+=dp[j][0];
	}
}

int main()
{
	memset(roots,true,sizeof(roots));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>happy[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>a[i]>>b[i];
		roots[a[i]]=false;
		tree[b[i]].push_back(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(roots[i])
		{
			root=i;
			break;
		}
	}
	dfs(root);
	cout<<max(dp[root][1],dp[root][0]);
	
	return 0;	
} 
