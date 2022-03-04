#include <iostream>
using namespace std;
int zs(int a)
{
	for(int i=2;i<a/1.0*0.5;i++)
	{
		if(a%i==0)
		{
			int b=a/i;
			return b;
			break;
		}
	}
}
int main(int argc, char** argv) {
	int c;
	cin>>c;
	cout<<zs(c);
	return 0;
}
