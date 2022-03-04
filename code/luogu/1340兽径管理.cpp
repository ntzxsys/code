#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

/*4
0 0
1 2
-1 2
0 4*/

int n,w;
int sum=0;
int f[6005];
bool vis[6005];

typedef struct node
{
	int x,y,w,t;	
}node;

node edge[6005];

int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}

bool cmp(node x,node y)
{
	return x.w<y.w;
}


int kr(int as)
{
	
    for(int i=1;i<=n;i++) f[i]=i;
	int cnt=0;
	int sum=0;
    for(int i=1;i<=w;i++)
	{
		if(edge[i].t>as) continue;
    	int x=edge[i].x;
    	int y=edge[i].y;
    	int val=edge[i].w;
    	int ux=find(edge[i].x);
    	int uy=find(edge[i].y);
    	if(ux==uy)
    	{
    		continue;
		}
		f[ux]=uy;
    	sum+=val;
    	cnt++;
		
		if(cnt==n-1)
		{
			return sum;
			break;
		}
	}
	
	return -1;
}

int main()
{
    
    cin>>n>>w;
    for(int i=1;i<=w;i++)
    {
    	cin>>edge[i].x>>edge[i].y>>edge[i].w;
    	edge[i].t=i;
	}
	sort(edge+1,edge+1+w,cmp);
	for(int i=1;i<=w;i++)
	{
		int ans=kr(i);
		cout<<ans<<endl;
	}
    
    return 0;
}
