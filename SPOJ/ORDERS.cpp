#include <stdio.h>
inline int inp()
{
	int noRead=0;
	char p=getchar_unlocked();
	for(;p<33;){p=getchar_unlocked();};
	while(p>32)
	{
		noRead = (noRead << 3) + (noRead << 1) + (p - '0');
		p=getchar_unlocked();
	}
	return noRead;
};
int T[1000000],A[300000],N,t,i,j,k,ans[300000];
void build(int node,int a,int b){
	int mid=(a+b)>>1;
	if(a==b) T[node]=1;
	else{
		build(node<<1,a,mid);
		build((node<<1)+1,mid+1,b);
		T[node]=b-a+1; 
	}
}
int query(int node,int pos,int a,int b){
	if(a==b){
		--T[node];
		return a;
	}
	int mid=(a+b)>>1;
	--T[node];
	if(pos<=T[node<<1]) return query(node<<1,pos,a,mid);
	else return query((node<<1)+1,pos-T[node<<1],mid+1,b);
}
int main(){
	scanf("%d",&t);
	while(t--){
		N=inp();
		for(i=0;i<N;i++) A[i]=inp();
		build(1,1,N);
		for(i=N-1;i>=0;i--) ans[i]=query(1,i-A[i]+1,1,N);
		for(i=0;i<N;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}