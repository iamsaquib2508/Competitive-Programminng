#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int n, tt, i, j, cnt, it;
    string s, t;
    cin >> tt;
    while(tt--)
    {
        cnt=0;
        bool ok=1;
        cin >> n >> s >> t;
        bool py[26]={}, ok2=0;
        ffr(i,0,n)
        {
            if(py[s[i]-'a']==0)
                py[s[i]-'a']=1;
            else ok2=1;
            if(s[i]!=t[i])
            {
                cnt++;
                if(cnt==1)
                {
                    it=i;
                }
                else if(cnt==2)
                {
                    if(s[it]!=s[i] || t[it]!=t[i]) ok=0;

                }
                else ok=0;
            }
        }
        if(cnt==1) ok=0;
        if(cnt==0) ok=ok2;
        if(ok) cout << "Yes\n";
        else cout << "No\n";

    }
}
