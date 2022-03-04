#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char str[1000005];
char key[15],word[15];
int flag=0;


int main()
{
    int cnt=0,index=-1,head=0,ans=-1;
    cin>>key;
    getchar();
    cin.getline(str,1000005);
    int l1=strlen(str);
    for(int i=0;i<=l1;i++)
    {
		if(str[i]==' '||i==l1)
		{
			str[i]='\0';
			strcpy(word,&str[head]);
			//cout<<word<<endl;
			if(strcasecmp(key,word)==0)
			{
				cnt++;
				if(cnt==1)
				{
					index=head;
				}
			}
			head=i+1;
		}		
	}
    if(cnt!=0)
    {
    	cout<<cnt<<" "<<index;
	}
	else
	{
		cout<<"-1";
	}
    
    
    
    return 0;
}
