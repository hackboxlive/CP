//accepted solution
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n, q;
lli L, R;
const int size = 500005;
lli a[size] = {0};
struct seg
{
	lli ans;
	lli lz, rz;
	lli l1, r1;
};
struct seg segl[4*size], segr[4 * size];
struct seg tempnode;


void buildlseg(int s, int e, int nodenum)
{
	if(s == e)
	{
		segl[nodenum].ans = 1;
		segl[nodenum].lz = 1;
		segl[nodenum].rz = 1;
		segl[nodenum].l1 = -1;
		segl[nodenum].r1 = -1; 
	}
	else
	{
		int mid = (s + e) / 2;
		buildlseg(s, mid, nodenum * 2);
		buildlseg(mid + 1, e, nodenum * 2 + 1);
		int lc = nodenum * 2, rc = nodenum * 2 + 1;
		segl[nodenum].ans = segl[lc].ans + segl[rc].ans;
		segl[nodenum].ans += segl[lc].rz * segl[rc].lz;

		segl[nodenum].l1 = -1;
		segl[nodenum].r1 = -1;
		segl[nodenum].lz = segl[lc].lz + segl[rc].rz;
		segl[nodenum].rz = segl[nodenum].lz;
			
	}
}

void lupdate(lli l, lli r, lli newval, lli s, lli e, lli nodenum)
{
    if(s>r || e<l) return;
    else if(s>=l && e<= r)
    {
		if(newval < L)
		{
			segl[nodenum].ans = 1;
			segl[nodenum].lz = 1;
			segl[nodenum].rz = 1;
			segl[nodenum].l1 = -1;
			segl[nodenum].r1 = -1; 
		} 
		else
		{
			segl[nodenum].ans = 0;
			segl[nodenum].lz = 0;
			segl[nodenum].rz = 0;
			segl[nodenum].l1 = s;
			segl[nodenum].r1 = s; 
 		} 
    }
    else
    {
        int m = (s+e)/2;
        lupdate(l,r,newval,s,m,nodenum*2);
        lupdate(l,r,newval,m+1,e,nodenum*2+1);
        int lc = nodenum * 2, rc = nodenum*2+1;
        segl[nodenum].ans = segl[lc].ans + segl[rc].ans;
        if(segl[lc].r1 > 0 && segl[rc].l1 > 0)
        {
        	segl[nodenum].ans += segl[lc].rz * segl[rc].lz;
        	segl[nodenum].l1 = segl[lc].l1;
        	segl[nodenum].r1 = segl[rc].r1;
        	segl[nodenum].lz = segl[lc].lz;
        	segl[nodenum].rz = segl[rc].rz;
        }
        else if(segl[lc].r1 > 0 && segl[rc].l1 < 0)
        {
        	segl[nodenum].ans += segl[lc].rz * segl[rc].lz;
        	segl[nodenum].l1 = segl[lc].l1;
        	segl[nodenum].r1 = segl[lc].r1;
        	segl[nodenum].lz = segl[lc].lz;
        	segl[nodenum].rz = segl[lc].rz + segl[rc].lz;
        }
        else if(segl[lc].r1 < 0 && segl[rc].l1 > 0)
        {
        	segl[nodenum].ans += segl[lc].rz * segl[rc].lz;
        	segl[nodenum].l1 = segl[rc].l1;
        	segl[nodenum].r1 = segl[rc].r1;
        	segl[nodenum].lz = segl[lc].rz + segl[rc].lz;
        	segl[nodenum].rz = segl[rc].rz;
        }
        if(segl[lc].r1 < 0 && segl[rc].l1 < 0)
        {
        	segl[nodenum].ans += segl[lc].rz * segl[rc].lz;
        	segl[nodenum].l1 = -1;
        	segl[nodenum].r1 = -1;
        	segl[nodenum].lz = segl[lc].rz + segl[rc].lz;
        	segl[nodenum].rz = segl[nodenum].lz;
        }
    }
}

struct seg merge(struct seg nodea, struct seg nodeb)
{
	struct seg temp;
	temp.ans = nodea.ans + nodeb.ans;
	if(nodea.r1 > 0 && nodeb.l1 > 0)
    {
        temp.ans += nodea.rz * nodeb.lz;
        temp.l1 = nodea.l1;
        temp.r1 = nodeb.r1;
        temp.lz = nodea.lz;
        temp.rz = nodeb.rz;
    }
    else if(nodea.r1 > 0 && nodeb.l1 < 0)
    {
        temp.ans += nodea.rz * nodeb.lz;
        temp.l1 = nodea.l1;
        temp.r1 = nodea.r1;
        temp.lz = nodea.lz;
        temp.rz = nodea.rz + nodeb.lz;
    }
    else if(nodea.r1 < 0 && nodeb.l1 > 0)
    {
        temp.ans += nodea.rz * nodeb.lz;
        temp.l1 = nodeb.l1;
        temp.r1 = nodeb.r1;
        temp.lz = nodea.rz + nodeb.lz;
        temp.rz = nodeb.rz;
    }
    if(nodea.r1 < 0 && nodeb.l1 < 0)
    {
       	temp.ans += nodea.rz * nodeb.lz;
       	temp.l1 = -1;
       	temp.r1 = -1;
       	temp.lz = nodea.rz + nodeb.lz;
       	temp.rz = temp.lz;
    }
    return temp;
}

struct seg lquery(int l,int r, int s, int e, int nodenum)
{
    if(s>r || e<l) return tempnode;
    else if(s>=l && e<=r) return segl[nodenum];
    else 
    {
        int m = (s+e)/2;
        struct seg nodea = lquery(l,r,s,m,nodenum*2);
        struct seg nodeb = lquery(l,r,m+1,e,nodenum*2+1);
		return merge(nodea, nodeb);
    }
}

