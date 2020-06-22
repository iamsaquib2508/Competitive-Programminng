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
#define bug(x) ;//cerr << #x << " = " << x << endl

using namespace std;

int main()
{
    ll n;
    while(cin >> n)
    {
        ll prev, i, cur;
        
        cin >> prev;
        ll cnt[n+1];
        mm(cnt,0);
        cnt[prev]++;

        ll ans=0;
        ll a, b;
        ffr(i,1,n)
        {
            cin >> cur;
            cnt[cur]++;
            a=min(prev,cur); b=max(prev,cur);
            ans+=(a*(n-b+1));
            bug(ans);
            prev=cur;
        }
        ans=-ans;
        ffrr(i,1,n) {ans+=(cnt[i]*(i*(n-i+1))); bug(ans);}
        cout << ans << endl;
    }
}
