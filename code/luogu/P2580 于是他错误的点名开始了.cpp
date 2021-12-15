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

int n,m,cnt;
char s[50];
struct nd{
	int vis,fin,son[27];
	nd(){
		cnt=fin=0;
		memset(son,0,sizeof(son));
	}
}trie[500010];

inline void insert(char *s){
	int len=strlen(s),v,u=0;
	for(int i=0;i<len;i++){
		v=s[i]-'a';
		if(!trie[u].son[v])
			trie[u].son[v]=++cnt;
		u=trie[u].son[v];
	}
	trie[u].fin=1;
}

inline int find(char *s){
	int len=strlen(s),v,u=0;
	for(int i=0;i<len;i++){
		v=s[i]-'a';
		if(!trie[u].son[v])return 3;
		u=trie[u].son[v];
	}
	if(!trie[u].fin)return 3;
	if(!trie[u].vis)return trie[u].vis=1;
	return 2;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	rd(n);
	for(int i=1;i<=n;i++)scanf("%s",s),insert(s);
	rd(m);
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		int k=find(s);
		switch(k){
			case 1:{
				puts("OK");
				break;
			}
			case 2:{
				puts("REPEAT");
				break;
			}
			case 3:{
				puts("WRONG");
				break;
			}
		}
	}
	return 0;
}

