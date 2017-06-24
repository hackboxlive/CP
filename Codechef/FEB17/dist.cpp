#include <bits/stdc++.h>
using namespace std;

//My Code Sucks
const double Alpha=0.7142758;
const int _N=201010;
const int _S=20;

int blockSize;

class IO
{
private:
    static const int BUF=10000000;
    char Buf[BUF],*buf,*buff,_s[4];
public:
    IO():buf(Buf),buff(Buf){}
    void init(){fread(Buf,1,BUF,stdin);}
   // void end(){fwrite(Buf,1,buff-Buf,stdout);}
    void read(int&a){for(a=0;*buf<48;buf++);while(*buf>47)a=a*10+*buf++-48;}
   // void write(long long a){char *s=_s;for(;a;a/=10)*s++=a%10+'0';while(s--!=_s)*buff++=*s;*buff++=10;}
}myInOut;

int n,m,q,v[_N],w[_N],c[_N];
int top[_N],fa[_N],bel[_N<<1],numB;
int now[_N],L[_N],R[_N],P[_N<<1],deep[_N],numP;

int Fir[_N],ed[_N<<1],Next[_N<<1],numE;

void addE(int x,int y)
{
    ed[++numE]=y,Next[numE]=Fir[x],Fir[x]=numE;
    ed[++numE]=x,Next[numE]=Fir[y],Fir[y]=numE;
}

int son[_N],siz[_N];

void dfs(int x)
{
    P[L[x]=++numP]=x,siz[x]=1;
    for(int e=Fir[x];e;e=Next[e])
        if(ed[e]^fa[x])
        {
            fa[ed[e]]=x,deep[ed[e]]=deep[x]+1,dfs(ed[e]),siz[x]+=siz[ed[e]];
            if(siz[ed[e]]>siz[son[x]])
                son[x]=ed[e];
        }
    P[R[x]=++numP]=x;
}

void dfs(int x,int tx)
{
    top[x]=tx;
    if(son[x])
        dfs(son[x],tx);
    for(int e=Fir[x];e;e=Next[e])
        if(ed[e]^fa[x]&&ed[e]^son[x])
            dfs(ed[e],ed[e]);
}

int calc_lca(int x,int y)
{
    if(L[x]<=L[y]&&R[y]<=R[x])
        return x;
    while(top[x]^top[y])
    {
        if(deep[top[x]]<deep[top[y]])
            swap(x,y);
        x=fa[top[x]];
    }
    return deep[x]<deep[y]?x:y;
}

void init()
{
    for(int i=1;i<=numP;numB++)
        for(int j=1;j<=blockSize&&i<=numP;j++,i++)
            bel[i]=numB;
}

bool vis[_N];
int num[_N],glca[_N];
long long ans,re[_N];

void modify(int x)
{
   // cout<<x<<' '<<ans<<' ';
    if(vis[x])
        ans-=(long long)w[num[c[x]]--];
    else
        ans+=(long long)w[++num[c[x]]];
    vis[x]^=1;
   // cout<<ans<<endl;
}

void change(int x,int y)
{
    if(vis[x])
        modify(x),c[x]=y,modify(x);
    else
        c[x]=y;
}

