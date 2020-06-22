#include<bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)

using namespace std;

int main()
{
    ll n, m, lim, i, MOD=998244353;
    string a, b;
    while(cin >> n >> m)
    {
        cin >> a >> b;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        if(n<m)
            ffr(i,n,m) a+='0';
        else
            ffr(i,m,n) b+='0';
        lim=max(n,m);
        ll cnt=0;
        ffr(i,0,lim)
        {
            cnt+=(b[i]=='1');
        }
        ll pw=1, ans=0;
        ffr(i,0,lim)
        {
            if(a[i]=='1')
                {ans+=(pw*cnt); ans%=MOD;}

            cnt-=(b[i]=='1');
            pw+=pw; pw%=MOD;
        }
        cout << ans%MOD << endl;
    }
}
