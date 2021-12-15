#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct node
{
	int u,v,w;
}node;
node edge[20005];

int n,m,s,t;
int uSet[20005];

bool cmp(node a,node b)
{
	return a.w<b.w;
}

int findRoot(int x)
{
	if(uSet[x]==x) return x;
	return uSet[x]=findRoot(uSet[x]);
}

int kruskal(int s,int t)
{
	for(int i=1;i<=n;i++)
	{
		uSet[i]=i;
	}
	
	sort(edge+1,edge+1+m,cmp);
	
	int mins=0;
	
	for(int i=1;i<=m;i++)
	{
		int u=edge[i].u;
		int v=edge[i].v;
		int val=edge[i].w;
		
		int uRoot=findRoot(u);
		int vRoot=findRoot(v);
		if(uRoot==vRoot) continue;
		else
		{
			uSet[uRoot]=vRoot;
			if(val>=mins)
			{
				mins=val;
			}
		}
		
		int x=findRoot(s);
		int y=findRoot(t);
		if(x==y)
		{
			return mins;
		}
	}
}

int main(){
	
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	cout<<kruskal(s,t);
	
	return 0;
}
