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

char s0[11000010],s[22000010];
int n,len[22000010],ans;

int main(){
	freopen("P3805_1.in","r",stdin);
	freopen("P3805.out","w",stdout);
	scanf("%s",s0+1);
	n=strlen(s0+1);
	s[0]='|',s[1]='#';
	for(int i=1;i<=n;i++){
		s[i*2]=s0[i],s[i*2+1]='#';
	}
	s[n*2+2]='$';n=n*2+2;
	int mx=0,p=0;
	for(int i=1;i<=n;i++){
		if(mx<i)len[i]=1;
		else len[i]=min(len[p*2-i],mx-i+1);
		while(s[i-len[i]]==s[i+len[i]])++len[i];
		if(len[i]+i>mx)mx=len[i]+i-1,p=i;
		if(len[i]>ans)ans=len[i]-1;
	}
	printf("%d\n",ans);
	return 0;
}

