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
    int tt; cin >> tt;
    while(tt--)
    {
        int n, i, s=0, zero=0, x, ans;
        cin >> n;
        ffr(i,0,n)
        {
            cin >> x;
            s+=x;
            //mul*=x;
            if(x==0) zero++;
        }
        if(zero==0)
        {
            if(s==0)
            {
                ans=1;
            }
            else ans=0;
        }
        else
        {
            ans=zero;

            if(s+zero==0) ans++;
        }
        cout << ans << endl;
    }
}
