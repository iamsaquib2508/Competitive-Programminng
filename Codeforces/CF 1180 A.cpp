#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    ll x, n;
    while(cin >> n)
    {
        if(n==1)
        {
            cout << "1\n"; continue;
        }
        ll ans=1;
        ffrr(x,2,n)
        {
            ans+=(4*x-4);
        }
        cout << ans << endl;
    }
}
