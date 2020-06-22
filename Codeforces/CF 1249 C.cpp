#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

vector <ll> v;

ll ff(ll n)
{
    if(n==1) return 1;
    if(n<4) return 3;
    int i=0;
    while(v[i]<n) i++;

    if(v[i]==n) return n;

    if(n*2>v[i]-1) return v[i];
    return v[i-1]+ff(n-v[i-1]);

}

int main()
{
    int q;
    ll cur=1;
    while(cur<1000000000000000000)
    {
        v.pb(cur); cur*=3;
    }
    v.pb(cur);

    //cout << v[v.size()-1];
    cin >> q;
    while(q--)
    {
        ll n;
        cin >> n;
        cout << ff(n) << endl;
    }
}
