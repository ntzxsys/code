#include <iostream>
#include <cstdio>
using namespace std;
		
int maps[35][35]={0};
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void dfs(int x,int y,int n)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(maps[nx][ny]==0&&nx>=1&&nx<=n&&ny>=1&&ny<=n)
		{
			maps[nx][ny]=2;
			dfs(nx,ny,n);
		}
	}
}


void show(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(maps[i][j]==0)
			{
				cout<<"2"<<" ";
			}
			else if(maps[i][j]==2)
			{
				cout<<"0"<<" ";
			}
			else
			{
				cout<<maps[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}
	
int main(){
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>maps[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(maps[i][j]==0&&(i==1||i==n||j==1||j==n))
			{
				maps[i][j]=2;
				dfs(i,j,n);
			}
		}
	}
	show(n);
	
	
	return 0;
}
