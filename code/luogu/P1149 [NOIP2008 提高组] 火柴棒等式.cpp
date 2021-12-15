#include <bits/stdc++.h>
using namespace std;

int n,h[2010]={6,2,5,5,4,5,6,3,7,6},ans;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=10,x;i<=2000;i++)h[i]=h[i%10]+h[i/10];
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			if(h[i]+h[j]+h[i+j]+4==n)++ans;
	printf("%d\n",ans);
	return 0;
}

