#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define plolo pair<ll,ll>

using namespace std;

plolo extendedEuclid(ll a, ll b) // returns x, y | ax + by = gcd(a,b)
{
    if(b == 0) return plolo(1ll, 0ll);
    else
    {
        plolo d = extendedEuclid(b, a % b);
        return plolo(d.yy, d.xx - d.yy * (a / b));
    }

}

ll modularInverse(ll a, ll n) {
    plolo ret = extendedEuclid(a, n);
    return ((ret.xx % n) + n) % n;
}

ll bm(ll a, ll p, ll mod)
{
	if(p==0) return 1ll;
	if(p==1) return a;
	ll x=bm(a,p>>1,mod);
	x= (x*x)%mod;
	if(p&1) x= (x*a)%mod;
	return x;
}

ll ff(ll n, ll k, ll mod)
{
	ll up=bm(n,k,mod)-1;
	if(up<0) up+=mod;
	ll g=__gcd(mod,n-1);
	ll down=(n-1)/g;
	up/=g;
	up = (up*modularInverse(down,mod));
}

int main() {
	// your code goes here
	cin >> T;
	while(T--)
	{
		cout << "Case " << cc++ << ": ";
		cin >> n >> k >> mod;

	}
	return 0;
}
