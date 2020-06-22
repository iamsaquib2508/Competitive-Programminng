#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

class num
{
public:
    ll x, y;
    num(){}
    num(ll xx, ll yy){x=xx, y=yy;}
    bool operator==(const num &b) const
    {
        return (x*b.y==y*b.x);
    }

    bool operator<(const num &b) const
    {
        return (x*b.y<y*b.x);
    }
    void simplify()
    {
        if(y<0)
        {
            y=-y;
            x=-x;
        }
        ll g=gcd(abs(x),y);
        x/=g; y/=g;
    }
};

int main()
{
    int n;
    while(cin >> n)
    {
        ll a[200005], x;
        int i;
        map<num,int> mp;
        mp.clear();
        ffr(i,0,n) cin >> a[i];
        int sp=0;
        ffr(i,0,n)
        {
            cin >> x;

            if(a[i]==0) sp+=(x==0);
            else
            {
                num temp(-x,a[i]);
                temp.simplify();
                mp[temp]++;
            }
            //mp[(-x/1.0/a[i])]++;
        }
        map<num,int>::iterator it;
        int ans=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            ans=max(ans,it->second);
        }
        cout << ans+sp << endl;
    }
    return 0;
}
