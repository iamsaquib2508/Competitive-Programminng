#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define pb push_back

using namespace std;

int n;
ll a[102];

bool find(ll x)
{
    int i;
    ffr(i,0,n)
    {
        if(a[i]==x) return true;
    }
    return false;
}

int main()
{
    int i, taken;
    ll cur, x;
    vector<ll> v;
    cin >> n;
    ffr(i,0,n)
    {
        cin >> x;
        //st.insert(x);
        a[i]=x;
    }
    ffr(i,0,n)
    {
        v.clear();
        cur=a[i];
        taken=1;
        v.pb(cur);
        while(1)
        {
            if(taken==n) break;
            if(find(cur+cur))
            {
                taken++;
                cur+=cur;
                v.pb(cur);
            }
            else if((cur%3==0) && find(cur/3))
            {
                taken++;
                cur/=3;
                
                v.pb(cur);
            }
            else break;
        }
        if(taken==n)
        {
            ffr(i,0,n)
            {
                cout << v[i] << ' ';
            }
            cout << '\n';
            break;
        }

    }

    return 0;
}
