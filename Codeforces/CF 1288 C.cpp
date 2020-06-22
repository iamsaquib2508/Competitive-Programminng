#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

ll mod=1000000007;
ll modinv[11], m;

ll bm(ll a, ll p)
{
    if(a==1) return 1;
    if(p==0) return 1;
    if(p==1) return a;
    ll x=bm(a,p/2);
    x=(x*x)%mod;
    if(p&1) x=(x*a)%mod;
    return x;
}

ll ncr(ll n, ll r)
{
    if(n<r) return 0;
    if(r==0) return 1;
    if(r+r>n) r=n-r;
    ll ans=1, i;
    ffrr(i,1,r)
    {
        ans*=(n-i+1); ans%=mod;
        ans*=(modinv[i]); ans%=mod;
    }
    return ans;
}

ll func(int lv, int t)
{
    //if(lv==0) return 1;
    ll ans=0;

    return ncr(t+lv-1,lv);
}

int main()
{
    int n, i, j;
    ll ans, temp;
    ffr(i,1,11)
    {
        modinv[i]=bm(i,mod-2);
    }
    while(cin >> n >> m)
    {
        ans=0;
        ffrr(i,1,n)
        {
            ffrr(j,i,n)
            {
                temp=func(m-1,n-j+1)*func(m-1,i);
                //cout << temp << " ";
                temp%=mod;
                ans+=temp;
                ans%=mod;
            }
        }
        //cout << "\n";
        cout << ans << endl;

    }
}
