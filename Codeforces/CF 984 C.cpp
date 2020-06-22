




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


ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    ll n, p, q, b, g;
    cin >> n;
    while(n--)
    {

        cin >> p >> q >> b;
        g=gcd(p,q);
        p/=g;
        q/=g;
        p=p%q;

        if(p==0 || q==1) cout << "Finite\n";
        else
        {
            while(q>1)
            {
                g=gcd(q,b);
                if(g==1)
                {
                    cout << "Infinite\n";
                    q=2; break;
                }
                while(q%g==0)
                {
                    q/=g;
                }
            }

            if(q==1) cout << "Finite\n";


        }
    }



    return 0;
}
