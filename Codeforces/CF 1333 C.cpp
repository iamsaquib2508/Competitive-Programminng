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
#define bug(x) cerr << #x << " = " << x << endl

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll gcd(ll a, ll b)
{
    if (b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    ll n;
    while(cin >> n)
    {
        ll i, a[200005];
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        map<ll,ll> mp; mp.clear();
        ll sum=0, ans=0, temp, len=0, itemp;
        mp[0]=-1;
        ffr(i,0,n)
        {
            sum += a[i];
            if(mp.find(sum)!=mp.end())
            {
                //rep
                temp=mp[sum];
                itemp=i;
                mp.clear();
                ans+=(len+2)*(len+1)/2;
                sum=0;
                mp[0]=temp+1;
                len=i-temp;
                i=temp+1;
                //if(a[i]!=0)
                {
                    //ans++;
                    ans += len-1;
                }
                if(a[i]==0) ans--;
                ans -= len*(len+1)/2;
                len=0;
            }
            else {mp[sum]=i; len++;}
        }
        ans+=(len)*(len+1)/2;

        cout << ans << endl;
    }
}
