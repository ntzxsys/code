#include <iostream>
#include <cstring>
using namespace std;

string a,b;
int ans=1,num=1;

int main(){
	cin>>a>>b; 
    for(int i=0;i<a.length();i++) 
	{
		ans*=a[i]-'@'; 
	}
    for(int i=0;i<b.length();i++) 
	{
		num*=b[i]-'@'; 
	}
    ans%=47;
	num%=47;
    if(ans == num) 
	{
		cout<<"GO"; 
	}
    else 
	{
		cout<<"STAY";
	} 
    return 0;
}
