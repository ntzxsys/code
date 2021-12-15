#include <iostream>
#include <cstring>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	char m[5005]={0};
	long long n;
	int s[5005]={0},ans;
	
	cin>>m>>n;
	
	int l=strlen(m);
	for(int i=0;i<l;i++){
		s[i]=m[i]-'0';
	}
	
	int re=0;
	bool flag=false;
	for(int i=0;i<l;i++){
		re=re*10+s[i];
		ans=re/n;
		re%=n;
		if(ans!=0||i==l-1) flag=true;
		if(flag) cout<<ans;
	}
	
	
	
	return 0;
}
