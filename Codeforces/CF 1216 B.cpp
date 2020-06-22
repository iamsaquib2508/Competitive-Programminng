#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int mn(int a, int b)
{
    if(a<b) return a;
    return b;
}


int main()
{
    int a[1002];
    stack<int> pos[1002];
    int i, n;
    ll ans;
    std::vector<ll> v;
    while(cin >> n)
    {
        ans=0;
        v.clear();
        ffr(i,0,1002) while(!pos[i].empty()) pos[i].pop();
        ffr(i,0,n)
        {
            cin >> a[i];
            pos[a[i]].push(i+1);
        }
        sort(a,a+n);
        int x=0;
        for(i=n-1;i>=0;i--)
        {
            ans+= (a[i]*x+1ll);
            x++;
            v.pb(pos[a[i]].top()); pos[a[i]].pop();
        }
        cout << ans << endl;
        ffr(i,0,n) cout << v[i] << " ";
        cout << endl;
    }
}
