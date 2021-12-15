#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	if(l/n==r/n)printf("%d\n",r%n);
	else printf("%d\n",n-1);
	return 0;
}
