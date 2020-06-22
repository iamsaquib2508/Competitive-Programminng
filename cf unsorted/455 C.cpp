




/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */




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

using namespace std;


class numberTheory{

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



/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */

int mod=1e9+7;
const int MAX=5001;
int dp[MAX][MAX];
string a;
int n;

int call(int pos, int lev)
{
    
    if(pos==n-1) return 1;
    if(dp[pos][lev]!=-1) return dp[pos][lev];
    ll ret;
    int i;
    if(a[pos]=='s')
    {
        ret= 0ll;
        if(lev==0) ret = call(pos+1, 0);
        else ret = (call(pos+1, lev)+call(pos, lev-1))%mod;
        
    }
    else
    {
        
        ret = call(pos+1, lev+1);
    }
    return dp[pos][lev]=ret;
}



int main()
{
    //while(1)
    {

        int i;
        mm(dp,-1);
        cin >> n;
        a="";
        char ch;

        ffr(i,0,n)
        {
            cin >> ch; a+=ch;
        }
        int ans=call(0, 0);
        cout << ans << endl;
    }
	return 0;

}
