#include <iostream>
#include <cstdio>
using namespace std;

int n;
int cnt=0;
int hang[15]={0};
int lie[15]={0};
int ans[15]={0};// ans[i] =y   => ��i�������ڵ�y�� 
int zdjx[30]={0};
int ydjx[30]={0};//���ҶԽ��� 

void print()
{
    int i;
	cnt++;
    if(cnt<=3)
	{
        for(i=1;i<=n;i++)
		{
			cout<<hang[i]<<" ";
		}
        cout<<endl;
    }
}
    

//void dfs(int done)
//{
	// done - �Ѿ�ȷ�������� 
//	int y;
	// ȷ����done+1 �����ӵ�λ��
//	for(int i=1;i<=n;i++)
//	{
//		y=i;
		// �ж� ��x,y�� �ܷ�����
//		int k=fun1(x,y);
//		int kk=fun2(x,y);
		
    
int dfs(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(lie[j]==0&&zdjx[i+j]==0&&ydjx[i-j+n]==0)
		{
            hang[i]=j; 
            lie[j]=1; 
            zdjx[i+j]=1;
			ydjx[i-j+n]=1;
            if(i==n)
			{
				print();
			}
            else
			{
				dfs(i+1);
			}
            lie[j]=0;
			zdjx[i+j]=0;
			ydjx[i-j+n]=0;//����
        }
	}
            
    return 0;
}
		
		
		
//        if(lie[y]==false&&zdjx[y+done]==false&&ydjx[y-done+n]==false)
//		{
//            hang[y]=true; 
//            lie[done]=true;
//            zdjx[y+done]=true;
//			ydjx[y-done+n]=true;
//			ans[i]=hang[y];
//			if(i==n)
//			{
//				couts();
//			}
//			else
//			{
//				dfs(done+1);
//			}
//		
//            lie[done]=false;
//			zdjx[y+done]=false;
//			ydjx[y-done+n]=false;
//		}
			
//			ans[x]=y;
//			dfs(done+1);
//			hang[x]=false;
//			lie[y]=false;
//	}
		// �С��С������Խ���ƽ���� ��ֻ����һ������
			// ���� =�� ����
			// �޸�״̬
			// ̽�� ȷ����һ��
			
			// ����״̬ 
//} 
	
int main(){
	cin>>n;
	
	dfs(1); 
	
	cout<<cnt; 
	return 0;
}