void buildrseg(int s, int e, int nodenum)
{
	if(s == e)
	{
		segr[nodenum].ans = 1;
		segr[nodenum].lz = 1;
		segr[nodenum].rz = 1;
		segr[nodenum].l1 = -1;
		segr[nodenum].r1 = -1; 
	}
	else
	{
		int mid = (s + e) / 2;
		buildrseg(s, mid, nodenum * 2);
		buildrseg(mid + 1, e, nodenum * 2 + 1);
		int lc = nodenum * 2, rc = nodenum * 2 + 1;
		segr[nodenum].ans = segr[lc].ans + segr[rc].ans;
		segr[nodenum].ans += segr[lc].rz * segr[rc].lz;

		segr[nodenum].l1 = -1;
		segr[nodenum].r1 = -1;
		segr[nodenum].lz = segr[lc].lz + segr[rc].rz;
		segr[nodenum].rz = segr[nodenum].lz;
			
	}
}

void rupdate(lli l, lli r, lli newval, lli s, lli e, lli nodenum)
{
    if(s>r || e<l) return;
    else if(s>=l && e<= r)
    {
		if(newval < (R+1))
		{
			segr[nodenum].ans = 1;
			segr[nodenum].lz = 1;
			segr[nodenum].rz = 1;
			segr[nodenum].l1 = -1;
			segr[nodenum].r1 = -1; 
		} 
		else
		{
			segr[nodenum].ans = 0;
			segr[nodenum].lz = 0;
			segr[nodenum].rz = 0;
			segr[nodenum].l1 = s;
			segr[nodenum].r1 = s; 
 		} 
    }
    else
    {
        int m = (s+e)/2;
        rupdate(l,r,newval,s,m,nodenum*2);
        rupdate(l,r,newval,m+1,e,nodenum*2+1);
        int lc = nodenum * 2, rc = nodenum*2+1;
        segr[nodenum].ans = segr[lc].ans + segr[rc].ans;
        if(segr[lc].r1 > 0 && segr[rc].l1 > 0)
        {
        	segr[nodenum].ans += segr[lc].rz * segr[rc].lz;
        	segr[nodenum].l1 = segr[lc].l1;
        	segr[nodenum].r1 = segr[rc].r1;
        	segr[nodenum].lz = segr[lc].lz;
        	segr[nodenum].rz = segr[rc].rz;
        }
        else if(segr[lc].r1 > 0 && segr[rc].l1 < 0)
        {
        	segr[nodenum].ans += segr[lc].rz * segr[rc].lz;
        	segr[nodenum].l1 = segr[lc].l1;
        	segr[nodenum].r1 = segr[lc].r1;
        	segr[nodenum].lz = segr[lc].lz;
        	segr[nodenum].rz = segr[lc].rz + segr[rc].lz;
        }
        else if(segr[lc].r1 < 0 && segr[rc].l1 > 0)
        {
        	segr[nodenum].ans += segr[lc].rz * segr[rc].lz;
        	segr[nodenum].l1 = segr[rc].l1;
        	segr[nodenum].r1 = segr[rc].r1;
        	segr[nodenum].lz = segr[lc].rz + segr[rc].lz;
        	segr[nodenum].rz = segr[rc].rz;
        }
        if(segr[lc].r1 < 0 && segr[rc].l1 < 0)
        {
        	segr[nodenum].ans += segr[lc].rz * segr[rc].lz;
        	segr[nodenum].l1 = -1;
        	segr[nodenum].r1 = -1;
        	segr[nodenum].lz = segr[lc].rz + segr[rc].lz;
        	segr[nodenum].rz = segr[nodenum].lz;
        }
    }
}

struct seg rquery(int l,int r, int s, int e, int nodenum)
{
    if(s>r || e<l) return tempnode;
    else if(s>=l && e<=r) return segr[nodenum];
    else 
    {
        int m = (s+e)/2;
        struct seg nodea = rquery(l,r,s,m,nodenum*2);
        struct seg nodeb = rquery(l,r,m+1,e,nodenum*2+1);
		return merge(nodea, nodeb);
    }
}

int main()
{
	scanf("%d%d",&n, &q);
	scanf("%lld%lld",&L, &R);
	tempnode.ans = 0;
	tempnode.l1 = -1;
	tempnode.r1= -1;
	tempnode.rz = 0;
	tempnode.lz = 0;
	buildlseg(1, n, 1);
	buildrseg(1, n, 1);
	while(q--)
	{
		lli type, l, r; scanf("%lld%lld%lld",&type, &l, &r);
		if(type == 1)
		{
			if(a[l] >= L && r < L) lupdate(l, l, r, 1, n, 1);
			else if(a[l] < L && r >= L) lupdate(l,l,r,1,n,1);
			if(a[l] >= (R+1) && r < (R+1)) rupdate(l,l,r,1,n,1);
			else if(a[l] < (R+1) && r >= (R+1)) rupdate(l,l,r,1,n,1);
			a[l] = r;
//            for(int i=1;i<=9;i++)   {
//                printf("%lld %lld\n",segl[i].ans,segr[i].ans);
//            }

		}
		else
		{
			struct seg nodel= lquery(l, r, 1, n, 1);
			struct seg noder = rquery(l, r, 1, n, 1);
			lli total = (r - l + 1);
			total = (total * (total + 1)) / 2;
            cout<<nodel.ans<<" "<<noder.ans<<endl;
//			lli ansl = total - nodel.ans;
//			lli ansr = total - noder.ans;
			//cout << ansl << " " << ansr << endl;
//			printf("%lld\n", ansl - ansr);
		}
	}
	return 0;
}