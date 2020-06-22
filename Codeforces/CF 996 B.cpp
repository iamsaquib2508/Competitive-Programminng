



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



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    ll n, x, i, ans, mn, m, t;
    ans=0; mn=1000000000;
    cin >> n;
    ffr(i,0,n)
    {
        cin >> x;

        //if(x<=i) m=x;
        //else
        {
            t=x/n;
            m=i+(t*n);
            //cout << t << " t\n";
            if(m<x) m+=n;

        }
        if(mn>m)
        {
            mn=m;
            ans=i;
        }
        //cout << m << " m i " << i << endl;
    }
    cout << ans+1 << endl;







    return 0;
}
