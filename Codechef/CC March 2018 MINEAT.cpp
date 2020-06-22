




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



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

ll h, a[100002];
int n;

bool possible(ll k)
{
    ll ans=0;
    int i;
    ffr(i,0,n)
    {
        ans+=(ceil(a[i]*1.0/k));
        if(ans>h) return 0;
    }
    return 1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, t, lo, hi, mid;
    ll ans, temp;
    

    cin >> t;
    while(t--)
    {
        cin >> n >> h;

        ffr(i,0,n)
        {
            cin >> a[i];
            hi=max(hi,a[i]);
        }

        lo=1;
        while(lo+1<hi)
        {
            mid=(lo+hi)/2;
            if(possible(mid))
            {
                hi=mid;
            }
            else
            {
                lo=mid;
            }
            
            
        }
        if(possible(lo)) hi=lo;
        cout << hi << endl;


    }
	return 0;

}
