







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


class temp
{
	public:
	ll str;
	ll sc, hc;
	temp(){
	}
	temp(ll s, ll h, ll ss)
	{
		sc=s; hc=h; str=ss;
	}
};

bool cmp(temp a, temp b)
{
	return a.sc*b.hc>a.hc*b.sc;
}

int main()
{
	ll n, ans, i, j, s, h, sz;
	cin >> n;
	string st;
	vector<temp> ar;
	vector<string> sss;
	
	ffr(i,0,n)
	{
		cin >> st;
		sz=st.size();
		s=0; h=0;
		sss.pb(st);
		
		ffr(j,0,sz)
		{
			if(st[j]=='s') s++; else h++;
			
		}
		ar.pb(temp(s,h,i));
		
	}
	sort(ar.begin(), ar.end(), cmp);
	st="";
	
	ffr(i,0,n) st+=sss[ar[i].str];
	sz=st.size();
	ans=0;
	s=0;
	
	ffr(i,0,sz)
	{
		if(st[i]=='s') s++;
		
		else ans+=s;
	}
	cout << ans << endl;
	return 0;
	
}
