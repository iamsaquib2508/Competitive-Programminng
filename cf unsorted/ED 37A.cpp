







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

/*
class numberTheory{

public:
    numberTheory(){}

    pii extendedEuclid(i64 a, i64 b) { // returns x, y | ax + by = gcd(a,b)

        if(b == 0) return pii(1LL, 0LL);
        else {
            pii d = extendedEuclid(b, a % b);
            return pii(d.yy, d.xx - d.yy * (a / b));
        }

    }

    i64 modularInverse(i64 a, i64 n) {
        pair<i64,i64> ret = extendedEuclid(a, n);
        return ((ret.xx % n) + n) % n;
    }


    i64 bigMod(i64 a, i64 n , i64 m)
    {
        if(n==0) return 1 ;
        i64 ret = bigMod(a,n/2,m) ;
        ret = (ret*ret)%m ;
        if(n%2) ret = (ret*a)%m ;
        return ret ;
    }
};*/


/*  **********************************            DONATE BLOOD, SAVE LIFE!               ************************************  */




int main()
{
	ll t, i, j, n, k, A[203], mx, a;
	cin >> t;
	while(t--)
	{
		mm(A,0);
		mx=0;
		cin >> n >> k;
		ffr(i,0,k)
		{
			cin >> a;
			A[a]=1;
		}
		ffrr(i,1,n)
		{
			ll temp=1e5;
			for(j=i;j<=n;j++)
			{
				if(A[j]==1) 
				{
					temp=j-i+1; break;
				}
			}
			for(j=i-1;j>0;j--)
			{
				if(A[j]==1) 
				{
					temp=min(i-j+1,temp); break;
				}
			}
			mx=max(mx,temp);
		}
		cout << mx << endl;
	}

	return 0;
	
}
