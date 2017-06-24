#include <bits/stdc++.h>
#include <ctime>
using namespace std;
char mat[100100];
int main()	{
	int start_s=clock();
	// the code you wish to time goes here

	
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int n,k,g,b;
	string kg="",kb="";
	cin>>n>>k>>g>>b;
	for(int i=0;i<k-1;i++)	{
		kg=kg+"G";
		kb=kb+"B";
	}
	if(g==b)	{
		string t="";
		for(int i=0;i<g;i++)	{
			t=t+"GB";
		}
		int hh=0;
		for(int i=0;i<t.length();i++)	{
			printf("%c",t[i]);
		}
//		cout<<t;
//		printf("%s",mat);
//		return 0;
	}
	if(g>b)	{
		string t="G";
		for(int i=0;i<b;i++)	{
			t=t+"BG";
		}
		g=g-b-1;
		string ff="";
		for(int i=0;i<t.length();i++)	{
			if(t[i]=='B')	{
				ff=ff+t[i];
			}
			if(t[i]=='G')	{
				ff=ff+t[i];
				if(g>k-1)	{
					ff=ff+kg;
					g=g-k+1;
				}
				else	{
					if(g>0)	{
						for(int j=0;j<g;j++)	{
							ff=ff+'G';
						}
						g=0;
					}
				}
			}
		}
		if(g!=0)	{
//			cout<<"NO";
			printf("NO");
		}
		else	{
			int hh=0;
			for(int i=0;i<ff.length();i++)	{
				printf("%c",ff[i]);
			}
	//		cout<<t;
//			printf("%s",mat);

//			cout<<ff;
		}
	}
	else	{
		string t="B";
		for(int i=0;i<g;i++)	{
			t=t+"GB";
		}
		b=b-g-1;
		string ff="";
		for(int i=0;i<t.length();i++)	{
			if(t[i]=='G')	{
				ff=ff+t[i];
			}
			if(t[i]=='B')	{
				ff=ff+t[i];
				if(b>k-1)	{
					ff=ff+kb;
					b=b-k+1;
				}
				else	{
					if(b>0)	{
						for(int j=0;j<b;j++)	{
							ff=ff+'B';
						}
						b=0;
					}
				}
			}
		}
		if(b!=0)	{
			cout<<"NO";
		}
		else	{
//			int hh=0;
			for(int i=0;i<ff.length();i++)	{
//				mat[hh++]=ff[i];
				printf("%c",ff[i]);
			}
	//		cout<<t;
//			printf("%s",mat);
		}
	}
	int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

	return 0;
}