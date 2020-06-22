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

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

ll gcd(ll a, ll b)
{
    if (b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int tt=100;
    while(tt--)
    {
        int n, m, s=0, x, take, xtra, pos, prev, i;
        int a[100005]={};
        vector<int> ans;
        ans.clear();

        cin >> n >> m;
        ffr(i,0,m)
        {
            cin >> x;
            a[i]=x;
            s+=x;
        }
        bool fel=0;

        if(s<n || a[m-1]+m-1>n)
        {
            fel=1;
        }
        else
        {
            xtra=s-n;

            ans.pb(1);
            pos=1;

            ffr(i,1,m)
            {
                prev=a[i-1];
                take=0;
                if(prev>1)
                {
                    take=minn(prev-1,xtra);
                }
                xtra-=take;
                pos=pos+prev-take;
                ans.pb(pos);
            }

        }

        if(fel)
        {
            cout << "-1\n";
        }
        else
        {
            for(int aa: ans)
            {
                cout << aa << ' ';
            }
            cout << '\n';
        }
    }
}
