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

int main()
{
    ll n, x, y, i;
    ll a[100005];
    while(cin >> n)
    {
        ffr(i,0,n) cin >> a[i];
        sort(a,a+n);
        x=0; y=0;i=0;
        while(1)
        {
            if(i>=n/2) break;
            x+=a[i];
            y+=a[n-1-i];
            i++;
        }

        if(n&1) y+=a[i];
        
        cout << x*x+y*y << endl;
    }

}
