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
    ll n, k;
    while(cin >> n >> k)
    {
        ll i, a[200005], ans, j;
        string s; cin >> s;
        while(s[0]=='L') s.erase(s.begin());
        while(s[s.size()-1]=='R') s.erase(s.begin()+s.size()-1);
        n=s.size();
        ll maximum=0, minimum=0;
        bool korsi=0;
        ffr(j,0,n)
        {
            korsi=0;
            ffr(i,0,n)
            {
                if(s[i]=='R' && i+1<n && s[i+1]=='L')
                {
                    s[i]='L'; s[i+1]='R';
                    korsi=1;
                    maximum++;
                    i++;
                }

            }
            if(korsi)
            minimum++;

        }

        cout << 0 << endl;
    }
}
