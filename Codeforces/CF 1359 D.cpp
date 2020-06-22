#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int n, i, ans, maxxx, sum, a[100005];
    while(cin >> n)
    {
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        ans=0;
        sum=0;
        maxxx=0;
        ffr(i,0,n)
        {
            sum+=a[i];
            if(sum<0)
            {
                sum=0;
                maxxx=0;
            }
            else
            {
                maxxx=maxx(maxxx,a[i]);
                ans=maxx(ans,sum-maxxx);
            }
        }
        cout << ans << endl;
    }
}
