#include <bits/stdc++.h>
using namespace std;
string a,b;
int main()	{
	int t,n;
	cin>>t;
	while(t--)	{
		cin>>n;
		cin>>a;
		cin>>b;
		int cntst=0;
		for(int i=0;i<n;i++)	{
			if(a[i]=='#')	{
				cntst++;
			}
			if(b[i]=='#')	{
				cntst++;
			}
		}
		if(cntst==0)	{
			cout<<"no\n";
			continue;
		}
		int startpos;
		for(int i=0;i<n;i++)	{
			if(a[i]=='#' || b[i]=='#')	{
				startpos=i;
				break;
			}
		}
		if(a[startpos]=='#')	{
			int cov=1;
			int ff=1;
			int aorb=1;
			int pos=startpos;
			while(true)	{
				if(ff==1)	{
					if(aorb==1)	{
						if(b[pos]=='#')	{
							ff=0;
							aorb=2;
							cov++;
						}
						else	{
							if(pos==n-1 || a[pos+1]=='.')	{
								break;
							}
							else	{
								pos++;
								cov++;
							}
						}
					}
					else	{
						if(a[pos]=='#')	{
							ff=0;
							aorb=1;
							cov++;
						}
						else	{
							if(pos==n-1 || b[pos+1]=='.')	{
								break;
							}
							else	{
								pos++;
								cov++;
							}
						}
					}
				}
				else	{
					if(aorb==1)	{
						if(pos==n-1 || a[pos+1]=='.')	{
							break;
						}
						else	{
							pos++;
							cov++;
							ff=1;
						}
					}
					else	{
						if(pos==n-1 || b[pos+1]=='.')	{
							break;
						}
						else	{
							pos++;
							cov++;
							ff=1;
						}
					}
				}
			}
			if(cov==cntst)	{
				cout<<"yes\n";
				continue;
			}
		}
		if(b[startpos]=='#')	{
			int cov=1;
			int ff=1;
			int aorb=2;
			int pos=startpos;
			while(true)	{
				if(ff==1)	{
					if(aorb==1)	{
						if(b[pos]=='#')	{
							ff=0;
							aorb=2;
							cov++;
						}
						else	{
							if(pos==n-1 || a[pos+1]=='.')	{
								break;
							}
							else	{
								pos++;
								cov++;
							}
						}
					}
					else	{
						if(a[pos]=='#')	{
							ff=0;
							aorb=1;
							cov++;
						}
						else	{
							if(pos==n-1 || b[pos+1]=='.')	{
								break;
							}
							else	{
								pos++;
								cov++;
							}
						}
					}
				}
				else	{
					if(aorb==1)	{
						if(pos==n-1 || a[pos+1]=='.')	{
							break;
						}
						else	{
							pos++;
							cov++;
							ff=1;
						}
					}
					else	{
						if(pos==n-1 || b[pos+1]=='.')	{
							break;
						}
						else	{
							pos++;
							cov++;
							ff=1;
						}
					}
				}
			}
			if(cov==cntst)	{
				cout<<"yes\n";
				continue;
			}			
		}
		cout<<"no\n";
	}
	return 0;
}