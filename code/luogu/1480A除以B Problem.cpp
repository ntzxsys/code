#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

long long p,b,f,n=0,pd=0;
char a[5005]={0};

int main(){
	
    cin>>a>>b;
    int len=strlen(a);
    for(int x=0;x<len;x++)
	{
		p=a[x]-48;
		n=n*10+p;
		f=n/b;
		n%=b;
		if(pd||f)
		{	
			pd=1;
			cout<<f;
		}	
	}
    
    return 0;
}
