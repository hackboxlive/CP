#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ulli unsigned long long int
#define ll long long 
#define ull  unsigned long long
#define mp make_pair
#define s(n)   scanf("%d",&n)
#define sc(n)  scanf("%c",&n)
#define sl(n)  scanf("%lld",&n)
#define sf(n)  scanf("%lf",&n)
#define ss(n)  scanf("%s",n)
#define p(n)   printf("%d",n)
#define pc(n)  printf("%c",n)
#define pl(n)  printf("%lld",n)
#define pf(n)  printf("%lf",n)
#define ps(n)  printf("%s",n)
#define pn printf("\n")
#define loopf(X,Y) for(int i=X;i<Y;i++)
#define loopb(X,Y) for(int i=X;i>Y;i--)
int main() {
    vector<string> vect;
    int h1, a1, c1, h2, a2, count;
    count = 0;
    s(h1),s(a1),s(c1),s(h2),s(a2);
    while(h2>0) {
        count++;
        if(((h2-a1) <= 0) || ((h1-a2) > 0)) {
            vect.push_back("STRIKE");
            h2 = h2 - a1;
        }
        else h1 = h1 + c1, vect.push_back("HEAL"); 

        if(h2>0) h1 = h1 - a2;
    }
    p(count),pn;
    for(int i=0; i<count; i++) 
    cout << vect[i] << endl;
}