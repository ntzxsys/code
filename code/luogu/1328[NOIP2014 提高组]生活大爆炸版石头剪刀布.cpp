#include<bits/stdc++.h>
using namespace std;

int n,na,nb;
int aorder[205],border[205];
int ansa,ansb;
int wl[10][10]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};


int main()
{
	
	cin>>n>>na>>nb;
	for(int i=0;i<na;i++)
	{
		cin>>aorder[i];
	}
	for(int i=0;i<nb;i++)
	{
		cin>>border[i];
	}
	for(int i=0;i<n;i++)
	{
		ansa+=wl[aorder[i%na]][border[i%nb]];
		ansb+=wl[border[i%nb]][aorder[i%na]];
	}
	cout<<ansa<<" "<<ansb;
    
    return 0;
}
