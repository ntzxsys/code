#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1010,M=100010,inf=0x3f3f3f3f;
ll n,m,hd[N],h[N],cnt,cn,d[N],vis[N],ans;
struct nd{
	int nxt,v,w;
}g[M],e[M];
struct pq{
	ll w,v;
	pq(int _v,int _w){v=_v,w=_w;};
	bool operator <(const pq &a)const{return w>a.w;}
};

inline void add(ll u,ll v,ll w){
	g[++cnt].nxt=hd[u],g[cnt].v=v,g[cnt].w=w,hd[u]=cnt;
}

inline void ad(ll u,ll v,ll w){
	e[++cn].nxt=h[u],e[cn].v=v,e[cn].w=w,h[u]=cn;
}

inline void dij(){
	priority_queue<pq>q;
	fill(d+1,d+n+1,inf);
	q.push((pq){1,0}),d[1]=0;
	while(!q.empty()){
		while(!q.empty()&&vis[q.top().v])q.pop();
		ll u=q.top().v;vis[u]=1;
		for(ll i=hd[u];i;i=g[i].nxt){
			ll v=g[i].v,w=g[i].w;
			if(d[v]>w+d[u])d[v]=d[u]+w,q.push((pq){v,d[v]});
		}
	}
}

inline void dijk(){
	priority_queue<pq>q;
	fill(d+1,d+n+1,inf);
	memset(vis,0,sizeof(vis));
	q.push((pq){1,0}),d[1]=0;
	while(!q.empty()){
		while(!q.empty()&&vis[q.top().v])q.pop();
		ll u=q.top().v;vis[u]=1;
		for(ll i=h[u];i;i=e[i].nxt){
			ll v=e[i].v,w=e[i].w;
			if(d[v]>w+d[u])d[v]=d[u]+w,q.push((pq){v,d[v]});
		}
	}
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w),ad(v,u,w);
	}
	dij();
	for(ll i=2;i<=n;i++)ans+=d[i];//,printf("%lld %lld\n",i,d[i]);
	dijk();
	for(ll i=2;i<=n;i++)ans+=d[i];
	printf("%lld\n",ans);
	return 0;
}

