#include<iostream>
#include<algorithm>
using namespace std;

int n,r,q;

typedef struct node
{
	int s;		//初始分 
	int w;		//实力 
	int num;	//编号 
}node;

node p[200005];

node win[200005],lose[200005];

bool cmp(node x,node y)
{
	if(x.s!=y.s) return x.s>y.s;
	else return x.num<y.num;
}

void msort()
{
	int i=1,j=1,k=1;
	while(i<=n&&j<=n)
	{
		if(cmp(win[i],lose[j]))
		{
			p[k++]=win[i++];
		}
		else
		{
			p[k++]=lose[j++];
		}
	}
	while(i<=n) p[k++]=win[i++];
	while(j<=n) p[k++]=lose[j++];
}

int main()
{
	cin>>n>>r>>q;
	for(int i=1;i<=2*n;i++)
	{
		cin>>p[i].s;
		p[i].num=i;
	}
	for(int i=1;i<=2*n;i++)
	{
		cin>>p[i].w;
	}
	sort(p+1,p+1+2*n,cmp);
	for(int i=1;i<=r;i++)
	{
		int len=1;
		for(int j=1;j<=n*2;j+=2)
		{
			if(p[j].w>p[j+1].w)
			{
				win[len]=p[j];
				win[len].s++;
				lose[len]=p[j+1];
			}
			else
			{
				win[len]=p[j+1];
				lose[len]=p[j];
				win[len].s++;
			}
			len++;
		}
		msort();
	}
	
	cout<<p[q].num;
			
	return 0;
} 
