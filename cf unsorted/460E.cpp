






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


class numbertheory{

public:
    numbertheory(){}

    plolo extendedEuclid(ll a, ll b) { // returns x, y | ax + by = gcd(a,b)

        if(b == 0) return pii(1LL, 0LL);
        else {
            plolo d = extendedEuclid(b, a % b);
            return pii(d.yy, d.xx - d.yy * (a / b));
        }

    }

    ll modInverse(ll a, ll n) {
        plolo ret = extendedEuclid(a, n);
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

ll modfix(ll a, ll b)
{
	if(a>=0) return a%b;
	ll t=-a/b+1;
	a+=(t*b);
	return a%b;
}


int main()
{
	ll a, b, p, mx, X, x, y, ans=0, m_1, cur;
	numbertheory nt;
	//while(1)
	{
	
	cin >> a >> b >> p >> mx;
	cur=1ll; ans=0ll;
	
	ffr(y,1,p)
	{
		cur=(cur*a)%p;
		//y=i;
		X=mx;
		
		m_1=nt.modInverse(cur,p);
		
		x=y-(b*m_1)%p;
		x=(p-1)*modfix(x,p)+y;
		if(x>X) continue;
		X=(X-x)/(p*(p-1))+1;
		
		
		ans+=X;
		
	}
		cout << ans << endl;
	}	
	return 0;
	
}
