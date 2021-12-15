#include<iostream>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    int sum,bus[1002]={0};
    for(int i=1;i<=n;i++)
	{
        cin>>x;
        if(bus[x])
        {
        	continue;
		}
        bus[x]++;
        sum++;
    }
    cout<<sum<<endl;
    for(int i=1;i<=1000;i++)
    {
    	if(bus[i])
    	{
    		cout<<i<<" ";
		}
	}
    cout<<endl;
    
    return 0;
}
