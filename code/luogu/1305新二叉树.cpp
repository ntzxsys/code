#include<bits/stdc++.h>
using namespace std;

int n;
char a[30][3];

void fun(char x)
{
    if(x!='*')
    {
        cout<<x;
        for(int i=1;i<=n;i++)
            if(a[i][0]==x)
            {
                fun(a[i][1]);
                fun(a[i][2]);
            }
    }
    return;
}

int main()
{
	
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
    fun(a[1][0]);
    
    return 0;
}
