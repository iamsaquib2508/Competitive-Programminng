#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main()
{
    int t, n, i, ans, x;
    vector<int> a;
    cin >> t;
    while(t--)
    {
        a.clear();
        cin >> n;
        ffr(i,1,n+1)
        {
            cin >> x;
            a.push_back(x);
            //if(x>=i) ans++;
        }
        sort(a.begin(),a.end());

        ans=0;
        for(i=n-1;i>=0;i--)
        {
            if(a[i]>=ans+1)
            {
                ans++;
            }
            else break;
        }
        cout << ans << endl;
    }
}
