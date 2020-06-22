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

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll a, b, ans=0, cur;
        cin >> a >> b;
        cur=9;
        while(cur<=b)
        {
            ans+=a;
            cur=(cur*10)+9;
        }
        cout << ans << endl;
    }
}
