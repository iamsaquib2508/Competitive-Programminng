




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

inline ll gcd(ll a, ll b){
    return b == 0 ? a: gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //while(1)
    {
        ll n, k, i, a, sz, gc, lc, temp, lcnew ;
        cin >> n >> k;
        
        cin >> lc;
        
        lc=gcd(k,lc);
        ffr(i,1,n)
        {
            cin >> a;
            
            gc=gcd(a,lc);
            lcnew=a/gc;
            lc*=gcd(lcnew,k/gc);
            
            //cout << lc << endl;
            

        }
        if(lc==k)
        cout << "Yes";
            
        else
        cout << "No";
    }

	return 0;

}

/*
17 510510
3 7 11 13 17 2 5

*/
