#include <iostream>
#include <cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int n,k=0;
	cin>>n; 
	while(n!=0)
	{
		k=n%10+k*10;
		n/=10;
	}
	cout<<k;
	
	return 0;
}
