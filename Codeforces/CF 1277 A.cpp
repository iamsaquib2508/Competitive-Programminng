#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minnn(int a, int b)
{
    if(a<b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, cur, one=0;
        cin >> n;
        int x=n, ans=-1;
        while(x>0)
        {
            one*=10; one++;
            x/=10;
            ans++;
        }
        ans*=9;
        cur=one;
        while(cur<=n)
        {
            ans++;
            cur+=one;
        }
        cout << ans << endl;
    }
}
