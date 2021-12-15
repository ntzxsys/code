#include<bits/stdc++.h>
using namespace std;

int fbi[1030],n;
int i2[11]={1,2,4,8,16,32,64,128,256,512,1024};

int main() {
    cin>>n; 
	char t;
    for(int i=1;i<=i2[n];++i) 
	{
        cin>>t; 
        fbi[i]=t-'0';
        if(fbi[i]==0) cout<<"B"; 
  		else if(fbi[i]==1) cout<<"I"; 
  		else cout<<"F";
        for(int k=1;k<11;++k) 
		{
            if(i%i2[k]==0)
			{
                if(fbi[i]!=fbi[i-i2[k-1]]) fbi[i]=2;
                if(fbi[i]==0) cout<<"B"; 
		  		else if(fbi[i]==1) cout<<"I"; 
		  		else cout<<"F";
            }
        }
    }
    return 0;
}
