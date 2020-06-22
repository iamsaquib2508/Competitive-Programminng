




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

#define MX 150002

    map<int,ll> m;
    ll a[MX]; bool taken[MX];

void ff(int i, ll x)
{
        if(m.find(x)==m.end() || m[x]==-1)
        {
            a[i]=x;
            m[x]=i;

        }
        else
        {
            int t=m[x];
            taken[t]=1;
            m[x]=-1;
            ff(i,x+x);
        }
        return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    mm(taken,0);
    int i, cn, n;
    ll x;
    vector<ll> v;
    cin >> n;
    ffr(i,0,n)
    {
        cin >> x;
        ff(i,x);
        
    }
    cn=0;
    ffr(i,0,n)
    {
        if(taken[i]) continue;
        cn++; v.pb(a[i]);
    }
    cout << cn << endl;
    ffr(i,0,cn) cout << v[i] << " ";

    return 0;
}
