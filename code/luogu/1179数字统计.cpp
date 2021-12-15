#include <iostream>
using namespace std;
int main() {
	
	long long a,b,s=0,y;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		y=i;
		while(y!=0)
		{
			if(y%10==2)
		{
		s++;
		}
		y/=10;
	}
	}
	cout<<s;
	
	return 0;
}
