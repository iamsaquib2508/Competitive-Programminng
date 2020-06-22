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
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, j, cnt[2]={0,0};
        string s;
        cin >> n;
        bool odd=0;
        ffr(i,0,n)
        {
            cin >> s;
            int sz=s.size();
            ffr(j,0,sz)
            {
                cnt[s[j]-'0']++;
            }
            if(sz&1) odd=1;
        }
        if(odd==0 && (cnt[0]&1)) cout << n-1 << endl;
        else cout << n << endl;
    }
}
