#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
int ans=0;
priority_queue<int,vector<int>,greater<int> >q;

int main()
{
   
   cin>>n;
   for(int i=1;i<=n;i++)
   {
	   	int x;
	   	cin>>x;
	   	q.push(x);
   }
    while(q.size()>=2)
    {
    	int a=q.top();
    	q.pop();
    	int b=q.top();
    	q.pop();
    	ans+=a+b;//1+2=3,3+9=12,3+12=15
    	q.push(a+b);
	}
	cout<<ans<<endl;
    
    return 0;
}
