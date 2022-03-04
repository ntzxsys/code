#include <iostream>
#include <cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int a;
	float num=0;
	cin>>a;
	if(a<=150)
	{
		num=a/1.0*0.4463;
	}
	if(a>150&&a<=400)
	{
		num=0.4463*150+0.4663*(a/1.0-150);	
	} 
	if(a>400)
	{
		num=0.4463*150+0.4663*250+0.5663*(a/1.0-400);
	}
	printf("%.1f",num);
	
	return 0;
}
