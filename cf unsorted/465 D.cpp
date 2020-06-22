




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




int main()
{
	//while(1)
	{
	
	ll n, m, i, ans, sum=0ll, temp, mul, mod=1000000007, mp=0, x;
	cin >> n >> m;
	
	
	int s1[100005], s2[100005];
	int equaltake=0, t=0, aisi=0;
	ffr(i,0,n) cin >> s1[i];
	ffr(i,0,n) cin >> s2[i];
	
	
	int a[100005];
	mm(a,-1);
	ffr(i,0,n)
	{
		if(s1[i]==0)
		{
			if(s2[i]>0)
			{
				a[i]=(m-s2[i])*2;
				aisi=1;
			}
			else
			{
				t=1;
				a[i]=(m-1);
				aisi=1;
			}
		}
		else
		{
			if(s2[i]==0)
			{
				a[i]=(s1[i]-1)*2;
				aisi=1;
			}
			else
			{
				if(s2[i]==s1[i]) continue;
				else if(s1[i]<s2[i])
				{
					n=i+1; break;
				}
				else
				{
					sum=2ll;
					n=i+1; break;
				}
			}
		}
	}

	mul=1ll;
	
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<0) continue;
		
		temp=(a[i]*mul)%mod;
		
		
		sum=(sum+temp)%mod;
		
		mul=(mul*m)%mod;
	}
	numberTheory nt;
	if(aisi==0)
	{
		ans=0;
		ffr(i,0,n)
		if(s1[i]>s2[i]) ans=1;
		goto dd;
	}
	
		if(sum%2==0) sum/=2;
		else mul=(mul+mul)%mod;
	
	mul=nt.bigMod(mul,mod-2,mod);
	ans=(sum*mul)%mod;
	dd:
	cout << ans << endl;
	
}

	return 0;
	
}
