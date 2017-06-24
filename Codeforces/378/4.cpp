#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
    int z;
    int ind;
}p[100005];
bool myfunc(struct node &p1, struct node &p2)
{
    if(p1.z != p2.z)
        return p1.z > p2.z;
    if(p1.y != p2.y)
        return p1.y > p2.y;
    return p1.x > p2.x;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[3];
    int index = 0;
    int orig = n;
    int answer = -2;
    bool flag = 0;
    int one = -1;
    for(int i=0;i<n;i++)	{
    	scanf("%d%d%d",a,a+1,a+2);
    	sort(a,a+3);
    	p[i].x=a[0];
    	p[i].y=a[1];
    	p[i].z=a[2];
    	p[i].ind=i+1;
    	if(a[0]>answer)	{
    		answer=a[0];
    		one=i+1;
    	}
    }
    int first = -1, second = -1;
    int answer2 = -2;
    sort(p, p+n, myfunc);
    for(int i=0; i<n-1; i++)
    {
        if(p[i].z == p[i+1].z && p[i].y == p[i+1].y)
        {
            if(min((p[i].x + p[i+1].x), min(p[i].z, p[i].y))> answer2)
            {
                flag = 1;
                first = p[i].ind;
                second = p[i+1].ind;
                answer2 = min((p[i].x + p[i+1].x), min(p[i].z, p[i].y));
            }
        }
    }
    if(flag && (answer2 > answer))
    {
        printf("2\n%d %d",first,second);
//        printf("%d %d\n", first+1, second+1);
    }
    else
    {
        printf("1\n%d",one);
//        printf("%d", one+1);
    }
    return 0;
}