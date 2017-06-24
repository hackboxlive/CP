#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i=l; i<=r; i++)
#define	dow(i, l, r) for(int i=l; i>=r; i--)
#define travel(x) for(edge *p=fir[x]; p; p=p->n)
#define travel_sap(x) for(edge *p=fir[x]; p; p=p->n)
#define clr(x,c) memset(x, c, sizeof(x))
typedef pair<int,int> Pii;
typedef long long ll;
#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define lowbit(x) (x&-x)
#define l(x) Left[x]
#define r(x) Right[x]

#define maxn 500109
#define maxm 500109

inline int read()
{
	int x=0, f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0', ch=getchar();
	return x*f;
}
int arr[100100];
struct nodee	{
	int val;
	int pos;
	int newpos;
}cparr[maxm];
int que[100100][3];
struct edge{int y; edge *n;} e[maxm], *fir[maxn], *pt=e;
inline void AddE(int x, int y){pt->y=y, pt->n=fir[x], fir[x]=pt++;}
int n, m, Q, v[maxn], w[maxn], c[maxn], last[maxn], cnt[maxn]; ll A[maxn], sum; bool vis[maxn];
int cn, L[maxn], R[maxn], h[17][maxn], dep[maxn], pos[maxm], Bk, B[maxm];
struct node{int l,r,t,id;} q[maxn]; int Q1, LCA[maxn];
bool cmp(const node &a, const node &b){return B[a.l]<B[b.l] || (B[a.l]==B[b.l] && B[a.r]<B[b.r]) || (B[a.l]==B[b.l] && B[a.r]==B[b.r] && a.t<b.t);}
struct node2{int x,pre,now;} p[maxn]; int Q2;

void dfs(int x)
{
    pos[L[x]=++cn]=x;
    rep(o, 1, 16) if (dep[x]>=(1<<o)) h[o][x]=h[o-1][h[o-1][x]]; else break;
    travel(x) if (p->y!=h[0][x]) h[0][p->y]=x, dep[p->y]=dep[x]+1, dfs(p->y);
    pos[R[x]=++cn]=x;
}

inline int lca(int x, int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	if (dep[x]!=dep[y])
	{
		int tmp=dep[x]-dep[y];
		rep(o, 0, 16) if (tmp&(1<<o)) x=h[o][x], tmp-=(1<<o); else if (!tmp) break;
	}
	dow(o, 16, 0) if (h[o][x]!=h[o][y]) x=h[o][x], y=h[o][y];
	return x==y?x:h[0][x];
}
inline void Vis(int x)
{
	if (vis[x]) sum-=1LL*w[cnt[c[x]]--]; else sum+=1LL*w[++cnt[c[x]]];
	vis[x]^=1;
}
inline void change(int x, int col)
{
	if (vis[x]) Vis(x),c[x]=col,Vis(x); else c[x]=col;
}
bool comp1(const nodee &p1,const nodee &p2)	{
	return p1.val<p2.val;
}
bool comp2(const nodee &p1,const nodee &p2)	{
	return p1.pos<p2.pos;
}
vector<int> vv;
int main()
{
	n=read();
	Q=read();
	w[1]=1;
	int cctr=1;
	for(int i=2;i<=n;i++)	{
		w[i]=0;
	}
	for(int i=1;i<=n;i++)	{
		scanf("%d",&arr[i]);
		cparr[cctr].val=arr[i];
		cparr[cctr].pos=i;
		cctr++;		
	}
	rep(i, 1, n-1) {int x=read(), y=read(); AddE(x,y); AddE(y,x);}
	for(int i=1;i<=Q;i++)	{
		scanf("%d%d%d",&que[i][0],&que[i][1],&que[i][2]);
		if(que[i][0]==2)	{
			cparr[cctr].val=que[i][2];
			cparr[cctr].pos=cctr;
			cctr++;
		}
	}
	sort(cparr+1,cparr+cctr,comp1);
	vv.push_back(cparr[1].val);
	cparr[1].newpos=1;
	int vvl=1;
	for(int i=2;i<cctr;i++)	{
		if(cparr[i].val != cparr[i-1].val)	{
			vv.push_back(cparr[i].val);
			vvl++;
			cparr[i].newpos=vvl;
		}
		else	{
			cparr[i].newpos=vvl;
		}
	}
	m=vvl;
	sort(cparr+1,cparr+cctr,comp2);
	for(int i=1;i<=n;i++)	{
		c[i]=cparr[i].newpos;
	}
	int gg=1;
	for(int i=1;i<=Q;i++)	{
		if(que[i][0]==2)	{
			que[i][2]=cparr[n+gg].newpos;
			gg++;
		}
	}
	for(int i=1;i<=m;i++)	{
		v[i]=vv[i-1];
	}
	dfs(1);
	
	Bk=n;
	if (n<=100000) Bk=1750;
	if (n<=90000) Bk=1630;
	if (n<=80000) Bk=1510;
	if (n<=10000) Bk=390;
	rep(i, 1, cn) B[i]=(i-1)/Bk+1;
	rep(i, 1, Q)
	{
		int op=que[i][0], x=que[i][1], y=que[i][2];
		if (op==1)
		{
			if (L[x]>L[y]) swap(x,y);
			int z=lca(x,y);
			++Q1, q[Q1]=(node){x==z?L[x]:R[x], L[y], Q2, Q1}, LCA[Q1]=(x!=z&&y!=z ? z : 0);
		} else p[++Q2]=(node2){x, last[x], y}, last[x]=y;
	}
	sort(q+1, q+1+Q1, cmp);
	int l=1, r=0, now=0; rep(i, 1, Q1)
	{
		while (now<q[i].t) now++, change(p[now].x, p[now].now);
		while (q[i].t<now) change(p[now].x, p[now].pre), now--;
		while (l<q[i].l) Vis(pos[l++]);
		while (q[i].r<r) Vis(pos[r--]);
		while (q[i].l<l) Vis(pos[--l]);
		while (r<q[i].r) Vis(pos[++r]);
		if (LCA[q[i].id]) Vis(LCA[q[i].id]);
		A[q[i].id]=sum;
		if (LCA[q[i].id]) Vis(LCA[q[i].id]);
	}
	rep(i, 1, Q1) printf("%lld\n", A[i]);
	return 0;
}