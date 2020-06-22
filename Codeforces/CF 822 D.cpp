#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define rmax 5000006

using namespace std;

bool notprime[rmax];
vector<int> prims;
ll mod=1e9+7;
ll spd[rmax];

void seive(ll n)
{
    ll i, j;
    mm(notprime,0);
    mm(spd,-1);

    prims.pb(2);
    spd[2]=2;

    ffr(i,2,n)
    {
        //cout << i << "hello\n";
        i++;
        if(!notprime[i])
        {
            prims.pb(i);
            spd[i]=i;
            for(j=i*i;j<n;j+=(i+i))
            {
                if(spd[j]==-1)
                spd[j]=i;
                notprime[j]=1;
            }
        }
    }
}

ll f[rmax];

ll fcal(ll n)
{
    if(n==1) return 0;
    if(f[n]!=-1) return f[n];
    ll i, sz=prims.size(), k;
    ll inv2=((mod+1)/2);

    if(n&1) k=spd[n];
    else k=2;

    f[n]=fcal(n/k)+((n*(k-1)%mod)*inv2)%mod;
    return f[n];
}


int main()
{
    seive(rmax-1);
    //fcalc(rmax-1);
    mm(f,-1);
    int t, l, r, i;
    //ffr(i,1,20) cout << i << " i fi " << f[i] << endl;
    while(cin >> t >> l >> r)
    {

        ll mul, ans=0ll;
        mul=1ll;
        ffrr(i,l,r)
        {
            ans+=((mul*fcal(i))%mod); ans%=mod;
            mul*=t; mul%=mod;
        }

        cout << ans << endl;
    }
}
