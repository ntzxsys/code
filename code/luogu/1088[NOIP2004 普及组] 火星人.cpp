#include<bits/stdc++.h>
using namespace std;

int a[10005],n,m;

int main()
{
	
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	while(m--) next_permutation(a,a+n);
	for(int i=0;i<n;i++)  cout<<a[i]<<" ";
    
    return 0;
}
