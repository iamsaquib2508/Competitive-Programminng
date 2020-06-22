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
#define bug(x) cerr << #x << " = " << x << endl

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll gcd(ll a, ll b)
{
    if (b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n;
        string x, aa="", ss="";
        cin >> n >> x;
        bool done=0;
        for ( char a: x )
        {
            if(done)
            {
                aa+='0';
                ss+=a;
            }
            else if(a=='1')
            {
                aa+='1';
                ss+='0';
                done=1;
            }
            else if(a=='2')
            {
                aa+='1';
                ss+='1';
            }
            else if(a=='0')
            {
                aa+='0';
                ss+='0';
            }
        }
        cout << aa << '\n' << ss << '\n';
    }
}
