#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;

int dx[4]={1,-1,2,-2};
int dy[4]={1,-1,2,-2};
int maps[401][401]={0};
bool vis[401][401]={0};
int n,m;

typedef struct node
{
	int x,y;
}node;

node h,h1;

void bfs(int x,int y,int step)
{
    maps[x][y]=step;
    vis[x][y]=false;
    queue <node> Q;
    h.x=x;
    h.y=y;
    Q.push(h);
    while(!Q.empty())
	{
		h1=Q.front();
        Q.pop();
        	for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                	if (abs(dx[i])!=abs(dy[j]))
					{
	                    int NewX=h1.x+dx[i];
	                    int NewY=h1.y+dy[j];
	                    if(NewX<1||NewX>n||NewY<1||NewY>m) continue;
						if(vis[NewX][NewY]) 
	                    {
	                        h.x=NewX;
	                        h.y=NewY;
	                        Q.push(h);
	                        vis[NewX][NewY]=false;
	                        maps[NewX][NewY]=maps[h1.x][h1.y]+1;
	                    }
                	}	
				}
            }
	}

}

int main()
{
	
    memset(vis,true,sizeof(vis));
    memset(maps,-1,sizeof(maps));
    int x,y;
    cin>>n>>m>>x>>y;
    bfs(x,y,0);
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=m;j++)
        {
            printf("%-5d", maps[i][j]);
		}
        cout<<endl;
    }
    
    return 0;
}
