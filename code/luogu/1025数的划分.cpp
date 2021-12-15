#include <iostream>
#include <cstring>
using namespace std;


int n,k;

int dfs(int apple ,int plate)
{
	//终止条件
	if(apple==0 || plate==1) return 1; 
	
	// 递归过程 
	if(apple<plate)
	{
		return dfs(apple,apple);
	}else
	{
		// 满 、 空
		return dfs(apple-plate,plate)+ dfs(apple,plate-1);
	}
}

int main(){
	
		cin>>n>>k;
		cout<<dfs(n-k,k)<<endl;
	
	return 0;
}
