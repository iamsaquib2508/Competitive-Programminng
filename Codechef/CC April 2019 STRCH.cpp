#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

using namespace std;

int main()
{
    ll T, n;
    string s; char x;
    vector<ll> v, pos;
    while(cin >> T)
    {
        while(T--)
        {
            cin >> n;
            cin >> s >> x;

            ll cnt=0, i;

            v.clear(); pos.clear();
            ffr(i,0,n)
            {
                if(s[i]==x)
                {
                    v.pb(cnt);
                    pos.pb(i);
                    cnt=0;
                }
                else
                {
                    cnt++;
                }
            }
            //v.pb(cnt);

            ll sz=v.size();
            ll ans=0;
            ffr(i,0,sz)
            {
                ans+=((v[i]+1)*(n-pos[i]));
            }

            cout << ans << endl;
        }
    }
    return 0;
}
