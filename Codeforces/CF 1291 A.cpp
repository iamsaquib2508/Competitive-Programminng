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
        int n, cnt=0;
        string s, ans="";
        
        cin >> n >> s;
        for(char a: s)
        {
            if(a&1)
            {
                if(cnt<2)
                {
                    ans+=a;
                    cnt++;
                }
                else break;
            }
        }
        if(ans.size()<2) ans="-1";
        cout << ans << endl;
    }
}
