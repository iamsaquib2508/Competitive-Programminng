#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ok=-1; bool done=0;
        int a[300005], i, j;
        ffr(i,0,n)
        {
            cin >> a[i];
            if(a[i]>=i && !done) ok++;
            else done=1;
        }
        //ok is ok
        for(i=n-1;i>0;i--)
        {
            if(a[i]<n-i-1) break;
        }
        i++;
        if(i<=ok || ok==n-1)
        {
            cout << "Yes\n";
        }
        else if(i-ok==1)
        {
            //check
            if(a[ok]==ok && a[i]==n-i-1) cout << "No\n";
            else cout << "Yes\n";
        }
        else cout << "No\n";

    }
}
