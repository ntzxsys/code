#include <bits/stdc++.h>
using namespace std;

const int N=10010,M=100010;
int n,m,cnt,hd[N],f[N],ans;
struct nd{
	int nxt,v;
}g[M*2];

inline void add(int u,int v){
	g[++cnt].nxt=hd[u],g[cnt].v=v,hd[u]=cnt;
}

inline int bfs(int u){
	queue<int>q;q.push(u);
	f[u]=1;int cnt[3]={0,1,0};
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=hd[x],v;i;i=g[i].nxt){
			v=g[i].v;
			if(!f[v])f[v]=!(f[x]-1)+1,++cnt[f[v]],q.push(v);
			else if(f[v]==f[x])return 1;
		}
	}
	ans+=min(cnt[1],cnt[2]);
	return 0;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),add(u,v),add(v,u);
	for(int i=1;i<=n;i++)if(f[i]||!f[i]&&!bfs(i))continue;else{puts("Impossible");return 0;}
	printf("%d\n",ans);
	return 0;
}

