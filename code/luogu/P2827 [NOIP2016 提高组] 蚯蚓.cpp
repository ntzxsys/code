#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M=7e6+10;
ll n,m,q,u,v,t,add;
ll h[M],x[M],y[M],f[3]={1,1,1};

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&q,&u,&v,&t);
	for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
	sort(h+1,h+n+1,greater<ll>());
	//for(int i=1;i<=n;i++)printf("%lld%c",h[i],i==n?'\n':' ');
	for(int i=1,tmp;i<=m;i++){
		//printf("%lld %lld %lld %lld %lld %lld ",f[0],f[1],f[2],h[f[0]],x[f[1]],y[f[2]]);
		if(f[0]>n){if(x[f[1]]>y[f[2]])tmp=x[f[1]],++f[1];else tmp=y[f[2]],++f[2];}
		else if(h[f[0]]>x[f[1]]){
			if(h[f[0]]>y[f[2]])tmp=h[f[0]],++f[0];
			else tmp=y[f[2]],++f[2];
		}
		else if(x[f[1]]>y[f[2]])tmp=x[f[1]],++f[1];
			 else tmp=y[f[2]],++f[2];
		tmp+=add;
		if(i%t==0)printf("%lld ",tmp);
		//puts("");
		add+=q;
		x[i]=tmp*u/v,y[i]=tmp-x[i];
		//printf("%lld %lld\n",x[i],y[i]);
		x[i]-=add,y[i]-=add;
	}
	puts("");
	//printf("%lld\n%lld %lld %lld\n",add,f[0],f[1],f[2]);
	priority_queue<ll>q;
	for(int i=f[0];i<=n;i++)q.push(h[i]);
	for(int i=f[1];i<=m;i++)q.push(x[i]);
	for(int i=f[2];i<=m;i++)q.push(y[i]);
	for(int i=1;!q.empty();i++){
		if(i%t==0)printf("%lld ",q.top()+add);
		q.pop();
	}
	puts("");
	return 0;
}

