#include <iostream>
#include <cstring>
using namespace std;


int n,k;

int dfs(int apple ,int plate)
{
	//��ֹ����
	if(apple==0 || plate==1) return 1; 
	
	// �ݹ���� 
	if(apple<plate)
	{
		return dfs(apple,apple);
	}else
	{
		// �� �� ��
		return dfs(apple-plate,plate)+ dfs(apple,plate-1);
	}
}

int main(){
	
		cin>>n>>k;
		cout<<dfs(n-k,k)<<endl;
	
	return 0;
}
