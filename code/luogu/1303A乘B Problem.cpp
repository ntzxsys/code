#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

string a1,b1;
int jw=0,lena,lenb,lenc,a[2005],b[2005],c[4005];//xλ��*yλ�����ó�x+yλ��
 
int main()
{
    
    cin>>a1>>b1;
    lena=strlen(a1);
    lenb=strlen(b1);
    if(a1[0]=='0' || b1[0]=='0')
    {
        cout<<0;
        return 0;//�ж�0�����
	}

 if(lena<lenb||(lena==lenb&&a1[0]<b1[0]))
    {
   		swap(a1,b1);
    	swap(lena,lenb);//�ѽ�С��������b1
	}

    if(a1[0]=='-'&&b1[0]!='-')
    {
        cout<<"-";
        a1[0]=' ';
        b1=' '+b1;
    }
    if(b1[0]=='-'&&a1[0]!='-')
    {
        cout<<"-";
        b1[0]=' ';
        a1=' '+a1;
    }
    if(a1[0]!='-'&&b1[0]!='-')
    {
        a1=' '+a1;
        b1=' '+b1;
    }
    if(a1[0]=='-'&&b1[0]=='-')
    {
        a1[0]=' ';
        b1[0]=' ';//�ж�һ�¸�����a1[0] �� b1[0]�жϣ�i��1��ʼ
}

    for(int i=1;i<=lena;i++)
    {	
	    a[i]=a1[lena-i+1]-'0';
	}
    for(int i=1;i<=lenb;i++)
    {
    	b[i]=b1[lenb-i+1]-'0';//����
	}
    for(int i=1;i<=lenb;i++)
    {
	    for(int j=1;j<=lena;j++)
	    {
		    c[i+j-1]=c[i+j-1]+(b[i]*a[j]);
		    c[i+j]+=c[i+j-1]/10;
		    c[i+j-1]%=10;//b[i]*a[j]Ӧ�����c[i+j]�У����������1��ʼ������-1
		}
	}
    
    int lenc=lena+lenb;
    while(lenc>0&&c[lenc]==0)
    {
    	lenc--;
	}
    for(int i=lenc;i>=1;i--)
    {
    	cout<<c[i];
	}
          
    return 0;
}
