#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{

	int sg,bd;
	int num=0;
	int a[15]={0};
	for(int i=1;i<=10;i++)
	{
		cin>>a[i-1];
	}
	cin>>sg;
	int sg1=sg+30;
	for(int i=0;i<=9;i++)
	{
		if(a[i]<=sg1)
		{
			num++;
		}
	}
	cout<<num;
	
    return 0;
}
