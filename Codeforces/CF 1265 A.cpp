#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define pf printf
#define ll long long int
#define ff first
#define ss second
#define sf(a) scanf("%d", &a)
#define CMAX 30002

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
int sz;

bool ok(int pos, char c)
{
    if(pos==0) return (s[1]!=c);
    if(pos==sz-1) return (s[sz-2]!=c);
    return (s[pos+1]!=c && s[pos-1]!=c);
}

void fill(int start)
{
    int i;
    ffr(i,start,sz)
    {
        if(s[i]=='?')
        {
            if(ok(i,'a'))
            {
                s[i]='a'; fill(start+1); return;
            }
            else if(ok(i,'b'))
            {
                s[i]='b'; fill(start+1); return;
            }
            else if(ok(i,'c'))
            {
                s[i]='c'; fill(start+1); return;
            }
            else
            {
                s[i]='?'; return;
            }
        }
    }
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int i;
        cin >> s;
        sz=s.size();
        fill(0);
        ffr(i,1,sz)
        {
            if(s[i-1]==s[i]) break;
        }
        if(i==sz) cout << s << endl;
        else cout << "-1\n";
    }
}
