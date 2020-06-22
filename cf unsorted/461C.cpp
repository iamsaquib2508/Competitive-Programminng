







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
	ll n, k, i, lc, gc;
	bool flag;
	//while(1)
	{
	
	cin >> n >> k;
	if(k==1)
	{
		cout << "Yes\n" ; return 0;
	}
	flag=false;
	gc=1;
	lc=1;
	
	ffrr(i,2,k)
	{
		gc=__gcd(lc,i);
		lc=(lc*i)/gc;
		if(lc>n+1)
		{
			//more gese
			flag=true; break;
		}
	}
	//cout << " lc " << lc << endl;
	if(flag==false)
	{
		if((n+1)%lc==0)
		{
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
	else cout << "No\n";
}
	return 0;
	
}
