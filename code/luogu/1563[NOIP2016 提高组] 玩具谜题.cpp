#include <bits/stdc++.h>
using namespace std;

int main()
{
	
    int dir[100000]={0};//³¯Ïò
    int n,m,i,bot=0,a,s;
    char occ[100000][15]={{0}};//Ö°Òµ
    cin>>n>>m;
    for(i=0;i<n;++i) cin>>dir[i]>>occ[i];
    for(i=0;i<m;++i)
	{
        cin>>a>>s;
        if(dir[bot]==a)
        {
            s*=-1;
        }
        bot=(bot+n+s)%n;
    }
    cout<<occ[bot];
    
    return 0;
}
