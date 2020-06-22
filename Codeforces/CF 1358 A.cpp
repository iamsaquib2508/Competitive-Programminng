#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

// int ff(int ir)
// {
//     int lo=-1, hi=v.size(), mid;
//     while(hi-lo>1)
//     {
//         mid=(lo+hi)/2;
//         if(v[mid]<=ir) lo=mid;
//         else hi=mid;
//     }
//     return v.size()-hi;
// }

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        ll n, m, ans;
        cin >> n >> m;
        ans=(n/2)*(m);
        //cout << ans << endl;
        if(n&1)
        {
            ans+=(m/2);
            if(m&1) ans++;
        }
        cout << ans << endl;

    }
}
