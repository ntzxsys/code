#include<iostream>
using namespace std;

int R,C;
char maps[1005][1005]={0};
char mapss[1005][1005]={0};
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int S=0;
int num=0;
int flag=1;

void dfs(int x,int y,int flag)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx>=1&&nx<=R&&ny>=1&&ny<=C&&maps[nx][ny]=='#')
		{
			maps[nx][ny]=flag;
			dfs(nx,ny,flag);	
		}
	}
	
	
}

bool check()
{
	num=0;
	for(int i=1;i<R;i++)
	{
	num=0;
		for(int j=1;j<C;j++)
		{
			num=0;
			if(mapss[i][j]=='#')num++;
			if(mapss[i+1][j]=='#')num++;
			if(mapss[i][j+1]=='#')num++;
			if(mapss[i+1][j+1]=='#')num++;
			if(num==3) return false;
		}
	}
	return true;
	
}

int main(){
	
    cin>>R>>C;
    for(int i=1;i<=R;i++)
    {
    	for(int j=1;j<=C;j++)
    	{
    		cin>>maps[i][j];
    		mapss[i][j]=maps[i][j];
		}
	}
	
	if(check()==false)
	{
		cout<<"Bad placement.";
		
	}
	else
	{
		for(int i=1;i<=R;i++)
		{
			for(int j=1;j<=C;j++)
			{
				if(maps[i][j]=='#')
				{
					S++;
					maps[i][j]=S;
					dfs(i,j,S);
				}
			}
		}
		cout<<"There are "<<S<<" ships.";
	}
    
    return 0;
}
