#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct node
{
	int p,a;
}node;
node milk[5005];

int n,m,num=0;;

bool cmp(node x,node y)
{
	if(x.p<y.p)
	{
		return true;
	}
	return false;
}

int main()
{
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>milk[i].p>>milk[i].a;
	}
	sort(milk+1,milk+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(n>=milk[i].a)
		{
			num+=milk[i].a*milk[i].p;
			n-=milk[i].a;
		}
		else if(milk[i].a>n)
		{
			num+=n*milk[i].p;
			n=0;
		}
		else
		{
			break;
		}
	}
	cout<<num;

	return 0;
}
