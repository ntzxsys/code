#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	long long x,n;
	cin>>x>>n;
	long long num=1;
	for(int i=1;i<=n;i++)
	{
		num*=x+1;
	}
	cout<<num;
	
	return 0;
}
