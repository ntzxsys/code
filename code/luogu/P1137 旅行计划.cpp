#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
typedef long long ll;

template<typename T>inline void rd(T &x){
	x=0;ll f=1;char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=x*10+c-'0';
	x*=f;
}

const int N=1e5+10,M=2e5+10;
int n,m,cnt,hd[N],in[N],ans[N];
struct nd{
	int nxt,v;
}g[M];

inline void add(int u,int v){
	g[++cnt].nxt=hd[u],g[cnt].v=v,hd[u]=cnt;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	rd(n),rd(m);
	for(int i=1,u,v;i<=m;i++)rd(u),rd(v),add(u,v),++in[v];
	queue<int>q;
	for(int i=1;i<=n;i++)if(!in[i])q.push(i),ans[i]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=hd[x];i;i=g[i].nxt){
			int v=g[i].v;
			--in[v];ans[v]=max(ans[v],ans[x]+1);
			if(!in[v])q.push(v);
		}
	}
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}

