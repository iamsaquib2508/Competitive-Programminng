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

vector<ll> ans;

int main()
{
    ll k; string s;

    while(cin >> k)
    {
        ans.clear();
        cin >> s;
        ll cnt, i, sz=s.size();
        ffr(i,0,sz)
        {
            cnt=0;
            while(i<sz && s[i]=='0')
            {
                cnt++;
                i++;
            }
            ans.pb(cnt);
        }
        if(s[sz-1]=='1') ans.pb(0);

        sz=ans.size();
        ll ret=0ll, tmp;
        ll l, r;
        if(k==0)
        {
            ffr(i,0,sz)
            {
                tmp=ans[i];
                ret+=tmp*(tmp+1)/2;
            }
        }
        else
        {
            l=1, r=k;
            while(r<sz)
            {
                tmp=(ans[l-1]+1)*(ans[r]+1);
                ret+=tmp;
                l++; r++;
            }

        }
        cout << ret << endl;
    }
    return 0;
}
