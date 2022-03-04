#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;



int main()
{
	
	char s1[2005]={0},s2[2005]={0};
	int n1[2005]={0},n2[2005]={0},ans[4005]={0};
    cin>>s1>>s2;
    
    int l1=strlen(s1);
    int l2=strlen(s2);
    
    for(int i=0;i<l1;i++)
	{
		n1[i]=s1[l1-i-1]-'0';
	}
	for(int i=0;i<l2;i++)
	{
		n2[i]=s2[l2-i-1]-'0';
	}
	
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			ans[i+j]=ans[i+j]+n1[i]*n2[j];
			
			ans[i+j+1]+=(ans[i+j]/10);
			ans[i+j]%=10;
		}
	}
    
    bool flag=false;
    
    for(int i=l1+l2;i>=0;i--)
    {
    	if(ans[i]!=0||i==0)
    	{
    		flag=true;
		}
		if(flag)
		{
			cout<<ans[i];
		}
	}
    
    
    return 0;
}
