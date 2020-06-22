#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf

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

string s;
int n, i;

int getnex(int pos, char c)
{
    ffr(i,pos,n)
    {
        if(s[i]==c) return i;
    }
    return 0;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int k, cur, extra;
        //string s;
        cin >> n >> k;
        cin >> s;

        extra=(n-k-k+2)/2;
        cur=0;
        vector<int> v;
        v.clear();
        char tmp;

        while(cur<extra)
        {
            int nex=getnex(cur,'(');
            //cout << nex << " nex\n";
            if(nex>cur)
            {
                //cout << cur << " cur\n";
                v.pb(cur); v.pb(nex);
                ffrr(i,0,(nex-cur)/2)
                {
                    tmp=s[nex-i];
                    s[nex-i]=s[cur+i];
                    s[cur+i]=tmp;
                }
            }
            cur++;
        }
        extra+=extra;
        while(cur<extra)
        {
            int nex=getnex(cur,')');
            if(nex>cur)
            {
                v.pb(cur); v.pb(nex);
                ffrr(i,0,(nex-cur)/2)
                {
                    tmp=s[nex-i];
                    s[nex-i]=s[cur+i];
                    s[cur+i]=tmp;
                }
            }
            cur++;
        }
        while(cur<n)
        {
            int nex=getnex(cur,'(');
            if(nex>cur)
            {
                v.pb(cur); v.pb(nex);
                ffrr(i,0,(nex-cur)/2)
                {
                    tmp=s[nex-i];
                    s[nex-i]=s[cur+i];
                    s[cur+i]=tmp;
                }
            }
            cur++;
            nex=getnex(cur,')');
            if(nex>cur)
            {
                v.pb(cur); v.pb(nex);
                ffrr(i,0,(nex-cur)/2)
                {
                    tmp=s[nex-i];
                    s[nex-i]=s[cur+i];
                    s[cur+i]=tmp;
                }
            }
            cur++;
        }
        //cout << s << endl;
        int sz=v.size();
        cout << sz/2 << endl;
        ffr(i,0,sz)
        {
            cout << v[i]+1 << " " << v[i+1]+1 << endl; i++;
        }
    }
}
