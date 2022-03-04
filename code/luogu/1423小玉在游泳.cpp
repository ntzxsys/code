#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	long double x,num=0,numm=0;
	float k=2;
	cin>>x;
	
	while(num<x)
	{
		num+=k;
		k*=0.98;
		numm++;
	}
	
	cout<<numm;
	
	return 0;
}
