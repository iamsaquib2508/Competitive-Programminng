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

ll poww(ll a, ll b)
{
    ll ans=1; while(b--) ans*=a; return ans;
}

string s;
int sz;

ll f2(int pos)
{
    if(pos==sz) return 1;
    else if(s[pos]=='9')
    {
        return 4*poww(5,(sz-pos-1)) + f2(pos+1);
    }
    else if(s[pos]=='8')
    {
        return 4*poww(5,(sz-pos-1));
    }
    else if(s[pos]=='7')
    {
        return 3*poww(5,(sz-pos-1)) + f2(pos+1);
    }
    else if(s[pos]=='6')
    {
        return 2*poww(5,(sz-pos-1)) + f2(pos+1);
    }
    else if(s[pos]=='5')
    {
        return 2*poww(5,(sz-pos-1));
    }
    else if(s[pos]=='4')
    {
        return poww(5,(sz-pos-1)) + f2(pos+1);
    }
    else if(s[pos]>'0')
    {
        return poww(5,(sz-pos-1));
    }
    else if(s[pos]=='0')
    {
        return f2(pos+1);
    }
    else return -11792;

}


int main()
{
    ll a;cin >> a;
    while(cin >> s)
    {
        sz=s.size();
        cout << f2(0) << endl;
    }
    return 0;
}
