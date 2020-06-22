#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int mn(int a, int b)
{
    if(a<b) return a;
    return b;
}


int main()
{
    int q, n, i, c, m, x, ans;
    while(cin >> q)
    {
        while(q--)
        {
            cin >> c >> m >> x;
            ans=mn(mn(c,m),x);
            if(x==ans)
            {
                 //ans+= (mn(c/2,m/2));
                 c-=x; m-=x;

                 if(m>c)
                 {
                    int take=mn(m/2,c);
                    ans+=(take);
                    c-=take;
                    m-=(take+take);
                    if(c>0)
                    {
                        if(m>0 && c>1) {c-=2; ans++;m--;}
                        ans+=(c/3);
                    }
                 }
                 else
                 {
                     int take=mn(c/2,m);
                     ans+=(take);
                     m-=take;
                     c-=(take+take);
                     if(m>0)
                     {
                         if(c>0 && m>1) {m-=2; ans++;c--;}
                         ans+=(m/3);
                     }
                 }
            }
            cout << ans << endl;
        }
    }
}
