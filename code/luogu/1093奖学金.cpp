#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node
{
    int num;
    int c,m,e;
    int sum;
}node;

bool cmp(node x,node y)
{
	if(x.sum>y.sum)
	{
		return true;
	}
	else if(x.sum==y.sum)
	{
		if(x.c>y.c)
		{
			return true;
		}
		else if(x.c==y.c)
		{
			if(x.num<y.num)
			{
				return true;
			}
		}
	}
	
	return false;
}

int main()
{
	
	node stu[305]={0};
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>stu[i].c>>stu[i].m>>stu[i].e;
		stu[i].sum=stu[i].c+stu[i].m+stu[i].e;
		stu[i].num=i;
	}
	
	sort(stu+1,stu+n+1,cmp);
	
	for(int i=1;i<=5;i++)
	{
		cout<<stu[i].num<<" "<<stu[i].sum<<endl;
	}
	
    return 0;
}
