#include<iostream>
using namespace std;

int situation[62505]={0};
int w,l;//win lose
char s;

int main()
{
	for(int i=1;cin>>s&&s!='E';i++)
	{
		if(s=='W') situation[i]=1;//me
		else situation[i]=2;//opposite
	}
	for(int i=1;1;i++)
	{
		if(situation[i]==1) w++;
		if(situation[i]==2) l++;
		if(situation[i]==0)
		{
			cout<<w<<":"<<l<<endl;
			break;
		}
		if((w-l>=2||l-w>=2)&&(l>=11||w>=11))
		{
			cout<<w<<":"<<l<<endl;
			w=0;
			l=0;
		}
		
	}
	cout<<endl;
	w=0;
	l=0;
	for(int i=1;1;i++)
	{
		if(situation[i]==1) w++;
		if(situation[i]==2) l++;
		if(situation[i]==0)
		{
			cout<<w<<":"<<l<<endl;
			break;
		}
		if((w-l>=2||l-w>=2)&&(l>=21||w>=21))
		{
			cout<<w<<":"<<l<<endl;
			w=0;
			l=0;
		}
	}
	
	return 0;
}
