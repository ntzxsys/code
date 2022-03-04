#include <iostream>
#include <cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool flag[15]={0};

int ranks[15]={0};


void fun(int now,int t,int n)
{
	if(now==t)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%5d",ranks[i]);
		}
		cout<<endl;
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==false)
			{
				ranks[now+1]=i;
				flag[i]=true;
				fun(now+1,t,n);
				flag[i]=false;
			}
		}
	}
}

int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	fun(0,n,n);
	
	
	return 0;
}
