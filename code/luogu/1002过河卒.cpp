#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

bool b[25][25];
long long a[25][25];
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int n,m,x,y;

int main()
{
	
	cin>>n>>m>>x>>y;
	memset(b,false,sizeof(b));
	b[x][y]=true;
	for(int i=0;i<=7;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<=n&&ny>=0&&ny<=m)
		{
		 		b[x+dx[i]][y+dy[i]]=1;
		}
	}
	int k=0;
	while(!b[k][0]&&k<=n)
	{
		a[k++][0]=1;
	}
	int l=0;
	while(!b[0][l]&&l<=m)
	{
		a[0][l++]=1;//运动方式及检查情况 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j])
			{
				a[i][j]=0;
			}
			else
			{
				a[i][j]=a[i-1][j]+a[i][j-1];
			}
		}
	}
	cout<<a[n][m];
	
	return 0;
}
