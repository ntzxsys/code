#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n,m;//��ׯ��������·����
int ii,jj,ww;//��㣻�յ㣻Ȩֵ 
int q;
int x,y,tx,t[205];//��㣻�յ㣻������գ��� 
int dis[205][205];
int G[205][205];//����Ȩֵ 
bool vis[205];

int main()
{
    
    memset(dis,0x3f,sizeof(dis));
    memset(G,0x3f,sizeof(G));
    memset(t,0x3f,sizeof(t));
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	cin>>t[i];
    	dis[i][i]=0;
	}
	for(int i=0;i<m;i++)
	{
		cin>>ii>>jj>>ww;
		dis[ii][jj]=dis[jj][ii]=ww;
	}
    cin>>q;
    int k=0;
    for(int l=1;l<=q;l++)
    {
        cin>>x>>y>>tx;
        while(t[k]<=tx)
        {
            for(int i=0;i<n;i++)
            {
            	for(int j=0;j<n;j++)
            	{
            		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}  
            k++;
        }
        if(dis[x][y]==0x3f3f3f3f||t[x]>tx||t[y]>tx) cout<<"-1"<<endl;
        else cout<<dis[x][y]<<endl;
     }
	
	
    
    return 0;
}
