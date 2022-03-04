#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int a,b,c,d,e,f,num=0,num1=0,num2=0;
	cin>>a>>b>>c>>d;
	num1=a*60+b;
	num2=c*60+d;
	num=num2-num1;
	e=num/60;
	f=num-(e*60);
	cout<<e<<" "<<f;
	
	return 0;
}
