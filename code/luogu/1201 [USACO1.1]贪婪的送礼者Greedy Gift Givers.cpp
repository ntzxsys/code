#include <bits/stdc++.h>
using namespace std;

int n,x,h;
char s[1000005],t[1000005];

typedef struct node
{
    char name[20];
    int sum;
}node;

node q[1000005];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>q[i].name;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=n;j++)
        {
           if(strcmp(s,q[j].name)==0)
		   {
		   		x=j;
				break;
			}
		}
        int a,b;
        cin>>a>>b;
        if(b==0) continue;
        int y=a/b;
        int m=y*b;
        q[x].sum-=m;
        for(int k=1;k<=b;k++)
        {
            cin>>s;
            for(int g=1;g<=n;g++)
            {
            	if(strcmp(s,q[g].name)==0)
				{
					h=g;
					break;
				}
			}
            q[h].sum+=y;
        }
    }
    for(int i=1;i<=n;i++)
    {
    	cout<<q[i].name<<' '<<q[i].sum<<endl;
	}
        
    return 0;
}
