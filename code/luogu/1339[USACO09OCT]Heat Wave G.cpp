#include<iostream>
using namespace std;

int u[6205],w[6205],v[6205],dis[6205],s,t,n,m;
bool check;

int main()
{
	cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)  cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=n;i++)  dis[i]=2e9;
    dis[s]=0;
    for(int i=1;i<=n;i++)
    {
        check=true;
        for(int j=1;j<=m;j++)
        {
            if(dis[v[j]]>dis[u[j]]+w[j])
            {
                dis[v[j]]=dis[u[j]]+w[j];
                check=false;
            }
            if(dis[u[j]]>dis[v[j]]+w[j])
            {
                dis[u[j]]=dis[v[j]]+w[j];
                check=false;
			}
        }                
        if(check)  break;
    } 
    cout<<dis[t];
        
    return 0;
}
