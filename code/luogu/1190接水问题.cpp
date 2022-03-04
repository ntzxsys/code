#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int w[10005];
int t=0;

bool cmp1(int x,int y)
{
	return x<y;
}

bool cmp2(int x,int y)
{
	return x>y;
}
int main()
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	} 
	for(int i=m+1;i<=n;i++)
	{
		sort(w+1,w+m+1,cmp1);
		w[1]+=w[i];
	}
	sort(w+1,w+m+1,cmp2);
	cout<<w[1];
	
	return 0;
}
