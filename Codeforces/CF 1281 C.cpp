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
        int x, k, l, sl, sz;
        ll ans, temp, MOD=1000000007;
        string s;
        cin >> x;
        cin >> s;
        l=0;
        //alllen=s.size();
        bool done=0;
        ans=s.size();
        while(l<x && l<s.size())
        {
            l++;
            sl=s[l-1]-'0';
            sz=s.size();

            if(done)
            {
                temp=(ans-l);
                if(temp<0) temp+=MOD;
                ans+=(temp*(sl-1))%MOD; ans%=MOD;
                //cout << ans << endl;
            }
            else
            {
                while(sl>1)
                {
                    ffr(k,l,sz)
                    {
                        s+=s[k];
                    }
                    ans+=(sz-l);
                    sl--;
                }
            }
            if(!done && s.size()>x) {done=1; }
            //cout << s << endl;
        }
        cout << ans << "\n";
    }
}
