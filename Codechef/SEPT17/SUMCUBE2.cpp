#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int blocksize;
long long powers[100100];
vector< vector < int > > graph(100100);
vector< pair < int , int > > edges;
map< pair < int , int > , bool > hashmap;
vector<int> heavyedges , lightedges;
long long degree[100100] , totaldegree[100100];
long long counttriangle(int n,int m)	{
	long long count = 0;
	int u , v , w ;
	int hl=0;
	for(int i = 0 ; i < heavyedges.size() ; i++)	{
		u = heavyedges[i];
		for(int j = 0 ; j < m ; j++)	{
			v = edges[j].first;
			w = edges[j].second;
			if( u != v && u != w)	{
				if(degree[v] < blocksize && degree[w] < blocksize)	{
					if(hashmap.find(make_pair(u,v)) != hashmap.end() && hashmap.find(make_pair(u,w)) != hashmap.end())	{
						count++;
					}
				}
				if((degree[v] >= blocksize && degree[w] < blocksize) || (degree[v] < blocksize && degree[w] >= blocksize))	{
					if(hashmap.find(make_pair(u,v)) != hashmap.end() && hashmap.find(make_pair(u,w)) != hashmap.end())	{
						hl++;
					}			
				}
			}
		}
	}
	hl/=2;
	count+=hl;
	hl=0;
	for(int i = 0 ; i < edges.size() ; i++)	{
		u = edges[i].first;
		v = edges[i].second;
		if(degree[u] < blocksize && degree[v] < blocksize)	{
			for(int j = 0 ; j < degree[u] ; j++)	{
				w=graph[u][j];
				if(degree[w] < blocksize)	{
					if(hashmap.find(make_pair(v,w)) != hashmap.end())	{
						hl++;
					}
				}
			}
		}
	}
	hl/=3;
	count+=hl;
	for(int i = 0 ; i < heavyedges.size() ; i++)	{
		u = heavyedges[i];
		for( int j = i + 1 ; j < heavyedges.size() ; j++)	{
			v = heavyedges[j];
			for(int k = j + 1 ; k < heavyedges.size() ; k++)	{
				w = heavyedges[k];
				if(hashmap.find(make_pair(u,v)) != hashmap.end() && hashmap.find(make_pair(v,w))!=hashmap.end() && hashmap.find(make_pair(u,w))!=hashmap.end())	{
					count++;
				}
			}
		}
	}
	return count;
}
long long counttree(int n,int m)	{
	long long count=0;
	int u,v;
	long long temp,claw = 0,straight = 0;
	for(int i = 0 ; i < m ; i++)	{
		u = edges[i].first;
		v = edges[i].second;
		temp = degree[u] - 1;
		temp *= (degree[v] - 1);
		straight += temp;
		temp = degree[u] - 1;
		temp *= (temp - 1);
		temp /= 2;
		claw += temp;
		temp = degree[v] - 1;
		temp *= (temp - 1);
		temp /= 2;
		claw += temp;
	}
	claw /= 3;
	count = claw + straight;
	return count;
}
long long onepowerscombination(int n , int m , int k)	{
	long long current , powerscomb = 0 , powersdiff = 0 , ans = 0;
	for(int i = 0 ; i < m ; i++)	{
		current = degree[edges[i].first] + degree[edges[i].second] - 2;
		powersdiff += (m - 1 - current);
		powerscomb += current;
	}
	powerscomb /= 2;
	powersdiff /= 2;
//	cout<<m<<" "<<powers[n-2]<<endl;
	ans = powers[n - 2] * m;
//	cout<<ans<<endl;
	ans %= MOD;
	if(n > 3)	{
		current = powers[n - 4] * k;
		current %= MOD;
		current *= powersdiff;
		current %= MOD;
		ans += current;
		ans %= MOD;		
	}
	if(n > 2)	{
		current = powers[n - 3] * k;
		current %= MOD;
		current *= powerscomb;
		current %= MOD;
		ans += current;
		ans %= MOD;
	}
	return ans;
}
void clear(int n)	{
	for(int i = 1 ; i <= n ; i++)	{
		graph[i].clear();
	}
	edges.clear();
	heavyedges.clear();
	lightedges.clear();
	hashmap.clear();
}
void inp(int m)	{
	int u,v;
	for(int i = 0 ; i < m ; i++)	{
		scanf("%d %d" , &u , &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
		edges.push_back(make_pair(u,v));
		hashmap[make_pair(u,v)] = true;
		hashmap[make_pair(v,u)] = true;
	}	
}
int main()	{
	powers[0] = 1;
	for(int i = 1 ; i <= 100000 ; i++)	{
		powers[i] = powers[i-1] * 2;
		powers[i] = powers[i] % MOD;
	}
	int t,n,m,k,u,v;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d %d" , &n , &m , &k);
		blocksize = (int)sqrt(m) + 50;
		inp(m);
		for(int i = 1 ; i <= n ; i++)	{
			degree[i] = (int)graph[i].size();
			if(degree[i] < blocksize)	{
				lightedges.push_back(i);
			}
			else	{
				heavyedges.push_back(i);
			}
		}
		if(k==3)	{
			long long pairofpowers=0;
			for(int i = 0 ; i < m ; i++)	{
				u = edges[i].first;
				v = edges[i].second;
				pairofpowers += degree[u];
				pairofpowers += degree[v];
				pairofpowers -= 2;
			}
			for(int i = 1 ; i <= n ; i++)	{
				totaldegree[i] = 0;
				for(int j = 0 ; j < degree[i] ; j++)	{
					totaldegree[i] += degree[graph[i][j]];
				}
			}
			pairofpowers /= 2;
			long long fournodes = counttree( n , m );
			long long ans = onepowerscombination( n , m , 6);
			long long triangles = counttriangle( n , m );
			fournodes -= 3 * triangles;
			long long tosubtract = 0;
			for(int i = 0 ; i < m ; i++)	{
				u = edges[i].first;
				v = edges[i].second;
				tosubtract += ((long long)(degree[u] + degree[v] - 2) * (degree[u] + degree[v] - 2));
				tosubtract += totaldegree[v] - degree[u];
				tosubtract += totaldegree[u] - degree[v];
			}
			tosubtract /= 2;
			long long fivenodes = m * pairofpowers;
			fivenodes -= tosubtract;
			fivenodes += 3*triangles;
			long long sixnodes = m;
			sixnodes *= (m-1);
			sixnodes *= (m-2);
			sixnodes /= 6;
			sixnodes -= triangles;
			sixnodes -= fournodes;
			sixnodes -= fivenodes;
//			cout<<triangles<<" "<<fournodes<<" "<<fivenodes<<" "<<sixnodes<<endl;
//			cout<<ans<<endl;
//			cout<<ans<<endl;
			if(n>5)	{
				tosubtract=6*powers[n-6];
				tosubtract%=MOD;
				sixnodes%=MOD;
				tosubtract*=sixnodes;
				tosubtract%=MOD;
				ans+=tosubtract;
				ans%=MOD;
			}
//			cout<<ans<<endl;
			if(n>4)	{
				tosubtract=6*powers[n-5];
				tosubtract%=MOD;
				fivenodes%=MOD;
				tosubtract*=fivenodes;
				tosubtract%=MOD;
				ans+=tosubtract;
				ans%=MOD;
			}
			if(n>3)	{
				tosubtract=6*powers[n-4];
				tosubtract%=MOD;
				fournodes%=MOD;
				tosubtract*=fournodes;
				tosubtract%=MOD;
				ans+=tosubtract;
				ans%=MOD;
			}
//			cout<<ans<<endl;
			if(n>2)	{
				tosubtract=6*powers[n-3];
				tosubtract%=MOD;
				triangles%=MOD;
				tosubtract*=triangles;
				tosubtract%=MOD;
				ans+=tosubtract;
				ans%=MOD;
			}
			cout<<ans<<endl;
		}
		if(k==2)	{
			cout<<onepowerscombination(n,m,2)<<endl;
		}
		if(k==1)	{
			long long ans = m;
			ans *= powers[n-2];
			ans %= MOD;
			printf("%lld\n",ans);
		}
		clear(n);
	}
	return 0;
}