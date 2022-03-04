#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n; 
int a,b,c;
bool isPrime[200005]={0};

int aiPrime(int n)
{
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(isPrime[i])
		{
			for(int j=2;i*j<=n;j++)
			{
				isPrime[i*j]=false;
			}
		}
	}
}



int main()
{
	
	cin>>n;
	aiPrime(n);
	for(int i=2;i<n-2;i++)
	{
		for(int j=i;j<n-2;j++)
		{
			int k=n-i-j;
			if(k>0)
			{
				if(isPrime[k]&&isPrime[j]&&isPrime[i])
				{
					cout<<i<<" "<<j<<" "<<k;
					return 0;
				}
			}
		}
	}
	
	
    return 0;
}//30ms

