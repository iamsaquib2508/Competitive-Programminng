#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

vector<int> v;

int ff(int ir)
{
    int lo=-1, hi=v.size(), mid;
    while(hi-lo>1)
    {
        mid=(lo+hi)/2;
        if(v[mid]<=ir) lo=mid;
        else hi=mid;
    }
    return v.size()-hi;
}

int main()
{
    int q, n, r, x, i;
    cin >> q;
    while(q--)
    {
        cin >> n >> r;
        set<int> s; s.clear();
        v.clear();
        ffr(i,0,n)
        {
            cin >> x;
            s.insert(x);
        }
        int sz=s.size();
        set<int>::iterator it;
        for(it=s.begin();it!=s.end();it++) v.pb((*it));
        int ans=0;
        while(ff(ans*r)>ans) ans++;
        cout << ans << endl;

    }
}
