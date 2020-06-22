







/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)

using namespace std;


class numberTheory{

public:
    numberTheory(){}

    pii extendedEuclid(ll a, ll b) { // returns x, y | ax + by = gcd(a,b)

        if(b == 0) return pii(1LL, 0LL);
        else {
            pii d = extendedEuclid(b, a % b);
            return pii(d.yy, d.xx - d.yy * (a / b));
        }

    }

    ll modularInverse(ll a, ll n) {
        pair<ll,ll> ret = extendedEuclid(a, n);
        return ((ret.xx % n) + n) % n;
    }


    ll bigMod(ll a, ll n , ll m)
    {
        if(n==0) return 1 ;
        ll ret = bigMod(a,n/2,m) ;
        ret = (ret*ret)%m ;
        if(n%2) ret = (ret*a)%m ;
        return ret ;
    }
};


/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */




int main()
{
	ll n, a, b, c, cnt=0, x;
	cin >> n;
	x=n/2;
	ffr(a,1,x)
	{
		ffr(b,1,x)
		{
			//if(a+b>x) continue;
			c=max(a-b+1,b-a+1);
			ll t=min(a+b,x);
			ffr(c,c,t)
			{
				
				if(a+b+c>n) continue;
				if(((a^b)^c)==0) 
				{
					cnt++;
					//cout << "a " << a << " b " << b << " c " << c << endl;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
	
}
