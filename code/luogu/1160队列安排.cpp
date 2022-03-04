#include<iostream> 
#include<cstdio> 
#include<cstring> 
using namespace std;

typedef struct node
{
	int data;
	int next;
	int pre;
	bool vis;
}node;

node Lis[100005]={0};

int main() {

	int n;
	cin>>n;
	int h=0;
	Lis[h].pre=Lis[h].next=-1;
	Lis[1].data=1;
	Lis[1].vis=true;
	Lis[1].pre=Lis[1].next=-1;
	Lis[h].next=1;
	Lis[1].pre=h;
	
	for(int i=2;i<=n;i++)
	{
		int k,p;
		cin>>k>>p;
		Lis[i].data=i;
		Lis[i].vis=true;
		Lis[i].pre=Lis[i].next=-1;
		if(p)
		{
			int r=Lis[k].next;
			Lis[i].pre=k;
			Lis[i].next=r;
			Lis[k].next=i;
			if(r!=-1)
			{
				Lis[r].pre=i;
			}
		}
		else
		{
			int l=Lis[k].pre;
			Lis[i].pre=l;
			Lis[i].next=k;
			Lis[k].pre=i;
			Lis[l].next=i;
		}
	}
	
	
//	while(p!=-1)
//	{
//		cout<<Lis[p].data<<" ";
//		p=Lis[p].next;
//	}
//	cout<<endl;
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		Lis[x].vis=false;
	}
	int p=Lis[h].next;
	while(p!=-1)
	{
		if(Lis[p].vis)
		{
			cout<<Lis[p].data<<" ";
		}
		p=Lis[p].next;
	}

	return 0;
}
