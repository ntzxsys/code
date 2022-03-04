#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n,m,k;
int sum=0,cnt=0;
int uSet[10005];

typedef struct node
{
	int x,y,w;	
}node;

node u[10005];

bool cmp(node x,node y)
{
	return x.w<y.w;
}

int findr(int s)
{
	if(uSet[s]==s) return s;
	return uSet[s]=findr(uSet[s]);
}

int main()
{
    
    cin>>n>>m>>k;
    for(int i=1;i<n;i++)
    {
    	uSet[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u[i].x>>u[i].y>>u[i].w;
	}
	sort(u+1,u+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=u[i].x;
		int fy=u[i].y;
		int fv=u[i].w;
		
		int xr=findr(fx);
		int yr=findr(fy);
		
		if(xr==yr) continue;
		
		uSet[xr]=yr;
		sum+=fv;
		cnt++;
		
		if(cnt==n-k)
		{
			break;
		}
	}
	cout<<sum;
    
    return 0;
}
