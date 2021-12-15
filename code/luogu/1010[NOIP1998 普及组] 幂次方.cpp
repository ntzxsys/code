#include<bits/stdc++.h>
using namespace std;

int n;

void search(int x)
{
	if(n!=0)
	{
		int p=1,q=0;
		cout<<"2";
		while(x>=p)
		{
			++q; 
			p*=2;	
		}
		--q;
		if(q==0||q==2) cout<<"("<<q<<")";
        if(q>=3)
		{
			cout<<"("; 
			search(q);
			cout<<")";
		}
		x-=p/2;
		if(x)
		{
			cout<<"+";
			search(x);
		}
	}
}
int main()
{
	cin>>n;
	search(n);
	
	return 0;	
} 
