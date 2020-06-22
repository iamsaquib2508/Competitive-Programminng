#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}


ll minn(ll a, ll b)
{
    if(a>b) return b; return a;
}



int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n, i, j, a[100005];
        vector<int> v; v.clear();
        cin >> n;
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        ffr(i,0,n)
        {
            j=n-1-i;
            v.pb(a[i]);
            if(j==i) break;
             v.pb(a[j]);
            if(j==i+1) break;
        }
        reverse(v.begin(),v.end());
        for(int aa: v)
        {
            cout << aa << ' ';
        }
        cout << endl;
    }
}
