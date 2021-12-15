#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef struct node
{
	int x,y,s;
}node;

node h,h1;

int n,m,a,b;
int maps[505][505]={0};
bool vis[505][505]={0};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

queue <node> Q;

void bfs()
{
	while(!Q.empty())
	{
		node ti=Q.front();
		maps[ti.x][ti.y]=ti.s;
		Q.pop();
		for(int i=0;i<4;i++)
		{
			int nx=ti.x+dx[i];
			int ny=ti.y+dy[i];
			
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny])
			{
				node tim={nx,ny,ti.s+1};
				Q.push(tim);
				vis[nx][ny]=false;
			}
		}
	}
}


int main(){
    
    memset(vis,true,sizeof(vis));
    memset(maps,999999,sizeof(maps));
    cin>>n>>m>>a>>b;
    for(int i=1;i<=a;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	maps[x][y]=0;
    	vis[x][y]=false;
		node h={x,y,0};
		Q.push(h);
	}
	bfs();
	for(int i=1;i<=b;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<maps[x][y]<<endl;
	}    
    
    
    return 0;
}
