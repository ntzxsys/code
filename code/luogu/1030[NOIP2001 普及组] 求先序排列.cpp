#include<iostream>
#include<cstring>
using namespace std;

char shuzhong[10],shuhou[10];
int lenzuo=0,lenyou=0;
int k=0;
int len=0;

int findroot(char str)
{
	for(int i=0;i<len;i++)
	{
		if(shuzhong[i]==str) return i;
	}
}

void dfs(int l1,int r1,int l2,int r2)
{
	char rt=shuhou[r2];
	int rindex=findroot(shuhou[r2]);
	cout<<rt;
	if(rindex>l1)  dfs(l1,rindex-1,l2,r2-r1+rindex-1);
	if(rindex<r1)  dfs(rindex+1,r1,r2-r1+rindex,r2-1);
} 

int main()
{
	
	cin>>shuzhong;
	cin>>shuhou;
	len=strlen(shuzhong);
	dfs(0,len-1,0,len-1);
	
	return 0;
}
