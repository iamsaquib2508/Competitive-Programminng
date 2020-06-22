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
        vector<int> ans;
        ans.clear();
        int n, i, c[200005], prev, prevcol;
        cin >> n;
        ffr(i,0,n)
        {
            cin >> c[i];
        }
        prev=c[0];
        prevcol=0;

        set<int> ss; ss.clear();
        ans.pb(prevcol);
        ss.insert(prevcol);
        n--;
        bool copy=0; int id;

        ffr(i,1,n)
        {
            if(c[i]!=prev)
            {
                prevcol^=1;
            }
            else {copy=1; id=i;}
            ans.pb(prevcol);
            ss.insert(prevcol);
            prev=c[i];
        }
        //n
        if(c[i]!=prev)
        {
            prevcol^=1;
            if(prevcol==ans[0] && c[n]!=c[0])
            {
                //genjam
                if(!copy)
                    prevcol=2;
                else
                {
                    ffr(i,id,n)
                    {
                        ans[i]^=1;
                        //8
//1 2 1 2 2 3 1 2
//

                    }
                    prevcol^=1;

                }
                //look for copy

            }

        }
        else
        {
            if(prevcol==ans[0] && c[n]!=c[0])
            {
                //genjam
                prevcol^=1;
            }
        }
        ss.insert(prevcol);
        ans.pb(prevcol);
        cout << ss.size() << endl;
        for (int a: ans)
        {
            cout << a+1 << ' ';
        }
        cout << endl;
    }
}

And here I am, playing along with the participants, solving the problems on the whiteboard :D It is seriously exciting when I solve the problems faster than the participants. Especially the 
