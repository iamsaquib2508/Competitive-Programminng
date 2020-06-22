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
    ll t, n, pd, qd, pe, qe, p, i;
    cin >> t;
    while(t--)
    {
        pe=0; pd=0; qe=0; qd=0;
        cin >> n;
        ffr(i,0,n)
        {
            cin >> p; if(p&1) pd++; else pe++;
        }
        cin >> n;
        ffr(i,0,n)
        {
            cin >> p; if(p&1) qd++; else qe++;
        }
        cout << pd*qd+pe*qe << endl;
    }
}
