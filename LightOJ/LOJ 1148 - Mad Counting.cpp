#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1000000

using namespace std;

int mp[mmxx+2];

int main()
{
    int T, n, i, x, ans, mod, temp, cc;

    while(cin >> T)
    {
        cc=1;
        mm(mp,0);
        while(T--)
        {
            cin >> n;
            ffr(i,0,n)
            {
                cin >> x; mp[x]++;
            }
            ans=n;
            mod=2;
            ffrr(i,1,mmxx)
            {
                if(mp[i]==0) continue;
                temp=mod-mp[i]%mod;
                if(temp==mod) temp=0;
                ans+=temp;
                mod++;
            }
            pf("Case %d: %d\n", cc, ans); cc++;
            mm(mp,0);
        }
    }
    return 0;
}
