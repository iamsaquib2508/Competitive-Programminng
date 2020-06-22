#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define pb push_back
#define ll long long int
#define pf printf
#define MMX 1000000009

using namespace std;

map<int,int> mp;

ll modd(ll a, ll b)
{
    if(b<0) {a=-a; b=-b;}
    return a-a/b*b;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int t; cin >> t;

    while(t--)
    {
        int n, x, xm, ans;
        string s;

        cin >> n >> xm;
        cin >> s;
        mp.clear();

        int cnt=0, fixed, temp;

        int mx=-MMX, mn=MMX;
        for(char a: s)
        {
            if(a=='0') cnt++;
            else cnt--;
            mp[cnt]++;
            if(cnt>mx) mx=cnt;
            if(cnt<mn) mn=cnt;
        }
        fixed=cnt;
        //mp[0]++;
        x=xm;
        if(cnt<0)
        {
            ans=0;
            if(x<mn)
            {
                temp=(mn-x)/fixed*fixed;
                x+=temp;
                //x=(mn/fixed)*fixed+modd(x,fixed);
            }
            while(x<=mx)
            {
                //if(mp.find(x)!=mp.end())
                ans+=mp[x];
                x-=fixed;
            }
        }
        else if(cnt==0)
        {
            if(mp[x]>0) ans=-1;
            else ans=(x==0);
        }
        else
        {
            ans=0;
            if(x>mx)
            {
                temp=(x-mx)/fixed*fixed;
                x-=temp;
                //x=(mx/fixed)*fixed+modd(x,fixed);
            }
            //cout << x << " mx\n";
            while(x>=mn)
            {
                //if(mp.find(x)!=mp.end())
                ans+=mp[x];
                x-=fixed;
            }
        }
        //if(xm==0 && ans>=0) ans++;
        cout << ans << "\n";
    }

    return 0;
}
