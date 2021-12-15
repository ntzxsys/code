#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005]={0};
int b[100005]={0};

void msort(int s,int t)
{
	if(s==t) return ;
	int mid=(s+t)/2;
	msort(s,mid);
	msort(mid+1,t);
	int i=s,j=mid+1,k=s;
	while(i<=mid&&j<=t)
	{
		if(a[i]>a[j])
		{
			b[k]=a[j];
			k++;
			j++;
		}
		else
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}

	while(j<=t)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	
	for(int i=s;i<=t;i++)
	{
		a[i]=b[i];
	}
}


int main()
{
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	msort(1,n);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}
