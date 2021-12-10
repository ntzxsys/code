#include <bits/stdc++.h>
using namespace std;

int n,m,h[1000010],q[1000010],l=1,r;

int main()
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		while(l<=r&&q[l]+m<=i) ++l;
		while(r>=l&&h[i]<=h[q[r]]) --r;
		q[++r]=i;
		if(i>=m)cout<<h[q[l]];
	}
	return 0;
}

