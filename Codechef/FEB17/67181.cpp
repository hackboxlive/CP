#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i = j; i <= k; i++)
#define dow(i,j,k) for(register int i = j; i >= k; i--)
#define ez(i,j) for(edge*i = head[j]; i; i=i->next)
#define maxn 100005
#define ll long long
using namespace std;

inline int read()
{
	int x=0, f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0', ch=getchar();
	return x*f;
}

int ti = 0, dep[maxn], pos[maxn<<1], L[maxn], R[maxn], fa[maxn][17], bin[17];
struct edge{ int to; edge*next; } e[maxn<<1], *pt = e, *head[maxn];
inline void add(int x,int y) { pt->to = y, pt->next = head[x], head[x] = pt++; pt->to = x, pt->next = head[y], head[y] = pt++; }
#define to i->to
inline void dfs(int x) {
	pos[L[x] = ++ti] = x;
	rep(i,1,16) if( dep[x] >= bin[i] ) fa[x][i] = fa[fa[x][i-1]][i-1]; else break;
	ez(i,x) if( to != fa[x][0] ) dep[to] = dep[x] + 1, fa[to][0] = x, dfs(to);
	pos[R[x] = ++ti] = x;
}

int v[maxn], w[maxn], last[maxn], c[maxn], B[maxn<<1], LCA[maxn], val[maxn];
inline int lca(int x,int y) {
	if( dep[x] < dep[y] ) swap(x,y);
	if( dep[x] - dep[y] != 0 ) {
		int dis = dep[x] - dep[y];
		rep(i,0,16) if( bin[i] & dis ) x = fa[x][i], dis - bin[i]; else if( !dis ) break; 
	}
	if( x == y ) return x;
	dow(i,16,0) if( fa[x][i] != fa[y][i] ) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

struct node{
int l, r, t, id; bool operator < (const node&rhs) const { return B[l]<B[rhs.l] || (B[l]==B[rhs.l] && B[r]<B[rhs.r]) || (B[l]==B[rhs.l] && B[r]==B[rhs.r] && t<rhs.t); }
} nod[maxn];
struct col{ int x, pre, now; } p[maxn]; int q2 = 0, q1 = 0;
ll res = 0, ans[maxn]; bool vis[maxn];
inline void update(int x) {
	if( vis[x] ) res -= 1ll * v[c[x]] * w[val[c[x]]--]; else res += 1ll * v[c[x]] * w[++val[c[x]]];
	vis[x] ^= 1;
}
inline void change(int x,int col) { if( vis[x] ) update(x), c[x] = col, update(x); else c[x] = col; }

int main() {
	bin[0] = 1; rep(i,1,16) bin[i] = bin[i-1] << 1;
	int n = read(), m = read(), q = read(), Bk = n;
	rep(i,1,m) v[i] = read(); rep(i,1,n) w[i] = read();
	rep(i,1,n-1) add(read(),read());
	rep(i,1,n) c[i] = last[i] = read(); dfs(1);
	if (n<=100000) Bk=1750;
	if (n<=90000) Bk=1630;
	if (n<=80000) Bk=1510;
	if (n<=10000) Bk=390;
	rep(i,1,ti) B[i] = (i - 1) / Bk + 1;
	int flag, x, y, z;
	rep(i,1,q) {
		flag = read(), x = read(), y = read();
		if( flag ) {
			if( L[x] > L[y] ) swap(x,y);
			z = lca(x,y); 
			q1++; nod[q1] = (node) {z == x? L[x] : R[x], L[y], q2, q1}; LCA[q1] = (z != x && z != y ? z : 0) ;  
		} else p[++q2] = (col) {x,last[x],y}, last[x] = y; 
	}
	sort(nod+1,nod+1+q1);
	int l = 1, r = 0, now = 0;
	rep(i,1,q1) {
		while( nod[i].t > now ) now++, change(p[now].x,p[now].now);
		while( nod[i].t < now ) change(p[now].x,p[now].pre), now--;
		while( l < nod[i].l ) update(pos[l++]);
		while( nod[i].r < r ) update(pos[r--]);
		while( nod[i].l < l ) update(pos[--l]);
		while( r < nod[i].r ) update(pos[++r]);
		if( LCA[nod[i].id] ) update(LCA[nod[i].id]);
		ans[nod[i].id] = res;
		if( LCA[nod[i].id] ) update(LCA[nod[i].id]);
	}
	rep(i,1,q1) printf("%lld\n", ans[i]);
	return 0;
}