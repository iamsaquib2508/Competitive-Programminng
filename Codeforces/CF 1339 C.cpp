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


ll minn(ll a, ll b)
{
    if(a>b) return b; return a;
}

ll pro(ll a)
{
    if(a==0) return 0;
    ll cur=1, ans=1;
    while(cur<a)
    {
        cur+=cur;
        ans++;
    }
    if(cur>a) ans--;
    return ans;
}

int main()
{
    int tt; cin >> tt;
    // cout << pro(0) << endl;
    // cout << pro(1) << endl;
    // cout << pro(2) << endl;
    // cout << pro(3) << endl;
    // cout << pro(4) << endl;
    while(tt--)
    {
        ll n, i, mx, slk, slkmax, x, a[100005];
        cin >> n;
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        mx=a[0];
        slkmax=0;
        ffr(i,1,n)
        {
            x=a[i];
            if(x<mx)
            {
                slk=mx-x;
                if(slk>slkmax) slkmax=slk;
            }
            else if(x>mx) mx=x;
        }
        cout << pro(slkmax) << endl;
    }
}
