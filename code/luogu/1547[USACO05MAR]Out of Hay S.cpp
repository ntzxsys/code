#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n,m;

typedef struct node
{
	int x,y,w;
};

node a[10005];

int uSet[10005];

int findRoot(int x)
{
	if(uSet[x]==x) return x;
	else return uSet[x]=findRoot(uSet[x]);
}

bool cmp(node a,node b)
{
	return a.w<b.w;
}

int Kruskal()
{
	int cnt=0;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x=a[i].x;
		int y=a[i].y;
		int val=a[i].w;
		
		int xRoot=findRoot(x);
		int yRoot=findRoot(y);
		if(xRoot==yRoot) continue;
		
		uSet[xRoot]=yRoot;
		ans=max(a[i].w,ans);
		
		cnt++;
		if(cnt==n-1)
		{
			break;
		}
	} 
	return ans;
}

int main()
{
    
    cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		uSet[i]=i;
	}
    for(int i=1;i<=m;i++)
    {
    	cin>>a[i].x>>a[i].y>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
    
    cout<<Kruskal();
    
    return 0;
}
