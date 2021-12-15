#include <iostream>
#include <cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int ranks[25]={0};
bool flag[25]={0};
int n,r;
void fun(int now,int total,int last)
{
	if(now==total)
	{
		for(int i=1;i<=r;i++)
		{
			printf("%3d",ranks[i]);
		}
		cout<<endl;
		return ;
	}
	else
	{
		for(int i=1+last;i<=n;i++)
		{
			if(flag[i]==false)
			{
				ranks[now+1]=i;
				flag[i]=true;
				fun(now+1,total,i);
				flag[i]=false;
			}
		}
	}
}


int main(int argc, char** argv) {
	
	cin>>n>>r;
	fun(0,r,0);
	
	return 0;
}
