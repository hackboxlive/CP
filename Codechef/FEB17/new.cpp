#include <bits/stdc++.h>
using namespace std;
inline int read()	{
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')	{
		if(ch=='-')	{
			f=-1;
		}
		ch=getchar();
	}
	while('0'<=ch && ch>='9')	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int arr[100100];
int que[100100][3];
int n,m,Q;
int v[100100];
int w[100100];
int c[100100];
int last[100100];
int cnt[100100];
long long int A[100100];
long long int sum;
bool vis[100100];
int cn;
int L[100100];
int R[100100];
int h[17][100100];
int dep[100100];
int pos[200200];
int fbk;
int fb[200200];
int Q1;
int lca[100100];
int Q2;
struct node{
	int l;
	int r;
	int t;
	int id;
}q[100100];
struct node2{
	int x;
	int pre;
	int now;
}fp[100100];
struct nodee	{
	int val;
	int pos;
	int newpos;
}cparr[200200];
struct edge	{
	int y;
	edge * n;
}fe[200200],*ffir[100100],*fpt=fe;
inline void addEdge(int x,int y)	{
	fpt -> y = y;
	fpt -> n = ffir[x];
	ffir[x] = fpt++;
}
bool cmp(const node &p1,const node &p2)	{
	if(fb[p1.l]!=fb[p2.l])	{
		return fb[p1.l]<fb[p2.l];
	}
	if(fb[p1.r]!=fb[p2.r])	{
		return fb[p1.r]<fb[p2.r];
	}
	return fb[p1.t]<fb[p2.t];
//	return fb[p1.l]<fb[p2.l] || (fb[p1.l]==fb[p2.l] && fb[p1.r]<fb[p2.r]) || (fb[p1.l]==fb[p2.l] && fb[p1.r]==fb[p2.r] && p1.t<p2.t);
}
bool comp1(const nodee &p1,const nodee &p2)	{
	return p1.val<p2.val;
}
bool comp2(const nodee &p1,const nodee &p2)	{
	return p1.pos<p2.pos;
}
void dfs(int x)	{
	L[x]=++cn;
	pos[L[x]]=x;
	for(int i=1;i<=16;i++)	{
		if(dep[x]>=(1<<i))	{
			h[i][x]=h[i-1][h[i-1][x]];
		}
		else	{
			break;
		}
	}
	for(edge *pp=ffir[x];pp;pp=pp -> n)	{
		if(pp -> y != h[0][x])	{
			h[0][pp -> y]=x;
			dep[pp -> y]=dep[x]+1;
			dfs(pp -> y);
		}
	}
	R[x]=++cn;
	pos[R[x]]=x;
	return;
}
inline int lcafunc(int x,int y)	{
	if(dep[x]<dep[y])	{
		swap(x,y);
	}
	if(dep[x]!=dep[y])	{
		int tmp=dep[x]-dep[y];
		for(int i=0;i<=16;i++)	{
			if(tmp & (1<<i))	{
				x=h[i][x];
				tmp-=(1<<i);
			}
			else if(!tmp)	{
				break;
			}
		}
	}
	for(int i=16;i>=0;i--)	{
		if(h[i][x] != h[i][y])	{
			x=h[i][x];
			y=h[i][y];
		}
	}
	return x==y?x:h[0][x];
}
inline void visited(int x)	{
	long long int tt=1;
	if(vis[x])	{
		sum-=tt*w[cnt[c[x]]--];
	}
	else	{
		sum+=tt*w[++cnt[c[x]]];
	}
	vis[x]^=1;
}
inline void update(int x,int val)	{
	if(vis[x])	{
		visited(x);
		c[x]=val;
		visited(x);
	}
	else	{
		c[x]=val;
	}
	return;
}
vector<int> vv;
int main()	{
	scanf("%d%d",&n,&Q);
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
	for(int i=1;i<=n-1;i++)	{
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(x,y);
		addEdge(y,x);
	}
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
	for(int i=2;i<cctr;i++)	{
		if(cparr[i].val != cparr[i-1].val)	{
			vv.push_back(cparr[i].val);
			cparr[i].newpos=(int)(vv.size());
		}
		else	{
			cparr[i].newpos=(int)(vv.size());
		}
	}
	m=(int)(vv.size());
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
	fbk=n;
	if(n<=100000)	{
		fbk=1750;
	}
	if(n<=90000)	{
		fbk=1630;
	}
	if(n<=80000)	{
		fbk=1510;
	}
	if(n<=10000)	{
		fbk=390;
	}
	for(int i=1;i<=cn;i++)	{
		fb[i]=(i-1)/fbk+1;
	}
	for(int i=1;i<=Q;i++)	{
		int oper=que[i][0];
		int x=que[i][1];
		int y=que[i][2];
		if(oper==1)	{
			if(L[x]>L[y])	{
				swap(x,y);
			}
			int z=lcafunc(x,y);
			++Q1;
			q[Q1]=(node){x==z?L[x]:R[x],L[y],Q2,Q1};
			lca[Q1]=(x!=z && y!=z ? z :0);
		}
		else	{
			fp[++Q2]=(node2){x,last[x],y};
			last[x]=y;
		}
	}
	sort(q+1,q+1+Q1,cmp);
	int l=1;
	int r=0;
	int now=0;
	for(int i=1;i<=Q1;i++)	{
		while(now<q[i].t)	{
			now++;
			update(fp[now].x,fp[now].now);
		}
		while(q[i].t<now)	{
			update(fp[now].x,fp[now].pre);
			now--;
		}
		while(l<q[i].l)	{
			visited(pos[l++]);
		}
		while(q[i].r<r)	{
			visited(pos[r--]);
		}
		while(q[i].l<l)	{
			visited(pos[--l]);
		}
		while(r<q[i].r)	{
			visited(pos[++r]);
		}
		if(lca[q[i].id])	{
			visited(lca[q[i].id]);
		}
		A[q[i].id]=sum;
		if(lca[q[i].id])	{
			visited(lca[q[i].id]);
		}
	}
	for(int i=1;i<=Q1;i++)	{
		printf("%lld\n",A[i]);
	}
	return 0;
}