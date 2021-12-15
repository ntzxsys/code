#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int n;
	int a[1005]={0};
	cin>>n;
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=i/2;j++)
		{
            a[i]+=a[j];
        }
        a[i]++;
    }
    cout<<a[n];
	
	return 0;
}
