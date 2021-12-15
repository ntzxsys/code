#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

int m,n;
int ans=0;
queue<int>q;
bool vocabulary[1005];

int main()
{
	
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(vocabulary[x]) continue;
		else
		{
			if(q.size()>=m)
			{
				vocabulary[q.front()]=false;
				q.pop();
			}
			q.push(x);
			vocabulary[x]=true;
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
