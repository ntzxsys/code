#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x;
	int y;
	int t;
}a[200005];

int f[200005],n,m,s,t;

int find(int xx)
{
	if(f[xx]!=xx) f[xx]=find(f[xx]);
	return f[xx];
}

void connect(int xx,int yy)
{
	f[yy]=xx;
}

bool cmp(node p,node q)
{
	return p.t<q.t;
}

int main()
{
	cin>>n>>m>>s>>t;
	for(int i=0;i<=m;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].t;
	}
	sort(a+1,a+m+1,cmp);
	int tot=0,num=0;
	for(int i=1;i<=m;i++)
	{
		int cc=find(a[i].x),dd=find(a[i].y);
		connect(cc,dd);
		if(find(s)==find(t))
		{
			cout<<a[i].t;
			break;
		}
	}
	
	return 0;
}
