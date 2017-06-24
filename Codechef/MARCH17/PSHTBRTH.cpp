#include <bits/stdc++.h>
using namespace std;
const int full = (1<<16) - 1;
int dp[100100];
int arr[100100];
int tree[600600];
int solve(int n)	{
	if(dp[n] != -1)	{
		return dp[n];
	}
	if(n == 0)	{
		return 0;
	}
	set<int> s;
	int mat[4][4];
	int d = n;
	for(int i = 0 ; i < 4 ; i++)	{
		for(int j = 0 ; j < 4 ; j++)	{
			mat[i][j] = d % 2;
			d /= 2;
		}
	}
/*	for(int i = 0 ; i < 4 ; i++)	{
		for(int j = 0 ; j < 4 ; j++)	{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
*/	int flag,val=0;
	for(int i = 0 ; i < 4 ; i++)	{
		for(int j = 0 ; j < 4 ; j++)	{
			for(int k = i ; k < 4 ; k++)	{
				for(int l = j ; l < 4 ; l++)	{
					flag = 0;
					for(int p = i ; p <= k ; p++)	{
						for(int q = j ; q <= l ; q++)	{
							if(mat[p][q] == 0)	{
								flag = 1;
								break;
							}
						}
						if(flag == 1)	{
							break;
						}
					}
					if(flag == 0)	{
//						cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<flag<<endl;
						val = 0;
						for(int p = 3 ; p >= 0 ; p--)	{
							for(int q = 3 ; q >= 0 ; q--)	{
								if(p >= i && p <= k && q >= j && q <= l)	{
									val = (val << 1);
								}
								else	{
									val = (val << 1) + mat[p][q];
								}
							}
						}
//						cout<<val<<endl;
						s.insert(solve(val));
					}
				}
			}
		}
	}
	int i=0;
	for(set<int>::iterator it = s.begin() ; it != s.end() ; it++)	{
		if(*it == i)	{
			i++;
			continue;
		}
		else	{
			break;
		}
	}
	dp[n] = i;
	return i;
}
void build_tree(int id, int l, int r)	{
	if(l == r)	{
		tree[id] = arr[l];
		return;
	}
	build_tree(2*id, l, (l+r)/2);
	build_tree(2*id + 1, (l+r)/2+1, r);
	tree[id] = tree[2*id] ^ tree [2*id + 1];
	return;
}
int query_tree(int id,int start,int end,int l,int r)	{
	if(start > r || end < l)	{
		return 0;
	}
	if(start >= l && end <= r)	{
		return tree[id];
	}
	return query_tree(2*id,start,(start+end)/2,l,r) ^ query_tree(2*id+1,(start+end)/2+1,end,l,r);
}
void update_tree(int id,int start,int end,int pos,int val)	{
	if(start > pos || end < pos)	{
		return;
	}
	if(start == pos && end == pos)	{
		tree[id] = val;
		return;
	}
	update_tree(2*id,start,(start+end)/2,pos,val);
	update_tree(2*id+1,(start+end)/2+1,end,pos,val);
	tree[id] = tree[2*id] ^ tree[2*id + 1];
	return;
}
int main()	{
	memset(dp, -1, sizeof(dp));
	for(int i = 0 ; i < full ; i++)	{
		dp[i] = solve(i);
//		cout<<i<<" = "<<dp[i]<<endl;
	}
	int t,n,m;
	int ll,rr;
	string str1,str2,str3,str4;
	int val;
	int ch;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)	{
			val=0;
			cin>>str1>>str2>>str3>>str4;
			for(int j = 3 ; j >= 0 ; j--)	{
				val = val<<1;
				if(str4[j] == '1')	{
					val++;
				}
			}
			for(int j = 3 ; j >= 0 ; j--)	{
				val = val<<1;
				if(str3[j] == '1')	{
					val++;
				}
			}
			for(int j = 3 ; j >= 0 ; j--)	{
				val = val<<1;
				if(str2[j] == '1')	{
					val++;
				}
			}
			for(int j = 3 ; j >= 0 ; j--)	{
				val = val<<1;
				if(str1[j] == '1')	{
					val++;
				}
			}
			arr[i] = dp[val];
		}
		build_tree(1,0,n-1);
		while(m--)	{
			scanf("%d",&ch);
			if(ch == 1)	{
				scanf("%d %d",&ll,&rr);
				if(query_tree(1,0,n-1,ll-1,rr-1))	{
					printf("Pishty\n");
				}
				else	{
					printf("Lotsy\n");
				}
			}
			else	{
				scanf("%d",&ll);
				cin>>str1;
				cin>>str2;
				cin>>str3;
				cin>>str4;
				val = 0;
				for(int j = 3 ; j >= 0 ; j--)	{
					val = val<<1;
					if(str4[j] == '1')	{
						val++;
					}
				}
				for(int j = 3 ; j >= 0 ; j--)	{
					val = val<<1;
					if(str3[j] == '1')	{
						val++;
					}
				}
				for(int j = 3 ; j >= 0 ; j--)	{
					val = val<<1;
					if(str2[j] == '1')	{
						val++;
					}
				}
				for(int j = 3 ; j >= 0 ; j--)	{
					val = val<<1;
					if(str1[j] == '1')	{
						val++;
					}
				}
				update_tree(1,0,n-1,ll-1,dp[val]);
			}
		}
	}
	return 0;
}