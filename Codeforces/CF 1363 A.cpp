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

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n, x, i, temp, a[2]={0,0};
        string ans="Yes\n";
        cin >> n >> x;
        ffr(i,0,n)
        {
            cin >> temp;
            a[(temp&1)]++;
        }
        if(a[1]==0) ans="No\n";
        else
        {
            if((a[1]&1)==0 && n==x) ans="No\n";
            else if((x&1)==0 && a[0]==0) ans="No\n";
        }
        cout << ans;
    }
}
