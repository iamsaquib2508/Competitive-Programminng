#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        ll n, i, anslast=0, ans, x=0, y=0, len;
        string s;
        cin >> n >> s;
        map< pair<ll,ll> ,ll> mapp;
        mapp.clear();
        mapp[make_pair(0ll,0ll)]=-1;

        ans=n+1;
        bool got=0;
        ffr(i,0,n)
        {
            char a=s[i];
            if(a=='L') x--;
            else if(a=='R') x++;
            else if(a=='U') y++;
            else if(a=='D') y--;
            pair<ll,ll> p=make_pair(x,y);

            if(mapp.find(p)!=mapp.end())
            {
                //got
                len=i-mapp[p];
                if(len<ans)
                {
                    ans=len; anslast=i;
                    got=1;
                }
            }
            mapp[p]=i;
        }
        anslast++;
        if(got)
        cout << anslast-ans+1 << ' ' << anslast << endl;
        else cout << "-1\n";
    }
}
