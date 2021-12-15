#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

string a1,b1;
int jw=0,lena,lenb,lenc,a[2005],b[2005],c[4005];//x位数*y位数最多得出x+y位数
 
int main()
{
    
    cin>>a1>>b1;
    lena=strlen(a1);
    lenb=strlen(b1);
    if(a1[0]=='0' || b1[0]=='0')
    {
        cout<<0;
        return 0;//判断0的情况
	}

 if(lena<lenb||(lena==lenb&&a1[0]<b1[0]))
    {
   		swap(a1,b1);
    	swap(lena,lenb);//把较小的数放在b1
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
        b1[0]=' ';//判断一下负数，a1[0] 和 b1[0]判断，i从1开始
}

    for(int i=1;i<=lena;i++)
    {	
	    a[i]=a1[lena-i+1]-'0';
	}
    for(int i=1;i<=lenb;i++)
    {
    	b[i]=b1[lenb-i+1]-'0';//逆序
	}
    for(int i=1;i<=lenb;i++)
    {
	    for(int j=1;j<=lena;j++)
	    {
		    c[i+j-1]=c[i+j-1]+(b[i]*a[j]);
		    c[i+j]+=c[i+j-1]/10;
		    c[i+j-1]%=10;//b[i]*a[j]应存放在c[i+j]中，由于数组从1开始，所以-1
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