class Ask
{
public:
    int l,r,t,pla;
    Ask(){}
    Ask(int _0,int _1,int _2,int _3):l(_0),r(_1),t(_2),pla(_3){}
}s[_N];
inline bool see0(const Ask &i,const Ask &j)
{
    return bel[i.l]<bel[j.l];
}
int com_type;
inline bool see1(const Ask &i,const Ask &j)
{
    return com_type?bel[i.r]>bel[j.r]:bel[i.r]<bel[j.r];
}
inline bool see2(const Ask &i,const Ask &j)
{
    return com_type?i.t>j.t:i.t<j.t;
}
class Eat
{
public:
    int pla,oc,nc;
    Eat(){}
    Eat(int _0,int _1,int _2):pla(_0),oc(_1),nc(_2){}
}t[_N];
int numS,numT;
int arr[100100];
int que[100100][3];
struct node	{
	int val;
	int pos;
	int newpos;
} cpa[300300];
bool comp1(const node &p1,const node &p2)	{
	return p1.val<p2.val;
}
bool comp2(const node &p1,const node &p2)	{
	return p1.pos<p2.pos;
}
int main()
{
	scanf("%d%d",&n,&q);
	int ctr=1;
	for(int i=1;i<=n;i++)	{
		scanf("%d",&arr[i]);
		cpa[ctr].val=arr[i];
		cpa[ctr].pos=i;
		ctr++;
	}
	static int x,y,type;
	for(int i=1;i<n;i++)	{
		scanf("%d%d",&x,&y);
		addE(x,y);
	}
	w[1]=1;
	for(int i=1;i<=q;i++)	{
		scanf("%d%d%d",&que[i][0],&que[i][1],&que[i][2]);
		if(que[i][0]==2)	{
			cpa[ctr].val=que[i][2];
			cpa[ctr].pos=ctr;
			ctr++;
		}
	}
	sort(cpa+1,cpa+ctr,comp1);
	m=1;
	v[1]=cpa[1].val;
	cpa[1].newpos=1;
	for(int i=2;i<ctr;i++)	{
		if(cpa[i].val!=cpa[i-1].val)	{
			v[++m]=cpa[i].val;
		}
		cpa[i].newpos=m;
	}
	sort(cpa+1,cpa+ctr,comp2);
	for(int i=1;i<=n;i++)	{
		c[i]=cpa[i].newpos;
	}
	int g=n;
	for(int i=1;i<=q;i++)	{
		if(que[i][0]==2)	{
			que[i][2]=cpa[++g].newpos;
		}
	}
   // freopen("233.txt","r",stdin);
   // freopen("22.txt","w",stdout);
//    myInOut.init(),myInOut.read(n),myInOut.read(m),myInOut.read(q);
    blockSize=max((int)pow(n,(double)2/3)-500,1000);
//    for(int i=1;i<=m;i++)
  //      myInOut.read(v[i]);
    //for(int i=1;i<=n;i++)
      //  myInOut.read(w[i]);
 //   static int type,x,y;
 //   for(int i=1;i<n;i++)
   //     myInOut.read(x),myInOut.read(y),addE(x,y);
 //   for(int i=1;i<=n;i++)
   //     myInOut.read(c[i]),now[i]=c[i];
    type=Alpha*n+0.5,dfs(type),dfs(type,type);
   // for(int i=1;i<=n;i++)
       // printf("%d %d\n",L[i],R[i]);
    init();
   // for(int i=1;i<=n;i++)
       // for(int j=i;j<=n;j++)
           // printf("%d %d %d\n",i,j,calc_lca(i,j));
    for(int i=1;i<=q;i++)
    {
    	type=que[i][0];
    	x=que[i][1];
    	y=que[i][2];
        if(type==1)
        {
            if(L[x]>L[y])
                swap(x,y);
            glca[++numS]=calc_lca(x,y);
            if(glca[numS]==x)
                s[numS]=Ask(L[x],L[y],numT,numS),glca[numS]=0;
            else
                s[numS]=Ask(R[x],L[y],numT,numS);
        }
        else
            t[++numT]=Eat(x,now[x],y),now[x]=y;
    }
    sort(s+1,s+numS+1,see0);
    for(int i=1,j=1;i<=numS;i=j)
    {
        for(;j<=numS&&bel[s[j].l]==bel[s[i].l];j++);
        sort(s+i,s+j,see1),com_type^=1;
    }
    com_type=0;
    for(int i=1,j=1;i<=numS;i=j)
    {
        for(;j<=numS&&bel[s[j].l]==bel[s[i].l]&&bel[s[j].r]==bel[s[i].r];j++);
        sort(s+i,s+j,see2),com_type^=1;
    }
    static int nowL=1,nowR,nowT;
    for(int i=1;i<=numS;i++)
    {
        static int toL,toR,toT;
        toL=s[i].l,toR=s[i].r,toT=s[i].t;
        while(nowT<toT)
            change(t[nowT].pla,t[++nowT].nc);
        while(nowT>toT)
            change(t[nowT--].pla,t[nowT].oc);
        while(nowR>toR)
            modify(P[nowR--]);
        while(nowL<toL)
            modify(P[nowL++]);
        while(nowR<toR)
            modify(P[++nowR]);
        while(nowL>toL)
            modify(P[--nowL]);
        re[s[i].pla]=ans;
        if(glca[s[i].pla])
            re[s[i].pla]+=(long long)w[num[c[glca[s[i].pla]]]+1];
    }
    for(int i=1;i<=numS;i++)
        printf("%lld\n",re[i]);
    return 0;
}