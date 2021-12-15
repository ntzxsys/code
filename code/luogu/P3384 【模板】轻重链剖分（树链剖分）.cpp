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

const int N=1e5+10;
int n,m,r,p;

int cnt,hd[N];
struct nd{
	int nxt,v;
}g[N*2];
inline void add(int u,int v){
	g[++cnt].nxt=hd[u],g[cnt].v=v,hd[u]=cnt;
}

int fa[N],dep[N],son[N],siz[N];
inline void dfs1(int u,int f){
	fa[u]=f,dep[u]=dep[f]+1,siz[u]=1;
	int mx=-1;
	for(int i=hd[u];i;i=g[i].nxt){
		int v=g[i].v;
		if(v==f)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>mx)mx=siz[v],son[u]=v;
	}
}

int h[N],top[N],dfn[N],w[N],tim;
inline void dfs2(int u,int tp){
	top[u]=tp,dfn[u]=++tim,w[tim]=h[u];
	if(!son[u])return;
	dfs2(son[u],tp);
	for(int i=hd[u];i;i=g[i].nxt){
		int v=g[i].v;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}

struct sgt{
	int l,r,len;
	ll s,x;
}t[N*4];

inline void upd(int o){
	t[o].s=(t[o<<1].s+t[o<<1|1].s)%p;
}

inline void psd(int o){
	if(t[o].x){
		t[o<<1].x+=t[o].x;
		t[o<<1|1].x+=t[o].x;
		t[o<<1].s+=t[o<<1].len*t[o].x;
		t[o<<1|1].s+=t[o<<1|1].len*t[o].x;
		t[o<<1].x%=p,t[o<<1|1].x%=p,t[o<<1].s%=p,t[o<<1|1].s%=p;
		t[o].x=0;
	}
}

inline void build(int o,int l,int r){
	t[o].l=l,t[o].r=r,t[o].len=r-l+1;
	if(l==r){t[o].s=w[l]%p;return;}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	upd(o);
}

inline ll query(int o,int l,int r){
	if(t[o].l>=l&&t[o].r<=r)return t[o].s;
	psd(o);
	ll mid=t[o].l+t[o].r>>1,ans=0;
	if(l<=mid)ans+=query(o<<1,l,r);
	if(r>mid)ans+=query(o<<1|1,l,r);
	return ans%p;
}

inline void add(int o,int l,int r,ll k){
	k%=p;
	if(t[o].l>=l&&t[o].r<=r){
		t[o].x+=k,t[o].s+=t[o].len*k;
		t[o].x%=p,t[o].s%=p;
		return;
	}
	psd(o);
	int mid=t[o].l+t[o].r>>1;
	if(l<=mid)add(o<<1,l,r,k);
	if(r>mid)add(o<<1|1,l,r,k);
	upd(o);
}

inline void q1(int x,int y,ll z){
	z%=p;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		add(1,dfn[top[x]],dfn[x],z);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	add(1,dfn[x],dfn[y],z);
}

inline int q2(int x,int y){
	ll ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=(ans+query(1,dfn[top[x]],dfn[x]))%p;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=(ans+query(1,dfn[x],dfn[y]))%p;
	return ans;
}

inline void q3(int x,ll z){
	z%=p;
	add(1,dfn[x],dfn[x]+siz[x]-1,z);
}

inline int q4(int x){
	return query(1,dfn[x],dfn[x]+siz[x]-1)%p;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	rd(n),rd(m),rd(r),rd(p);
	for(int i=1;i<=n;i++)rd(h[i]);
	for(int i=1,u,v;i<n;i++)rd(u),rd(v),add(u,v),add(v,u);
	dfs1(r,r),dfs2(r,r);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		ll o,x,y,z;
		rd(o);
		switch(o){
			case 1:{
				rd(x),rd(y),rd(z);
				q1(x,y,z);
				break;
			}
			case 2:{
				rd(x),rd(y);
				printf("%lld\n",q2(x,y));
				break;
			}
			case 3:{
				rd(x),rd(y);
				q3(x,y);
				break;
			}
			case 4:{
				rd(x);
				printf("%lld\n",q4(x));
				break;
			}
		}
	}
	return 0;
}

