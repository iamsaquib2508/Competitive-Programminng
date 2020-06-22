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

int ff(string s)
{
    int i, sz=s.size(), cnt=0, ans, cntorg;
    ffr(i,0,sz)
    {
        if(s[i]=='1') { cnt++;}
    }
    ans=minn(sz-cnt,cnt);
    cntorg=cnt;
    ffr(i,0,sz)
    {
        if(s[i]=='1') cnt--;
        //cout << i+1+cnt-(cntorg-cnt) << ' ' << (cntorg-cnt+sz-i-cnt-1) << endl;
        ans=minn(i+1+cnt-(cntorg-cnt),ans);
        ans=minn(ans,cntorg-cnt+sz-i-cnt-1);
    }
    return ans;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        string s;
        cin >> s;
        cout << ff(s) << endl;
    }
}
