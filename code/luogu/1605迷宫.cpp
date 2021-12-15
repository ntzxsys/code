#include<iostream>
#include<cstring>
using namespace std;

int maps[10][10]={0};
bool vis[10][10]={0};
int n,m,t,cnt=0;
int sx,sy,fx,fy;
int ent;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

void dfs(int x,int y)
{
	if(x==fx&&y==fy)
	{
		cnt++;
		return ;
	}
	
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		
		if((nx>=1&&nx<=n)&&(ny>=1&&ny<=m)&&maps[nx][ny]==0&&vis[nx][ny]==false)
		{
			vis[nx][ny]=true;
			dfs(nx,ny);
			vis[nx][ny]=false;
		}	
	} 
}



int main()
{
    
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i=0;i<t;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	maps[x][y]=1;
	}
	
	vis[sx][sy]=true;
	dfs(sx,sy);
	cout<<cnt;
    
    
    return 0;
}
