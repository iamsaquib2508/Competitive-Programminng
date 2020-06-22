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

ll sum[200005], k, x, y;
int a, b, lc, q;

ll minn(ll a, ll b)
{
    if(a>b) return b; return a;
}

bool ok(int n)
{
    ll t1, t2, t3;
    t1 = sum[n/lc] * (x+y);

    t2 = (sum[ minn(n/b + n/lc , n)] - sum[n/lc]) * y;
    t3 = (sum[ minn(n/a + n/b , n)] - sum[n/b]) * x ;
    return ( ( t1 + t2 + t3 ) >= k ) ;
}

int main() {
    int n, i;
    ll arr[200005];
    cin >> q;
    while(q--)
    {
        cin >> n;
        ffr(i,0,n)
        {
            cin >> arr[i];
            arr[i]/=100;
        }
        sort(arr,arr+n);
        sum[0]=0;
        ffr(i,0,n)
        {
            sum[i+1]=sum[i]+arr[n-1-i];
        }
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        if(x>y)
        {
            x^=y; y^=x; x^=y;
            a^=b; b^=a; a^=b;
        }
        lc=(a*b)/gcd(a,b);

        if(!ok(n)) cout << "-1\n";
        else
        {
            int hi=n, lo=0, mid;
            while(hi-lo>1)
            {
                mid=(hi+lo)/2;
                if(ok(mid))
                hi=mid;
                else lo=mid;
            }
            if(ok(lo)) cout << lo << endl;
            else cout << hi << endl;
        }

    }
}
