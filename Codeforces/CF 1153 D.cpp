#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

vector<int> v[300005];
bool ismax[300005];
int l;

int func(int s)
{
    int sz=v[s].size(), i;
    if(sz==0) {l++; return 1;}
    if(ismax[s])
    {
        int ret=300005;
        ffr(i,0,sz) ret=min(func(v[s][i]),ret);
        i=ret;
    }
    else
    {
        int ret=0;
        ffr(i,0,sz) ret+=func(v[s][i]);
        i=ret;
    }
    return i;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int i, x;
        l=0;
        mm(ismax,0);
        ffr(i,0,n) v[i].clear();
        ffrr(i,1,n)
        {
            cin >> x;
            ismax[i]=x;
        }
        ffrr(i,2,n)
        {
            cin >> x;
            v[x].pb(i);
        }
        int ans=func(1);
        cout << l+1-ans << endl;
    }
}
