#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


char ans[35]={0};

int nToTen(int n,char s[]){
	int ten=0;
	
	int len=strlen(s);
	int num=0;
	//k����Ϊn
	int k=1; 
	for(int i=len-1;i>=0;i--){
		//'0'~'9' 0~9
		//'A'~'F' 10~15
		//ten=s[i] * k;
		if(s[i]>='0'&&s[i]<='9'){
			// ASCII ������ ��ֵ 
			//'0'  0 
			num=s[i]-'0'; 
		}else{//'A'~'F' 10~15
			num=s[i]- '7'; 
		}
		ten+=(num*k);
		k*=n;
	}
	
	
	return ten;
}

int tenToM(int ten,int m,char ans[]){
	//���ϳ�m,����������ֱ����Ϊ0��������������ϡ�
	//0~9   '0'~'9'
	//10~15  'A'~'F'
	int x=ten;
	int index=0;
	int num=0;
	
	while(ten!=0)
	{
		ten/=m;
		x=x%m;
		ans[index]=x;
		if(ans[index]>=0&&ans[index]<=9)
		{
			ans[index]=ans[index]+'0';
		}
		else
		{
			ans[index]=ans[index]+'7';
		}
		x=ten;
		
		
		num++;
		index++;
	}
	
	return num;
} 

int main(int argc, char** argv) {
	int n,m;
	char s[35]={0};
	char ans[35]={0};
	cin>>n;
	cin>>s;
	cin>>m;
	//1. n����ת����10����
	int ten=nToTen(n,s);
	//2. 10����ת����m����
	int len=tenToM(ten,m,ans);
	
	for(int i=len-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
