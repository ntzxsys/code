#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a,b;
bool isPrime[10000005]={0};
int n=10000000;
int p=0,q=0;

int aiPrime(int z)
{
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<=z;i++)
	{
		if(isPrime[i])
		{
			for(int j=2;i*j<=z;j++)
			{
				isPrime[i*j]=false;
			}
		}
	}
}



int main()
{
	
	cin>>a>>b;
	if(b>n)
	{
		b=n;
	}
	aiPrime(b);
	for(int i=a;i<=b;i++)
	{
		q=0;
		int x=i;
		while(x!=0&&isPrime[i])
		{
			q=q*10+x%10;
			x/=10;
		}
		if(q==i)
		{
			cout<<i<<endl;
		}
	}
	
    return 0;
}
