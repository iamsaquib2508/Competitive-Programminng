#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf
#define PI acos(-1.0)

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

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, x, ans, s, k, i, hi=1, lo=1;
        cin >> n >> s >> k;
        bool mara=0;
        set<int> a; a.clear();
        ffr(i,0,k)
        {
            cin >> x;
            if(x>s)
            {
                a.insert(x);
                if(x==s+hi)
                {
                    hi++;
                    while(a.find(s+hi)!=a.end()) hi++;
                }
            }
            else if(x<s)
            {
                a.insert(x);
                if(x==s-lo)
                {
                    lo++;
                    while(a.find(s-lo)!=a.end()) lo++;
                }
            }
            else mara=1;

        }
        if(s==lo) lo=hi;
        if(s+hi>n) hi=lo;
        if(!mara) ans=0;
        else ans=minn(hi, lo);
        cout << ans << endl;
        //sotr(a,a+k);
        //ffr(i,0,)



    }
}
