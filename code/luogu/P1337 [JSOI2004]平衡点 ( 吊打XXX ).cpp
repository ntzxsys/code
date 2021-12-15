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

int n;
double ansx,ansy,answ;
struct nd{
	int x,y,w;
}h[1010];

inline double calc(double x,double y){
	double r=0,dx,dy;
	for(int i=1;i<=n;i++){
		dx=x-h[i].x;
		dy=y-h[i].y;
		r+=sqrt(dx*dx+dy*dy)*h[i].w;
	}
	return r;
}

inline void SA(){
	double tem=3000;
	while(tem>1e-15){
		double nx=ansx+(rand()*2-RAND_MAX)*tem;
		double ny=ansy+(rand()*2-RAND_MAX)*tem;
		double nw=calc(nx,ny);double delta=nw-answ;
		if(delta<0)ansx=nx,ansy=ny,answ=nw;
		else if(exp(-delta/tem)*RAND_MAX>rand())ansx=nx,ansy=ny;
		tem*=0.98;
	}
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	rd(n);
	for(int i=1;i<=n;i++)rd(h[i].x),rd(h[i].y),rd(h[i].w),ansx+=h[i].x,ansy+=h[i].y;
	ansx/=n,ansy/=n,answ=calc(ansx,ansy);
	for(int t=5;t;--t)SA();
	printf("%.3lf %.3lf\n",ansx,ansy);
	return 0;
}
