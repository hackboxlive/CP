Hash hashp(int id,int l,int r,int pos,int par)	{
	if(l==r)	{
		Hash h;
		h.sum=(pos-treep[par].cnt)*l;
		h.sumsq=(pos-treep[par].cnt)*l*l;
		return h;
	}
	if(treep[treep[id].left].cnt-treep[treep[par].left].cnt>=pos)	{
		return hashp(treep[id].left,l,(l+r)/2,pos,treep[par].left);
	}
	Hash h;
	h.sum=treep[treep[id].left].sum-treep[treep[par].left].sum;
	h.sumsq=treep[treep[id].left].sumsq-treep[treep[par].left].sumsq;
	Hash oh=hashp(treep[id].right,(l+r)/2+1,r,pos-(treep[treep[id].left].cnt-treep[treep[par].left].cnt),treep[par].right);
	h.sum+=oh.sum;
	h.sumsq+=oh.sumsq;
	return h;
}
