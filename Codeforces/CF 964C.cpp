




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;


class numberTheory
{

public:
    numberTheory(){}

    plolo extendedEuclid(ll a, ll b) { // returns x, y | ax + by = gcd(a,b)

        if(b == 0) return plolo(1LL, 0LL);
        else {
            pii d = extendedEuclid(b, a % b);
            return plolo(d.yy, d.xx - d.yy * (a / b));
        }

    }

    ll modularInverse(ll a, ll n) {
        plolo ret = extendedEuclid(a, n);
        return ((ret.xx % n) + n) % n;
    }


    ll bigMod(ll a, ll n , ll m)
    {

        ll res=1, x=a;
        while ( n )
    	{
        	if ( n & 1 )
        	{
            	res = ( res * x ) % m;
        	}
        	x = ( x * x ) % m;
        	n = n >> 1;
    	}
    	return res;
    }

};

/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    numberTheory nt;
    ll n, a, b, k, hi, lo, sum, mul, ans, rt, bbya, bbyak, mod, i;
    string s;
    
    cin >> n >> a >> b>> k;
    cin >> s;
    
    mod=1000000009;
    mul=nt.bigMod(a,n,mod);
    sum=0;
    if(b==a)
    {
        ffr(i,0,k)
        {
            if(s[i]=='+')
            {
                sum+=mul;
            }
            else
            {
                sum+=(mod-mul);
            }
            while(sum<0)
            sum=(sum+mod);
            
            sum%=mod;
        }
        rt=(n+1)/k;
        
        cout << (sum*rt)%mod << endl;
        return 0;
    }
    
    bbya=(b*(nt.bigMod(a,mod-2,mod)))%mod;
    bbyak=1;
    ffr(i,0,k)
    {
        if(s[i]=='+')
        {
            sum+=mul;
        }
        else
        {
            sum+=(mod-mul);
        }
        
        while(sum<0)
        sum=(sum+mod);
        sum%=mod;
        
        mul*=bbya; mul%=mod;
        bbyak*=bbya; bbyak%=mod;
    }
    //cout << sum << " " << bbyak%mod << endl;
    rt=(n+1)/k;
    if(bbyak==1)
    {
        cout << (sum*rt)%mod << endl;
        return 0;
    }
    hi=nt.bigMod(bbyak,rt,mod)-1;
    
    
    //hi=nt.bigMod(b,rt,mod)-nt.bigMod(a,rt,mod);
    while(hi<0)
    hi=(hi+mod);
    hi%=mod;
    
    
    //lo=nt.bigMod(a,rt-1,mod)*((b-a+mod)%mod);
    
    lo=nt.modularInverse(bbyak-1,mod);
    while(lo<0)
    lo=(lo+mod);
    lo%=mod;
    //cout << hi << " " << lo << endl;
    
    if(hi==0)
    {
        if(lo==0)
        {
            cout << (sum*rt)%mod << endl;
            return 0;
        }
        else
        {
            cout << (sum*lo)%mod << endl;
            return 0;
        }
    }
    //find  bbyak^rt-1/bbyak-1
    ans=(sum*hi)%mod; ans=(ans*lo)%mod;
    
    cout << ans << endl;

    return 0;
}
