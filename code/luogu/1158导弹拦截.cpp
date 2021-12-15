#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int x1,y1,x2,y2;
int r2_=0;
int n;
typedef struct node
{
	int x,y;//µ¼µ¯×ø±ê 
	int r1,r2;//¾àÀë 
}node;
node N[100005]={0};
int mins=99999999;

bool cmp(node x,node y)
{
	return x.r1<=y.r1;
}
//int ans1=0,ans2=0;
//int dist1[100005]={0};
//int dist2[100005]={0};
//int maxdis1=0;
//int maxdis2=0;
//int max1=0,max2=0;

int main()
{
	
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>N[i].x>>N[i].y;
		N[i].r1=(N[i].x-x1)*(N[i].x-x1)+(N[i].y-y1)*(N[i].y-y1);
		N[i].r2=(N[i].x-x2)*(N[i].x-x2)+(N[i].y-y2)*(N[i].y-y2);
	}
	sort(N+1,N+1+n,cmp);
	mins=N[n].r1;
	for(int i=n-1;i>=1;i--)
	{
		if(r2_<N[i+1].r2) r2_=N[i+1].r2;
		mins=min(mins,N[i].r1+r2_);
	}
	cout<<mins<<endl;
	
	return 0;
}
