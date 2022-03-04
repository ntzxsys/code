#include <iostream>
using namespace std;
int main()
{
    
    int a,b,maxs=0,n=0;
    for(int i=1;i<=7;i++)
    {
    	cin>>a>>b;
    	if(a+b>maxs)
    	{
    		maxs=a+b;
    		n=i;
		}
	}
	
    cout<<n;
    
    return 0;
 } 
