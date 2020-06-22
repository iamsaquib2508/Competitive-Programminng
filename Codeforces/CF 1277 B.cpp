#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int i, n, x, ans;
        map<int,int> s;
        s.clear();

        cin >> n;
        ffr(i,0,n)
        {
            cin >> x;
            ans=0;
            while(x%2==0) {x/=2; ans++;}
            if(s.find(x)==s.end()) s[x]=ans;
            else s[x]=maxx(ans,s[x]);
        }
        ans=0;
        for(map<int,int>::iterator it=s.begin();it!=s.end();it++)
        {
            ans+=(it->second);
        }
        cout << ans << endl;
    }
}
