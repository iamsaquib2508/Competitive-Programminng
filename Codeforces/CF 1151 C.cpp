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

ll MOD=1000000007;

ll ff(ll n)
{
    if(n<2) return n;
    ll mul=1, total=0, odd=0, even=0;
    bool oddturn=1;
    while(1){
        if((total|mul)>n) break;
        if(oddturn) odd+=mul;
        else even+=mul;
        total|=mul;
        mul<<=1;
        oddturn=!oddturn;
    }
    if(oddturn) odd+=(n-total);
    else even+=(n-total);
    odd%=MOD; even%=MOD;

    ll ans = odd*odd%MOD + even*(even+1)%MOD;
    return ans%MOD;
}

int main()
{
    ll L, R;
    while(cin >> L >> R)
    {
        ll ans=ff(R)-ff(L-1);
        while(ans<0) ans+=MOD;
        cout << ans << '\n';
    }
}
